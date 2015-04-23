#include <curl/curl.h>
#include "../include/network.h"

int forceUri(char *uri)
{
  CURL *request = curl_easy_init();
  CURLcode result;
  int c;

  if (request && *words) {
    for (c = 0; *(words + c); c++) {
      curl_easy_setopt(request, CURLOPT_URL, strcat(uri, *(words + c)));
      result = curl_easy_perform(request);
      if (result != CURLE_HTTP_RETURNED_ERROR)
        puts("\033[32m[x]\033[m File");
      curl_easy_cleanup(request);
    }
  }

  return 0;
}
