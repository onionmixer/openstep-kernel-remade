/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109248. */
int __cdecl setsigvec(int a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  volatile __int32 *v4; // edx
  int v5; // edx
  unsigned int v6; // eax
  volatile __int32 *v7; // edx
  _DWORD *i; // edx
  _DWORD *v10; // [esp+10h] [ebp-4h]

  v2 = 1 << (a1 - 1); /*0x10925c*/
  v3 = *(_DWORD *)active_u; /*0x109263*/
  splhigh(); /*0x109265*/
  v4 = (volatile __int32 *)(v3 + 112); /*0x10926a*/
  do /*0x109282*/
  {
    while ( *v4 ) /*0x109270*/
      ; /*0x109272*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x109282*/
  *(_DWORD *)(active_u + 4 * a1 + 48) = *(_DWORD *)a2; /*0x109291*/
  v5 = *(_DWORD *)(a2 + 4); /*0x1092a1*/
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x1092aa*/
    v6 = v5 & 0xFFFEFEFF; /*0x1092ae*/
  else
    v6 = v5 & 0xFFFAFEFF; /*0x1092ba*/
  *(_DWORD *)(active_u + 4 * a1 + 180) = v6; /*0x1092c5*/
  if ( (*(_BYTE *)(a2 + 8) & 2) != 0 ) /*0x1092d3*/
    *(_DWORD *)(active_u + 320) |= v2; /*0x1092da*/
  else
    *(_DWORD *)(active_u + 320) &= ~v2; /*0x1092ee*/
  if ( (*(_BYTE *)(a2 + 8) & 1) != 0 ) /*0x1092fb*/
    *(_DWORD *)(active_u + 316) |= v2; /*0x109302*/
  else
    *(_DWORD *)(active_u + 316) &= ~v2; /*0x109316*/
  if ( *(_DWORD *)a2 == 1 || (*(_BYTE *)(v3 + 22) & 2) != 0 && !*(_DWORD *)a2 && a1 == 20 ) /*0x109334*/
  {
    *(_DWORD *)(v3 + 24) &= ~v2; /*0x10933a*/
    if ( (v2 & 0x1EF8) != 0 ) /*0x109343*/
    {
      v10 = (_DWORD *)(*(_DWORD *)(v3 + 104) + 28); /*0x10934b*/
      v7 = *(volatile __int32 **)(v3 + 104); /*0x10934e*/
      do /*0x109362*/
      {
        while ( *v7 ) /*0x109350*/
          ; /*0x109352*/
      }
      while ( _InterlockedExchange(v7, 1) == 1 ); /*0x109362*/
      for ( i = (_DWORD *)*v10; v10 != i; i = (_DWORD *)i[4] ) /*0x10936b*/
        *(_DWORD *)(i[33] + 124) &= ~v2; /*0x10937d*/
      _InterlockedExchange(*(volatile __int32 **)(v3 + 104), 0); /*0x10938d*/
    }
    *(_DWORD *)(v3 + 32) |= v2; /*0x10938f*/
    *(_DWORD *)(v3 + 36) &= ~v2; /*0x109396*/
  }
  else
  {
    *(_DWORD *)(v3 + 32) &= ~v2; /*0x1093a0*/
    if ( *(_DWORD *)a2 ) /*0x1093a6*/
    {
      *(_DWORD *)(v3 + 36) |= v2; /*0x1093c8*/
    }
    else
    {
      if ( (*(_BYTE *)(v3 + 22) & 2) != 0 ) /*0x1093af*/
        *(_DWORD *)(active_u + 4 * a1 + 48) = 0; /*0x1093b9*/
      *(_DWORD *)(v3 + 36) &= ~v2; /*0x1093c1*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(v3 + 112), 0); /*0x1093cd*/
  return spl0(); /*0x1093d8*/
}
