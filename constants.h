#ifndef MAXMIND_C_LIB_PRACTICE_CONSTANTS_H
#define MAXMIND_C_LIB_PRACTICE_CONSTANTS_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace geo_ip_loader {

using VCStr = std::vector<const char *>;

const VCStr ISP_MCC_VEC{"mobile_country_code", nullptr};
const VCStr ISP_MNC_VEC{"mobile_network_code", nullptr};
const VCStr COUNTRY_ISO_CODE_VEC{"country", "iso_code", nullptr};

const std::string DEFAULT_MCC = "000";
const std::string DEFAULT_MCCMNC = DEFAULT_MCC + "00";
const std::string TEST_MCC = "001";
const std::string TEST_MCCMNC = TEST_MCC + "01";
const std::string INVALID_MCCMNC = "6553565535";
const std::unordered_set<std::string> INVALID_MCCMNC_SET{DEFAULT_MCC, DEFAULT_MCCMNC, TEST_MCC, TEST_MCCMNC,
														 INVALID_MCCMNC};

//#define COUNTRY_MCC_MAP_V2(X)    \
//    X(GR, {"202"})               \
//    X(NL, {"204"})               \
//    X(AE, {"424", "430", "431"})
//
//enum class CountryV2 {
//#define ENUM_VALUE(country, mccs) country,
//	COUNTRY_MCC_MAP_V2(ENUM_VALUE)
//#undef ENUM_VALUE
//};
//
//const std::unordered_map<CountryV2, std::vector<std::string>> COUNTRY_MCC_MAP_V2 = {
//#define MCC_VECTOR(country, mccs) {Country::country, mccs},
//		COUNTRY_MCC_MAP_V2(MCC_VECTOR)
//#undef MCC_VECTOR
//};

//template <typename... Args>
//auto make_enum_map(Args... args) {
//	enum class Country : int { args... };
//	const std::unordered_map<Country, std::vector<std::string>> country_mccs = {
//			{Country(args), std::vector<std::string>({args...})}...
//	};
//	return std::make_pair(Country{}, country_mccs);
//}

//#define COUNTRY_ENUM_MAP(...) \
//    enum class Country { __VA_ARGS__, COUNT }; \
//    const std::unordered_map<std::string, Country> country_map = { \
//        {#__VA_ARGS__, Country::__VA_ARGS__}... \
//    }; \
//    const std::vector<std::vector<std::string>> country_mccs_vec = { \
//        {args...}... \
//    }; \
//    const std::unordered_map<Country, std::vector<std::string>> country_mccs = { \
//        {Country::__VA_ARGS__, country_mccs_vec[static_cast<int>(Country::__VA_ARGS__)]}... \
//    }





