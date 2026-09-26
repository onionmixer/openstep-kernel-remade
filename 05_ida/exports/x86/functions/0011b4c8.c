/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b4c8. */
int __cdecl dnlc_lookupSymLink(char *a1, int a2)
{
  unsigned int v2; // kr04_4

  v2 = strlen(a1) + 1; /*0x11b4de*/
  if ( (int)(v2 - 1) > 32 ) /*0x11b4ea*/
    return 0; /*0x11b50c*/
  else
    return sub_11B8DC(a2, a1, v2 - 1, ((_BYTE)a2 + (_BYTE)v2 - 1 + a1[v2 - 2] + *a1) & 0x3F, -1); /*0x11b503*/
}
