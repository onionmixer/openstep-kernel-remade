/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be960. */
unsigned int __cdecl audio_max_peak(unsigned int *a1, int a2)
{
  unsigned int v3; // ebx
  unsigned int v5; // eax

  v3 = 0; /*0x1be967*/
  while ( --a2 != -1 ) /*0x1be97b*/
  {
    v5 = *a1++; /*0x1be970*/
    if ( v5 > v3 ) /*0x1be977*/
      v3 = v5; /*0x1be979*/
  }
  return v3; /*0x1be983*/
}
