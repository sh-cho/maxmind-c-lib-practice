#include <gtest/gtest.h>

#include "geo_ip_loader.h"

namespace geo_ip_loader {

/// Fixtures
class GeoIPLoaderFixture : public ::testing::Test {
protected:
	GeoIPLoader *maxmindGeoIpLoader = nullptr;

	void SetUp() override {
		maxmindGeoIpLoader = new MaxmindGeoIPLoader("../files/GeoIP2-ISP-Test-1c93857.mmdb",
													"../files/GeoIP2-Country-Test-d202e5e.mmdb");
	}

	void TearDown() override {
		delete maxmindGeoIpLoader;
	}
};

/// Tests

TEST(HelloTest, BasicAssertions) {
	EXPECT_EQ(7 * 6, 42);
}

TEST_F(GeoIPLoaderFixture, NormalMccmnc) {
	// 1. Exists in ISP DB range
	// 1-1. mcc, mnc exist
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("149.101.100.0"), "310004");
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("::9565:6400"), "310004");
	// 1-2. mcc, mnc not exist
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("1.0.128.0"), DEFAULT_MCC);
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("2001:1700::"), DEFAULT_MCC);

	// 2. Not exists in ISP DB - Lookup Country DB
	// 2-1. Exists in Country DB
	// 2-1-1. Have "country.iso_code" path
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("2001:0220:0000:0000:0000:2000:0000:0000"),
			  std::to_string(COUNTRY_MCC_MAP.at("KR")));
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("217.65.48.0"),
			  std::to_string(COUNTRY_MCC_MAP.at("GI")));
	// 2-1-2. Doesn't have iso_code
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("::212.47.235.81"),
			  DEFAULT_MCCMNC);
	// 2-2. Not Exists in Country DB
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("0.0.0.0"), DEFAULT_MCC);
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("::1"), DEFAULT_MCC);
}

TEST_F(GeoIPLoaderFixture, Ipv6Format) {
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("::217.65.48.0"),
			  std::to_string(COUNTRY_MCC_MAP.at("GI")));
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("::d941:3000"),
			  std::to_string(COUNTRY_MCC_MAP.at("GI")));
}

TEST_F(GeoIPLoaderFixture, WrongFormat) {
	// No exception
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("abc"), DEFAULT_MCC);
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc(""), DEFAULT_MCC);
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc(":123"), DEFAULT_MCC);
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("123.456"), DEFAULT_MCC);
}

} // namespace geo_ip_loader
