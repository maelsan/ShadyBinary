#include <curl/curl.h>
#include "../include/network.h"

void forceUri(char *uri)
{
  CURL *request = curl_easy_init();
  long codeHttp;
  int buffExt, buffFile, buffFolder, buffResults;
  char **saveAddr = NULL;

  const char *files[7] = {"/index", "/test", "/info", "/admin", "/login", "/register", "/install"};
  const char *ext[6] = {".php~", ".rb~", ".py~", ".txt", ".pdf", ".csv"};
  const char *folders[5] = {"/.svn/", "/.git/", "/svn/", "/git/", "/admin/"};

  buffResults = 0;

  //# Comb files & extensions.
  for (buffFile = 0; *(files + buffFile); buffFile++) {
    for (buffExt = 0; *(ext + buffExt); buffExt++) {
      char *concatURI = malloc(sizeof(*uri) + sizeof(*(files + buffFile)) + sizeof(*(ext + buffExt)));

      saveAddr = &concatURI;
      strcat(concatURI, uri);
      strcat(concatURI, *(files + buffFile));
      strcat(concatURI, *(ext + buffExt));

      curl_easy_setopt(request, CURLOPT_NOBODY, concatURI);
      curl_easy_perform(request);
      curl_easy_getinfo(request, CURLINFO_RESPONSE_CODE, &codeHttp);

      if (codeHttp == 200 || codeHttp == 403 || (codeHttp >= 300 && codeHttp <= 399)) {
        printf("\033[32m[v]\033[m Found : ");
        printf("%s\n", concatURI);
        buffResults++;
      }
      if ((buffExt + 1) == (sizeof(ext) / sizeof(ext[0]))) break;
    }
    if ((buffFile + 1) == (sizeof(files) / sizeof(files[0]))) break;
  }
  free(*saveAddr);

  //# Folders.
  for (buffFolder = 0; *(folders + buffFolder); buffFolder++) {
    char *concatURI = malloc(sizeof(*uri) + sizeof(*(folders + buffFolder)));

    saveAddr = &concatURI;
    strcat(concatURI, uri);
    strcat(concatURI, *(folders + buffFolder));

    curl_easy_setopt(request, CURLOPT_NOBODY, concatURI);
    curl_easy_perform(request);
    curl_easy_getinfo(request, CURLINFO_RESPONSE_CODE, &codeHttp);

    if (codeHttp == 200 || codeHttp == 403 || (codeHttp >= 300 && codeHttp <= 399)) {
      printf("\033[32m[v]\033[m Found : ");
      printf("%s\n", concatURI);
      buffResults++;
    }
    if ((buffFolder + 1) == (sizeof(folders) / sizeof(folders[0]))) break;
  }

  if (buffResults <= 0) NONERES
  curl_easy_cleanup(request);
  free(*saveAddr);
}
