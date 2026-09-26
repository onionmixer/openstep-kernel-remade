/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113814. */
int __cdecl syioctl(int a1, int a2, int a3, int a4)
{
  int v4; // ebx
  _DWORD *posix_proc; // edx
  int v6; // eax

  if ( a2 == 536900721 ) /*0x113822*/
  {
    v4 = *(_DWORD *)active_u; /*0x113829*/
    posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x113835*/
    v6 = *(_DWORD *)(posix_proc[4] + 8); /*0x11383a*/
    if ( *(_DWORD *)(v6 + 4) == v4 ) /*0x113840*/
    {
      *(_DWORD *)(v6 + 8) = 0; /*0x113842*/
      *(_WORD *)(*(_DWORD *)(posix_proc[4] + 8) + 12) = 0; /*0x11384f*/
    }
    *(_DWORD *)(v4 + 40) &= ~0x40000000u; /*0x113855*/
    *(_DWORD *)(active_u + 360) = 0; /*0x113861*/
    *(_WORD *)(active_u + 364) = 0; /*0x113870*/
    return 0; /*0x113879*/
  }
  else if ( *(_DWORD *)(active_u + 360) ) /*0x113886*/
  {
    return (*(&funcs_10EA24 + 11 * *(unsigned __int8 *)(active_u + 365)))(*(__int16 *)(active_u + 364), a2, a3, a4); /*0x1138b4*/
  }
  else
  {
    return 6; /*0x1138b8*/
  }
}
