/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119a20. */
int __cdecl vfs_getmajor(int a1)
{
  int i; // ebx
  int v2; // eax

  for ( i = 0; i < (vfsNVFS - (char *)&vfssw) >> 3; ++i ) /*0x119a25*/
    byte_1E58C8[i >> 3] |= 1 << (i - 8 * (i >> 3)); /*0x119a43*/
  v2 = vfs_getnum(byte_1E58C8, 16); /*0x119a62*/
  if ( v2 == -1 ) /*0x119a6f*/
    return vfs_fixedmajor(a1); /*0x119a7a*/
  else
    return v2 + 128; /*0x119a80*/
}
