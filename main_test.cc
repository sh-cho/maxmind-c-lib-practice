#include <gtest/gtest.h>

#include "geo_ip_loader.h"

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

TEST_F(GeoIPLoaderFixture, Mccmnc) {
	EXPECT_EQ(maxmindGeoIpLoader->getMccmnc("149.101.100.0"), "310004");
}
