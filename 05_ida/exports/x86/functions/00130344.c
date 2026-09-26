/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x130344. */
int sub_130344()
{
  int v1; // esi
  int v2; // edi
  unsigned int v3; // esi
  int v4; // ebx
  unsigned int v5; // kr04_4
  unsigned int v6; // kr08_4
  int v7; // [esp+14h] [ebp-84h]
  int v8; // [esp+18h] [ebp-80h]
  char v9; // [esp+20h] [ebp-78h] BYREF
  _DWORD v10[4]; // [esp+24h] [ebp-74h] BYREF
  _DWORD v11[6]; // [esp+34h] [ebp-64h] BYREF
  int v12; // [esp+4Ch] [ebp-4Ch] BYREF
  _DWORD v13[4]; // [esp+50h] [ebp-48h] BYREF
  _BYTE v14[4]; // [esp+60h] [ebp-38h] BYREF
  int v15; // [esp+64h] [ebp-34h]
  void *v16; // [esp+70h] [ebp-28h] BYREF
  void *v17; // [esp+74h] [ebp-24h]
  int v18; // [esp+80h] [ebp-18h] BYREF
  _BYTE v19[4]; // [esp+84h] [ebp-14h] BYREF
  _BYTE v20[2]; // [esp+88h] [ebp-10h] BYREF
  __int16 v21; // [esp+8Ah] [ebp-Eh]

  if ( dword_1DC76C ) /*0x130357*/
    return 0; /*0x13035b*/
  dword_1DC76C = 1; /*0x130360*/
  bzero(v20, 0x10u); /*0x130376*/
  v1 = ifb_ifwithaf(); /*0x130382*/
  if ( !v1 )
  {
    printf("whoami: zero ifp\n");
    return 65; /*0x13039a*/
  }
  if ( initrootnet() ) /*0x1303a0*/
    panic(aWhoamiInitroot); /*0x1303ae*/
  v7 = in_control(0, -1071617774, v13, v1); /*0x1303c7*/
  if ( v7 )
  {
    printf("whoami: in_control 0x%x if_flags 0x%x\n", v7, *(__int16 *)(v1 + 12));
    panic(aBadSiocgifbrda); /*0x1303ef*/
  }
  bcopy(v14, v20, 0x10u); /*0x130404*/
  bcopy(v14, &unk_1E59D8, 0x10u); /*0x130411*/
  v18 = 1; /*0x130416*/
  if ( in_control(0, -1071617779, v13, v1) ) /*0x130426*/
    panic(aBadSiocgifaddr); /*0x130439*/
  v12 = v15; /*0x130444*/
  bcopy(&v12, v19, 4u); /*0x130451*/
  v8 = 3; /*0x130456*/
  v16 = (void *)kalloc(0x100u); /*0x130470*/
  v17 = (void *)kalloc(0x100u); /*0x13047f*/
  v2 = 0; /*0x130482*/
  do
  {
    v21 = __ROR2__(111, 8); /*0x13049d*/
    v3 = clntkudp_create(v20, 100000, 2, 5, *(_DWORD *)(active_u + 28)); /*0x1304c0*/
    if ( !v3 ) /*0x1304c7*/
      panic(aPmapRmtcallCln); /*0x1304ce*/
    v11[0] = 100026; /*0x1304d6*/
    v11[1] = 1; /*0x1304dd*/
    v11[2] = 1; /*0x1304e4*/
    v11[4] = &v18; /*0x1304ee*/
    v11[5] = xdr_bp_whoami_arg; /*0x1304f1*/
    v10[0] = &v9; /*0x1304fb*/
    v10[2] = &v16; /*0x130501*/
    v10[3] = xdr_bp_whoami_res; /*0x130504*/
    v4 = clntkudp_callit_addr(v3, 5, xdr_rmtcall_args, v11, xdr_rmtcallres, v10, v8, 0, 0); /*0x13052d*/
    (*(void (__cdecl **)(unsigned int))(*(_DWORD *)(v3 + 4) + 16))(v3); /*0x130539*/
    if ( v4 == 5 && !v2 )
    {
      printf("No bootparam server responding; still trying\n"); /*0x13054c*/
      printf("whoami: pmap_rmtcall status 0x%x\n", 5);
      v2 = 1; /*0x13055d*/
    }
    v8 = 20; /*0x130565*/
  }
  while ( v4 == 5 );
  if ( v2 ) /*0x13057e*/
    printf("Bootparam response received\n"); /*0x130585*/
  if ( !v4 )
  {
    v5 = strlen((const char *)v16) + 1; /*0x1305bb*/
    hostnamelen = v5 - 1; /*0x1305c2*/
    if ( v5 - 1 <= 0x100 )
    {
      if ( (int)(v5 - 1) <= 0 )
      {
        printf("whoami: no host name\n");
        v7 = 6; /*0x1305e6*/
        goto LABEL_31; /*0x1305f3*/
      }
      bcopy(v16, hostname, v5 - 1); /*0x1305ff*/
      printf("hostname: %s\n", hostname);
      v6 = strlen((const char *)v17) + 1; /*0x130623*/
      domainnamelen = v6 - 1; /*0x13062a*/
      if ( v6 - 1 <= 0x100 )
      {
        if ( (int)(v6 - 1) > 0 )
        {
          bcopy(v17, domainname, v6 - 1); /*0x13065f*/
          printf("domainname: %s\n", domainname);
        }
        goto LABEL_31; /*0x13066e*/
      }
      printf("whoami: domainname too long");
    }
    else
    {
      printf("whoami: hostname too long");
    }
    v7 = 63; /*0x130645*/
    goto LABEL_31; /*0x130652*/
  }
  v7 = v4; /*0x130591*/
  printf("whoami RPC call failed with status %d\n", v4); /*0x13059d*/
LABEL_31:
  kfree((int)v16, 0x100u); /*0x130676*/
  kfree((int)v17, 0x100u); /*0x13068d*/
  return v7; /*0x13069e*/
}
