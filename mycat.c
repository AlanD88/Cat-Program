/*
 *Alan Duncan
 aljdunca@ucsc.edu
 CMPS 111
 asgn0
 mycat - A simple program to replicate the functionality of the linux/unix cat program.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int fd;
    int n_char;
    char content[10];

    if (argc == 0){
        perror("Error");
        exit(1);
    } 
    else {
          if(argc == 1){//While only one argument is given
          	while((n_char = read(STDIN_FILENO, content,1))){
                       if(n_char > 0) {
                             write(STDOUT_FILENO, content, n_char);
                       }
                       else if(n_char == 0) {
                            exit(1); 
                       }
                       else if(n_char < 0) {
                             perror("Error");
			     exit(1);	
                       } 
                }
 
          }
	  else{

         	 for (int i = 1; i < argc; i++) {
	   		 fd = open(argv[i], O_RDONLY);

           		 if (fd < 0) {
				 char errormsg[100];
				
				 sprintf(errormsg, "mycat: %s", argv[i]); 
				 perror(errormsg);
                		 exit(1); 
           		 }
           		 else{
               			 while((n_char = read(fd,content, 1)) > 0)
               		 	{
					 write(STDOUT_FILENO, content, n_char);
               		 	}
               			 if (n_char < 0) 
				{
					perror("Error");
                			exit(1);
          			}   
           		 }
		 }
	 }
    }

    return 0;
}
