/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9444. */
char __cdecl -[AudioStream bytesProcessed:atTime:](AudioStream *self, SEL a2, unsigned int *a3, unsigned int *a4)
{
  unsigned __int64 v4; // rax
  unsigned __int64 v6; // rax

  objc_msgSend(self->device, sel__outputStartTime); /*0x1b945e*/
  LODWORD(v4) = objc_msgSend(self->device, sel__lastInterruptTimeStamp); /*0x1b946e*/
  if ( v4 ) /*0x1b9478*/
  {
    v6 = v4 / 0x3E8; /*0x1b9499*/
    if ( a4 ) /*0x1b94a0*/
      *a4 = v6; /*0x1b94a2*/
    *a3 = self->bytesProcessed; /*0x1b94a7*/
    return 1; /*0x1b94a9*/
  }
  else
  {
    *a4 = 0; /*0x1b947e*/
    *a3 = 0; /*0x1b9484*/
    return 0; /*0x1b948a*/
  }
}
