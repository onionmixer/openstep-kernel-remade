/* S1-C sample yeartoday -- cut verbatim from darwin01/kernel/bsd/dev/i386/rtc.c lines 120-124
 * (SHA-256 038de9f26aaf459bad433fef23973eac18d5bdd8346d70febc2107e69dd137d2, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: '' */
/* ---- verbatim ---- */
yeartoday(year)
int year;
{
	return((year%4) ? 365 : 366);
}
