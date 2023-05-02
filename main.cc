#include <iostream>

#include "geo_ip_loader.h"
#include <spdlog/spdlog.h>

int main() {
	spdlog::set_level(spdlog::level::debug);

	const std::string ISP_DB_FILENAME = "../files/GeoIP2-ISP-Test-1c93857.mmdb";
//	const std::string ISP_DB_FILENAME = "../files/GeoIP2-ISP-real.mmdb";
	const std::string COUNTRY_DB_FILENAME = "../files/GeoIP2-Country-Test-d202e5e.mmdb";

	geo_ip_loader::GeoIPLoader *p_geo = new geo_ip_loader::MaxmindGeoIPLoader(ISP_DB_FILENAME, COUNTRY_DB_FILENAME);

	std::cout << p_geo->getMccmnc("45.58.25.2") << std::endl;

	spdlog::info("spdlog test {}", 1);

	delete p_geo;
	return 0;
}
