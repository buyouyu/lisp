#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

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

        mpc_parser_t* Number = mpc_new("number");
        mpc_parser_t* Operator = mpc_new("operator");
        mpc_parser_t* Expr = mpc_new("expr");
        mpc_parser_t* Lispy= mpc_new("lispy");

        mpca_lang(MPCA_LANG_DEFAULT,
        "\
        number : /-?[0-9]+/;\
        operator : '+'|'-'|'*'|'/';\
        expr : <number>|'('<operator><expr>+')';\
        lispy : /^/<operator><expr>+/$/;\
        ",
        Number,Operator,Expr,Lispy);

        char * input=readline("lispy> ");
        add_history(input);

        mpc_result_t r;
        if(mpc_parse("<stdin>",input,Lispy,&r)){
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        }else{
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

       // printf("hello you input %s\n",input);
        free(input);
    }
    return 0;
}