/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1370b4. */
void __cdecl svc_getreq(int a1)
{
  auth_stat v1; // eax
  unsigned int v2; // ebx
  int i; // edx
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v6; // [esp+Ch] [ebp-9Ch]
  int v7; // [esp+10h] [ebp-98h]
  unsigned __int32 v8; // [esp+24h] [ebp-84h]
  char v9[4]; // [esp+28h] [ebp-80h] BYREF
  int v10; // [esp+2Ch] [ebp-7Ch]
  int v11; // [esp+30h] [ebp-78h]
  int v12; // [esp+34h] [ebp-74h]
  auth_stat v13; // [esp+38h] [ebp-70h]
  int v14; // [esp+3Ch] [ebp-6Ch]
  int v15; // [esp+40h] [ebp-68h]
  unsigned int v16; // [esp+44h] [ebp-64h]
  unsigned int v17; // [esp+48h] [ebp-60h]
  svc_req v18; // [esp+58h] [ebp-50h] BYREF
  rpc_msg v19; // [esp+78h] [ebp-30h] BYREF

  if ( rqcred_head ) /*0x1370ca*/
  {
    v8 = rqcred_head; /*0x1370cc*/
    rqcred_head = *(_DWORD *)rqcred_head; /*0x1370d4*/
  }
  else
  {
    v8 = kalloc(0x4B0u); /*0x1370f6*/
  }
  v19.ru.RM_rmb.ru.RP_ar.ru.AR_versions.low = v8; /*0x137105*/
  v19.ru.RM_cmb.cb_verf.oa_base = (caddr_t)(v8 + 400); /*0x13710e*/
  v18.rq_clntcred = (caddr_t)(v8 + 800); /*0x13711d*/
  while ( 1 ) /*0x137134*/
  {
    if ( !(**(int (__cdecl ***)(int, rpc_msg *))(a1 + 8))(a1, &v19) ) /*0x137148*/
      goto LABEL_22; /*0x137148*/
    v18.rq_xprt = (SVCXPRT *)a1; /*0x13714e*/
    *(_QWORD *)&v18.rq_prog = *(_QWORD *)&v19.ru.RM_rmb.ru.RP_ar.ar_verf.oa_flavor; /*0x137154*/
    *(rejected_reply::$6C15D86E9FF71BEC28C6FBB4951D0AF6 *)&v18.rq_proc = *(rejected_reply::$6C15D86E9FF71BEC28C6FBB4951D0AF6 *)((char *)&v19.ru.RM_rmb.ru.RP_dr.ru + 4); /*0x137160*/
    *(_QWORD *)&v18.rq_cred.oa_base = *((_QWORD *)&v19.ru.RM_rmb.ru.RP_dr + 2); /*0x13716c*/
    v1 = _authenticate(&v18, &v19); /*0x137180*/
    if ( v1 ) /*0x13718a*/
    {
      v10 = 1; /*0x13718c*/
      v11 = 1; /*0x137193*/
      v12 = 1; /*0x13719a*/
      v13 = v1; /*0x1371a1*/
      (*(void (__cdecl **)(int, char *))(*(_DWORD *)(a1 + 8) + 12))(a1, v9); /*0x1371b2*/
      goto LABEL_22; /*0x1371b7*/
    }
    v7 = 0; /*0x1371bc*/
    v6 = -1; /*0x1371c6*/
    v2 = 0; /*0x1371d0*/
    for ( i = dword_1E5A1C; i; i = *(_DWORD *)i ) /*0x1371da*/
    {
      if ( *(_DWORD *)(i + 4) == v18.rq_prog ) /*0x1371f9*/
      {
        v4 = *(_DWORD *)(i + 8); /*0x1371fb*/
        if ( v18.rq_vers == v4 ) /*0x137204*/
        {
          (*(void (__cdecl **)(svc_req *, int))(i + 12))(&v18, a1); /*0x137270*/
          goto LABEL_22; /*0x137275*/
        }
        v7 = 1; /*0x137206*/
        if ( v6 > v4 ) /*0x137216*/
          v6 = *(_DWORD *)(i + 8); /*0x137218*/
        if ( v4 > v2 ) /*0x137220*/
          v2 = *(_DWORD *)(i + 8); /*0x137222*/
      }
    }
    v10 = 1; /*0x137233*/
    v11 = 0; /*0x13723a*/
    v12 = *(_DWORD *)(a1 + 32); /*0x137244*/
    v13 = *(_DWORD *)(a1 + 36); /*0x13724a*/
    v14 = *(_DWORD *)(a1 + 40); /*0x137250*/
    if ( v7 ) /*0x137231*/
    {
      v15 = 2; /*0x137253*/
      v16 = v6; /*0x137260*/
      v17 = v2; /*0x137263*/
    }
    else
    {
      v15 = 1; /*0x137298*/
    }
    (*(void (__cdecl **)(int, char *))(*(_DWORD *)(a1 + 8) + 12))(a1, v9); /*0x1372ad*/
    (*(void (__cdecl **)(int, _DWORD, _DWORD))(*(_DWORD *)(a1 + 8) + 16))(a1, 0, 0); /*0x1372bd*/
LABEL_22:
    v5 = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 8) + 4))(a1); /*0x1372c9*/
    if ( !v5 ) /*0x1372d0*/
      break; /*0x1372d0*/
    if ( v5 != 1 ) /*0x1372d9*/
      goto LABEL_24; /*0x1372d9*/
  }
  (*(void (__stdcall **)(int))(*(_DWORD *)(a1 + 8) + 20))(a1); /*0x1370e3*/
LABEL_24:
  *(_DWORD *)v8 = rqcred_head; /*0x1372df*/
  rqcred_head = v8; /*0x1372ed*/
}
