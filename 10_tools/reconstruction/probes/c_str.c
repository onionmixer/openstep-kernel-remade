/* c_str.c -- probe (plan 412): literal placement and identity, with and without
 * -fwritable-strings. */
extern void ext_use(const char *, const char *, const char *);

const char *kr_s1(void) { return "kr-same"; }
const char *kr_s2(void) { return "kr-same"; }
char kr_s_arr[] = "kr-array";
const char *kr_s_ptr = "kr-ptr";

void kr_s3(void)
{
    ext_use("kr-same", "kr-other", kr_s_ptr);
}
