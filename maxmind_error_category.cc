#include "maxmind_error_category.h"

#include <maxminddb.h>

namespace geo_ip_loader {

const char *ErrorCategory::name() const noexcept {
	return "GeoLite2PP";
}

std::string ErrorCategory::message(int code) const {
	std::string msg = MMDB_strerror(code);
	if (msg.empty()) {
		msg = "unknown MMDB error #" + std::to_string(code);
	}

	return msg;
}

const ErrorCategory &get_error_category() noexcept {
	static ErrorCategory const ecat;
	return ecat;
}

std::error_code make_error_code(MMDBStatus s) {
	return std::error_code(static_cast<int>(s), get_error_category());
}

std::error_condition make_error_condition(MMDBStatus s) {
	return std::error_condition(static_cast<int>(s), get_error_category());
}

} // ::geo_ip_loader
