#ifndef MAXMIND_LIB_TEST_GEO_IP_LOADER_H
#define MAXMIND_LIB_TEST_GEO_IP_LOADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <sys/socket.h>

#include <maxminddb.h>

#include "constants.h"
#include "maxmind_db_reader.h"

namespace geo_ip_loader {

class GeoIPLoader {
public:
	virtual ~GeoIPLoader() = default;

	virtual std::string getMccmnc(const std::string &ip_address) = 0;

	virtual std::string getMccmnc(const sockaddr_in &addr) = 0;
};

class EmptyGeoIPLoader final : public GeoIPLoader {
public:
	std::string getMccmnc(const std::string &ip_address) override;

	std::string getMccmnc(const sockaddr_in &addr) override;
};

class MaxmindGeoIPLoader final : public GeoIPLoader {
private:

	MaxmindDBReader isp_db_reader;
	MaxmindDBReader country_db_reader;

public:
	MaxmindGeoIPLoader(const std::string &isp_db_filename, const std::string &country_db_filename);

	~MaxmindGeoIPLoader() override;

	std::string getMccmnc(const std::string &ip_address) override;

	std::string getMccmnc(const sockaddr_in &addr) override;
};

} // namespace geo_ip_loader


#endif //MAXMIND_LIB_TEST_GEO_IP_LOADER_H
