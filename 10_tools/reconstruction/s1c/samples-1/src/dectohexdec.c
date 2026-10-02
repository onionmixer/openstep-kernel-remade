/* S1-C sample dectohexdec -- cut verbatim from darwin01/kernel/bsd/dev/i386/rtc.c lines 132-137
 * (SHA-256 038de9f26aaf459bad433fef23973eac18d5bdd8346d70febc2107e69dd137d2, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: '' */
/* ---- verbatim ---- */
char
dectohexdec(n)
int n;
{
	return((char)(((n/10)<<4)&0xF0) | ((n%10)&0x0F));
}
