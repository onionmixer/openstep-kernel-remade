/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121530. */
void __cdecl raw_connaddr(int a1, int a2)
{
  bcopy((const void *)(*(_DWORD *)(a2 + 4) + a2), (void *)(a1 + 12), 0x10u); /*0x121544*/
  *(_BYTE *)(a1 + 76) |= 2u; /*0x121549*/
}
