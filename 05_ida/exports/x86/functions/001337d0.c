/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1337d0. */
int __cdecl sync_vp(int a1)
{
  int result; // eax

  mfs_fsync(a1); /*0x1337d8*/
  result = *(_DWORD *)(a1 + 48); /*0x1337dd*/
  if ( (*(_BYTE *)(result + 96) & 0x10) != 0 ) /*0x1337e7*/
    return sub_133824(a1); /*0x1337ea*/
  return result; /*0x1337ef*/
}
