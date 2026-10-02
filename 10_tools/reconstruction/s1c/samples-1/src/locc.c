/* S1-C sample locc -- cut verbatim from darwin01/kernel/bsd/libkern/locc.c lines 62-74
 * (SHA-256 3b55abd41475898de5c043851f87ba7474758c15a1f403aabd324feed5bdc4fb, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: 'typedef unsigned char u_char;\ntypedef unsigned int u_int;\n' */
typedef unsigned char u_char;
typedef unsigned int u_int;
/* ---- verbatim ---- */
int
locc(mask0, cp0, size)
	int mask0;
	char *cp0;
	u_int size;
{
	register u_char *cp, *end, mask;

	mask = mask0;
	cp = (u_char *)cp0;
	for (end = &cp[size]; cp < end && *cp != mask; ++cp);
	return (end - cp);
}
