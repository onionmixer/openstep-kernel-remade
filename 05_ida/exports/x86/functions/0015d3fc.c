/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d3fc. */
int __cdecl sub_15D3FC(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // edx
  int result; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  int v10; // [esp-Ch] [ebp-64h]
  int v11; // [esp-8h] [ebp-60h]
  unsigned int v12; // [esp+Ch] [ebp-4Ch]
  _DWORD *v13; // [esp+14h] [ebp-44h]
  unsigned int v14; // [esp+18h] [ebp-40h] BYREF
  int v15; // [esp+1Ch] [ebp-3Ch] BYREF
  unsigned int v16; // [esp+20h] [ebp-38h] BYREF
  int v17; // [esp+24h] [ebp-34h] BYREF
  _DWORD __b[5]; // [esp+28h] [ebp-30h] BYREF
  _DWORD v19[7]; // [esp+3Ch] [ebp-1Ch] BYREF

  v4 = (_BYTE *)(*(_DWORD *)(a1 + 8) + a1); /*0x15d40d*/
  do /*0x15d421*/
  {
    if ( (unsigned int)v4 >= *(_DWORD *)(a1 + 4) + a1 ) /*0x15d416*/
      return 2; /*0x15d56c*/
  }
  while ( *v4++ ); /*0x15d421*/
  result = sub_15D57C(*(_DWORD *)(a1 + 8) + a1, v19, &v17, &v16, &v15); /*0x15d434*/
  if ( !result ) /*0x15d440*/
  {
    v11 = *(_DWORD *)(a2 + 24); /*0x15d44e*/
    v10 = *(_DWORD *)(a2 + 20); /*0x15d455*/
    v7 = pmap_create(v16); /*0x15d45a*/
    v13 = (_DWORD *)vm_map_create(v7, v10, v11, 1); /*0x15d468*/
    memset(__b, 0, sizeof(__b)); /*0x15d473*/
    __b[0] = 0; /*0x15d47b*/
    v8 = sub_15CB1C(v15, (int)v13, v19, v17, v16, a3, 0, (int)__b); /*0x15d49f*/
    if ( !v8 ) /*0x15d4a6*/
    {
      if ( (int)v13[7] <= 0 ) /*0x15d4b3*/
      {
        v8 = 4; /*0x15d540*/
      }
      else
      {
        v12 = *(_DWORD *)(v13[4] + 8); /*0x15d4bf*/
        v9 = *(_DWORD *)(v13[3] + 12) - v12; /*0x15d4c8*/
        v14 = v12; /*0x15d4ce*/
        if ( vm_map_find(a2, 0, 0, &v14, v9, 0) && vm_map_find(a2, 0, 0, &v14, v9, 1) /*0x15d51c*/
          || vm_map_copy(a2, v13, v14, v9, v12, 0, 0) )
        {
          v8 = 5; /*0x15d528*/
        }
        if ( v12 != v14 ) /*0x15d533*/
          __b[1] += v14 - v12; /*0x15d538*/
      }
      if ( !v8 ) /*0x15d547*/
      {
        *(_BYTE *)(a4 + 16) |= 2u; /*0x15d54c*/
        *(_DWORD *)(a4 + 4) = __b[1]; /*0x15d553*/
      }
    }
    vm_map_deallocate(v13); /*0x15d55a*/
    vn_rele(v15); /*0x15d563*/
    return v8; /*0x15d568*/
  }
  return result; /*0x15d574*/
}
