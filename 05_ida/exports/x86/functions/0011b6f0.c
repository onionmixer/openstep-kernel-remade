/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b6f0. */
unsigned int __cdecl dnlc_remove(int a1, char *a2)
{
  unsigned int result; // eax
  size_t v3; // edi
  int v4; // esi

  result = strlen(a2) + 1; /*0x11b703*/
  v3 = result - 1; /*0x11b709*/
  if ( (int)(result - 1) <= 32 ) /*0x11b70f*/
  {
    v4 = ((_BYTE)a1 + (_BYTE)v3 + a2[v3 - 1] + *a2) & 0x3F; /*0x11b722*/
    while ( 1 ) /*0x11b731*/
    {
      result = sub_11B8DC(a1, a2, v3, v4, -1); /*0x11b731*/
      if ( !result ) /*0x11b73b*/
        break; /*0x11b73b*/
      sub_11B830(result); /*0x11b73e*/
    }
  }
  return result; /*0x11b74b*/
}
