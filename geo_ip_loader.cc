#include "geo_ip_loader.h"

#include <unordered_map>

#include <spdlog/spdlog.h>

namespace geo_ip_loader {

std::string EmptyGeoIPLoader::getMccmnc(const std::string &ip_address) {
	return geo_ip_loader::DEFAULT_MCCMNC;
}

std::string EmptyGeoIPLoader::getMccmnc(const sockaddr_in &addr) {
	return geo_ip_loader::DEFAULT_MCCMNC;
}

MaxmindGeoIPLoader::MaxmindGeoIPLoader(const std::string &isp_db_filename, const std::string &country_db_filename)
		: isp_db_reader(MaxmindDBReader(isp_db_filename)),
		  country_db_reader(MaxmindDBReader(country_db_filename)) {
	spdlog::debug("ctor, isp_db_filename: {}, country_db_filename: {}", isp_db_filename, country_db_filename);
}

MaxmindGeoIPLoader::~MaxmindGeoIPLoader() {
	spdlog::debug("dtor");
}

std::string MaxmindGeoIPLoader::getMccmnc(const std::string &ip_address) {
	try {
		// 1. find in ISP db
		auto lookup = isp_db_reader.lookup_raw(ip_address);
		const std::string mcc = isp_db_reader.get_field(&lookup, ISP_MCC_VEC);
		const std::string mnc = isp_db_reader.get_field(&lookup, ISP_MNC_VEC);
		if (!mcc.empty() && !mnc.empty()) {
			// TODO: absl::StrCat
			return mcc + mnc;
		}
	} catch (const NotFoundException& err) {
		spdlog::debug("ISP - not found. ip: {}", ip_address);
	} catch (const std::exception& err) {
		spdlog::warn("ISP - Other error. ip: {}, err: {}", ip_address, err.what());
		return DEFAULT_MCC;
	}

	try {
		// 2. find in Country db
		auto lookup = country_db_reader.lookup_raw(ip_address);
		const std::string iso_code = country_db_reader.get_field(&lookup, COUNTRY_ISO_CODE_VEC);
		if (!iso_code.empty()) {
			try {
				return std::to_string(COUNTRY_MCC_MAP.at(iso_code));
			} catch (...) {
				spdlog::debug("Failed to get country code. iso_code: {}", iso_code);
				throw;
			}
		}

		spdlog::debug("not found. ip_address: {}", ip_address);
		return DEFAULT_MCCMNC;
	} catch (const std::exception& err) {
		spdlog::warn("lookup fail. ip: {}, err: {}", ip_address, err.what());
		return DEFAULT_MCC;
	}
}

std::string MaxmindGeoIPLoader::getMccmnc(const sockaddr_in &addr) {
	// TODO
	throw std::logic_error("Not implemented yet");
}

} // namespace geo_ip_loader
