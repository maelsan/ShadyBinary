#include <curl/curl.h>
#include "../include/network.h"

int forceUri(char *uri, shadyLogs *results)
{
  CURL *request = curl_easy_init();
  CURLcode result;

  if (request) {
    curl_easy_setopt(request, CURLOPT_URL, "http://example.com");
    result = curl_easy_perform(request);
    curl_easy_cleanup(request);
  }

  return 0;
}
