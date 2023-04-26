#include "geo_ip_loader.h"

#include <sstream>
#include <unordered_map>

const std::unordered_map<int, std::string> ISO_MAP = {
		{202, "GR"},
		{204, "NL"},
		{206, "BE"},
		{208, "FR"},
		{212, "MC"},
		{213, "AD"},
		{214, "ES"},
		{216, "HU"},
		{218, "BA"},
		{219, "HR"},
		{220, "RS"},
		{221, "XK"},
		{222, "IT"},
		{226, "RO"},
		{228, "CH"},
		{230, "CZ"},
		{231, "SK"},
		{232, "AT"},
		{234, "GB"},
		{235, "GB"},
		{238, "DK"},
		{240, "SE"},
		{242, "NO"},
		{244, "FI"},
		{246, "LT"},
		{247, "LV"},
		{248, "EE"},
		{250, "RU"},
		{255, "UA"},
		{257, "BY"},
		{259, "MD"},
		{260, "PL"},
		{262, "DE"},
		{266, "GI"},
		{268, "PT"},
		{270, "LU"},
		{272, "IE"},
		{274, "IS"},
		{276, "AL"},
		{278, "MT"},
		{280, "CY"},
		{282, "GE"},
		{283, "AM"},
		{284, "BG"},
		{286, "TR"},
		{288, "FO"},
		{289, "AB"},
		{290, "GL"},
		{292, "SM"},
		{293, "SI"},
		{294, "MK"},
		{295, "LI"},
		{297, "ME"},
		{302, "CA"},
		{308, "PM"},
		{310, "US"},
		{311, "US"},
		{312, "US"},
		{313, "US"},
		{314, "US"},
		{315, "US"},
		{316, "US"},
		{330, "PR"},
		{332, "VI"},
		{334, "MX"},
		{338, "JM"},
		{340, "MF"},
		{342, "BB"},
		{344, "AG"},
		{346, "KY"},
		{348, "VG"},
		{350, "BM"},
		{352, "GD"},
		{354, "MS"},
		{356, "KN"},
		{358, "LC"},
		{360, "VC"},
		{362, "SX"},
		{363, "AW"},
		{364, "BS"},
		{365, "AI"},
		{366, "DM"},
		{368, "CU"},
		{370, "DO"},
		{372, "HT"},
		{374, "TT"},
		{376, "TC"},
		{400, "AZ"},
		{401, "KZ"},
		{402, "BT"},
		{404, "IN"},
		{405, "IN"},
		{406, "IN"},
		{410, "PK"},
		{412, "AF"},
		{413, "LK"},
		{414, "MM"},
		{415, "LB"},
		{416, "JO"},
		{417, "SY"},
		{418, "IQ"},
		{419, "KW"},
		{420, "SA"},
		{421, "YE"},
		{422, "OM"},
		{424, "AE"},
		{425, "PS"},
		{426, "BH"},
		{427, "QA"},
		{428, "MN"},
		{429, "NP"},
		{430, "AE"},
		{431, "AE"},
		{432, "IR"},
		{434, "UZ"},
		{436, "TJ"},
		{437, "KG"},
		{438, "TM"},
		{440, "JP"},
		{441, "JP"},
		{450, "KR"},
		{452, "VN"},
		{454, "HK"},
		{455, "MO"},
		{456, "KH"},
		{457, "LA"},
		{460, "CN"},
		{461, "CN"},
		{466, "TW"},
		{467, "KP"},
		{470, "BD"},
		{472, "MV"},
		{502, "MY"},
		{505, "NF"},
		{510, "ID"},
		{514, "TL"},
		{515, "PH"},
		{520, "TH"},
		{525, "SG"},
		{528, "BN"},
		{530, "NZ"},
		{536, "NR"},
		{537, "PG"},
		{539, "TO"},
		{540, "SB"},
		{541, "VU"},
		{542, "FJ"},
		{543, "WF"},
		{544, "AS"},
		{545, "KI"},
		{546, "NC"},
		{547, "PF"},
		{548, "CK"},
		{549, "WS"},
		{550, "FM"},
		{551, "MH"},
		{552, "PW"},
		{553, "TV"},
		{554, "TK"},
		{555, "NU"},
		{602, "EG"},
		{603, "DZ"},
		{604, "MA"},
		{605, "TN"},
		{606, "LY"},
		{607, "GM"},
		{608, "SN"},
		{609, "MR"},
		{610, "ML"},
		{611, "GN"},
		{612, "CI"},
		{613, "BF"},
		{614, "NE"},
		{615, "TG"},
		{616, "BJ"},
		{617, "MU"},
		{618, "LR"},
		{619, "SL"},
		{620, "GH"},
		{621, "NG"},
		{622, "TD"},
		{623, "CF"},
		{624, "CM"},
		{625, "CV"},
		{626, "ST"},
		{627, "GQ"},
		{628, "GA"},
		{629, "CG"},
		{630, "CD"},
		{631, "AO"},
		{632, "GW"},
		{633, "SC"},
		{634, "SD"},
		{635, "RW"},
		{636, "ET"},
		{637, "SO"},
		{638, "DJ"},
		{639, "KE"},
		{640, "TZ"},
		{641, "UG"},
		{642, "BI"},
		{643, "MZ"},
		{645, "ZM"},
		{646, "MG"},
		{647, "RE"},
		{648, "ZW"},
		{649, "NA"},
		{650, "MW"},
		{651, "LS"},
		{652, "BW"},
		{653, "SZ"},
		{654, "KM"},
		{655, "ZA"},
		{657, "ER"},
		{658, "SH"},
		{659, "SS"},
		{702, "BZ"},
		{704, "GT"},
		{706, "SV"},
		{708, "HN"},
		{710, "NI"},
		{712, "CR"},
		{714, "PA"},
		{716, "PE"},
		{722, "AR"},
		{724, "BR"},
		{730, "CL"},
		{732, "CO"},
		{734, "VE"},
		{736, "BO"},
		{738, "GY"},
		{740, "EC"},
		{742, "GF"},
		{744, "PY"},
		{746, "SR"},
		{748, "UY"},
		{750, "FK"},
		{995, "IO"},
		{999, "PC"}
};

