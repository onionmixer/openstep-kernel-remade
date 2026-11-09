/*
 * machdep/m68k/bdiv.c -- __bdiv, division of 16-bit digit strings (plan 639, D145).
 *
 * Written from the original bytes (D024, D145): the 1997 m68k kernel range
 * [0x4090d4c, 0x4091080) (820 bytes; __bdiv 706 and the static shift_digits
 * 114; inventory row m68k-264 with __ashldi3).  a / b over 16-bit digits,
 * most significant first; m and n are byte counts; q gets m - n digits, r
 * gets n digits.  A zero divisor ends in a division by zero (n = 10 / n), as
 * in the original.  The two-digit numerator is a variable of its own (plan
 * 638; its form, num, is a user decision).
 * The shape of these helpers looks like the GCC 1.x gnulib2.c family, but
 * that text was neither imported nor compared (D145); the license judgement
 * is the user's.
 * C names carry one leading _ less than the symbols (the compiler adds it).
 */

extern void	bcopy();
static int	shift_digits();	/* plan 639 (D145): this project's name; the original keeps no static symbol */

void
_bdiv(a, b, q, r, m, n)	/* plan 639 (D024, D145): from the original bytes 0x4090d4c */
    unsigned short	*a, *b, *q, *r;
    unsigned long	m, n;
{
    unsigned long	qhat, rhat, acc;
    unsigned short	*u = (unsigned short *)alloca(m);
    unsigned short	*v = (unsigned short *)alloca(n);
    unsigned short	*u0, *u1, *u2, *v0;
    int			d, qn, i, j;

    m /= sizeof *a;
    n /= sizeof *b;
    qn = m - n;

    while (*b == 0) {
	*r++ = 0;
	a++;
	b++;
	m--;
	n--;
	if (n == 0)
	    n = 10 / n;
    }

    if (n == 1) {
	acc = *a++;
	for (j = 0; j < qn; j++) {
	    acc = (acc << 16) | a[j];
	    q[j] = acc / *b;
	    acc = acc % *b;
	}
	*r = acc;
	return;
    }

    for (d = 0; d < 16; d++)
	if (*b & (1 << (16 - 1 - d)))
	    break;
    shift_digits(a, d, u, 0, m);
    shift_digits(b, d, v, 0, n);

    u0 = u;
    u1 = u0 + 1;
    u2 = u1 + 1;
    u++;
    v0 = v;

    for (j = 0; j < qn; j++) {
	if (u0[j] == *v0) {
	    qhat = 0xffff;
	    rhat = (unsigned long)*v0 + u1[j];
	} else {
	    unsigned long	num = ((unsigned long)u0[j] << 16) | u1[j];

	    qhat = num / *v0;
	    rhat = num % *v0;
	}
	while (rhat <= 0xffff && qhat * v0[1] > ((rhat << 16) | u2[j])) {
	    qhat--;
	    rhat += *v0;
	}

	acc = 0;
	for (i = n - 1; i >= 0; i--) {
	    acc += (unsigned long)(u + j)[i] - v[i] * qhat;
	    (u + j)[i] = acc;
	    if (acc <= 0xffff)
		acc = 0;
	    else
		acc = (acc >> 16) | 0xffff0000;
	}
	q[j] = qhat;

	if ((long)(u0[j] + acc) < 0) {
	    q[j]--;
	    acc = 0;
	    for (i = n - 1; i >= 0; i--) {
		acc += (unsigned long)(u + j)[i] + v[i];
		(u + j)[i] = acc;
		acc >>= 16;
	    }
	}
    }

    *r = shift_digits(u + j - 1, 16 - d, r + 1, u[m - 2] >> d, n - 1);
}

/* w = u << k over n digits (most significant first), carry_in shifted in */
static int
shift_digits(u, k, w, carry_in, n)	/* plan 639 (D024, D145): from the original bytes 0x409100e */
    unsigned short	*u, *w;
    int			k;
    unsigned short	carry_in;
    int			n;
{
    unsigned long	acc;
    int			i;

    if (k == 0) {
	bcopy(u, w, n * sizeof *u);
	return 0;
    }
    acc = carry_in;
    for (i = n - 1; i >= 0; i--) {
	acc |= (unsigned long)u[i] << k;
	w[i] = acc;
	acc >>= 16;
    }
    return acc;
}
