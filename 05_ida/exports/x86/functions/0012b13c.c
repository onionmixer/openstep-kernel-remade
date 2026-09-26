/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b13c. */
int __cdecl tcp_attach(int a1)
{
  int result; // eax
  _DWORD *v2; // edi
  _DWORD *v3; // eax
  __int16 v4; // ax
  __int16 v5; // bx

  if ( *(_WORD *)(a1 + 62) && *(_WORD *)(a1 + 38) || (result = soreserve(a1, tcp_sendspace, tcp_recvspace)) == 0 ) /*0x12b16c*/
  {
    result = in_pcballoc(a1, (int)&tcb); /*0x12b174*/
    if ( !result ) /*0x12b17e*/
    {
      v2 = *(_DWORD **)(a1 + 8); /*0x12b180*/
      v3 = tcp_newtcpcb((int)v2); /*0x12b184*/
      if ( v3 ) /*0x12b18e*/
      {
        *((_WORD *)v3 + 4) = 0; /*0x12b1b0*/
        return 0; /*0x12b1b6*/
      }
      else
      {
        v4 = *(_WORD *)(a1 + 6); /*0x12b190*/
        v5 = v4 & 1; /*0x12b196*/
        LOBYTE(v4) = v4 & 0xFE; /*0x12b199*/
        *(_WORD *)(a1 + 6) = v4; /*0x12b19b*/
        in_pcbdetach(v2); /*0x12b1a0*/
        *(_WORD *)(a1 + 6) |= v5; /*0x12b1a5*/
        return 55; /*0x12b1a9*/
      }
    }
  }
  return result; /*0x12b1bb*/
}
