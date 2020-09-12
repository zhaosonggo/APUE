#include<apue.h>
#include<setjmp.h>


static void f1(int, int, int ,int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globalval;

int main(void)
{
	int autoval;
	register int regival;
	volatile int volaval;
	static int statval;
	
	globalval = 1;
	autoval = 2;
	regival = 3;
	volaval = 4;
	statval = 5;
	
	if(setjmp(jmpbuffer) != 0)
	{
		printf("after longjmp:\n");
		printf("globalval = %d, autoval = %d, regival = %d"
		", volaval = %d, statval = %d\n",
		globalval, autoval, regival, volaval, statval);
		exit(0);
	}
	globalval = 11;
	autoval = 12;
	regival = 13;
	volaval = 14;
	statval = 15;
	
	f1(autoval, regival, volaval, statval);
	exit(0);
	return 0;
}

static void f1(int autoval, int regival, int volaval, int statval)
{
	printf("in f1():\n");
	printf("globalval = %d, autoval = %d, regival = %d"
		", volaval = %d, statval = %d\n",
		globalval, autoval, regival, volaval, statval);
	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer, 1);
}






