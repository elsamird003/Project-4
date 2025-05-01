
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#include <signal.h>
// fork that are three children
// i HAVE A PARENT THAT FORKS TO THREEE CHILDREN
// note Notice that the main function is not equivalent to the main process even though they have similar names.
  int core_status[3] = {0,0,0};   // 0  is idle. 1 is busy and 2 is done
void no_interrupt_sleep(int sec)
{
    // * advanced sleep which will not be interfered by signals
    struct timespec req, rem;

    req.tv_sec = sec;  // The time to sleep in seconds
    req.tv_nsec = 0; // Additional time to sleep in nanoseconds

    while(nanosleep(&req, &rem) == -1)
        if(errno == EINTR)
            req = rem;
}


// Need a task_id
    typedef struct{
     int task_id; // the task id
     int n;
     int ID;
    
   }  Data;
   

// define a helper function for process 2, that helps me do the task,, it should take CHILD TO PARENT, I NEED TO KEEP TRACK OF THE CORE TO PASS THAT LATER ON
// second argument means the cores 
// third means the max amount of 
int main(int argc, char** argv){
  if(argc != 3){ // error handling 
    //first arg is name of program, second is num of cores, and third is the max rand int
    printf("error, we need 3 arguments passed in\n");


  } 


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
    int core_status[3] = {0,0,0};   // 0  is idle. 1 is busy and 2 is done
    int n;
  
    int task_num = atoi(argv[1]);  //number of tasks
    int max_bit = atoi(argv[2]);   // max number of bits
    int counter = 0;
  
    for(int i = 0; i < 3 ; i++){
  
   

      pid_t f= fork();
      for(int j =0;j < 3 ; j++){
        close(child_to_parent[j][0]);
        close(parent_to_child[j][1]);

         if(i != j){   // pipe that is not for me, close those end of the pipe 
           close(child_to_parent[j][1]);
           close(parent_to_child[j][0]);
         }
      }  
        if (f < 0 ) {// won't work 
           perror("fork doesn't work");
           exit(1);

         }
        
        if(f ==0){ // child
             Data data; 
             int ID = 0;
            while (read(parent_to_child[i][0], &data, sizeof(data))){ // read the parent to child
             no_interrupt_sleep(1);
             // EXTRACT LEFT MOST BITS FROM THE TASK ID
 
         // shift the bits to the left
               int message_result = data.task_id >> (32 - data.n);
                write(child_to_parent[i][1], &message_result, sizeof(message_result));
 
            /// as a child i need to be able to read and receive task 
                // the child needs used KILL TO SIGNAL THE PARENT 
        } 
        exit(0); //exit the child
        }


        if(f > 0 ){ // parent
         
                 // keeps tracks of the core 
    
            
            while (counter < task_num){   /// I only want the while loop to run if there is task able to run. THERE IS TASKS TO RUN
            // COUNTE ACTS ASK TASK_ID
             //  Maybe creating another variable 
             // 
              
              n = rand() % max_bit + 1;
              Data data = {counter, n}; 
            //send the numbers to the pipes
            for(int i = 0; i < 3; i++){
              if (core_status[i] == 0){ // if the core is idle, then write to the pipe
                  write(parent_to_child[i][1], &data, sizeof(data)); // write to the 
                  core_status[i] = 1; // busy

               // break out of the for loop
             counter++;
            }
            if (core_status[i] == 2){  //2 means is done
               int message ; 
              read(child_to_parent[i][0], &message, sizeof(message));
             
               core_status[i]= 0;
            // write(parent_to_child[counter%3 ][1],&data, sizeof(data));   //reading is  0, writing is 1
              

            // "
            }
            if (core_status[i] == 1){
               printf("Busy core%d" , i);
               }

            }

       


    }
      
      int n;

      int task_num = atoi(argv[1]);  //number of tasks
      int max_bit = atoi(argv[2]);   // max number of bits
      int counter = 0;

  
  // while (counter < task_num){
    
  //   n = rand() % max_bit + 1;
  //   Data data = {counter, n}; 
  //   //send the numbers to the pipes

  //   write(parent_to_child[counter%3 ][1],&data, sizeof(data));   //reading is  0, writing is 1
      
  //   counter++;

  // }



    
  
    return 0; 


    
  
    }

    void signal_handler(int signo) {
    if (signo == SIGUSR1) {
        printf("Main process received SIGUSR1 signal\n");

    }
        
    }

    }
//     Handle_new_result_from_core1()
//       Handle the new result…

// Main_process()
//       Register SIGUSR1 with signal handler Handle_new_result_from_core1
//       While there are still unsolved tasks
//             Assign an unsolved and unassigned task to the next idle core

// Core(core_id=1)
//       While the main_to_core1 pipe is not closed
//             Wait for a new task
//             Process the new task
//             Push the result to core1_to_main and send a signal SIGUSR1 to main process




// we only want to read from the process only when we know that the process is done we need to check the while loop if the status is 2
// we use KILL send a signal to the process and we are going to send it to tghe parent process

 
  //  printf("Hello World!\n");
  
  }

