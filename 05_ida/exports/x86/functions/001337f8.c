/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1337f8. */
int __cdecl sync_vp_invalidate(int a1, int a2)
{
  int result; // eax

  mfs_fsync_invalidate(a1, a2); /*0x133804*/
  result = *(_DWORD *)(a1 + 48); /*0x133809*/
  if ( (*(_BYTE *)(result + 96) & 0x10) != 0 ) /*0x133813*/
    return sub_133824(a1); /*0x133816*/
  return result; /*0x13381b*/
}
