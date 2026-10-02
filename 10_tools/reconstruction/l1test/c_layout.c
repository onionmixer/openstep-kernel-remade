/* c_layout.c -- probe: structure sizes/offsets as initialized data (read from
 * the .o without running it).  Marker words bracket the table. */
struct s1 { char c; int i; short s; };
struct s2 { char c; double d; };
struct s3 { unsigned a:3, b:5, c:9; char x; };
struct s4 { char c; struct s1 in; long l; char arr[3]; };
struct s5 { short s; char c; };
#define KR_OFF(t, f) ((unsigned long)&((t *)0)->f)

unsigned long kr_layout[] = {
    0x4b524c59UL,                                   /* "KRLY" */
    sizeof(char), sizeof(short), sizeof(int), sizeof(long),
    sizeof(void *), sizeof(float), sizeof(double),
    sizeof(struct s1), KR_OFF(struct s1, i), KR_OFF(struct s1, s),
    sizeof(struct s2), KR_OFF(struct s2, d),
    sizeof(struct s3), KR_OFF(struct s3, x),
    sizeof(struct s4), KR_OFF(struct s4, in), KR_OFF(struct s4, l), KR_OFF(struct s4, arr),
    sizeof(struct s5),
    0x454e4421UL                                    /* "END!" */
};
