/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124e60. */
int __cdecl in_pcbbind(int a1, int a2)
{
  int v2; // ebx
  __int16 v3; // si
  int v4; // edi
  __int16 v6; // si
  __int16 v7; // dx
  unsigned __int16 v8; // ax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+14h] [ebp-4h]

  v10 = *(_DWORD *)(a1 + 28); /*0x124e72*/
  v2 = *(_DWORD *)(a1 + 8); /*0x124e78*/
  v3 = 0; /*0x124e7b*/
  if ( !in_ifaddr ) /*0x124e84*/
    return 49; /*0x124e84*/
  if ( *(_WORD *)(a1 + 24) || *(_DWORD *)(a1 + 20) ) /*0x124e90*/
    return 22; /*0x124e94*/
  if ( a2 ) /*0x124e98*/
  {
    v4 = *(_DWORD *)(a2 + 4) + a2; /*0x124ea0*/
    if ( *(_WORD *)(a2 + 8) != 16 ) /*0x124ea8*/
      return 22; /*0x124eaf*/
    if ( *(_DWORD *)(v4 + 4) ) /*0x124eb4*/
    {
      v6 = *(_WORD *)(v4 + 2); /*0x124eba*/
      *(_WORD *)(v4 + 2) = 0; /*0x124ebe*/
      if ( !ifa_ifwithaddr((_WORD *)v4) ) /*0x124ec5*/
        return 49; /*0x124ed6*/
      *(_WORD *)(v4 + 2) = v6; /*0x124edc*/
    }
    v3 = *(_WORD *)(v4 + 2); /*0x124ee0*/
    if ( v3 ) /*0x124ee7*/
    {
      v9 = 0; /*0x124ef3*/
      if ( __ROR2__(v3, 8) <= 0x3FFu && *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) && *(char *)(v10 + 6) >= 0 ) /*0x124f16*/
        return 13; /*0x124f1d*/
      v7 = *(_WORD *)(v10 + 2); /*0x124f27*/
      if ( (v7 & 4) == 0 && ((*(_BYTE *)(*(_DWORD *)(v10 + 12) + 10) & 4) == 0 || (v7 & 2) == 0) ) /*0x124f43*/
        v9 = 1; /*0x124f45*/
      if ( in_pcblookup(v2, zeroin_addr, 0, *(_DWORD *)(v4 + 4), v3, v9) ) /*0x124f62*/
        return 48; /*0x124f73*/
    }
    *(_DWORD *)(a1 + 20) = *(_DWORD *)(v4 + 4); /*0x124f7e*/
  }
  if ( !v3 ) /*0x124f84*/
  {
    do /*0x124fc5*/
    {
      v8 = *(_WORD *)(v2 + 24); /*0x124f88*/
      *(_WORD *)(v2 + 24) = v8 + 1; /*0x124f8c*/
      if ( v8 <= 0x9FFu || *(_WORD *)(v2 + 24) > 0x1388u ) /*0x124f9c*/
        *(_WORD *)(v2 + 24) = 2560; /*0x124f9e*/
      v3 = __ROR2__(*(_WORD *)(v2 + 24), 8); /*0x124fac*/
    }
    while ( in_pcblookup(v2, zeroin_addr, 0, *(_DWORD *)(a1 + 20), v3, 0) ); /*0x124fc5*/
  }
  *(_WORD *)(a1 + 24) = v3; /*0x124fd4*/
  return 0; /*0x124fdd*/
}
