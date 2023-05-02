#ifndef MAXMIND_C_LIB_PRACTICE_MAXMIND_DB_READER_H
#define MAXMIND_C_LIB_PRACTICE_MAXMIND_DB_READER_H

#include <maxminddb.h>
#include <string>

#include "constants.h"

namespace geo_ip_loader {

/**
 * libmaxminddb wrapper
 */
class MaxmindDBReader final {
private:
	MMDB_s mmdb;

public:
	explicit MaxmindDBReader(const std::string &db_filename);

	~MaxmindDBReader();

	MMDB_lookup_result_s lookup_raw(const std::string &ip_address);

	std::string get_field(const std::string &ip_address, const VCStr &lookup_path);

	/**
	 * @param[in]	lookup
	 * @param		lookup_path
	 * @return		value if exists, or empty string
	 */
	std::string get_field(MMDB_lookup_result_s *lookup, const VCStr &lookup_path);
};

/// Exceptions
class NotFoundException final: public std::logic_error {
public:
	NotFoundException(): std::logic_error("NOT FOUND") {};
};

} // namespace geo_ip_loader

#endif //MAXMIND_C_LIB_PRACTICE_MAXMIND_DB_READER_H
