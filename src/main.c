#include <getopt.h>

#include "../include/network.h"

int main (int argc, char **argv)
{
  int currentOption;

  while (1)
  {
    struct option options[] = {
      {"url",      required_argument, 0, 'a'},
      {"version",  no_argument,       0, 'b'},
      {"help",     no_argument,       0, 'c'}
    };

    currentOption = getopt_long(argc, argv, "abc", options, NULL);

    if (currentOption == -1)
      break;

    switch (currentOption) {
      case 'a':
        forceUri(*(argv + 2));
        break;

      case 'b':
        VERSION
        break;

      case 'c':
        puts("shady --url domain.com (ex: google.com)");
        puts("shady --version");
        break;

      case '?':
        UNKNOWO
        exit(0);
        break;

      default:
        UNKNOWO
        exit(0);
    }
  }

  return 0;
}
