/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c204. */
int __cdecl nfs_validate_caches(int a1, int a2, int a3)
{
  _BYTE v4[64]; // [esp+0h] [ebp-40h] BYREF

  return nfsgetattr(a1, v4, a2, a3); /*0x12c21f*/
}
