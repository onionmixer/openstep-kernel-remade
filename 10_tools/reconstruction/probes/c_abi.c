/* c_abi.c -- probe (plan 412): data-layout facts as initialized data, read from the .o
 * without running it.  kr_abi[] holds compile-time constants only (no relocations);
 * the kr_v_* instances show bit order, padding and byte order.  long long, long double,
 * __alignof__ and non-int bitfield types are GNU extensions, measured here only. */
struct a_c { char c; };
struct a_c3 { char c[3]; };
struct a_sc { short s; char c; };
struct a_s1 { char c; int i; short s; };
union a_u { char c; short s; };
struct a_in { char c; struct a_c in; };
struct a_inu { char c; union a_u u; char d; };
struct o_s { char c; short v; };
struct o_i { char c; int v; };
struct o_l { char c; long v; };
struct o_f { char c; float v; };
struct o_d { char c; double v; };
struct o_p { char c; char *v; };
struct o_ll { char c; long long v; };
struct o_ld { char c; long double v; };
struct o_fp { char c; int (*v)(void); };
struct bf_a { unsigned a:3, b:5, c:9; char x; };
struct bf_b { unsigned a:12, b:12, c:12; };
struct bf_c { char c; int b:4; };
struct bf_d { unsigned a:4; int :0; unsigned b:4; };
struct bf_e { unsigned short a:4, b:4; };
struct bf_f { char c; unsigned b:9; };
enum e_1 { E1A, E1B };
enum e_2 { E2N = -1, E2P = 1 };
enum e_3 { E3BIG = 0x7fffffff };
#define KR_OFF(t, f) ((unsigned long)&((t *)0)->f)

unsigned long kr_abi[] = {
    0x4b524142UL,                                   /* "KRAB" */
    ((char)-1 < 0),
    sizeof(long long), sizeof(long double), sizeof(int (*)(void)),
    __alignof__(char), __alignof__(short), __alignof__(int), __alignof__(long),
    __alignof__(float), __alignof__(double), __alignof__(char *),
    __alignof__(long long), __alignof__(long double),
    __alignof__(struct a_c), __alignof__(struct a_s1), __alignof__(union a_u),
    sizeof(struct a_c), sizeof(struct a_c3), sizeof(struct a_sc), sizeof(union a_u),
    sizeof(struct a_in), KR_OFF(struct a_in, in),
    sizeof(struct a_inu), KR_OFF(struct a_inu, u), KR_OFF(struct a_inu, d),
    sizeof(struct a_c3[2]), sizeof(struct a_sc[3]),
    KR_OFF(struct o_s, v), KR_OFF(struct o_i, v), KR_OFF(struct o_l, v),
    KR_OFF(struct o_f, v), KR_OFF(struct o_d, v), KR_OFF(struct o_p, v),
    KR_OFF(struct o_ll, v), KR_OFF(struct o_ld, v), KR_OFF(struct o_fp, v),
    sizeof(struct o_d), sizeof(struct o_ll), sizeof(struct o_ld),
    sizeof(struct bf_a), KR_OFF(struct bf_a, x), sizeof(struct bf_b),
    sizeof(struct bf_c), sizeof(struct bf_d), sizeof(struct bf_e), sizeof(struct bf_f),
    sizeof(enum e_1), sizeof(enum e_2), sizeof(enum e_3), ((enum e_2)-1 < 0),
    0x454e4421UL                                    /* "END!" */
};

/* value instances: every byte is read and recorded */
struct bf_a kr_v_bfa = { 5, 17, 300, 0x5a };
struct bf_b kr_v_bfb = { 0xabc, 0x123, 0x456 };
struct bf_c kr_v_bfc = { 0x11, -3 };
struct bf_d kr_v_bfd = { 0x9, 0x6 };
struct bf_e kr_v_bfe = { 0x3, 0xc };
struct bf_f kr_v_bff = { 0x22, 0x1a5 };
struct a_s1 kr_v_s1 = { 0x11, 0x22334455, 0x6677 };
struct o_d kr_v_od = { 0x33, 1.5 };
long long kr_v_ll = 0x0102030405060708LL;
long double kr_v_ld = 1.5;
float kr_v_f = 1.5;

/* standalone globals in declaration order: their addresses show global alignment */
char kr_g_c1 = 1;
int kr_g_i = 2;
char kr_g_c2 = 3;
short kr_g_s = 4;
char kr_g_c3 = 5;
double kr_g_d = 6.0;
char kr_g_c4 = 7;
struct a_c kr_g_sc = { 8 };
char kr_g_c5 = 9;
