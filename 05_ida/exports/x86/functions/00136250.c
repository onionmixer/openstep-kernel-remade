/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136250. */
int __cdecl xdr_callmsg(XDR *a1, rpc_msg *a2)
{
  unsigned int oa_length; // edx
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // eax
  int32_t *v6; // ebx
  _DWORD *v7; // ebx
  _DWORD *v8; // ebx
  _DWORD *v9; // ebx
  _DWORD *v10; // ebx
  _DWORD *v11; // ebx
  unsigned int v12; // eax
  _DWORD *v13; // ebx
  void *v14; // ebx
  unsigned int *v15; // eax
  unsigned int *v16; // ebx
  msg_type v17; // eax
  unsigned int v18; // eax
  unsigned int *v19; // ebx
  unsigned __int32 v20; // eax
  unsigned int v21; // eax
  unsigned int *v22; // ebx
  unsigned int v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  unsigned int v26; // edx
  int32_t *v27; // eax
  unsigned int *v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // edx
  int32_t *v32; // eax

  if ( a1->x_op == XDR_ENCODE ) /*0x13625f*/
  {
    oa_length = a2->ru.RM_cmb.cb_cred.oa_length; /*0x136268*/
    if ( oa_length > 0x190 ) /*0x136271*/
      return 0; /*0x136271*/
    v3 = a2->ru.RM_cmb.cb_verf.oa_length; /*0x136277*/
    if ( v3 > 0x190 ) /*0x13627f*/
      return 0; /*0x13627f*/
    v4 = oa_length + 3; /*0x13628e*/
    LOBYTE(v4) = v4 & 0xFC; /*0x136291*/
    v5 = v3 + 3; /*0x136294*/
    LOBYTE(v5) = v5 & 0xFC; /*0x136297*/
    v6 = a1->x_ops->x_inline(a1, v4 + v5 + 40); /*0x1362aa*/
    if ( v6 ) /*0x1362b1*/
    {
      *v6 = _byteswap_ulong(a2->rm_xid); /*0x1362bb*/
      v7 = v6 + 1; /*0x1362bd*/
      *v7 = _byteswap_ulong(a2->rm_direction); /*0x1362c5*/
      v8 = v7 + 1; /*0x1362c7*/
      if ( a2->rm_direction == CALL ) /*0x1362ca*/
      {
        *v8 = _byteswap_ulong(a2->ru.RM_cmb.cb_rpcvers); /*0x1362d9*/
        v9 = v8 + 1; /*0x1362db*/
        if ( a2->ru.RM_cmb.cb_rpcvers == 2 ) /*0x1362e2*/
        {
          *v9 = _byteswap_ulong(a2->ru.RM_cmb.cb_prog); /*0x1362ed*/
          v10 = v9 + 1; /*0x1362ef*/
          *v10++ = _byteswap_ulong(a2->ru.RM_cmb.cb_vers); /*0x1362f7*/
          *v10++ = _byteswap_ulong(a2->ru.RM_cmb.cb_proc); /*0x136301*/
          *v10++ = _byteswap_ulong(a2->ru.RM_cmb.cb_cred.oa_flavor); /*0x13630b*/
          *v10 = _byteswap_ulong(a2->ru.RM_cmb.cb_cred.oa_length); /*0x136315*/
          v11 = v10 + 1; /*0x136317*/
          if ( a2->ru.RM_cmb.cb_cred.oa_length ) /*0x13631a*/
          {
            bcopy(a2->ru.RM_cmb.cb_cred.oa_base, v11, a2->ru.RM_cmb.cb_cred.oa_length); /*0x136327*/
            v12 = a2->ru.RM_cmb.cb_cred.oa_length + 3; /*0x13632f*/
            LOBYTE(v12) = v12 & 0xFC; /*0x136332*/
            v11 = (_DWORD *)((char *)v11 + v12); /*0x136334*/
          }
          *v11 = _byteswap_ulong(a2->ru.RM_cmb.cb_verf.oa_flavor); /*0x13633e*/
          v13 = v11 + 1; /*0x136340*/
          *v13 = _byteswap_ulong(a2->ru.RM_cmb.cb_verf.oa_length); /*0x136348*/
          v14 = v13 + 1; /*0x13634a*/
          if ( a2->ru.RM_cmb.cb_verf.oa_length ) /*0x13634d*/
            bcopy(a2->ru.RM_cmb.cb_verf.oa_base, v14, a2->ru.RM_cmb.cb_verf.oa_length); /*0x13635e*/
          return 1; /*0x13635e*/
        }
      }
      return 0; /*0x13643b*/
    }
  }
  if ( a1->x_op == XDR_DECODE ) /*0x13636a*/
  {
    v15 = (unsigned int *)a1->x_ops->x_inline(a1, 32); /*0x136379*/
    if ( v15 ) /*0x136382*/
    {
      a2->rm_xid = _byteswap_ulong(*v15); /*0x13638f*/
      v16 = v15 + 2; /*0x136393*/
      v17 = _byteswap_ulong(v15[1]); /*0x136396*/
      a2->rm_direction = v17; /*0x136398*/
      if ( v17 ) /*0x13639d*/
        return 0; /*0x13639d*/
      v18 = *v16; /*0x1363a3*/
      v19 = v16 + 1; /*0x1363a5*/
      v20 = _byteswap_ulong(v18); /*0x1363a8*/
      a2->ru.RM_cmb.cb_rpcvers = v20; /*0x1363aa*/
      if ( v20 != 2 ) /*0x1363b0*/
        return 0; /*0x1363b0*/
      v21 = *v19; /*0x1363b6*/
      v22 = v19 + 1; /*0x1363b8*/
      a2->ru.RM_cmb.cb_prog = _byteswap_ulong(v21); /*0x1363bd*/
      v23 = *v22++; /*0x1363c0*/
      a2->ru.RM_cmb.cb_vers = _byteswap_ulong(v23); /*0x1363c7*/
      v24 = *v22++; /*0x1363ca*/
      a2->ru.RM_cmb.cb_proc = _byteswap_ulong(v24); /*0x1363d1*/
      a2->ru.RM_cmb.cb_cred.oa_flavor = _byteswap_ulong(*v22); /*0x1363db*/
      v25 = _byteswap_ulong(v22[1]); /*0x1363e0*/
      a2->ru.RM_cmb.cb_cred.oa_length = v25; /*0x1363e2*/
      if ( v25 ) /*0x1363e7*/
      {
        if ( v25 > 0x190 ) /*0x1363ee*/
          return 0; /*0x1363ee*/
        if ( !a2->ru.RM_rmb.ru.RP_ar.ru.AR_versions.low ) /*0x1363f0*/
          a2->ru.RM_rmb.ru.RP_ar.ru.AR_versions.low = kalloc(v25); /*0x1363fc*/
        v26 = a2->ru.RM_cmb.cb_cred.oa_length + 3; /*0x13640b*/
        LOBYTE(v26) = v26 & 0xFC; /*0x13640e*/
        v27 = a1->x_ops->x_inline(a1, v26); /*0x136416*/
        if ( v27 ) /*0x13641f*/
        {
          bcopy(v27, a2->ru.RM_cmb.cb_cred.oa_base, a2->ru.RM_cmb.cb_cred.oa_length); /*0x136449*/
        }
        else if ( !xdr_opaque(a1, a2->ru.RM_cmb.cb_cred.oa_base, a2->ru.RM_cmb.cb_cred.oa_length) ) /*0x13642d*/
        {
          return 0; /*0x136437*/
        }
      }
      v29 = (unsigned int *)a1->x_ops->x_inline(a1, 8); /*0x136460*/
      if ( v29 ) /*0x136469*/
      {
        a2->ru.RM_cmb.cb_verf.oa_flavor = _byteswap_ulong(*v29); /*0x13649b*/
        a2->ru.RM_cmb.cb_verf.oa_length = _byteswap_ulong(v29[1]); /*0x1364a2*/
      }
      else if ( !xdr_enum(a1, &a2->ru.RM_cmb.cb_verf.oa_flavor) || !xdr_u_int(a1, &a2->ru.RM_cmb.cb_verf.oa_length) ) /*0x136484*/
      {
        return 0; /*0x13648e*/
      }
      v30 = a2->ru.RM_cmb.cb_verf.oa_length; /*0x1364a5*/
      if ( v30 ) /*0x1364aa*/
      {
        if ( v30 > 0x190 ) /*0x1364b1*/
          return 0; /*0x1364b1*/
        if ( !a2->ru.RM_cmb.cb_verf.oa_base ) /*0x1364b3*/
          a2->ru.RM_cmb.cb_verf.oa_base = (caddr_t)kalloc(a2->ru.RM_cmb.cb_verf.oa_length); /*0x1364bf*/
        v31 = a2->ru.RM_cmb.cb_verf.oa_length + 3; /*0x1364ce*/
        LOBYTE(v31) = v31 & 0xFC; /*0x1364d1*/
        v32 = a1->x_ops->x_inline(a1, v31); /*0x1364d9*/
        if ( v32 ) /*0x1364e2*/
        {
          bcopy(v32, a2->ru.RM_cmb.cb_verf.oa_base, a2->ru.RM_cmb.cb_verf.oa_length); /*0x136509*/
        }
        else if ( !xdr_opaque(a1, a2->ru.RM_cmb.cb_verf.oa_base, a2->ru.RM_cmb.cb_verf.oa_length) ) /*0x1364f0*/
        {
          return 0; /*0x1364f7*/
        }
      }
      return 1; /*0x136513*/
    }
  }
  if ( xdr_u_long(a1, &a2->rm_xid) /*0x1365a5*/
    && xdr_enum(a1, (int *)&a2->rm_direction)
    && a2->rm_direction == CALL
    && xdr_u_long(a1, &a2->ru.RM_cmb.cb_rpcvers)
    && a2->ru.RM_cmb.cb_rpcvers == 2
    && xdr_u_long(a1, &a2->ru.RM_cmb.cb_prog)
    && xdr_u_long(a1, &a2->ru.RM_cmb.cb_vers)
    && xdr_u_long(a1, &a2->ru.RM_cmb.cb_proc)
    && xdr_opaque_auth(a1, &a2->ru.RM_cmb.cb_cred.oa_flavor) )
  {
    return xdr_opaque_auth(a1, &a2->ru.RM_cmb.cb_verf.oa_flavor); /*0x1365b9*/
  }
  else
  {
    return 0; /*0x1365c0*/
  }
}
