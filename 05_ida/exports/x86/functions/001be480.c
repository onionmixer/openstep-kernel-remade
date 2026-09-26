/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be480. */
int __usercall audio_convertLinear8ToLinear16@<eax>(__int16 a1@<bx>, _BYTE *a2, _WORD *a3, int a4)
{
  int result; // eax

  result = a4; /*0x1be48a*/
  while ( --result != -1 ) /*0x1be49d*/
  {
    LOBYTE(a1) = *a2; /*0x1be490*/
    a1 <<= 8; /*0x1be492*/
    *a3 = a1; /*0x1be496*/
    ++a2; /*0x1be499*/
    ++a3; /*0x1be49a*/
  }
  return result; /*0x1be4a3*/
}
