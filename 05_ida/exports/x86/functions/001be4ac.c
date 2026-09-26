/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be4ac. */
void __usercall audio_convertLinear8ToMulaw8(__int16 a1@<ax>, _BYTE *a2, _BYTE *a3, int a4)
{
  while ( --a4 != -1 ) /*0x1be4d3*/
  {
    LOBYTE(a1) = *a2++; /*0x1be4c0*/
    a1 = audio_shortToMulaw(a1 << 8); /*0x1be4c9*/
    *a3 = a1; /*0x1be4ce*/
  }
}
