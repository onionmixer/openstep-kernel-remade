/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137690. */
int __cdecl svckudp_send(int *a1, rpc_msg *a2)
{
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // eax
  int *v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // edx
  __int16 v9; // ax
  void (__stdcall **v10)(_DWORD); // eax
  int v12; // [esp+Ch] [ebp-4h]

  v2 = a1[12]; /*0x13769c*/
  v12 = 0; /*0x1376a2*/
  v3 = splimp(); /*0x1376ae*/
  while ( 1 ) /*0x1376c3*/
  {
    v4 = *(_DWORD *)v2; /*0x1376c3*/
    if ( (*(_DWORD *)v2 & 1) == 0 ) /*0x1376c7*/
      break; /*0x1376c7*/
    LOBYTE(v4) = v4 | 2; /*0x1376b4*/
    *(_DWORD *)v2 = v4; /*0x1376b6*/
    sleep(v2); /*0x1376bb*/
  }
  *(_BYTE *)v2 |= 1u; /*0x1376c9*/
  splx(v3); /*0x1376cd*/
  v5 = mclgetx((int)sub_137994, v2, a1[11], 8800, 1); /*0x1376e6*/
  v6 = (int)v5; /*0x1376eb*/
  if ( v5 )
  {
    xdrmbuf_init(v2 + 36, v5, 0); /*0x13771b*/
    a2->rm_xid = *(_DWORD *)(v2 + 4); /*0x137726*/
    if ( xdr_replymsg((XDR *)(v2 + 36), a2) )
    {
      v9 = (*(int (__cdecl **)(unsigned int))(*(_DWORD *)(v2 + 40) + 16))(v2 + 36); /*0x13773d*/
      if ( !*(_DWORD *)v6 ) /*0x137742*/
        *(_WORD *)(v6 + 8) = v9; /*0x137747*/
      if ( !ku_sendto_mbuf(*a1, v6, a1 + 4) ) /*0x137759*/
        v12 = 1; /*0x137765*/
    }
    else
    {
      printf("svckudp_send: xdr_replymsg failed\n");
      m_freem(v6); /*0x13777b*/
    }
    v10 = *(void (__stdcall ***)(_DWORD))(v2 + 44); /*0x137783*/
    if ( v10 ) /*0x137788*/
      (*v10)(*(_DWORD *)(v2 + 44)); /*0x13778d*/
  }
  else
  {
    v7 = *(_DWORD *)v2; /*0x1376f4*/
    v8 = *(_DWORD *)v2; /*0x1376f6*/
    LOBYTE(v8) = *(_DWORD *)v2 & 0xFE; /*0x1376f8*/
    *(_DWORD *)v2 = v8; /*0x1376fb*/
    if ( (v7 & 2) != 0 ) /*0x1376ff*/
    {
      LOBYTE(v7) = v7 & 0xFC; /*0x137705*/
      *(_DWORD *)v2 = v7; /*0x137707*/
      wakeup(v2); /*0x13770a*/
    }
  }
  return v12; /*0x137795*/
}
