#ifndef SHADY_STRUCT
#define SHADY_STRUCT

typedef struct shadyLogs shadyLogs;
struct shadyLogs {
  char *uri;
  shadyLogs *next;
};

#endif
