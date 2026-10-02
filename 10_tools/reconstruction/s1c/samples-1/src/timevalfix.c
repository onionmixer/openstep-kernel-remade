/* S1-C sample timevalfix -- cut verbatim from darwin01/kernel/bsd/kern/kern_time.c lines 529-541
 * (SHA-256 0bb75f916d04e51c1e7b3314da8fbbd81cd5c53b16b7c69ff0bd6c2cad99f626, APSL; candidate text, not a fact about the original).
 * Prepended below the separator: 'struct timeval { long tv_sec; long tv_usec; };\n' */
struct timeval { long tv_sec; long tv_usec; };
/* ---- verbatim ---- */
timevalfix(t1)
	struct timeval *t1;
{

	if (t1->tv_usec < 0) {
		t1->tv_sec--;
		t1->tv_usec += 1000000;
	}
	if (t1->tv_usec >= 1000000) {
		t1->tv_sec++;
		t1->tv_usec -= 1000000;
	}
}
