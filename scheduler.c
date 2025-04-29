
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

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
     
  
    for(int i = 0; i <3 ; i++){
    int core_status[3] = {0,0,0};   // 0  is iddle. 1 is busy and 2 is done
    int n;

    int task_num = atoi(argv[1]);  //number of tasks
    int max_bit = atoi(argv[2]);   // max number of bits
    int counter = 0;
     typedef struct{
     int task_id; // the task id
     int n;
    
   }  Data;
   

      pid_t f= fork();
      for(int j =0;j < 3 ; j++){
        close(child_to_parent[j][0]);
        close(parent_to_child[j][1]);

         if(i != j){   // pipe that is not for me, close those end of the pipe 
           close(child_to_parent[j][1]);
           close(parent_to_child[j][0]);
         }
      }  
        
        if(f ==0){ // child
           Data data;  
             read(parent_to_child[i][0], &data, sizeof(data)); // read the parent to child
             no_interrupt_sleep(1);
             // EXTRACT LEFT MOST BITS FROM THE TASK ID

             data.task_id  >> (32 - data.n); // shift the bits to the left

            /// as a child i need to be able to read and receive task 

        }

        if(f > 0 ){ // parent
            typedef struct{
           int task_id; // the task id
            int n;
        }  Data;
        
                 // keeps tracks of the core 
    
            
            while (counter < task_num){
              
              n = rand() % max_bit + 1;
              Data data = {counter, n}; 
            //send the numbers to the pipes
            for(int i = 0; i < 3; i++){
           if (core_status[i] == 0){ // if the core is idle, then write to the pipe
               write(child_to_parent[i][1], &data, sizeof(data)); // write to the 
               core_status[i] = 1; // busy

               
             counter++;
            }
            if (core_status[i] == 2){ 
               int message ; 
              read(child_to_parent[i][0], &message, sizeof(message));
             
               core_status[i]= 0;
            // write(parent_to_child[counter%3 ][1],&data, sizeof(data));   //reading is  0, writing is 1
              
           

            // "
            }
               }

            }

         if (f < 0 ) {// won't work 


         }


    }


  
   

      
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


    
  
    }



 
  //  printf("Hello World!\n");
  
  }

