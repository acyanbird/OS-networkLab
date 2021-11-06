#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// code to sum all integers up to a given limit
void *sum_runner(void *limit){
  int i;
  int *limit1=(int *)limit;
  int *sum=(int*)malloc(sizeof(int));
  for(i=1; i <= *limit1; i++){
    *sum+=i;
  }
  return(sum);
}


int main(int argc, char *argv[]) {

  int i,x;
  int *ans;
  if (argc <=1){
    printf("Error! Usage: ./sum_thread <num>\n"); // Gives an error msg when no numbers are entered
  }
  else{
    int *limit=(int *)malloc(argc*sizeof(int)); // creating memory to store the limits
    pthread_t *threads=(pthread_t *)malloc(argc*sizeof(pthread_t)); // creating variables to store thread ids
    // creating threads to compute sums
    for (i = 0; i < argc-1; i++) {
      limit[i]=atoi(argv[1+i]);
      pthread_create(&threads[i], NULL, &sum_runner, (void *)&limit[i]);
    }
    // joining on the threads
    for (i = 0; i < argc-1; ++i) {
      pthread_join(threads[i], (void **)&ans); // the return value is stored in ans
      printf("Sum of integers up to %d is %d\n",limit[i], *ans);
      free(ans);
    }
    // freeing dynamically allocated memory
    free(threads);
    free(limit);
  }
  return 0;
}
