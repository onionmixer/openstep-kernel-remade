/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a0a4. */
int __cdecl copyinstr(unsigned int a1, unsigned __int8 *a2, int a3, _DWORD *a4)
{
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // eax

  *(_DWORD *)(active_threads + 116) = &loc_18A0F8; /*0x18a0bb*/
  v6 = a3 - 1; /*0x18a0c2*/
  if ( a3 > 0 ) /*0x18a0c7*/
  {
    do /*0x18a0dc*/
    {
      v7 = __readfsbyte(a1); /*0x18a0cc*/
      *a2++ = v7; /*0x18a0cf*/
      ++a1; /*0x18a0d2*/
      if ( !v7 ) /*0x18a0d5*/
        break; /*0x18a0d5*/
      v8 = v6--; /*0x18a0d7*/
    }
    while ( v8 > 0 ); /*0x18a0dc*/
  }
  if ( a4 ) /*0x18a0e0*/
    *a4 = a3 - v6; /*0x18a0e4*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x18a0eb*/
  return 0; /*0x18a10c*/
}
