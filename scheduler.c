
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

#include <unistd.h>
// fork that are three children
// i HAVE A PARENT THAT FORKS TO THREEE CHILDREN
// note Notice that the main function is not equivalent to the main process even though they have similar names.

void schedule_handler(int parent_to_child(),int n){



}


// Need a task_id


// define a helper function for process 2, that helps me do the task,, it should take CHILD TO PARENT, I NEED TO KEEP TRACK OF THE CORE TO PASS THAT LATER ON
// second argument means the cores 
// third means the max amount of 
int main(int argv[], char** argc){
  if(argc != 3){ // error handling 
    //first arg is name of program, second is num of cores, and third is the max rand int
    printf("error, we need 3 arguments passed in\n");

  } 
  //for limit_bits extract left signiificant bit
     //int num_tasks = argv[1];
    //  int maxBitsWeCanExtract = argv[2];  


  
    


      /// we need to do the left bits subctration
      

   

  // Pipes created! 
  int parent_to_child [3][2];
  int child_to_parent [3][2];
  
  for (int i = 0; i < 3; i++){
    if (pipe(child_to_parent[i]) == -1) { printf("Error with Pipe"); }  // pipes created
   if( pipe(parent_to_child[i]) == -1){printf("Error with Pipe");}    // pipes created 
  }

  //Subprocess is a process created by fork parent process
   /// keep it simple, stores the pid, and call it to the process

    // need to create the pipes first because after using fork, the memory address will change and we want to keep it the same at the moment
     
    pid_t p1  = fork();
    if(p1 == -1){
      perror("Error in the fork ");
      exit(1);
    }
    pid_t p2;
    
    pid_t p3;
    if (p1 != 0)   // parent process,
    {
      p2 = fork();
      if(p2 == -1){
        perror("Error in the fork ");
        exit(1);
      }
      if (p2 != 0)
      {
          p3 = fork();
          
          if(p3 == -1){
            perror("Error in the fork ");
            exit(1);
          }
          if (p3 != 0){
            //  means we are in th e main function 
             close(parent_to_child[0][0]); //clossing read end of the pipe
             close(parent_to_child[1][0]);
              close(parent_to_child[2][0]);

              // close the write end of the child pipe

              close (child_to_parent[0][1]);
              close (child_to_parent[1][1]);
              close (child_to_parent[2][1]);
          }
        }
      }
    if (p1 == 0) {  // child process 1
      close(parent_to_child[0][1]); //clossing write end of the pipe
      close(parent_to_child[1][1]);
      close(parent_to_child[2][1]);

      //close the read end of this pipe 
       close(parent_to_child[1][0]);
       close (parent_to_child[2][0]);

       // close the reading end of the pipe because we don't care about the reading end of child to parent pipes 

      close (child_to_parent[0][0]);
      close (child_to_parent[1][0]);
      close (child_to_parent[2][0]);

      close (child_to_parent[1][1]); // close the write part of the child
      close (child_to_parent[2][1]);



    }
    if (p2 ==0 ){
   // child process 2
        close(parent_to_child[0][1]); //clossing write end of the pipe
        close(parent_to_child[1][1]);
        close(parent_to_child[2][1]);
  
        //close the read end of this pipe 
          close(parent_to_child[0][0]);
         close (parent_to_child[2][0]);
  
         // close the reading end of the pipe because we don't care about the reading end of child to parent pipes 
  
        close (child_to_parent[0][0]);
        close (child_to_parent[1][0]);
        close (child_to_parent[2][0]);
  
        close (child_to_parent[0][1]); // close the write part of the child
        close (child_to_parent[2][1]);
  
      
    }
    if (p3 == 0 ){
        // child process 3
        close(parent_to_child[0][1]); //clossing write end of the pipe
        close(parent_to_child[1][1]);
        close(parent_to_child[2][1]);
  
        //close the read end of this pipe 
          close(parent_to_child[0][0]);
         close (parent_to_child[1][0]);
  
         // close the reading end of the pipe because we don't care about the reading end of child to parent pipes 
  
        close (child_to_parent[0][0]);
        close (child_to_parent[1][0]);
        close (child_to_parent[2][0]);
  
        close (child_to_parent[0][1]); // close the write part of the child
        close (child_to_parent[1][1]);
  
    } 

  
   
   typedef struct{
     int task_id; // the task id
     int n;
   }  Data;
   
      
    int n;

      int task_num = atoi(argv[1]);  //number of tasks
       int max_bit = atoi(argv[2]);   // max number of bits
      int counter = 0;

      
      while (counter < task_num){
        
        n = rand() % max_bit + 1;
        Data data = {counter, n}; 
       //send the numbers to the pipes

       write(parent_to_child[counter%3 ][1],&data, sizeof(data));   //reading is  0, writing is 1
         
        counter++;

      }

    
  
    
    return 0; 


    
  




 
  //  printf("Hello World!\n");
  
  }

  void left_shifting(int n){


    

  }