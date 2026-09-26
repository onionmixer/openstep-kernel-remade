/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f5ac. */
int __cdecl sub_13F5AC(int a1, const char *a2, int a3)
{
  return printf(
           "%s: bad dir ino %d at offset %d: %s\n",
           (const char *)(*(_DWORD *)(a1 + 80) + 212),
           *(_DWORD *)(a1 + 72),
           a3,
           a2);
}
