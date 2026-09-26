/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1399e8. */
int __cdecl slookup(int a1, __int16 a2)
{
  int v2; // edx
  int result; // eax

  v2 = stable[((_BYTE)a2 + HIBYTE(a2)) & 0xF]; /*0x1399ff*/
  if ( !v2 ) /*0x139a08*/
    return 0; /*0x139a26*/
  while ( 1 ) /*0x139a0c*/
  {
    if ( *(_WORD *)(v2 + 66) == a2 ) /*0x139a10*/
    {
      result = v2 + 4; /*0x139a12*/
      if ( *(_DWORD *)(v2 + 44) == a1 ) /*0x139a18*/
        break; /*0x139a18*/
    }
    v2 = *(_DWORD *)v2; /*0x139a20*/
    if ( !v2 ) /*0x139a24*/
      return 0; /*0x139a24*/
  }
  ++*(_WORD *)(v2 + 10); /*0x139a1a*/
  return result; /*0x139a28*/
}
