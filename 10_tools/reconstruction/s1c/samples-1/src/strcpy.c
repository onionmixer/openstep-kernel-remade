/* S1-C sample strcpy -- cut verbatim from darwin01/kernel/machdep/i386/libc/strcpy.c lines 39-48
 * (SHA-256 2eb390dcd4d3aa8a81b7c20ee2ed5b5bad84f15f06a2a9f0198b34378c8b2395, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: '' */
/* ---- verbatim ---- */
char *
strcpy(char *s1, const char *s2)
{
	char *os1;

	os1 = s1;
	while (*s1++ = *s2++)
		;
	return(os1);
}
