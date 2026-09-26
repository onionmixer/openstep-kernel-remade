/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116354. */
int __cdecl soqremque(_DWORD *a1, int a2)
{
  int v2; // ecx
  _DWORD *i; // edx
  _DWORD *v4; // eax

  v2 = a1[4]; /*0x116360*/
  for ( i = (_DWORD *)v2; ; i = v4 )
  {
    v4 = (_DWORD *)(a2 ? i[7] : i[5]);
    if ( v4 == a1 ) /*0x116379*/
      break; /*0x116379*/
    if ( v4 == (_DWORD *)v2 ) /*0x11637d*/
      return 0; /*0x116396*/
  }
  if ( a2 ) /*0x116386*/
  {
    i[7] = v4[7]; /*0x11639b*/
    --*(_WORD *)(v2 + 32); /*0x11639e*/
  }
  else
  {
    i[5] = v4[5]; /*0x11638b*/
    --*(_WORD *)(v2 + 24); /*0x11638e*/
  }
  v4[7] = 0; /*0x1163a2*/
  v4[5] = 0; /*0x1163a9*/
  v4[4] = 0; /*0x1163b0*/
  return 1; /*0x1163bf*/
}
