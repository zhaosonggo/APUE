#include<apue.h>

struct stat
{
	mode_t st_mode;
	//文件类型和拥有者 、同组者 、其他人的访问权限，设置用户ID和组ID位
	ino_t st_ino;
	//i节点编号
	dev_t st_dev;
	//设备号1
	dev_t st_rdev;
	//特殊设备号
	nlink_t st_nlink;
	//连接数目
	uid_t st_uid;
	//文件拥有者的用户ID
	gid_t st_gid;
	//文件所属组的用户ID
	off_t st_size;
	//文件的大小
	struct timespec st_atime;
	//最后访问时间
	struct timespec st_mtime;
	//最后修改时间
	struct timespec st_ctime;
	//最后状态改变时间
	blksize_t st_blksize;
	//最佳的磁盘块大小
	blkcnt_t st_blocks;
	//磁盘块的数目
}



S_IRUSR //用户读
S_IWUSR
S_IXUSR

S_IRGRP
S_IWGRP
S_IXGRP

S_IROTH
S_IWOTH
S_IXOTH


if(进程有效用户ID==0)
{
	允许访问
}
else if(进程的有效用户ID==文件的拥有者ID)
{
	查看对应权限位是否设置，设置就允许，没有设置就拒绝
}else if(进程的有效组ID==文件的所在组ID)
{
	查看对应权限位是否设置，设置就允许，没有设置就拒绝
}else
{
	查看其他人对应权限位是否设置，设置就允许，没有设置就拒绝
}


mode = 
R_OK    //是否可以读该文件
W_OK    //是否可以写该文件
X_OK   //是否可以执行该文件
F_OK  //文件是否存在

flag = 
AT_EACCESS  //使用有效ID进行权限检查


S_ISUID   //设置用户ID位
S_ISGID   //设置组ID位
S_ISVTX   //保存正文(粘着位)

S_IRWXU
	S_IRUSR
	S_IWUSR
	S_IXUSR
S_IRWXG
	S_IRGRP
	S_IWGRP
	S_IXGRP
S_IRWXO
	S_IROTH
	S_IWOTH
	S_IXOTH
























