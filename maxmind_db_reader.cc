#include "maxmind_db_reader.h"
#include "maxmind_error_category.h"

#include <spdlog/spdlog.h>
#include <system_error>

namespace geo_ip_loader {

MaxmindDBReader::MaxmindDBReader(const std::string &db_filename) {
	const int status = MMDB_open(db_filename.data(), MMDB_MODE_MMAP, &mmdb);

	if (MMDB_SUCCESS != status) {
		spdlog::info("failed to open");

		const ErrorCategory &category(get_error_category());
		const std::error_code code(status, category);
		const std::string msg(MMDB_strerror(status));

		throw std::system_error(code, msg);
	}
}

MaxmindDBReader::~MaxmindDBReader() {
	MMDB_close(&mmdb);
}

MMDB_lookup_result_s MaxmindDBReader::lookup_raw(const std::string &ip_address) {
	int gai_error;
	int mmdb_error;
	MMDB_lookup_result_s result = MMDB_lookup_string(&mmdb, ip_address.data(), &gai_error, &mmdb_error);

	if (gai_error) {
		throw std::invalid_argument(gai_strerror(gai_error));
	}
	if (mmdb_error) {
		const ErrorCategory &category(get_error_category());
		const std::error_code code(mmdb_error, category);
		const std::string msg(MMDB_strerror(mmdb_error));

		throw std::system_error(code, msg);
	}
	if (!result.found_entry) {
		throw NotFoundException();
	}

	return result;
}

std::string MaxmindDBReader::get_field(const std::string &ip_address, const VCStr &lookup_path) {
	MMDB_lookup_result_s lookup = lookup_raw(ip_address);
	return get_field(&lookup, lookup_path);
}

std::string MaxmindDBReader::get_field(MMDB_lookup_result_s *lookup, const VCStr &lookup_path) {
	if (!lookup) {
		return std::string();
	}

	VCStr new_v = lookup_path;
	if (new_v.empty() || *new_v.rbegin() != nullptr) {
		new_v.push_back(nullptr);
	}

	MMDB_entry_s *entry = &lookup->entry;
	MMDB_entry_data_s result;
	MMDB_aget_value(entry, &result, new_v.data());

	if (result.has_data) {
		switch (result.type) {
			case MMDB_DATA_TYPE_UTF8_STRING:
				return std::string(result.utf8_string, result.data_size);
			case MMDB_DATA_TYPE_DOUBLE:
				return std::to_string(result.double_value);
			case MMDB_DATA_TYPE_UINT16:
				return std::to_string(result.uint16);
			case MMDB_DATA_TYPE_UINT32:
				return std::to_string(result.uint32);
			case MMDB_DATA_TYPE_INT32:
				return std::to_string(result.int32);
			case MMDB_DATA_TYPE_UINT64:
				return std::to_string(result.uint64);
			case MMDB_DATA_TYPE_FLOAT:
				return std::to_string(result.float_value);
			case MMDB_DATA_TYPE_BOOLEAN:
				return (result.boolean ? "true" : "false");

			default:
				spdlog::debug("Not supported for quick retrieval. type: {}", result.type);
		}
	}

	return std::string();
}

} // namespace geo_ip_loader