std::string EmptyGeoIPLoader::getMccmnc(std::string ip) {
	return GeoIPLoader::DEFAULT_MCCMNC;
}

std::string EmptyGeoIPLoader::getMccmnc(sockaddr_in &addr) {
	return GeoIPLoader::DEFAULT_MCCMNC;
}

MaxmindGeoIPLoader::MaxmindGeoIPLoader(std::string isp_db_filename, std::string country_db_filename) {
	{
		if (isp_db_filename.empty()) {
			return;
		}
		int status = MMDB_open(isp_db_filename.data(), MMDB_MODE_MMAP, &isp_db);
		if (MMDB_SUCCESS != status) {
			std::cerr << "(ISP) Can't open " << isp_db_filename << " - " << MMDB_strerror(status) << std::endl;
		}
	}

	{
		if (country_db_filename.empty()) {
			return;
		}
		int status = MMDB_open(country_db_filename.data(), MMDB_MODE_MMAP, &country_db);
		if (MMDB_SUCCESS != status) {
			std::cerr << "(COUNTRY) Can't open " << country_db_filename << " - " << MMDB_strerror(status) << std::endl;
		}
	}
}

MaxmindGeoIPLoader::~MaxmindGeoIPLoader() {
	std::clog << "[~MaxmindGeoIPLoader]" << std::endl;

	MMDB_close(&isp_db);
	MMDB_close(&country_db);
}

std::string MaxmindGeoIPLoader::getMccmnc(std::string ip) {
	std::clog << "[::getMccmnc] ip: " << ip << std::endl;

	{
		int gai_error, mmdb_error;
		MMDB_lookup_result_s result = MMDB_lookup_string(&isp_db, ip.data(), &gai_error, &mmdb_error);
		if (0 != gai_error) {
			std::cerr << "getaddressinfo error: " << gai_strerror(gai_error) << std::endl;
			return GeoIPLoader::DEFAULT_MCCMNC;
		}
		if (MMDB_SUCCESS != mmdb_error) {
			std::cerr << "libmaxminddb error: " << MMDB_strerror(mmdb_error) << std::endl;
			return GeoIPLoader::DEFAULT_MCCMNC;
		}

		if (!result.found_entry) {
			std::clog << "[::getMccmnc] entry not found" << std::endl;
			return GeoIPLoader::DEFAULT_MCCMNC;
		}

		std::clog << "[::getMccmnc] found entry" << std::endl;
		MMDB_entry_data_list_s *entry_data_list = NULL;
		int status = MMDB_get_entry_data_list(&result.entry, &entry_data_list);
		if (MMDB_SUCCESS != status) {
			std::clog << "[::getMccmnc] got an error while get_entry_data_list: " << MMDB_strerror(status) << std::endl;
			goto cleanup_;
		}

		if (nullptr == entry_data_list) {
			std::clog << "[::getMccmnc] entry not found" << std::endl;
			goto cleanup_;
		}

		{
			std::clog << "[::getMccmnc] dump" << std::endl;
			MMDB_dump_entry_data_list(stdout, entry_data_list, 2);

			MMDB_entry_data_s entry_data;

			/// mobile_country_code + mobile_network_code
			/// NOTE: entry_data -> out parameter
//			std::string mcc, mnc;
			int status2 = MMDB_get_value(&result.entry, &entry_data, "mobile_country_code", nullptr);
			if (MMDB_SUCCESS != status2) {
				std::clog << "[::getMccmnc][mcc] mmdb error: " << MMDB_strerror(status2)
						  << std::endl;
				goto cleanup_;
			} else if (!entry_data.has_data) {
				std::clog << "[::getMccmnc][mcc] !entry_data.has_data" << std::endl;
				goto cleanup_;
			}

			std::ostringstream oss;
			oss << std::string_view{entry_data.utf8_string, entry_data.data_size};

			int status3 = MMDB_get_value(&result.entry, &entry_data, "mobile_network_code", nullptr);
			if (MMDB_SUCCESS != status3) {
				std::clog << "[::getMccmnc][mnc] mmdb error: " << MMDB_strerror(status3)
						  << std::endl;
				goto cleanup_;
			} else if (!entry_data.has_data) {
				std::clog << "[::getMccmnc][mnc] !entry_data.has_data" << std::endl;
				goto cleanup_;
			}

			oss << std::string_view{entry_data.utf8_string, entry_data.data_size};

			const auto & mccmnc = oss.str();
			if (mccmnc.empty()) {
				std::clog << "[::getMccmnc] empty mccmnc" << std::endl;
				goto cleanup_;
			}

			std::clog << "[::getMccmnc] GOOD! - " << mccmnc << std::endl;

			MMDB_free_entry_data_list(entry_data_list);
			return mccmnc;
		}

		cleanup_:
		MMDB_free_entry_data_list(entry_data_list);
	}

	std::clog << "[::getMccmnc] returning default mccmnc" << std::endl;
	return GeoIPLoader::DEFAULT_MCCMNC;

	/// country_db

}

std::string MaxmindGeoIPLoader::getMccmnc(sockaddr_in &addr) {
	return std::string();
}
