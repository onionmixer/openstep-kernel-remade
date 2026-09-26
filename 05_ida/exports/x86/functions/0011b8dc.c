/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b8dc. */
int __cdecl sub_11B8DC(int a1, _BYTE *a2, size_t a3, int a4, _WORD *a5)
{
  int v5; // ebx
  _WORD *v6; // edx

  v5 = nc_hash[2 * a4]; /*0x11b8f5*/
  if ( (int *)v5 == &nc_hash[2 * a4] ) /*0x11b8fd*/
    return 0; /*0x11b976*/
  while ( 1 ) /*0x11b903*/
  {
    if ( *(_DWORD *)(v5 + 20) == a1 /*0x11b927*/
      && a3 == *(char *)(v5 + 24)
      && *(_BYTE *)(v5 + 25) == *a2
      && !bcmp((const void *)(v5 + 25), a2, a3) )
    {
      if ( a5 == (_WORD *)-1 ) /*0x11b936*/
        break; /*0x11b936*/
      v6 = *(_WORD **)(v5 + 60); /*0x11b938*/
      if ( v6 == a5 || a5[1] == v6[1] && a5[2] == v6[2] && !bcmp(a5 + 5, v6 + 5, 0x20u) ) /*0x11b95d*/
        break; /*0x11b95d*/
    }
    v5 = *(_DWORD *)v5; /*0x11b970*/
    if ( (int *)v5 == &nc_hash[2 * a4] ) /*0x11b974*/
      return 0; /*0x11b974*/
  }
  return v5; /*0x11b97b*/
}
