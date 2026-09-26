/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134fe4. */
_BOOL4 __cdecl authkern_marshal(int *a1, XDR *a2)
{
  int v2; // eax
  __int16 *v3; // edi
  unsigned int v4; // esi
  size_t v5; // eax
  int32_t *v6; // ebx
  _DWORD *v7; // ebx
  char *v8; // ebx
  size_t v9; // eax
  char *v10; // ebx
  _DWORD *v11; // ebx
  unsigned int i; // eax
  char *v14; // esi
  _BOOL4 v15; // ebx
  unsigned int v16; // [esp+Ch] [ebp-28h]
  unsigned int v17; // [esp+14h] [ebp-20h] BYREF
  XDR v18; // [esp+1Ch] [ebp-18h] BYREF

  v2 = *(_DWORD *)(active_u + 28); /*0x134ff2*/
  v3 = (__int16 *)(v2 + 10); /*0x134ff5*/
  v4 = v2 + 42; /*0x134ff8*/
  if ( v2 + 42 > (unsigned int)(v2 + 10) ) /*0x134ffd*/
  {
    do /*0x135010*/
    {
      if ( *(_WORD *)(v4 - 2) != 0xFFFF ) /*0x135009*/
        break; /*0x135009*/
      v4 -= 2; /*0x13500b*/
    }
    while ( v4 > (unsigned int)v3 ); /*0x135010*/
  }
  v5 = hostnamelen + 3; /*0x135023*/
  if ( (int)(hostnamelen + 3) < 0 ) /*0x135028*/
    v5 = hostnamelen + 6; /*0x13502a*/
  LOBYTE(v5) = v5 & 0xFC; /*0x13502d*/
  v16 = v5 + 4 * ((int)(v4 - (_DWORD)v3) >> 1) + 20; /*0x135033*/
  v6 = a2->x_ops->x_inline(a2, v5 + 4 * ((int)(v4 - (_DWORD)v3) >> 1) + 36); /*0x135048*/
  if ( v6 )
  {
    getthetime(&v17); /*0x135059*/
    *v6 = _byteswap_ulong(1u); /*0x135068*/
    v7 = v6 + 1; /*0x13506a*/
    *v7++ = _byteswap_ulong(v16); /*0x135072*/
    *v7++ = _byteswap_ulong(v17); /*0x13507c*/
    *v7 = _byteswap_ulong(hostnamelen); /*0x135088*/
    v8 = (char *)(v7 + 1); /*0x13508a*/
    bcopy(hostname, v8, hostnamelen); /*0x13509a*/
    v9 = hostnamelen + 3; /*0x1350a5*/
    if ( (int)(hostnamelen + 3) < 0 ) /*0x1350aa*/
      v9 = hostnamelen + 6; /*0x1350ac*/
    LOBYTE(v9) = v9 & 0xFC; /*0x1350af*/
    v10 = &v8[v9]; /*0x1350b1*/
    *(_DWORD *)v10 = _byteswap_ulong(*(__int16 *)(*(_DWORD *)(active_u + 28) + 2)); /*0x1350c1*/
    v10 += 4; /*0x1350c3*/
    *(_DWORD *)v10 = _byteswap_ulong(*(__int16 *)(*(_DWORD *)(active_u + 28) + 4)); /*0x1350d4*/
    v11 = v10 + 4; /*0x1350d6*/
    for ( i = (int)(v4 - (_DWORD)v3) >> 1; ; i = *v3++ ) /*0x1350d9*/
    {
      *v11++ = _byteswap_ulong(i); /*0x1350e8*/
      if ( (unsigned int)v3 >= v4 ) /*0x1350ef*/
        break; /*0x1350ef*/
    }
    *v11 = _byteswap_ulong(0); /*0x1350f5*/
    v11[1] = _byteswap_ulong(0); /*0x1350fe*/
    return 1; /*0x135100*/
  }
  else
  {
    v14 = (char *)kalloc(0x190u); /*0x135116*/
    xdrmem_create(&v18, v14, 0x190u, XDR_ENCODE); /*0x135124*/
    if ( xdr_authkern(&v18) )
    {
      a1[2] = v18.x_ops->x_getpostn(&v18); /*0x135154*/
      a1[1] = (int)v14; /*0x135157*/
      v15 = xdr_opaque_auth(a2, a1) && xdr_opaque_auth(a2, a1 + 3); /*0x135182*/
    }
    else
    {
      printf("authkern_marshal: xdr_authkern failed\n");
      v15 = 0; /*0x135140*/
    }
    kfree((int)v14, 0x190u); /*0x135194*/
    return v15; /*0x135199*/
  }
}
