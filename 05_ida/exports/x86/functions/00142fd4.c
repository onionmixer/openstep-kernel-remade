/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142fd4. */
unsigned int __cdecl skpc(char a1, int a2, _BYTE *a3)
{
  _BYTE *v3; // eax
  unsigned int v4; // edx

  v3 = a3; /*0x142fd7*/
  v4 = (unsigned int)&a3[a2]; /*0x142fdf*/
  if ( a3 < &a3[a2] ) /*0x142fe4*/
  {
    do /*0x142fef*/
    {
      if ( *v3 != a1 ) /*0x142fea*/
        break; /*0x142fea*/
      ++v3; /*0x142fec*/
    }
    while ( (unsigned int)v3 < v4 ); /*0x142fef*/
  }
  return v4 - (_DWORD)v3; /*0x142ff7*/
}
