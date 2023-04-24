#ifndef MAXMIND_LIB_TEST_GEO_IP_LOADER_H
#define MAXMIND_LIB_TEST_GEO_IP_LOADER_H

#include <string>
#include <sys/socket.h>
#include <unordered_map>

class GeoIPLoader {
public:
	static inline const std::string DEFAULT_MCC = "000";
	static inline const std::string DEFAULT_MCCMNC = DEFAULT_MCC + "00";
	static inline const std::string TEST_MCC = "001";
	static inline const std::string TEST_MCCMNC = TEST_MCC + "01";

	virtual ~GeoIPLoader() = default;

	virtual std::string getMccmnc(std::string ip) = 0;

	virtual std::string getMccmnc(sockaddr &addr) = 0;
};

class EmptyGeoIPLoader : public GeoIPLoader {
public:
	std::string getMccmnc(std::string ip) override;

	std::string getMccmnc(sockaddr &addr) override;
};

class MaxmindGeoIPLoader : public GeoIPLoader {
public:
	std::string getMccmnc(std::string ip) override;

	std::string getMccmnc(sockaddr &addr) override;
};

#endif //MAXMIND_LIB_TEST_GEO_IP_LOADER_H
