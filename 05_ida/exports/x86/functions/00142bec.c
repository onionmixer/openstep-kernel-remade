/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142bec. */
int __cdecl badblock(int a1, unsigned int a2)
{
  if ( *(_DWORD *)(a1 + 36) > a2 ) /*0x142bf9*/
    return 0; /*0x142c18*/
  printf("bad block %d, ", a2); /*0x142c01*/
  fserr(a1, (int)aBadBlock); /*0x142c0c*/
  return 1; /*0x142c1a*/
}
