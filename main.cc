#include <iostream>
#include <filesystem>
#include <cstring>

#include <maxminddb.h>

int main() {
	MMDB_s mmdb;
	std::filesystem::path cwd = std::filesystem::current_path();
	std::cout << cwd << std::endl;

	std::string _ip{"0000:0000:0000:0000:0000:0000:3B00:0001"};
	std::string _filename{"../files/GeoIP2-ISP-Test.mmdb"};  // note cwd

	char *filename = _filename.data();
	char *ip_address = _ip.data();

	int status = MMDB_open(filename, MMDB_MODE_MMAP, &mmdb);

	if (MMDB_SUCCESS != status) {
		fprintf(stderr, "\n  Can't open %s - %s\n",
				filename, MMDB_strerror(status));

		if (MMDB_IO_ERROR == status) {
			fprintf(stderr, "    IO error: %s\n", strerror(errno));
		}
		exit(1);
	}

	int gai_error, mmdb_error;
	MMDB_lookup_result_s result =
			MMDB_lookup_string(&mmdb, ip_address, &gai_error, &mmdb_error);

	if (0 != gai_error) {
		fprintf(stderr,
				"\n  Error from getaddrinfo for %s - %s\n\n",
				ip_address, gai_strerror(gai_error));
		exit(2);
	}

	if (MMDB_SUCCESS != mmdb_error) {
		fprintf(stderr,
				"\n  Got an error from libmaxminddb: %s\n\n",
				MMDB_strerror(mmdb_error));
		exit(3);
	}

	MMDB_entry_data_list_s *entry_data_list = NULL;

	int exit_code = 0;
	if (result.found_entry) {
		int status = MMDB_get_entry_data_list(&result.entry,
											  &entry_data_list);

		if (MMDB_SUCCESS != status) {
			fprintf(
					stderr,
					"Got an error looking up the entry data - %s\n",
					MMDB_strerror(status));
			exit_code = 4;
			goto end;
		}

		if (NULL != entry_data_list) {
			MMDB_dump_entry_data_list(stdout, entry_data_list, 2);
		}
	} else {
		fprintf(
				stderr,
				"\n  No entry for this IP address (%s) was found\n\n",
				ip_address);
		exit_code = 5;
	}

	end:
		MMDB_free_entry_data_list(entry_data_list);
		MMDB_close(&mmdb);
		exit(exit_code);
}
