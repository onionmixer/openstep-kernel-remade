/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ca90. */
int __cdecl loutw(unsigned __int16 a1, unsigned __int16 *a2, int a3)
{
  unsigned __int16 v5; // ax
  int result; // eax

  while ( 1 ) /*0x18cab5*/
  {
    result = a3--; /*0x18cab5*/
    if ( !result ) /*0x18caba*/
      break; /*0x18caba*/
    v5 = *a2++; /*0x18caa4*/
    __outword(a1, v5); /*0x18caac*/
    _InterlockedIncrement(&dword_1E7728); /*0x18caae*/
  }
  return result; /*0x18cabf*/
}
