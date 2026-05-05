#include "libs.h"

int His=-1;
char *Hist[100];

//Shellcea - shell in c

void ShellInit(){
	system ("clear");
  	printf("welcome to my shell:) ");

	
}
char *GetCommand()
{
	char *Arr=malloc(100); //defining command shell
    fgets(Arr, 100, stdin); //getting the command shell 
 if (His < 99)
	Hist[His++]=Arr; //history to save executed commands 
    return Arr; //return command 
}
char *ReadCommand(char *command){ //read comman (validation)
	
      if(command == NULL ){
      	printf("No ones every command executed");
      return NULL;
      }
      return command;
}



char *command;
char **args;
char **split_line(char *command){
   int size = 64;
   int i = 0;

   char **args = malloc(size * sizeof(char *));
    if (!args) {
        perror("malloc");
        exit(1);
    }
    char *token = strtok(command, " \t\n");
    while (token != NULL) {
        args[i++] = token;
        
        if (i >= size) {  // expandir se necessário
            size *= 2;
            args = realloc(args, size * sizeof(char *));
        }
        
        token = strtok(NULL, " \t\n");
    }
    
    args[i] = NULL;


   return args;	
}


int main() {
    //init shell
    ShellInit();
    while (TRUE) {
     
     printf("$$> "); //visual prompt
    	 char *command = GetCommand();
      char **args = split_line(command);
      pid_t pid = fork();
      
      if (pid == 0){ //child  process to exec shell commands (ls, cd)
      if (execvp(args[0], args) == -1)
      {
      perror("execvp");
      _exit(1);
      }
      else //parent  process
        wait(NULL);
     for (int i =0;args[i] !=NULL;i++)   
      free(args);
    	free(command);
    }
    return 0;
}
}

