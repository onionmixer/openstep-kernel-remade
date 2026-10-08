/*
 * libDriver/label_subr.h - libDriver private header (plan 316, D030).
 *
 * Not in the OPENSTEP 4.2 SDK; needed by IODiskPartition.m, whose object matches
 * the original kernel bytes.  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/label_subr.h; kept as project-authored under D030, without Darwin's
 * notices (license judgement: D017).
 */

/*
 * Validate an m68k-style label. Returns 0 if good, else returns pointer
 * to an error string describing what is wrong with the label.
 */
char *check_label(char *raw_label,	// as it came off disk
	int block_num);			// physical block # of start of label

/*
 * Machine-independent version of kernel's checksum_16().
 * *wp is a raw m68k-style label.
 */
unsigned short checksum16(unsigned short *wp, int num_shorts);
