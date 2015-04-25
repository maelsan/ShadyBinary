#include <getopt.h>
#include <regex.h>

#include "../include/network.h"

int main (int argc, char **argv)
{
  regex_t buffRegex;
  int currentOption, buffOp;
  const char *domain = "(w{3}\\.)?[a-z0-9]+\\.[a-z]+";

  buffOp = 0;
  while (1)
  {
    struct option options[] = {
      {"url",      required_argument, 0, 'a'},
      {"version",  no_argument,       0, 'b'},
      {"help",     no_argument,       0, 'c'}
    };

    currentOption = getopt_long(argc, argv, "abc", options, NULL);

    if (currentOption == -1) {
      if (!buffOp) ERRCHOS
      break;
    }

    buffOp++;
    switch (currentOption) {
      case 'a':
        sleep(1);
        TITLESH
        TITLEDE
        sleep(2);

        if (!*(argv + 2)) { ERRFORM exit(0); }

        regcomp(&buffRegex, domain, REG_ICASE | REG_NOSUB | REG_EXTENDED);
        if (regexec(&buffRegex, *(argv + 2), 0, NULL, 0) == REG_NOMATCH) {
          regfree(&buffRegex);
          ERRFORM exit(0);
        }

        forceUri(*(argv + 2));
        break;

      case 'b':
        VERSION
        break;

      case 'c':
        puts("shady --url domain.com (ex: google.com)");
        puts("shady --version");
        puts("shady --help");
        break;

      case '?':
        UNKNOWO
        break;

      default:
        UNKNOWO
    }
  }

  return 0;
}
