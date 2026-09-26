/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1373a0. */
int __cdecl _svcauth_unix(int a1, int a2)
{
  authunix_parms *v2; // edi
  unsigned int *v3; // eax
  char *v4; // ebx
  size_t v5; // eax
  unsigned int *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int *v10; // ebx
  int v11; // esi
  int v12; // ebx
  int i; // ecx
  unsigned int v14; // eax
  int v16; // [esp+10h] [ebp-24h]
  size_t v17; // [esp+10h] [ebp-24h]
  unsigned int v18; // [esp+14h] [ebp-20h]
  XDR v19; // [esp+1Ch] [ebp-18h] BYREF

  v2 = *(authunix_parms **)(a1 + 24); /*0x1373af*/
  v2->aup_machname = (char *)&v2[1]; /*0x1373b8*/
  v2->aup_gids = (int *)&v2[11].aup_len; /*0x1373c1*/
  v18 = *(_DWORD *)(a2 + 32); /*0x1373c7*/
  xdrmem_create(&v19, *(char **)(a2 + 28), v18, XDR_DECODE); /*0x1373d5*/
  v3 = (unsigned int *)v19.x_ops->x_inline(&v19, v18); /*0x1373e5*/
  if ( !v3 ) /*0x1373ee*/
  {
    if ( !xdr_authunix_parms(&v19, v2) ) /*0x1374c1*/
    {
      v19.x_op = XDR_FREE; /*0x1374cd*/
      xdr_authunix_parms(&v19, v2); /*0x1374d9*/
      v12 = 1; /*0x1374de*/
      goto LABEL_14; /*0x1374e6*/
    }
    goto LABEL_13; /*0x1374cb*/
  }
  v2->aup_time = _byteswap_ulong(*v3); /*0x1373fb*/
  v4 = (char *)(v3 + 2); /*0x1373ff*/
  v16 = _byteswap_ulong(v3[1]); /*0x137404*/
  if ( v16 <= 255 ) /*0x13740c*/
  {
    bcopy(v4, v2->aup_machname, v16); /*0x137417*/
    v2->aup_machname[v16] = 0; /*0x137422*/
    v5 = v16 + 3; /*0x137429*/
    if ( v16 + 3 < 0 ) /*0x13742c*/
      v5 = v16 + 6; /*0x137431*/
    LOBYTE(v5) = v5 & 0xFC; /*0x137434*/
    v17 = v5; /*0x137436*/
    v6 = (unsigned int *)&v4[v5]; /*0x137439*/
    v7 = *v6++; /*0x13743b*/
    v2->aup_uid = _byteswap_ulong(v7); /*0x137445*/
    v8 = *v6++; /*0x137448*/
    v2->aup_gid = _byteswap_ulong(v8); /*0x13744f*/
    v9 = *v6; /*0x137452*/
    v10 = v6 + 1; /*0x137454*/
    v11 = _byteswap_ulong(v9); /*0x137459*/
    if ( v11 <= 16 ) /*0x13745e*/
    {
      v2->aup_len = v11; /*0x13746c*/
      for ( i = 0; i < v11; ++i ) /*0x137473*/
      {
        v14 = *v10++; /*0x137478*/
        v2->aup_gids[i] = _byteswap_ulong(v14); /*0x13748b*/
      }
      if ( v18 < v17 + 4 * v11 + 20 ) /*0x13749d*/
      {
        printf("bad auth_len gid %d str %d auth %d", v11, v18, v18); /*0x1374aa*/
        v12 = 1; /*0x1374af*/
        goto LABEL_14; /*0x1374b7*/
      }
LABEL_13:
      *(_DWORD *)(*(_DWORD *)(a1 + 28) + 32) = 0; /*0x1374e8*/
      *(_DWORD *)(*(_DWORD *)(a1 + 28) + 40) = 0; /*0x1374f8*/
      v12 = 0; /*0x1374ff*/
      goto LABEL_14; /*0x1374ff*/
    }
  }
  v12 = 1; /*0x137460*/
LABEL_14:
  ((void (__stdcall *)(XDR *))v19.x_ops->x_destroy)(&v19); /*0x137501*/
  return v12; /*0x137512*/
}
