/* S1-C sample hexdectodec -- cut verbatim from darwin01/kernel/bsd/dev/i386/rtc.c lines 126-130
 * (SHA-256 038de9f26aaf459bad433fef23973eac18d5bdd8346d70febc2107e69dd137d2, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: '' */
/* ---- verbatim ---- */
hexdectodec(n)
char n;
{
	return(((n>>4)&0x0F)*10 + (n&0x0F));
}
