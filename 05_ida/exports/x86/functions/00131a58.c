/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x131a58. */
int __cdecl sub_131A58(_DWORD *a1, _DWORD *a2, int a3)
{
  sync_vp(a1); /*0x131a68*/
  return nfsgetattr(a1, a2, a3, 0); /*0x131a7a*/
}
