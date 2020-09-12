pid_t getpid(void);//调用进程的进程id
	
pid_t getppid(void); //调用进程的父进程id

uid_t getuid(void); //调用进程的实际用户id

uid_t geteuid(void);  //调用进程的有效用户id

gid_t getgid(void); //调用进程的实际组id

gid_t getegid(void); //调用进程的有效组id


options  //不仅可以获取终止状态，还可以获取停止状态的信息
[
	WCONTINUED 
	//实现支持作业控制的前提下，如果由pid指定的子进程在停止后已经继续，但是其状态尚未报告，则返回状态
	WNOHANG
	//非阻塞模式，如果没有终止的满足要求的子进程，则立刻返回0
	WUNTRACED
	//实现支持作业控制的前提下，如果由pid指定的子进程处于停止状态，但是其状态尚未报告，则返回状态
]
