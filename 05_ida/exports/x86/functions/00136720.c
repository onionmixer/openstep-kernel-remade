/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136720. */
int __cdecl xdr_replymsg(XDR *a1, rpc_msg *a2)
{
  int32_t *v2; // ebx
  _DWORD *v3; // ebx
  _DWORD *v4; // ebx
  unsigned __int32 v5; // eax
  int oa_flavor; // eax
  unsigned int *v8; // eax
  unsigned int *v9; // ebx
  msg_type v10; // eax
  unsigned __int32 v11; // eax
  unsigned __int32 cb_prog; // eax
  unsigned int *v13; // eax
  unsigned __int32 cb_proc; // eax
  unsigned int v15; // edx
  int32_t *v16; // eax
  int v17; // eax
  int v18; // [esp+0h] [ebp-14h]
  int v19; // [esp+4h] [ebp-10h]
  int v20; // [esp+8h] [ebp-Ch]
  int v21; // [esp+Ch] [ebp-8h]
  int savedregs; // [esp+14h] [ebp+0h]

  if ( a1->x_op == XDR_ENCODE && !a2->ru.RM_cmb.cb_rpcvers && a2->rm_direction == REPLY ) /*0x136746*/
  {
    v2 = a1->x_ops->x_inline(a1, a2->ru.RM_cmb.cb_proc + 24); /*0x13675c*/
    if ( v2 ) /*0x136763*/
    {
      *v2 = _byteswap_ulong(a2->rm_xid); /*0x13676d*/
      v3 = v2 + 1; /*0x13676f*/
      *v3++ = _byteswap_ulong(a2->rm_direction); /*0x136777*/
      *v3++ = _byteswap_ulong(a2->ru.RM_cmb.cb_rpcvers); /*0x136781*/
      *v3++ = _byteswap_ulong(a2->ru.RM_cmb.cb_prog); /*0x13678b*/
      *v3 = _byteswap_ulong(a2->ru.RM_cmb.cb_proc); /*0x136795*/
      v4 = v3 + 1; /*0x136797*/
      if ( a2->ru.RM_cmb.cb_proc ) /*0x13679a*/
      {
        bcopy(a2->ru.RM_rmb.ru.RP_ar.ar_verf.oa_base, v4, a2->ru.RM_cmb.cb_proc); /*0x1367a7*/
        v5 = a2->ru.RM_cmb.cb_proc + 3; /*0x1367af*/
        LOBYTE(v5) = v5 & 0xFC; /*0x1367b2*/
        v4 = (_DWORD *)((char *)v4 + v5); /*0x1367b4*/
      }
      *v4 = _byteswap_ulong(a2->ru.RM_cmb.cb_cred.oa_flavor); /*0x1367be*/
      oa_flavor = a2->ru.RM_cmb.cb_cred.oa_flavor; /*0x1367c0*/
      if ( !oa_flavor ) /*0x1367c5*/
        return ((int (__cdecl *)(XDR *, unsigned __int32))a2->ru.RM_cmb.cb_cred.oa_length)( /*0x1367e1*/
                 a1,
                 a2->ru.RM_rmb.ru.RP_ar.ru.AR_versions.low);
      if ( oa_flavor != 2 ) /*0x1367ca*/
        return 1; /*0x136a15*/
      if ( xdr_u_long(a1, &a2->ru.RM_rmb.ru.RP_ar.ru.AR_versions.low) ) /*0x1367f0*/
        return xdr_u_long(a1, &a2->ru.RM_cmb.cb_cred.oa_length); /*0x13680d*/
      return 0; /*0x1367fa*/
    }
  }
  if ( a1->x_op == XDR_DECODE ) /*0x13681a*/
  {
    v8 = (unsigned int *)a1->x_ops->x_inline(a1, 12); /*0x136829*/
    if ( v8 ) /*0x136832*/
    {
      a2->rm_xid = _byteswap_ulong(*v8); /*0x13683f*/
      v9 = v8 + 2; /*0x136843*/
      v10 = _byteswap_ulong(v8[1]); /*0x136846*/
      a2->rm_direction = v10; /*0x136848*/
      if ( v10 == REPLY ) /*0x13684e*/
      {
        v11 = _byteswap_ulong(*v9); /*0x136856*/
        a2->ru.RM_cmb.cb_rpcvers = v11; /*0x136858*/
        if ( v11 ) /*0x13685d*/
        {
          if ( v11 == 1 && xdr_enum(a1, &a2->ru.RM_rmb.ru.RP_ar.ar_verf.oa_flavor) ) /*0x136870*/
          {
            cb_prog = a2->ru.RM_cmb.cb_prog; /*0x136880*/
            if ( cb_prog ) /*0x136885*/
            {
              if ( cb_prog == 1 ) /*0x13688a*/
                return xdr_enum(a1, (int *)&a2->ru.RM_cmb.cb_vers); /*0x1368cd*/
            }
            else if ( xdr_u_long(a1, &a2->ru.RM_cmb.cb_vers) ) /*0x13689c*/
            {
              return xdr_u_long(a1, &a2->ru.RM_cmb.cb_proc); /*0x1368b9*/
            }
          }
          return 0; /*0x13688a*/
        }
        v13 = (unsigned int *)a1->x_ops->x_inline(a1, 8); /*0x1368e9*/
        if ( v13 ) /*0x1368f2*/
        {
          a2->ru.RM_cmb.cb_prog = _byteswap_ulong(*v13); /*0x1368fb*/
          a2->ru.RM_cmb.cb_proc = _byteswap_ulong(v13[1]); /*0x136902*/
        }
        else if ( !xdr_enum(a1, &a2->ru.RM_rmb.ru.RP_ar.ar_verf.oa_flavor) || !xdr_u_int(a1, &a2->ru.RM_cmb.cb_proc) ) /*0x136924*/
        {
          return 0; /*0x13692e*/
        }
        cb_proc = a2->ru.RM_cmb.cb_proc; /*0x136930*/
        if ( cb_proc ) /*0x136935*/
        {
          if ( cb_proc > 0x190 ) /*0x13693c*/
            return 0; /*0x13693c*/
          if ( !a2->ru.RM_cmb.cb_vers ) /*0x13693e*/
            a2->ru.RM_cmb.cb_vers = kalloc(a2->ru.RM_cmb.cb_proc); /*0x13694a*/
          v15 = a2->ru.RM_cmb.cb_proc + 3; /*0x136959*/
          LOBYTE(v15) = v15 & 0xFC; /*0x13695c*/
          v16 = a1->x_ops->x_inline(a1, v15); /*0x136964*/
          if ( v16 ) /*0x13696d*/
          {
            bcopy(v16, a2->ru.RM_rmb.ru.RP_ar.ar_verf.oa_base, a2->ru.RM_cmb.cb_proc); /*0x136999*/
          }
          else if ( !xdr_opaque(a1, a2->ru.RM_rmb.ru.RP_ar.ar_verf.oa_base, a2->ru.RM_cmb.cb_proc) ) /*0x13697b*/
          {
            return 0; /*0x136985*/
          }
        }
        if ( xdr_enum(a1, &a2->ru.RM_cmb.cb_cred.oa_flavor) ) /*0x1369ac*/
        {
          v17 = a2->ru.RM_cmb.cb_cred.oa_flavor; /*0x1369bb*/
          if ( !v17 ) /*0x1369c0*/
            return ((int (__stdcall *)(XDR *, unsigned __int32, int, int, int, int, reply_body::$B1794D2A0DAD208A76987CA2B117700C *, int))a2->ru.RM_cmb.cb_cred.oa_length)( /*0x1369df*/
                     a1,
                     a2->ru.RM_rmb.ru.RP_ar.ru.AR_versions.low,
                     v18,
                     v19,
                     v20,
                     v21,
                     &a2->ru.RM_rmb.ru,
                     savedregs);
          if ( v17 != 2 ) /*0x1369c5*/
            return 1; /*0x1369c5*/
          if ( xdr_u_long(a1, &a2->ru.RM_rmb.ru.RP_ar.ru.AR_versions.low) ) /*0x1369ef*/
            return xdr_u_long(a1, &a2->ru.RM_cmb.cb_cred.oa_length); /*0x1369f9*/
        }
      }
      return 0; /*0x136989*/
    }
  }
  if ( xdr_u_long(a1, &a2->rm_xid) && xdr_enum(a1, (int *)&a2->rm_direction) && a2->rm_direction == REPLY ) /*0x136a41*/
    return xdr_union(a1, (int *)&a2->ru, (char *)&a2->ru.RM_rmb.ru, &stru_1DD140, nullptr); /*0x136a56*/
  else
    return 0; /*0x136a60*/
}
