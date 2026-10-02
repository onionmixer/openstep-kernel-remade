/* S1-C sample strcmp -- cut verbatim from darwin01/kernel/machdep/i386/libc/strcmp.c lines 39-47
 * (SHA-256 cab7a39df19eedd119601f97117aca323a032afc4291fb1a5d70a872faf13331, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: '' */
/* ---- verbatim ---- */
int
strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
	s1++;
	s2++;
    }
    return (*s1 - *s2);
}
