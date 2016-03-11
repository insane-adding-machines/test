START_TEST(test_chown)
{
	int ret;
	ret = chown(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_chmod)
{
	int ret;
	ret = chmod(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_clearenv)
{
	int ret;
	ret = clearenv();
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_fcntl)
{
	int ret;
	ret = fcntl(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_fnmatch)
{
	int ret;
	ret = fnmatch(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_getpagesize)
{
	int ret;
	ret = getpagesize();
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_getsid)
{
	int ret;
	ret = getsid(NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_glob)
{
	int ret;
	ret = glob(NULL, NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_globfree)
{
	globfree(NULL);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_lchown)
{
	int ret;
	ret = lchown(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_major)
{
	int ret;
	ret = major(NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_malloc_trim)
{
	malloc_trim(NULL);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_mallopt)
{
	int ret;
	ret = mallopt(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_minor)
{
	int ret;
	ret = minor(NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_mknod)
{
	int ret;
	ret = mknod(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_nanosleep)
{
	int ret;
	ret = nanosleep(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_readlink)
{
	int ret;
	ret = readlink(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_realpath)
{
	int ret;
	ret = realpath(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_regcomp)
{
	int ret;
	ret = regcomp(NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_regerror)
{
	int ret;
	ret = regerror(NULL, NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_regexec)
{
	int ret;
	ret = regexec(NULL, NULL, NULL, NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_regfree)
{
	regfree(NULL);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_rmdir)
{
	int ret;
	ret = rmdir(NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
	/*
	 * test list
	 *  - returns success?
	 *  - find/valid directory?
	 *  - returns proper error conditions
	 *  - reacts well to garbage & trailing // or empty input
	 */

}
END_TEST

START_TEST(test_strverscmp)
{
	int ret;
	ret = strverscmp(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_symlink)
{
	int ret;
	ret = symlink(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_utimes)
{
	int ret;
	ret = utimes(NULL, NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_chroot)
{
	int ret;
	ret = chroot(NULL);
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST

START_TEST(test_fork)
{
	int ret;
	ret = fork();
	fail_if(ret != -1);
	fail_if(errno != ENOSYS);
}
END_TEST
