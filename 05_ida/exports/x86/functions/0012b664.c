/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b664. */
int __cdecl udp_ctlinput(unsigned int a1, int a2, int a3)
{
  __int16 *v3; // eax
  int result; // eax

  if ( a1 == 1 || a1 <= 0x15 && inetctlerrmap[a1] ) /*0x12b67c*/
  {
    if ( a3 ) /*0x12b687*/
    {
      v3 = (__int16 *)(a3 + 4 * (*(_BYTE *)a3 & 0xF)); /*0x12b68e*/
      return in_pcbnotify(&udb, a2, v3[1], *(_DWORD *)(a3 + 12), *v3, a1, (int (__cdecl *)(int))udp_notify); /*0x12b6a4*/
    }
    else
    {
      return in_pcbnotify(&udb, a2, 0, zeroin_addr, 0, a1, (int (__cdecl *)(int))udp_notify); /*0x12b6bf*/
    }
  }
  return result; /*0x12b6c7*/
}
