/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125bd0. */
int __cdecl icmp_reflect(int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  _DWORD *v4; // edx
  int result; // eax
  int v6; // [esp+Ch] [ebp-4h]

  v2 = 0; /*0x125bdc*/
  v6 = 4 * (*(_BYTE *)a1 & 0xF) - 20; /*0x125bea*/
  v3 = *(_DWORD *)(a1 + 16); /*0x125bed*/
  *(_DWORD *)(a1 + 16) = *(_DWORD *)(a1 + 12); /*0x125bf3*/
  v4 = (_DWORD *)in_ifaddr; /*0x125bf6*/
  if ( !in_ifaddr ) /*0x125bfe*/
    goto LABEL_7; /*0x125bfe*/
  do /*0x125c18*/
  {
    if ( v4[1] == v3 || (*(_BYTE *)(v4[8] + 12) & 2) != 0 && v4[5] == v3 ) /*0x125c11*/
      break; /*0x125c11*/
    v4 = (_DWORD *)v4[16]; /*0x125c13*/
  }
  while ( v4 ); /*0x125c18*/
  if ( !v4 ) /*0x125c1c*/
  {
LABEL_7:
    v4 = (_DWORD *)ifptoia(a2); /*0x125c27*/
    if ( !v4 ) /*0x125c2e*/
      v4 = (_DWORD *)in_ifaddr; /*0x125c30*/
  }
  *(_DWORD *)(a1 + 12) = v4[1]; /*0x125c39*/
  *(_BYTE *)(a1 + 8) = -1; /*0x125c3c*/
  if ( v6 > 0 ) /*0x125c44*/
  {
    v2 = ip_srcroute(); /*0x125c4b*/
    *(_WORD *)(a1 + 2) -= v6; /*0x125c51*/
    ip_stripoptions(a1, 0); /*0x125c58*/
  }
  result = icmp_send(a1, v2); /*0x125c62*/
  if ( v2 ) /*0x125c6c*/
    return m_free(v2); /*0x125c6f*/
  return result; /*0x125c77*/
}
