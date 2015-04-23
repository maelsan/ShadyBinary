#include <curl/curl.h>
#include "../include/network.h"

int forceUri(char *uri)
{
  CURL *request = curl_easy_init();
  CURLcode result;
  int c;

  if (request && *words) {
    for (c = 0; *(words + c); c++) {

      char *concatURI = malloc(sizeof(*uri) + sizeof(c));

      strcat(concatURI, uri);
      strcat(concatURI, *(words + c));

      curl_easy_setopt(request, CURLOPT_URL, concatURI);
      result = curl_easy_perform(request);

      if (result != CURLE_HTTP_RETURNED_ERROR) {
        //# strcat(file[0], concatURI);
        puts("\033[32m[v]\033[m File has found : ...");
        //# strcpy(file[0], file[1]);
      }
    }
    curl_easy_cleanup(request);
  }

  return 0;
}
