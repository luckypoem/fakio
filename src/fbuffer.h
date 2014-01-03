#ifndef _FAKIO_BUFFER_H_
#define _FAKIO_BUFFER_H_

#include <string.h>
#include <stdlib.h>

#define BUFSIZE 4088

typedef struct {
    unsigned char buffer[BUFSIZE];
    int length;
    int start;
} fbuffer;


#define FBUF_CREATE(B) do {     \
    (B) = (fbuffer *)malloc(sizeof(fbuffer)); \
    if ((B) != NULL) {                        \
        (B)->length = (B)->start = 0;         \
    }                                          \
} while (0)

#define FBUF_WRITE_AT(B) ((B)->buffer)

#define FBUF_COMMIT_WRITE(B, A) ((B)->length += (A))

#define FBUF_DATA_AT(B) ((B)->buffer + (B)->start)

#define FBUF_DATA_LEN(B) ((B)->length)

#define FBUF_COMMIT_READ(B, A) do { \
    (B)->length -= (A);                \
    if ((B)->length == 0) {            \
        (B)->start = 0;                \
    } else {                           \
        (B)->start += (A);             \
    }                                  \
} while (0);



#endif