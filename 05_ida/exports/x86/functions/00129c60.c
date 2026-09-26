/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x129c60. */
int __cdecl tcp_mss(int a1, unsigned __int16 a2)
{
  int v2; // esi
  int v3; // eax
  int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  int v10; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 32); /*0x129c70*/
  v3 = *(_DWORD *)(v2 + 36); /*0x129c76*/
  if ( !v3 ) /*0x129c7b*/
  {
    if ( *(_DWORD *)(v2 + 12) ) /*0x129c7d*/
    {
      *(_WORD *)(v2 + 40) = 2; /*0x129c83*/
      *(_DWORD *)(v2 + 44) = *(_DWORD *)(v2 + 12); /*0x129c8c*/
      rtalloc((int *)(v2 + 36)); /*0x129c90*/
    }
    v3 = *(_DWORD *)(v2 + 36); /*0x129c98*/
    if ( !v3 ) /*0x129c9d*/
      return tcp_mssdflt; /*0x129c9f*/
  }
  v10 = *(_DWORD *)(v2 + 28); /*0x129cb2*/
  v5 = *(__int16 *)(*(_DWORD *)(v3 + 44) + 10) - 40; /*0x129cb9*/
  if ( v5 > 1024 ) /*0x129cc2*/
    v5 &= 0x7FFFFC00u; /*0x129cc4*/
  if ( !in_localaddr(*(_DWORD *)(v2 + 12)) ) /*0x129cce*/
    v5 = min(v5, tcp_mssdflt); /*0x129ce7*/
  if ( a2 && v5 > a2 ) /*0x129cf6*/
    v5 = a2; /*0x129cf8*/
  if ( v5 < 32 ) /*0x129cfd*/
    v5 = 32; /*0x129cff*/
  if ( v5 < *(unsigned __int16 *)(a1 + 24) || a2 ) /*0x129d12*/
  {
    v6 = *(unsigned __int16 *)(v10 + 62); /*0x129d17*/
    if ( v6 >= v5 ) /*0x129d1d*/
    {
      v7 = min(v6, 0xFFFFu); /*0x129d2a*/
      sbreserve(v10 + 60, v5 * (v7 / v5)); /*0x129d3e*/
    }
    else
    {
      v5 = *(unsigned __int16 *)(v10 + 62); /*0x129d1f*/
    }
    *(_WORD *)(a1 + 24) = v5; /*0x129d49*/
    v8 = *(unsigned __int16 *)(v10 + 38); /*0x129d50*/
    if ( v8 > v5 ) /*0x129d56*/
    {
      v9 = min(v8, 0xFFFFu); /*0x129d5e*/
      sbreserve(v10 + 36, v5 * (v9 / v5)); /*0x129d72*/
    }
  }
  *(_WORD *)(a1 + 84) = v5; /*0x129d7a*/
  return v5; /*0x129d83*/
}
