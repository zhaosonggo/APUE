again:
	if((n = read(fd, buf, BUFFSIZE)) < 0)
	{
		if(errno == EINTR)
			goto again;
	}
