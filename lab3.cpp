#include <iostream>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
	
	bool flag[] = {0, 0, 0, 0, 0}; 
	const char* short_opts = "hdr::nV::"; // short options
	const struct option long_opts[]  = { // long options
		{"help", optional_argument, NULL, 'h'},
		{"delete", no_argument, NULL, 'd'},
		{"resolution", no_argument, NULL, 'r'},
		{"novid", no_argument, NULL, 'n'},
		{"value", optional_argument, NULL, 'V'},
		{NULL, 0, NULL, 0}	
	};

	int i = 0; 
	int c = 1;
	int opt_idx = -1;
	while ((i = getopt_long(argc,argv, short_opts, long_opts, &opt_idx)) != -1){
		switch (i) {
			case 'h':
				if (!flag[0]) {
					printf("Arg: Help");
					if (optarg != NULL) printf(" = %s", optarg);
					printf("\n");
					flag[0] = 1;
				}
				break;
			case 'd':
			        if (!flag[1]) {	
					printf("Arg: Delete\n"); 
					flag[1] = 1;
				}
				break;
			case 'r': 
				if (!flag[2]) {
					printf("Arg: Resolution\n"); 
					flag[2] = 1;
				}
				break;
			case 'n': 
				if (!flag[3]) {
					printf("Arg: Novid\n"); 
					flag[3] = 1;
				}	
				break;
			case 'V':
				if (!flag[4]) {
					printf("Arg: Value = %s\n", optarg);
					flag[4] = 1;
				}
				break;	
			case '?':
				printf("Unexpected input\n");
		}
		opt_idx = -1;
	}
	return 0;	
}