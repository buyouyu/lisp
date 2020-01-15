#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char *readline(char * prompt){
    fputs(prompt,stdout);
    fgets(buffer,2048,stdin);
    char *tmp=malloc(strlen(buffer)+1);
    strcpy(tmp,buffer);
    tmp[strlen(buffer)-1]='\0';
    return tmp;
}

void add_history(char *unused){}


#else
#ifdef __linux__
#include <editline/readline.h>
#endif

#ifdef __MACH__
#include <editline/readline.h>
#endif

#endif

//static char input[2048];

int main(int argc,char **argv){
    puts("Lispy Version 1.0");
    puts("Press Ctrl+C to Exit\n");
    
    while(1){
        //to get show to use readline and history
        //fputs("lispy> ",stdout);
        //fgets(input,2048,stdin);
        //fputs do not add \n in the end,fgets will add \n in the end
        //readline will not add \n in the end

        char * input=readline("lispy> ");
        add_history(input);

        printf("hello you input %s\n",input);
        free(input);
    }
    return 0;
}