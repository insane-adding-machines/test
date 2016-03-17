
START_TEST(test_dirname)
{
 	char *path;
	/* trailing slashes? */
	path = dirname("/dev/");
	fail_if(path < 0);
	ck_assert_str_eq("/dev", path);
	path = dirname("/dev/ttyUSB0");
	fail_if(path < 0);
	ck_assert_str_eq("/dev", path);
	path = dirname("/dev///tty");
	fail_if(path < 0);
	ck_assert_str_eq("/dev", path);
	path = dirname("/dev/test/");
	fail_if(path < 0);
	ck_assert_str_eq("/dev/test",path);
	path = dirname("/");
	fail_if(path < 0);
	ck_assert_str_eq("/", path);
	path = dirname("/////");
	fail_if(path < 0);
	ck_assert_str_eq("/", path);
	path = dirname("test/");
	fail_if(path < 0);
	ck_assert_str_eq("test", path);
	char *null = NULL;
	path = dirname(null);
	fail_if(path < 0);
	ck_assert_str_eq(".", path);

	char *empty = malloc(sizeof(char) * 2);
	path = dirname(empty);
	fail_if(path < 0);
	ck_assert_str_eq(".", path);

}
END_TEST

START_TEST(test_basename)
{
 	char *path;
	/* trailing slashes? */
	path = basename("dev");
	fail_if(path < 0);
	ck_assert_str_eq("dev", path);
	path = basename("/dev/ttyUSB0");
	fail_if(path < 0);
	ck_assert_str_eq("ttyUSB0", path);
	path = basename("/dev///tty");
	fail_if(path < 0);
	ck_assert_str_eq("tty", path);
	path = basename("/dev/test");
	fail_if(path < 0);
	ck_assert_str_eq("test",path);
	path = basename("/");
	fail_if(path < 0);
	ck_assert_str_eq("/", path);
	path = basename("/////");
	fail_if(path < 0);
	ck_assert_str_eq("/", path);
	path = basename("test/");
	fail_if(path < 0);
	ck_assert_str_eq("test", path);
	char *null = NULL;
	path = basename(null);
	fail_if(path < 0);
	ck_assert_str_eq(".", path);

	char *empty = malloc(sizeof(char) * 2);
	path = basename(empty);
	fail_if(path < 0);
	ck_assert_str_eq(".", path);

}
END_TEST


START_TEST(test_getpwnam)
{
 	struct passwd *passwd;
	passwd = getpwnam(NULL);
	fail_if(passwd);
	fail_if(errno != EBADF);
	passwd = getpwnam("");
	fail_if(passwd);
	fail_if(errno != ENOENT);
	errno = 0;
	passwd = getpwnam("root");
	fail_if(errno);
	fail_if(!passwd);
	fail_if(passwd->pw_uid != 0);
	passwd = getpwnam("test");
	fail_if(passwd);
	fail_if(errno != ENOENT);
}
END_TEST

START_TEST(test_getpwuid)
{
 	struct passwd *passwd;
	passwd = getpwuid("");
	fail_if(passwd);
	fail_if(errno != ENOENT);
	passwd = getpwuid(1);
	fail_if(passwd);
	fail_if(errno != ENOENT);
	errno = 0;
	passwd = getpwuid(0);
	fail_if(errno);
	fail_if(!passwd);
	ck_assert_str_eq("root", passwd->pw_name);
}
END_TEST
