Introduction to getopt():
The getopt() function is used to parse command-line options in a standardized way. It allows you to specify options that can be short (like -h) or long (like --help), and

All of the following ls command perform the same task.

ls -aFilL /etc
ls -a -il -FL /etc
ls -a -i -l -F -L /etc
ls -ailLF /etc


    -d, -m, and -p options. The -d is treated as a some flag.
    An optional -s followed by a name.
    A mandatory -f followed by a name.
    One or more command line options after all that.

    getopt takes three parameters. 
    getopt(int argc, char * const argv[], const char *optstring);
    - argc: The number of command-line arguments.
    - argv: An array of strings representing the command-line arguments.
    - optstring: A string that specifies the valid options. Each character in the string represents
    optstring "dmps:f:"



	Declare extern char *optarg; extern int optind; in your function. These are two external variables that getopt uses. 
	optarg: is used when parsing options that take a name as a parameter 
	optind: is the current index into the main function's argument list

	getopt is called repeatedly. Each time it is called, it returns the next command-line option that it found.
	If theres a follow-on parameter, it is stored in optarg.
	 If getopt encounters an option that's not in the list given to it, it returns a '?' character to signify an error.
	getopt returns a -1 when there are no more command-line options found then 


    Structure:

    command -l arg -p arg2
    argc =5 
    optind = 5
    ./echo does she "weigh the same" as\ a duck?

    argc = 7
    arg[0] = "./echo"
    arg[1] = "does"
    arg[2] = "she"
    arg[3] = "weigh the same"
    arg[4] = "as"
    arg[5] = "a"
    arg[6] = "duck?"