/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12bf04. */
int __cdecl igmp_joingroup(unsigned int *a1)
{
  int v1; // esi

  v1 = splnet(); /*0x12bf11*/
  if ( *a1 == dword_1E59AC || a1[1] == loifp ) /*0x12bf24*/
  {
    a1[4] = 0; /*0x12bf26*/
  }
  else
  {
    igmp_sendreport(a1); /*0x12bf31*/
    a1[4] = (_byteswap_ulong(*a1) + ipstat + _byteswap_ulong(*(_DWORD *)(in_ifaddr + 4))) % 0x32 + 1; /*0x12bf59*/
    dword_1DBF44 = 1; /*0x12bf5c*/
  }
  return splx(v1); /*0x12bf6f*/
}
