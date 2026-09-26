/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11991c. */
int __cdecl vfs_lock(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 12); /*0x119922*/
  if ( (v1 & 2) != 0 ) /*0x119927*/
    return 16; /*0x119934*/
  LOBYTE(v1) = v1 | 2; /*0x119929*/
  *(_DWORD *)(a1 + 12) = v1; /*0x11992b*/
  return 0; /*0x119932*/
}
