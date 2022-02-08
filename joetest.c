/* Tests for users with no password */
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int main(argc, argv) int argc;
char **argv;
{
	struct passwd *pw;

	while (pw = getpwent())
	{
		char *crypt();
		char *result;

		if (pw->pw_passwd[0] == 0)
		{
			printf("%s has not password\n", pw->pw_name);
			continue;
		}
		result = crypt(pw->pw_name, pw->pw_passwd);
		if (!strcmp(result, pw->pw_passwd))
		{
			printf("%s is a joe\n", pw->pw_name);
		}
	}
}


/*

Alternate from book:


* joetest.c:
*
* Scan for "joe" accounts -- accounts with the same username
*and password.

#include <stdio.h>
#include <pwd.h>
int   main(int argc,char **argv)
{
    struct     passwd *pw;

    while(pw=getpwent() ){
        char     *crypt();
        char     *result;

        result = crypt(pw->pw_name,pw->pw_passwd);
        if(!strcmp(result,pw->pw_passwd)){
            printf("%s is a joe\n",pw->pw_name);
        }
    }
    exit(0);
}

*/