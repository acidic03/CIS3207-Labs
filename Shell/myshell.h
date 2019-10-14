#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>


#define MAX_INPUT_SIZE 40
#define MAX_PATH_SIZE 4
#define FD_READ 0
#define FD_WRITE 1

extern char **environ;

enum shell_mode
{
    BATCH,
    NORMAL
};

enum input_redirection_type
{
    NONE,
    INPUT,
    OUTPUT,
    OUTPUT_APPEND
};

void run(char *userInput);
int builtInCommand(char* tokens[], int numOfArgs);
void execCommand(char* tokens[], int numOfArgs, int execInBackground);
void pipeExec(char* tokens[], int numOfArgs);
void backgroundExec(char* tokens[], int numOfArgs);
void inputRedirect(char* input[], int numOfArgs);
