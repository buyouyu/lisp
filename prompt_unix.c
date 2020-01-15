#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>


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
}