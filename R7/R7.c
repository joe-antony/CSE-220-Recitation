/*
Agenda:
1. Getfamiliar with command line arguments.
2. Introduce how to parse them. Use getopt() function
3. Introduce String Parsing functions.
4. I/o functions: strstr, strchr, fscanf,sscanf, fgets, and fgetc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* int main(int argc, char **argv) {
    int i;
    printf("Number of arguments: %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
 */

 int main(int argc, char **argv) {
	extern char *optarg;
	extern int optind;
	int debug = 0;
	int c, err = 0; // c to get the processed option; error to flag if an error occured 
	int mflag=0, pflag=0, fflag=0;
	char *sname = "default_sname", *fname;
	static char usage[] = "usage: %s [-dmp] -f fname [-s sname] name [name ...]\n";

	while ((c = getopt(argc, argv, "df:mps:")) != -1){ // ":" denotes that the option accepts an argument
		switch (c) {
		case 'd':
			debug = 1;
			break;
		case 'm':
			mflag = 1;
			break;
		case 'p':
			pflag = 1;
			break;
		case 'f':
			fflag = 1;
			fname = optarg;
			break;
		case 's':
			sname = optarg;
			break;
		case '?':
			err = 1;
			break;
		}
	}

	// You want enforce certain flags to be manadatory; follow this pattern
	if (fflag == 0) {	/* -f was mandatory */
		fprintf(stderr, "%s: missing -f option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if ((optind+1) > argc) {	
		/* need at least one argument (change +1 to +2 for two, etc. as needeed) */

		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing non option\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}

	return 0;
 }


