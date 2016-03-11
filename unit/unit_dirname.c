
START_TEST(test_dirname)
{
 	char *ret;
	/* trailing slashes? */
	ret = dirname("/dev/");
	fail_if(ret < 0);
	ck_assert_str_eq("/dev", ret);
	ret = dirname("/dev/ttyUSB0");
	fail_if(ret < 0);
	ck_assert_str_eq("/dev", ret);
	ret = dirname("/dev///tty");
	fail_if(ret < 0);
	ck_assert_str_eq("/dev", ret);
	ret = dirname("/dev/test/");
	fail_if(ret < 0);
	ck_assert_str_eq("/dev/test", ret);
	ret = dirname("/");
	fail_if(ret < 0);
	ck_assert_str_eq("/", ret);
	ret = dirname("/////");
	fail_if(ret < 0);
	ck_assert_str_eq("/", ret);
	ret = dirname("test/");
	fail_if(ret < 0);
	ck_assert_str_eq("test", ret);
	char *null = NULL;
	ret = dirname(null);
	fail_if(ret < 0);
	ck_assert_str_eq(".", ret);

	char *empty = malloc(sizeof(char) * 2);
	ret = dirname(empty);
	fail_if(ret < 0);
	ck_assert_str_eq(".", ret);

}
END_TEST
