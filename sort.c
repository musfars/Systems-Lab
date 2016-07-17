#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main()
	{
		int pipes_fd[2];
		pid_t pid;
		FILE *stream;

		int stat;

		if(pipe(pipes_fd)==-1)
			printf("Error!. Could not create pipe.");
		switch(fork())
			{
				case -1:
					fprintf(stderr,"error forking\n");
					break;
				case 0:
					dup2(pipes_fd[0],STDIN_FILENO);
					pid=getpid();
					printf("Child process%d\n",pid);

					if(close(pipes_fd[1])==-1)
							fprintf(stderr,"Error closing write end pid=%d\n",pid);
					if(close(pipes_fd[0])==-1)
						fprintf(stderr,"Error  closing read end pid=%d\n",pid);

						execl("/usr/bin/sort","sort",(char*)NULL);
						exit(EXIT_FAILURE);
						break;
					default:
						stream=fdopen(pipes_fd[1],"w");
						pid=getpid();
						printf("From parent. PID=%d\n",pid);

						if(stream==NULL)
							fprintf(stderr,"Could not create file stream");
						if(close(pipes_fd[0]) ==-1)
							printf("Error closing read end PID=%d\n",pid);

							fputs("bob\n",stream);
							fputs("cat \n",stream);
							fputs("ace\n",stream);
							fputs("dog\n",stream);
							
							if(fclose(stream)==EOF)
								fprintf(stderr,"Error while closing stream\n");
							break;
			}
		wait(&stat);
		return 0;
	}




