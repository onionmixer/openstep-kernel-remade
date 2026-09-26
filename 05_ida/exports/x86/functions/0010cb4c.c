/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cb4c. */
int __cdecl harderr(int a1, const char *a2)
{
  return printf(
           "%s%d%c: hard error sn%d ",
           a2,
           (unsigned __int8)*(_WORD *)(a1 + 30) >> 3,
           (*(_WORD *)(a1 + 30) & 7) + 97,
           *(_DWORD *)(a1 + 36));
}
