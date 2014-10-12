#include <stdio.h>
#include <string.h>

char computePasswordCharacter(char current, char previous)
{
	return (current+previous-7) - 95*((current+previous-7)/95) + 32;
}

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		printf("wtf man\n");
		return 0;
	}
	
	char * username = argv[1];
	char password[strlen(username)+1];

	char p = 59;
	for(int i = 0; i < strlen(username); i++)
	{
		//printf("%c",computePasswordCharacter(username[i],p));

		password[i] = computePasswordCharacter(username[i], p);
		
		p = computePasswordCharacter(username[i], p);

	}

	password[strlen(username)] = 0;
	printf("%s\n",password);

	char username2[strlen(password)];
	p = 59; 
	for(int i = 0; i < strlen(username); i++)
	{
			int temp = password[i]-25-p;
			
			while(temp < 33)
			{
				temp += 95;
			}
			username2[i] = temp;

			p = password[i];
	}
	username2[strlen(password)] = 0;
	printf("%s\n",username2);
	
	/*
	for(int i = 0; i < 256; i++)
	{
		printf("%d\n", computePasswordCharacter(i,59));
	}
	*/

	return 1;
}
