
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
// fork that are three children
// i HAVE A PARENT THAT FORKS TO THREEE CHILDREN

int main(){

  // Pipes created! 
  int parent_to_child [3][2];
  int child_to_parent [3][2];
  
  for (int i = 0; i < 3; i++){
   if( pipe( child_to_parent[i]) == -1){printf("Error with Pipe");}
   if( pipe(parent_to_child[i]) == -1){printf("Error with Pipe");} 
  }
    // need to create the pipes first because after using fork, the memory address will change and we want to keep it the same at the moment
    
  // int p[2]= pipe();
    pid_t p  = fork();

  //  printf("Hello World!\n");
    return 0;
}