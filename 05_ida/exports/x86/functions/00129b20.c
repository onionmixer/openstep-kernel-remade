/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x129b20. */
void __cdecl tcp_pulloutofband(int a1, int a2, int *a3)
{
  int v4; // edi
  int v5; // eax
  _BYTE *v6; // edx
  int v7; // eax

  v4 = *(unsigned __int16 *)(a2 + 38) - 1; /*0x129b33*/
  if ( v4 < 0 ) /*0x129b38*/
LABEL_6:
    panic(aTcpPulloutofba); /*0x129b7c*/
  while ( 1 ) /*0x129b3c*/
  {
    v5 = *((__int16 *)a3 + 4); /*0x129b3c*/
    if ( v5 > v4 ) /*0x129b42*/
      break; /*0x129b42*/
    v4 -= v5; /*0x129b70*/
    a3 = (int *)*a3; /*0x129b72*/
    if ( !a3 || v4 < 0 ) /*0x129b7a*/
      goto LABEL_6; /*0x129b7a*/
  }
  v6 = (char *)a3 + a3[1] + v4; /*0x129b49*/
  v7 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 32); /*0x129b4e*/
  *(_BYTE *)(v7 + 105) = *v6; /*0x129b53*/
  *(_BYTE *)(v7 + 104) |= 1u; /*0x129b56*/
  bcopy(v6 + 1, v6, *((__int16 *)a3 + 4) - v4 - 1); /*0x129b65*/
  --*((_WORD *)a3 + 4); /*0x129b6a*/
}
