/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a61c. */
int __cdecl sub_13A61C(_DWORD *a1, unsigned int a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // ebx
  int v6; // esi
  unsigned __int8 *v7; // esi
  int v8; // ebx
  int v9; // ebx
  unsigned int v10; // ebx
  unsigned __int8 *v11; // edi
  int v12; // ebx
  int v14; // [esp+24h] [ebp-1Ch]
  int v15; // [esp+24h] [ebp-1Ch]
  unsigned __int8 v16; // [esp+28h] [ebp-18h]
  unsigned __int8 v17; // [esp+28h] [ebp-18h]
  int v18; // [esp+2Ch] [ebp-14h]
  unsigned __int8 v19; // [esp+30h] [ebp-10h]
  int v20; // [esp+34h] [ebp-Ch]
  vm_size_t v21; // [esp+38h] [ebp-8h]
  unsigned int v22; // [esp+3Ch] [ebp-4h]

  v21 = a2 / page_size; /*0x13a630*/
  v20 = a3 / *a1; /*0x13a63d*/
  v5 = a1[3]; /*0x13a640*/
  v19 = *(_BYTE *)(v5 + 4 * (a2 / page_size) + 3); /*0x13a64a*/
  if ( (v19 & 0xF) != 0 ) /*0x13a64f*/
  {
    *(_BYTE *)((*(_DWORD *)(v5 + 4 * v21) & 0xFFFFFF) + a1[5]) |= ((1 << (v19 & 0xF)) - 1) << (v19 >> 4); /*0x13a6b1*/
  }
  else
  {
    *(_BYTE *)(v21 + a1[5]) = -1; /*0x13a657*/
    if ( a1[7] <= v21 ) /*0x13a661*/
    {
      a1[7] = v21 + 1; /*0x13a664*/
      dword_1E5A70 = v21 + 1; /*0x13a667*/
    }
  }
  v6 = a1[8]; /*0x13a6cb*/
  if ( v6 == a1[11] / page_size || v6 == a1[16] / page_size ) /*0x13a6df*/
  {
    v7 = (unsigned __int8 *)(a1[5] + v6); /*0x13a6e4*/
    v16 = *v7; /*0x13a6e9*/
    if ( !*v7 ) /*0x13a6e9*/
      goto LABEL_16; /*0x13a6e9*/
    v8 = (1 << v20) - 1; /*0x13a6fa*/
    v14 = 0; /*0x13a6fd*/
    if ( v20 == 9 ) /*0x13a70e*/
      goto LABEL_16; /*0x13a70e*/
    while ( (unsigned __int8)(v8 & v16) != v8 ) /*0x13a718*/
    {
      v16 >>= 1; /*0x13a71a*/
      if ( ++v14 >= (unsigned int)(9 - v20) ) /*0x13a723*/
        goto LABEL_16; /*0x13a723*/
    }
    *v7 &= ~(unsigned __int8)(v8 << v14); /*0x13a731*/
    v9 = v14; /*0x13a733*/
  }
  else
  {
    v9 = -1; /*0x13a738*/
  }
  if ( v9 >= 0 ) /*0x13a73f*/
  {
    v22 = a1[8]; /*0x13a747*/
    ++dword_1E5A64; /*0x13a74a*/
    goto LABEL_29; /*0x13a750*/
  }
LABEL_16:
  v10 = 0; /*0x13a758*/
  if ( !a1[7] ) /*0x13a762*/
    goto LABEL_26; /*0x13a762*/
  while ( *(unsigned __int8 *)(v10 + a1[5]) != 255 ) /*0x13a774*/
  {
    if ( a1[7] <= ++v10 ) /*0x13a7e3*/
      goto LABEL_26; /*0x13a7e3*/
  }
  v22 = v10; /*0x13a776*/
  v11 = (unsigned __int8 *)(v10 + a1[5]); /*0x13a77f*/
  v17 = *v11; /*0x13a783*/
  if ( *v11 && (v12 = (1 << v20) - 1, v15 = 0, v20 != 9) ) /*0x13a7be*/
  {
    while ( 1 ) /*0x13a7c6*/
    {
      v18 = (unsigned __int8)(v12 & v17); /*0x13a7c6*/
      if ( v18 == v12 ) /*0x13a7cb*/
        break; /*0x13a7cb*/
      v17 >>= 1; /*0x13a7cd*/
      if ( ++v15 >= (unsigned int)(9 - v20) ) /*0x13a7d6*/
        goto LABEL_26; /*0x13a7d6*/
    }
    *v11 &= ~(unsigned __int8)(v18 << v15); /*0x13a796*/
    v9 = v15; /*0x13a798*/
  }
  else
  {
LABEL_26:
    v9 = -1; /*0x13a7e5*/
  }
  if ( v9 < 0 ) /*0x13a7ec*/
    return 0; /*0x13a8a8*/
  ++dword_1E5A68; /*0x13a7f2*/
LABEL_29:
  *(_DWORD *)(a1[3] + 4 * v21) = v22 & 0xFFFFFF | *(_DWORD *)(a1[3] + 4 * v21) & 0xFF000000; /*0x13a800*/
  *(_BYTE *)(a1[3] + 4 * v21 + 3) = (16 * v9) | *(_BYTE *)(a1[3] + 4 * v21 + 3) & 0xF; /*0x13a839*/
  *(_BYTE *)(a1[3] + 4 * v21 + 3) = v20 & 0xF | *(_BYTE *)(a1[3] + 4 * v21 + 3) & 0xF0; /*0x13a854*/
  *a4 = page_size * v22; /*0x13a865*/
  *a5 = *a1 * v9; /*0x13a870*/
  if ( v20 != page_size / *a1 ) /*0x13a886*/
    a1[8] = v22; /*0x13a88b*/
  if ( dword_1E5A6C < v22 ) /*0x13a897*/
    dword_1E5A6C = v22; /*0x13a899*/
  return 1; /*0x13a8ad*/
}
