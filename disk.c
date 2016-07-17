#include<stdio.h>
#include<sys/vfs.h>
int main(int argc,char **argv)
{
	int status;
	struct statfs info;
	status=statfs("/home/Desktop",&info);
	printf("\nTotal Block:%ld\n",info.f_blocks);
	printf("Total free Blocks: %ld\n",info.f_bfree);
	printf("Total files: %ld\n",info.f_files);
	printf("Total free files:%ld\n",info.f_ffree);
}
