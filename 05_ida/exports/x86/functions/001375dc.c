/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1375dc. */
int __cdecl svckudp_recv(int *a1, rpc_msg *a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  XDR *v6; // [esp+Ch] [ebp-4h]

  v2 = a1[12]; /*0x1375e8*/
  v6 = (XDR *)(v2 + 12); /*0x1375ee*/
  ++rsstat; /*0x1375f1*/
  v3 = splnet(); /*0x1375fc*/
  v4 = ku_recvfrom(*a1, a1 + 4); /*0x13760a*/
  splx(v3); /*0x13760d*/
  if ( !v4 ) /*0x137617*/
  {
    ++dword_1EF288; /*0x137619*/
    return 0; /*0x137621*/
  }
  if ( *(_WORD *)(v4 + 8) > 0xFu ) /*0x137629*/
  {
    xdrmbuf_init(v6, v4, 1); /*0x13763b*/
    if ( xdr_callmsg(v6, a2) ) /*0x137648*/
    {
      *(_DWORD *)(v2 + 4) = a2->rm_xid; /*0x137659*/
      *(_DWORD *)(v2 + 8) = v4; /*0x13765c*/
      return 1; /*0x137664*/
    }
    ++dword_1EF290; /*0x137668*/
  }
  else
  {
    ++dword_1EF28C; /*0x13762b*/
  }
  m_freem(v4); /*0x13766f*/
  *(_DWORD *)(v2 + 8) = 0; /*0x137674*/
  ++dword_1EF284; /*0x13767b*/
  return 0; /*0x137686*/
}
