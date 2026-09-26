/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108b84. */
int __cdecl boot(int a1, int a2, int a3)
{
  int v3; // eax
  int i; // esi
  int v5; // ebx
  _DWORD *j; // edx
  int v8; // [esp+Ch] [ebp-4h]

  md_prepare_for_shutdown(a1, a2, a3); /*0x108b99*/
  if ( (a2 & 4) == 0 && waittime < 0 && dword_1E8764 ) /*0x108bc4*/
  {
    waittime = 0; /*0x108bca*/
    v3 = acctp; /*0x108bd4*/
    if ( acctp ) /*0x108bdb*/
    {
      acctp = 0; /*0x108bdd*/
      vn_rele(v3); /*0x108be8*/
    }
    sync(); /*0x108bf0*/
    unmount_all(); /*0x108bf5*/
    if_down_all(); /*0x108bfa*/
    v8 = 0; /*0x108bff*/
    for ( i = 0; i <= 19; ++i ) /*0x108c06*/
    {
      v5 = 0; /*0x108c08*/
      for ( j = (_DWORD *)(buf + 68 * nbuf - 68); (unsigned int)j >= buf; j -= 17 ) /*0x108c24*/
      {
        if ( (*j & 0xA) == 8 ) /*0x108c30*/
          ++v5; /*0x108c32*/
      }
      if ( !v5 ) /*0x108c3c*/
        break; /*0x108c3c*/
      printf("%d ", v5); /*0x108c44*/
      if ( v8 != v5 ) /*0x108c4f*/
        i = 0; /*0x108c51*/
      v8 = v5; /*0x108c53*/
      us_spin(40000 * i); /*0x108c66*/
    }
  }
  md_shutdown_devices(a1, a2, a3); /*0x108c80*/
  return md_do_shutdown(a1, a2); /*0x108c99*/
}
