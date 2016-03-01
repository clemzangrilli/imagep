/*
 * mem_test.c
 *
 *  Created on: Nov 6, 2015
 *      Author: jon
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <pthread.h>

/*#define TEST_SINGLE_THREADED*/

#ifdef TEST_SINGLE_THREADED
#define LOCK_MUTEX
#define UNLOCK_MUTEX
#else
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#define LOCK_MUTEX pthread_mutex_lock(&mutex)
#define UNLOCK_MUTEX pthread_mutex_unlock(&mutex)
#endif



struct Data {
  int malloc_leaks;
  int malloc_leaks_n;
  int realloc_leaks;
  int realloc_leaks_n;
  int strdup_leaks;
  int strdup_leaks_n;
  int memalign_leaks;
  int memalign_leaks_n;
  int posix_memalign_leaks;
  int posix_memalign_leaks_n;
};

typedef struct Data Data;
static Data data;


void test_malloc(void *opaque) {
  void* ptrs[100];
  int i;
  int size = 0;
  int leaks = 0;
  for (i = 1; i <= 99; i++) {
    ptrs[i] = malloc(i);
    size+=i;
    leaks++;
  }

  for (i = 1; i <= 99; i=i+2) {
    free(ptrs[i]);
    size-=i;
    leaks--;
  }
  LOCK_MUTEX;
  data.malloc_leaks += size;
  data.malloc_leaks_n += leaks;
  UNLOCK_MUTEX;
}

void test_realloc(void *opaque) {
  void *ptr = malloc(60);
  free(realloc(ptr, 50));
  ptr = malloc(55);
  free(realloc(ptr, 75));

  ptr = realloc(0, 998);
  ptr = realloc(ptr, 17);

  LOCK_MUTEX;
  data.realloc_leaks += 17;
  data.realloc_leaks_n += 1;
  UNLOCK_MUTEX;
}

void test_strdup(void *opaque) {
  const char *str = "123456";
  free(strdup(str));
  strdup(str);
  free(strdup(str));

  LOCK_MUTEX;
  data.strdup_leaks += (strlen(str)+1);
  data.strdup_leaks_n += 1;
  UNLOCK_MUTEX;
}

void test_memalign(void *opaque) {
  void *ptr;
  free(memalign(16, 224));
  memalign(16, 24);

  LOCK_MUTEX;
  data.memalign_leaks += 24;
  data.memalign_leaks_n += 1;
  UNLOCK_MUTEX;
}

void test_posix_memalign(void *opaque) {
  void *ptr;
  int ret = posix_memalign(&ptr, 32, 145);
  free(ptr);
  ret = posix_memalign(&ptr, 32, 175);

  LOCK_MUTEX;
  data.posix_memalign_leaks += 175;
  data.posix_memalign_leaks_n += 1;
  UNLOCK_MUTEX;
}

void *run_tests (void *opaque) {
  test_malloc(opaque);
  test_realloc(opaque);
  test_strdup(opaque);
  test_memalign(opaque);
  test_posix_memalign(opaque);
  return 0;
}

int main () {
  int i;
  int t = 0;
  int t_n = 0;
  memset(&data, 0, sizeof(Data));

#define NUM_OF_TESTS 22

#ifdef TEST_SINGLE_THREADED
  for(i = 0; i < NUM_OF_TESTS; i++)
    run_tests(0);
#else
  pthread_t *threads = (pthread_t*)malloc(NUM_OF_TESTS * sizeof(pthread_t));
  for(i = 0; i < NUM_OF_TESTS; i++)
    pthread_create(&threads[i],NULL, run_tests, (void*)i);
  for (i = 0; i < NUM_OF_TESTS; i++)
    pthread_join(threads[i], NULL);

  free(threads); threads = 0;

#endif

  printf("Expected leaks: (pid=%d)\n", getpid());
  printf("in test_malloc(0x%x)        : size=%d leaks=%d\n", test_malloc, data.malloc_leaks, data.malloc_leaks_n);
  printf("in test_realloc(0x%x)       : size=%d leaks=%d\n", test_realloc, data.realloc_leaks, data.realloc_leaks_n);
  printf("in test_strdup(0x%x)        : size=%d leaks=%d\n", test_strdup, data.strdup_leaks, data.strdup_leaks_n);
  printf("in test_memalign(0x%x)      : size=%d leaks=%d\n", test_memalign, data.memalign_leaks, data.memalign_leaks_n);
  printf("in test_posix_memalign(0x%x): size=%d leaks=%d\n", test_posix_memalign, data.posix_memalign_leaks, data.posix_memalign_leaks_n);

  t+=data.malloc_leaks; t_n+=data.malloc_leaks_n;
  t+=data.realloc_leaks; t_n+=data.realloc_leaks_n;
  t+=data.strdup_leaks; t_n+=data.strdup_leaks_n;
  t+=data.memalign_leaks; t_n+=data.memalign_leaks_n;
  t+=data.posix_memalign_leaks; t_n+=data.posix_memalign_leaks_n;

  printf("Total:: size=%d leaks=%d\n", t, t_n);
  return 0;
}
