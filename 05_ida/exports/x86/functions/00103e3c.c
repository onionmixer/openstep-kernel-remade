/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103e3c. */
int getdtablesize(void)
{
  int result; // eax

  result = dword_1E875C; /*0x103e3f*/
  *(_DWORD *)(dword_1E875C + 96) = 256; /*0x103e44*/
  return result; /*0x103e4d*/
}
