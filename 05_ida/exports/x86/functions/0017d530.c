/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d530. */
_BOOL4 __cdecl vnode_has_page(int a1, unsigned int a2)
{
  unsigned __int8 v3[4]; // [esp+4h] [ebp-4h] BYREF

  if ( !a1 ) /*0x17d53c*/
    panic(aVnodeHasPageFa); /*0x17d543*/
  if ( (*(_BYTE *)(a1 + 12) & 1) == 0 ) /*0x17d54f*/
    panic(aVnodeHasPageCa); /*0x17d579*/
  return sub_17CD58((int *)a1, a2, 1, v3) != 5; /*0x17d57e*/
}
