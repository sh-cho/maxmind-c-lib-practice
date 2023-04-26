#include <iostream>

#include "geo_ip_loader.h"

int main() {
	const std::string ISP_DB_FILENAME = "../files/GeoIP2-ISP-Test-1c93857.mmdb";
//	const std::string ISP_DB_FILENAME = "../files/GeoIP2-ISP-real.mmdb";
	const std::string COUNTRY_DB_FILENAME = "../files/GeoIP2-Country-Test-d202e5e.mmdb";

	GeoIPLoader *pGeo = new MaxmindGeoIPLoader(ISP_DB_FILENAME, COUNTRY_DB_FILENAME);

//	std::cout << pGeo->getMccmnc("5.145.96.123") << std::endl;
	std::cout << pGeo->getMccmnc("45.58.25.2") << std::endl;

	delete pGeo;
	return 0;
}
