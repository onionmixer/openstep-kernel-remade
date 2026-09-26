/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194ae8. */
int __cdecl cnioctl(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  _DWORD *posix_proc; // edx
  int v6; // eax

  if ( a2 != 536900721 ) /*0x194af6*/
    return (*(&funcs_10EA24 + 11 * *(unsigned __int8 *)(cons_tp + 57)))(*(__int16 *)(cons_tp + 56), a2, a3, a4); /*0x194b65*/
  v4 = *(_DWORD *)active_u; /*0x194afd*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x194b09*/
  cons_tp = (int)&cons; /*0x194b0b*/
  v6 = *(_DWORD *)(posix_proc[4] + 8); /*0x194b18*/
  if ( *(_DWORD *)(v6 + 4) == v4 ) /*0x194b1e*/
  {
    *(_DWORD *)(v6 + 8) = 0; /*0x194b20*/
    *(_WORD *)(*(_DWORD *)(posix_proc[4] + 8) + 12) = 0; /*0x194b2d*/
  }
  *(_DWORD *)(v4 + 40) &= ~0x40000000u; /*0x194b33*/
  return 0; /*0x194b6a*/
}
