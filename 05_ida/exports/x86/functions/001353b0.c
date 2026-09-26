/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1353b0. */
int __cdecl clntkudp_create(int a1, __int64 a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  int *v6; // eax
  int v7; // edi
  int v8; // eax
  int v9; // eax
  _DWORD v11[2]; // [esp+10h] [ebp-38h] BYREF
  rpc_msg v12; // [esp+18h] [ebp-30h] BYREF

  *(_DWORD *)(active_threads + 392) = 1; /*0x1353be*/
  v4 = kalloc(0x78u); /*0x1353cf*/
  bzero((void *)v4, 0x78u); /*0x1353d4*/
  if ( !clntkudpxid ) /*0x1353e9*/
  {
    getthetime(v11); /*0x1353ef*/
    clntkudpxid = v11[1]; /*0x1353f7*/
  }
  *(_DWORD *)(v4 + 8) = &udp_ops; /*0x135400*/
  *(_DWORD *)(v4 + 12) = v4; /*0x135407*/
  *(_DWORD *)(v4 + 4) = authkern_create(); /*0x13540f*/
  v12.rm_xid = 0; /*0x135412*/
  v12.rm_direction = CALL; /*0x135419*/
  v12.ru.RM_cmb.cb_rpcvers = 2; /*0x135420*/
  *(_QWORD *)&v12.ru.RM_rmb.ru.RP_ar.ar_verf.oa_flavor = a2; /*0x13542a*/
  clntkudp_init(v4 + 4, a1, a3, a4); /*0x135443*/
  v5 = kalloc(0x2260u); /*0x13544d*/
  *(_DWORD *)(v4 + 104) = v5; /*0x135452*/
  v6 = mclgetx((int)sub_135D8C, 0, v5, 8800, 1); /*0x135464*/
  v7 = (int)v6; /*0x135469*/
  if ( v6 )
  {
    xdrmbuf_init(v4 + 52, v6, 0); /*0x13547d*/
    if ( xdr_callhdr((XDR *)(v4 + 52), &v12) )
    {
      *(_DWORD *)(v4 + 100) = (*(int (__cdecl **)(int))(*(_DWORD *)(v4 + 56) + 16))(v4 + 52); /*0x1354b1*/
      m_free(v7); /*0x1354b5*/
      v8 = socreate(2, (char **)(v4 + 20), 2, 17); /*0x1354c4*/
      if ( v8 )
      {
        printf("clntkudp_create: socket creation problem, %d", v8);
      }
      else
      {
        v9 = sub_135CB4(*(_DWORD *)(v4 + 20)); /*0x1354dc*/
        if ( !v9 ) /*0x1354e6*/
        {
          *(_DWORD *)(active_threads + 392) = 0; /*0x1354ed*/
          return v4 + 4; /*0x1354fa*/
        }
        printf("clntkudp_create: socket bind problem, %d", v9);
      }
    }
    else
    {
      printf("clntkudp_create - Fatal header serialization error."); /*0x135498*/
      m_freem(v7); /*0x13549e*/
    }
  }
  *(_DWORD *)(active_threads + 392) = 0; /*0x13550f*/
  kfree(*(_DWORD *)(v4 + 104), 0x2260u); /*0x135522*/
  crfree(*(_WORD **)(v4 + 116)); /*0x13552b*/
  kfree(v4, 0x78u); /*0x135533*/
  return 0; /*0x13553d*/
}
