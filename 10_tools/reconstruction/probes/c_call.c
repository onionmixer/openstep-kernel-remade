/* c_call.c -- probe (plan 412): calling convention as seen in caller and callee code.
 * The external callees are left undefined so every call stays a real call. */
struct s_c { char c; };
struct s_s { short s; };
struct s_c3 { char c[3]; };
struct s_i { int i; };
struct s_ii { int a, b; };
struct s_i3 { int a[3]; };
struct s_f { float f; };
struct s_d { double d; };
struct bf_p { int f:3; unsigned u:3; };

extern int ext_narrow(signed char, unsigned char, short, unsigned short, int, long, char *);
extern int ext_mixed(char, double, short, float, int);
extern int ext_ll(long long, int, long double);
extern int ext_var(int, ...);
extern int ext_sc(struct s_c), ext_ss(struct s_s), ext_sc3(struct s_c3), ext_si(struct s_i);
extern int ext_sii(struct s_ii), ext_si3(struct s_i3), ext_sf(struct s_f), ext_sd(struct s_d);
extern struct s_c ext_rc(void);
extern struct s_i ext_ri(void);
extern struct s_ii ext_rii(void);
extern struct s_i3 ext_ri3(void);
extern struct s_d ext_rd(void);
extern int ext_old();
extern void ext_opaque(void);
extern double kr_dsink;

/* callers */
int kr_c_narrow(void) { return ext_narrow(-2, 200, -3, 60000, 5, 6L, (char *)0x70); }
int kr_c_mixed(void) { return ext_mixed(1, 2.5, 3, 4.5f, 5); }
int kr_c_ll(void) { return ext_ll(0x0102030405060708LL, 9, 1.5); }
int kr_c_var(void) { return ext_var(1, (char)2, (short)3, 4.5f, 5.5, 0x0102030405060708LL, (char *)0x70); }
int kr_c_old(void) { return ext_old((char)1, (short)2, 3.5f, 4); }
int kr_c_structs(struct s_c a, struct s_s b, struct s_c3 c, struct s_i d,
                 struct s_ii e, struct s_i3 f, struct s_f g, struct s_d h)
{
    return ext_sc(a) + ext_ss(b) + ext_sc3(c) + ext_si(d)
         + ext_sii(e) + ext_si3(f) + ext_sf(g) + ext_sd(h);
}
int kr_c_rets(void)
{
    struct s_c a; struct s_i b; struct s_ii c; struct s_i3 d; struct s_d e;
    a = ext_rc(); b = ext_ri(); c = ext_rii(); d = ext_ri3(); e = ext_rd();
    return a.c + b.i + c.b + d.a[2] + (int)e.d;
}

/* callees: argument and result handling */
signed char kr_r_sc(int x) { return x; }
unsigned char kr_r_uc(int x) { return x; }
short kr_r_s(int x) { return x; }
unsigned short kr_r_us(int x) { return x; }
char *kr_r_p(char *p) { return p + 1; }
float kr_r_f(float f) { return f * 2; }
double kr_r_d(double d) { return d * 2; }
long long kr_r_ll(long long x) { return x + 1; }
long double kr_r_ld(long double x) { return x * 2; }
int kr_a_narrow(signed char a, unsigned char b, short c, unsigned short d) { return a + b + c + d; }
int kr_a_mixed(char a, double b, short c, float d, int e) { return a + (int)b + c + (int)d + e; }
struct s_c kr_r_sc1(struct s_c a) { a.c++; return a; }
struct s_i kr_r_si(struct s_i a) { a.i++; return a; }
struct s_ii kr_r_sii(struct s_ii a) { a.b++; return a; }
struct s_i3 kr_r_si3(struct s_i3 a) { a.a[2]++; return a; }
struct s_d kr_r_sd(struct s_d a) { a.d += 1; return a; }

int kr_old_def(a, b, c, d)
    char a; short b; float c; int d;
{
    return a + b + (int)c + d;
}

/* plain int and unsigned bitfield extraction */
int kr_bf_plain(struct bf_p *p) { return p->f; }
int kr_bf_uns(struct bf_p *p) { return p->u; }

/* registers live across an opaque call */
int kr_pressure(int *v, double *w)
{
    int a = v[0], b = v[1], c = v[2], d = v[3], e = v[4], f = v[5], g = v[6], h = v[7];
    int *p = v + 8, *q = v + 16, *r = v + 24;
    double x = w[0], y = w[1], z = w[2];
    ext_opaque();
    kr_dsink = x * y + z;
    return a + b * c + d * e + f * g + h + *p + *q + *r;
}

/* compiler helper routines */
long long kr_h_llmul(long long a, long long b) { return a * b; }
long long kr_h_lldiv(long long a, long long b) { return a / b; }
unsigned long long kr_h_ullmod(unsigned long long a, unsigned long long b) { return a % b; }
long long kr_h_llshl(long long a, int n) { return a << n; }
int kr_h_d2i(double d) { return (int)d; }
unsigned kr_h_d2u(double d) { return (unsigned)d; }
double kr_h_ll2d(long long a) { return (double)a; }
long long kr_h_d2ll(double d) { return (long long)d; }
int kr_h_idiv(int a, int b) { return a / b + a % b; }
unsigned kr_h_udiv(unsigned a, unsigned b) { return a / b + a % b; }