const std::unordered_map<std::string, int> COUNTRY_MCC_MAP = {
		{"GR", 202},
		{"NL", 204},
		{"BE", 206},
		{"FR", 208},
		{"MC", 212},
		{"AD", 213},
		{"ES", 214},
		{"HU", 216},
		{"BA", 218},
		{"HR", 219},
		{"RS", 220},
		{"XK", 221},
		{"IT", 222},
		{"RO", 226},
		{"CH", 228},
		{"CZ", 230},
		{"SK", 231},
		{"AT", 232},
		{"GB", 234},
		{"GB", 235},
		{"DK", 238},
		{"SE", 240},
		{"NO", 242},
		{"FI", 244},
		{"LT", 246},
		{"LV", 247},
		{"EE", 248},
		{"RU", 250},
		{"UA", 255},
		{"BY", 257},
		{"MD", 259},
		{"PL", 260},
		{"DE", 262},
		{"GI", 266},
		{"PT", 268},
		{"LU", 270},
		{"IE", 272},
		{"IS", 274},
		{"AL", 276},
		{"MT", 278},
		{"CY", 280},
		{"GE", 282},
		{"AM", 283},
		{"BG", 284},
		{"TR", 286},
		{"FO", 288},
		{"AB", 289},
		{"GL", 290},
		{"SM", 292},
		{"SI", 293},
		{"MK", 294},
		{"LI", 295},
		{"ME", 297},
		{"CA", 302},
		{"PM", 308},
		{"US", 310},
		{"US", 311},
		{"US", 312},
		{"US", 313},
		{"US", 314},
		{"US", 315},
		{"US", 316},
		{"PR", 330},
		{"VI", 332},
		{"MX", 334},
		{"JM", 338},
		{"MF", 340},
		{"BB", 342},
		{"AG", 344},
		{"KY", 346},
		{"VG", 348},
		{"BM", 350},
		{"GD", 352},
		{"MS", 354},
		{"KN", 356},
		{"LC", 358},
		{"VC", 360},
		{"SX", 362},
		{"AW", 363},
		{"BS", 364},
		{"AI", 365},
		{"DM", 366},
		{"CU", 368},
		{"DO", 370},
		{"HT", 372},
		{"TT", 374},
		{"TC", 376},
		{"AZ", 400},
		{"KZ", 401},
		{"BT", 402},
		{"IN", 404},
		{"IN", 405},
		{"IN", 406},
		{"PK", 410},
		{"AF", 412},
		{"LK", 413},
		{"MM", 414},
		{"LB", 415},
		{"JO", 416},
		{"SY", 417},
		{"IQ", 418},
		{"KW", 419},
		{"SA", 420},
		{"YE", 421},
		{"OM", 422},
		{"AE", 424},
		{"PS", 425},
		{"BH", 426},
		{"QA", 427},
		{"MN", 428},
		{"NP", 429},
		{"AE", 430},
		{"AE", 431},
		{"IR", 432},
		{"UZ", 434},
		{"TJ", 436},
		{"KG", 437},
		{"TM", 438},
		{"JP", 440},
		{"JP", 441},
		{"KR", 450},
		{"VN", 452},
		{"HK", 454},
		{"MO", 455},
		{"KH", 456},
		{"LA", 457},
		{"CN", 460},
		{"CN", 461},
		{"TW", 466},
		{"KP", 467},
		{"BD", 470},
		{"MV", 472},
		{"MY", 502},
		{"NF", 505},
		{"ID", 510},
		{"TL", 514},
		{"PH", 515},
		{"TH", 520},
		{"SG", 525},
		{"BN", 528},
		{"NZ", 530},
		{"NR", 536},
		{"PG", 537},
		{"TO", 539},
		{"SB", 540},
		{"VU", 541},
		{"FJ", 542},
		{"WF", 543},
		{"AS", 544},
		{"KI", 545},
		{"NC", 546},
		{"PF", 547},
		{"CK", 548},
		{"WS", 549},
		{"FM", 550},
		{"MH", 551},
		{"PW", 552},
		{"TV", 553},
		{"TK", 554},
		{"NU", 555},
		{"EG", 602},
		{"DZ", 603},
		{"MA", 604},
		{"TN", 605},
		{"LY", 606},
		{"GM", 607},
		{"SN", 608},
		{"MR", 609},
		{"ML", 610},
		{"GN", 611},
		{"CI", 612},
		{"BF", 613},
		{"NE", 614},
		{"TG", 615},
		{"BJ", 616},
		{"MU", 617},
		{"LR", 618},
		{"SL", 619},
		{"GH", 620},
		{"NG", 621},
		{"TD", 622},
		{"CF", 623},
		{"CM", 624},
		{"CV", 625},
		{"ST", 626},
		{"GQ", 627},
		{"GA", 628},
		{"CG", 629},
		{"CD", 630},
		{"AO", 631},
		{"GW", 632},
		{"SC", 633},
		{"SD", 634},
		{"RW", 635},
		{"ET", 636},
		{"SO", 637},
		{"DJ", 638},
		{"KE", 639},
		{"TZ", 640},
		{"UG", 641},
		{"BI", 642},
		{"MZ", 643},
		{"ZM", 645},
		{"MG", 646},
		{"RE", 647},
		{"ZW", 648},
		{"NA", 649},
		{"MW", 650},
		{"LS", 651},
		{"BW", 652},
		{"SZ", 653},
		{"KM", 654},
		{"ZA", 655},
		{"ER", 657},
		{"SH", 658},
		{"SS", 659},
		{"BZ", 702},
		{"GT", 704},
		{"SV", 706},
		{"HN", 708},
		{"NI", 710},
		{"CR", 712},
		{"PA", 714},
		{"PE", 716},
		{"AR", 722},
		{"BR", 724},
		{"CL", 730},
		{"CO", 732},
		{"VE", 734},
		{"BO", 736},
		{"GY", 738},
		{"EC", 740},
		{"GF", 742},
		{"PY", 744},
		{"SR", 746},
		{"UY", 748},
		{"FK", 750},
		{"IO", 995},
		{"PC", 999}
};


} // namespace geo_ip_loader

#endif //MAXMIND_C_LIB_PRACTICE_CONSTANTS_H
