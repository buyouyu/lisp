#include <stdio.h>

static char input[2048];

int main(int argc,char **argv){
    puts("Lispy Version 1.0");
    puts("Press Ctrl+C to Exit\n");
    
    while(1){
        fputs("lispy> ",stdout);
        fgets(input,2048,stdin);
        printf("hello you input %s",input);
    }
}