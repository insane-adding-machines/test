/* Frosted unit tests */
/* Inclusion of all the modules to test */
/* This allow direct access to static functions, and also
 * by compiling this, the namespace is checked for clashes in
 * static symbols.
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <check_stdint.h>
#include <check.h>
#include "dirname.c"
#include "pwd.c"
#include "unit_libc.c"
#include "stubs.c"
#include "unit_stubs.c"

Suite *frosted_suite(void)
{
    Suite *s = suite_create("Frosted");

    TCase *libc = tcase_create("Libc");
    tcase_add_test(libc, test_dirname);
    tcase_add_test(libc, test_basename);
    tcase_add_test(libc, test_getpwnam);
    tcase_add_test(libc, test_getpwuid);
    suite_add_tcase(s, libc);


    TCase *stubs = tcase_create("Stubs");

    tcase_add_test(stubs, test_chown);
    tcase_add_test(stubs, test_chmod);
    tcase_add_test(stubs, test_clearenv);
    tcase_add_test(stubs, test_fcntl);
    tcase_add_test(stubs, test_fnmatch);
    tcase_add_test(stubs, test_getpagesize);
    tcase_add_test(stubs, test_getsid);
    tcase_add_test(stubs, test_glob);
    tcase_add_test(stubs, test_globfree);
    tcase_add_test(stubs, test_lchown);
    tcase_add_test(stubs, test_major);
    tcase_add_test(stubs, test_malloc_trim);
    tcase_add_test(stubs, test_mallopt);
    tcase_add_test(stubs, test_minor);
    tcase_add_test(stubs, test_mknod);
    tcase_add_test(stubs, test_nanosleep);
    tcase_add_test(stubs, test_readlink);
    tcase_add_test(stubs, test_realpath);
    tcase_add_test(stubs, test_regcomp);
    tcase_add_test(stubs, test_regerror);
    tcase_add_test(stubs, test_regexec);
    tcase_add_test(stubs, test_regfree);
    tcase_add_test(stubs, test_rmdir);
    tcase_add_test(stubs, test_strverscmp);
    tcase_add_test(stubs, test_symlink);
    tcase_add_test(stubs, test_utimes);
    tcase_add_test(stubs, test_chroot);
    tcase_add_test(stubs, test_fork);

    suite_add_tcase(s, stubs);

    return s;
}

int main(void)
{
    int fails;
    Suite *s = frosted_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_VERBOSE);
    fails = srunner_ntests_failed(sr);
    srunner_free(sr);
    return fails;
}
