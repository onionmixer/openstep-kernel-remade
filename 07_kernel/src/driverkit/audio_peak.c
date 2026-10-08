/*
 * audio_peak.c - peak detection for the audio driver (plan 288).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * original 0x1be71c-0x1be9bd).  The text is nearly the same as Darwin 0.1
 * driverkit-1/libDriver/Kernel/audio_peak.c (every instruction checked
 * against the original bytes); kept as project-authored under D027/D030,
 * without Darwin's notices (license judgement: D017).
 */

#import <bsd/sys/types.h>	/* plan 288: Darwin imports the local audio_peak.h / audio_mulaw.h */

extern const short audio_muLaw[];	/* audio_mulaw.c (plan 287) */

/*
 * Calculate peaks in a mulaw 8-bit buffer.
 * Returns peak as 16-bit linear int.
 */
void audio_mulaw8_peak(u_int chans, unsigned char *buf, u_int count,
		 u_int *peak_left, u_int *peak_right)
{
    int i;
    short samp;

    *peak_left = *peak_right = 0;
    if (chans == 1) {
	for (i = 0; i < count/4; i++) {
	    samp = audio_muLaw[*buf++];
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_left)
		*peak_left = samp;
	    buf += 3;
	}
	*peak_right = *peak_left;
    } else {
	for (i = 0; i < count/4; i++) {
	    samp = audio_muLaw[*buf++];
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_left)
		*peak_left = samp;
	    buf++;
	    samp = audio_muLaw[*buf++];
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_right)
		*peak_right = samp;
	    buf++;
	}
    }
}

/*
 * Calculate peaks in a linear 16-bit buffer.
 */
void audio_linear16_peak(u_int chans, short *buf, u_int count,
			 u_int *peak_left, u_int *peak_right)
{
    int i;
    short samp;

    *peak_left = *peak_right = 0;
    if (chans == 1) {
	for (i = 0; i < count/2; i++) {
	    samp = *buf++;
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_left)
		*peak_left = samp;
	    buf++;
	}
	*peak_right = *peak_left;
    } else {
	for (i = 0; i < count/2; i++) {
	    samp = *buf++;
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_left)
		*peak_left = samp;
	    samp = *buf++;
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_right)
		*peak_right = samp;
	}
    }
}
/*
 * Calculate peaks in a linear 8-bit buffer.
 * Returns peak as 16-bit linear int.
 */
void audio_linear8_peak(u_int chans, char *buf, u_int count, u_int *peak_left,
			u_int *peak_right)
{
    int i;
    char samp;

    *peak_left = *peak_right = 0;
    if (chans == 1) {
	for (i = 0; i < count/2; i++) {
	    samp = *buf++;
	    /* FIXME: iff devIsUnary */
	    /* convert to 2's comp. by xor'ing the high bit */
	    samp = (samp ^ 0x80) | (samp & 0x7f);
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_left)
		*peak_left = samp;
	    buf++;
	}
	*peak_right = *peak_left;
    } else {
	for (i = 0; i < count/2; i++) {
	    samp = *buf++;
	    /* FIXME: iff devIsUnary */
	    /* convert to 2's comp. by xor'ing the high bit */
	    samp = (samp ^ 0x80) | (samp & 0x7f);
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_left)
		*peak_left = samp;
	    samp = *buf++;
	    /* FIXME: iff devIsUnary */
	    /* convert to 2's comp. by xor'ing the high bit */
	    samp = (samp ^ 0x80) | (samp & 0x7f);
	    if (samp < 0)
		samp = -samp;
	    if (samp > *peak_right)
		*peak_right = samp;
	}
    }
    *peak_right <<= 8;
    *peak_left <<= 8;
}

/*
 * Clear peaks in peak buffer.
 */
void audio_clear_peaks(u_int *peak_buf, u_int count)
{
    while (count--)
	*peak_buf++ = 0;
}

/*
 * Return max peak in peak buffer.
 */
u_int audio_max_peak(u_int *peak_buf, u_int count)
{
    u_int peak, max = 0;

    while (count--) {
	peak = *peak_buf++;
	if (peak > max)
	    max = peak;
    }
    return max;
}

/*
 * Add a peak to circular peak buffer and bump cur index.
 */
void audio_add_peak(u_int *peak_buf, u_int peak, u_int *cur, u_int count)
{
    if (count == 0)
	return;
    peak_buf[*cur] = peak;
    *cur = *cur + 1;
    if (*cur == count)
	*cur = 0;
}
