#ifndef COMMON_H_
#define COMMON_H_

#define QUEUE_NAME "/queue"
#define MAX_SIZE 185972

#define CHECK(x) \
    do { \
        if (!(x)) { \
            fprintf(stderr, "%s:%d: ", __func__, __LINE__); \
            perror(#x); \
            exit(-1); \
        } \
    } while (0) \

#endif