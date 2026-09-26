/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a83c. */
int __cdecl tcp_ctlinput(unsigned int a1, int a2, int a3)
{
  void (__cdecl *v3)(int); // edx
  __int16 *v4; // eax
  int result; // eax

  v3 = tcp_notify; /*0x12a84b*/
  if ( a1 == 4 ) /*0x12a853*/
  {
    v3 = (void (__cdecl *)(int))tcp_quench; /*0x12a868*/
LABEL_6:
    if ( !a3 ) /*0x12a86f*/
      return in_pcbnotify(&tcb, a2, 0, zeroin_addr, 0, a1, (int (__cdecl *)(int))v3); /*0x12a89f*/
    v4 = (__int16 *)(a3 + 4 * (*(_BYTE *)a3 & 0xF)); /*0x12a876*/
    return in_pcbnotify(&tcb, a2, v4[1], *(_DWORD *)(a3 + 12), *v4, a1, (int (__cdecl *)(int))v3); /*0x12a888*/
  }
  if ( a1 <= 0x15 && inetctlerrmap[a1] ) /*0x12a85a*/
    goto LABEL_6; /*0x12a861*/
  return result; /*0x12a8a7*/
}
