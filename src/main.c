#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "../include/network.h"

int main (int argc, char **argv)
{
  int currentOption;

  //# TODO : Logo shady.
  while (1)
  {
    struct option options[] =
    {
      {"url",      required_argument, 0, 'a'},
      {"version",  no_argument,       0, 'b'},
      {"help",     no_argument,       0, 'c'}
    };

    currentOption = getopt_long(argc, argv, "abc", options, NULL);

    if (currentOption == -1)
      break;

    switch (currentOption)
    {
      case 'a':
        //# Here, the script.
        break;

      case 'b':
        VERSION
        break;

      case 'c':
        //# Here, listing of options.
        break;

      case '?':
        UNKNOWO
        break;

      default:
        //# Here, listing of options.
        abort();
    }
  }
}
