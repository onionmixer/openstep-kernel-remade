/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119acc. */
int __cdecl vfs_putmajor(int a1, int a2)
{
  int result; // eax

  result = (int)*(&off_1DB644 + 2 * a2 - 256); /*0x119ad8*/
  if ( *(_DWORD *)(a1 + 4) != result ) /*0x119ae2*/
    return vfs_putnum(byte_1E58C8, a2 - 128); /*0x119aea*/
  return result; /*0x119af1*/
}
