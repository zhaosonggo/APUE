struct passwd
{
	char *pw_name;  //用户名
	char *pw_passwd;//用户口令
	uid_t pw_uid;  //用户id
	gid_t pw_gid;  //用户组id
	char *pw_gecos; //注释字段
	char *pw_dir;　　//初始工作目录
	char *pw_shell; //初始shell
	char *pw_class; //用户访问类
	time_t pw_change;//下次更改口令日期
	time_t pw_expire; 　//账户有效期时间
};

struct spwd
{
	char *sp_namp; //用户登录名
	char *sp_pwdp; //加密口令
	int sp_lstchg; //上次口令更改至今的时间
	int sp_min;    //多少天后允许更改 
	int sp_max;　　//要求更改的剩余天数
	int sp_wan;   //超期警告天数
	int sp_inact; //账号不活动之前剩余天数
	int sp_expire; //超期天数
	unsigned int sp_flag; //保留
};


{
	CLOCK_REALTIME; //实时系统时间
	CLOCK_MONOTONIC; //不带负跳数的实时系统时间
	CLOCK_PROCESS_CPUTIME_ID; //调用进程的CPU时间
	CLOCK_THREAD_CPUTIME_ID; //调用线程的CPU时间
}


