/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1d9c. */
int __cdecl sub_1A1D9C(int a1, int a2, __int16 a3)
{
  int *v3; // eax
  int v4; // ecx
  unsigned int v5; // edx
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // edx

  v3 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a1dad*/
  v4 = 0; /*0x1a1db3*/
  if ( v3 ) /*0x1a1db7*/
    v4 = *v3; /*0x1a1db9*/
  if ( v4 && (v5 = *(_DWORD *)(v4 + 132), v5 <= 7) ) /*0x1a1dc8*/
    v6 = v4 + 132 * v5 + 136; /*0x1a1dd1*/
  else
    v6 = 0; /*0x1a1ddc*/
  v7 = *(_DWORD *)(a2 + 64); /*0x1a1dde*/
  if ( *(_DWORD *)(v6 + 104) ) /*0x1a1de1*/
    BYTE1(v7) |= 2u; /*0x1a1de7*/
  else
    BYTE1(v7) &= ~2u; /*0x1a1dec*/
  v8 = *(_WORD *)(v6 + 112) & 0x7000 | v7; /*0x1a1df8*/
  v9 = 16 * *(unsigned __int16 *)(a2 + 72); /*0x1a1e0f*/
  v10 = (unsigned __int16)(*(_WORD *)(a2 + 68) - 4); /*0x1a1e12*/
  *(_DWORD *)(a1 + 116) = &loc_1A1E2C; /*0x1a1e18*/
  __writefsdword(v10 + v9, v8); /*0x1a1e1f*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a1e23*/
  *(_DWORD *)(a2 + 56) = (unsigned __int16)(*(_WORD *)(a2 + 56) + a3 + 1); /*0x1a1e47*/
  *(_DWORD *)(a2 + 68) = (unsigned __int16)(*(_WORD *)(a2 + 68) - 4); /*0x1a1e57*/
  return 1; /*0x1a1e69*/
}
