Implementatio details from PROJECT 4  pipes and signals
I have the no_interrupt_sleep function outside the main fuction 

The main function takes two parameters:
1. argument count is  integer that represents the number of command-line arguments, including the program name.
2. argument vector: is an array of strings (char *argv[]) that contains the actual arguments:
   - argv[0] is the program name
   - argv[1] is the first argument
   - argv[2] is the second argument



then parent_to_child pipe is created, where is a double d array the fist set [3]represets the  3 core pipes and the [2]represent the two ways in can talk 
same idea is for the child to parent pipe 

-if a pipe has nothing in it then then there there will be printed Error with pipe.
- This is for both ends of the pipes


In line 61 there has been created the 3 tasks for the pipes 0-idle or ready to use, 1- busy, 2- done


on line 73 there is for loop that it closed it's perspective pipes
if the pipe I which is the one we suposed to be at,  then we are goning to close 
that aren't needed it. i represents the current process index. and J represents the the index of th pipe we are checking 


in line 88 to 101 there is a check that if we are in the child proces fork will return 0
Data structure is created that hold the data that will be sent from parent
- line  91 there is a read from the child through the pipe. Data containsIt reads a Data structure which contains at least:
task_id: Some integer value
n: Number of bits to extract.

if everything goes well, we will sleep for 1 second. and then we will extract the left most nbits 
after that our final step is to use the write end of the child parent pipe and send back the new calculated result

Line 103 we are in the parent process.  Here we are be checking the status of each pipe, 

if the pipe is ready to use ==0 we will write to the parent pipe. and the we can shift its status from idle to busy
if the pipe is done we will read the message the task from child to parent, then we will write to the child pipe and then parent reads the result from child pipe. 
 keeping in mind comunication hapends one wa.

 