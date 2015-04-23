#include <curl/curl.h>
#include "../include/network.h"

int forceUri(char *uri, shadyLogs *results)
{
  CURL *request = curl_easy_init();
  CURLcode result;
  int c;

  if (request && *words) {
    for (c = 0; *(words + c); c++) {
      curl_easy_setopt(request, CURLOPT_URL, *uri);
      result = curl_easy_perform(request);
      //# Here, the script.
      curl_easy_cleanup(request);
    }
  }

  return 0;
}
