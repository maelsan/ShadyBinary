#include <curl/curl.h>
#include "../include/network.h"

int forceUri(char *uri)
{
  CURL *request = curl_easy_init();
  CURLcode result;
  long code;
  int c;

  char **saveAddr = NULL;

  //# TODO: Dynamic check.
  const char *words[8] = {
    "/index.php~",
    "/index.rb~",
    "/index.py~",
    "/index.txt",
    "/.svn/",
    "/.git/",
    "/admin/"
  };

  for (c = 0; *(words + c); c++) {

    char *concatURI = malloc(sizeof(*uri) + sizeof(c));

    saveAddr = &concatURI;
    strcat(concatURI, uri);
    strcat(concatURI, *(words + c));

    curl_easy_setopt(request, CURLOPT_URL, concatURI);
    result = curl_easy_perform(request);
    curl_easy_getinfo(request, CURLINFO_RESPONSE_CODE, &code);

    if (code == 200 && result != CURLE_HTTP_RETURNED_ERROR) {
      printf("\033[32m[v]\033[m Found : ");
      printf("%s\n", *(words + c));
    }
  }

  free(*saveAddr);
  curl_easy_cleanup(request);

  return 0;
}
