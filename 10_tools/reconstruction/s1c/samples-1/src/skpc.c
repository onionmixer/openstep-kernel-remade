/* S1-C sample skpc -- cut verbatim from darwin01/kernel/bsd/libkern/skpc.c lines 62-74
 * (SHA-256 17c2700cdad1fb09616546519a1e111aeb7d0dec54bf9a2672907b276ea4f9bb, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: 'typedef unsigned char u_char;\n' */
typedef unsigned char u_char;
/* ---- verbatim ---- */
int
skpc(mask0, size, cp0)
	int mask0;
	int size;
	char *cp0;
{
	register u_char *cp, *end, mask;

	mask = mask0;
	cp = (u_char *)cp0;
	for (end = &cp[size]; cp < end && *cp == mask; ++cp);
	return (end - cp);
}
