/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142ffc. */
unsigned int __cdecl locc(char a1, int a2, _BYTE *a3)
{
  _BYTE *v3; // eax
  unsigned int v4; // edx

  v3 = a3; /*0x142fff*/
  v4 = (unsigned int)&a3[a2]; /*0x143007*/
  if ( a3 < &a3[a2] ) /*0x14300c*/
  {
    do /*0x143017*/
    {
      if ( *v3 == a1 ) /*0x143012*/
        break; /*0x143012*/
      ++v3; /*0x143014*/
    }
    while ( (unsigned int)v3 < v4 ); /*0x143017*/
  }
  return v4 - (_DWORD)v3; /*0x14301f*/
}
