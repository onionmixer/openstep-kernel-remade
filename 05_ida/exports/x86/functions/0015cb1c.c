/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15cb1c. */
int __cdecl sub_15CB1C(int a1, int a2, _DWORD *a3, int a4, unsigned int a5, int a6, int a7, int a8)
{
  int v9; // ecx
  int v10; // ebx
  int v11; // esi
  _DWORD *v12; // ecx
  int v13; // eax
  int v14; // [esp+Ch] [ebp-1Ch]
  unsigned int v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch]
  _DWORD *v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h] BYREF
  int v20; // [esp+44h] [ebp+1Ch]

  v18 = nullptr; /*0x15cb25*/
  if ( a6 > 6 ) /*0x15cb30*/
    return 4; /*0x15cb92*/
  v20 = a6 + 1; /*0x15cb32*/
  if ( a3[1] != dword_1E8E04 || !check_cpu_subtype(a3[2]) ) /*0x15cb46*/
    return 1; /*0x15cb52*/
  switch ( a3[3] ) /*0x15cb68*/
  {
    case 1: /*0x15cb68*/
    case 2: /*0x15cb68*/
    case 5: /*0x15cb68*/
      if ( v20 != 1 ) /*0x15cb90*/
        return 4; /*0x15cb90*/
      goto LABEL_11; /*0x15cb90*/
    case 3: /*0x15cb68*/
    case 6: /*0x15cb68*/
      if ( v20 == 1 ) /*0x15cba0*/
        return 4; /*0x15cba0*/
      goto LABEL_11; /*0x15cba0*/
    case 7: /*0x15cb68*/
      if ( v20 != 2 ) /*0x15cba8*/
        return 4; /*0x15cba8*/
LABEL_11:
      v17 = vnode_pager_setup(a1, 0, 1); /*0x15cbaa*/
      v9 = a3[5]; /*0x15cbbd*/
      if ( a5 < v9 + 28 ) /*0x15cbc9*/
        return 2; /*0x15cbc9*/
      v16 = ~page_mask & (v9 + page_mask + 28); /*0x15cbd8*/
      if ( !v16 ) /*0x15cbdb*/
        return 2; /*0x15cbe2*/
      v19 = 0; /*0x15cbe8*/
      v10 = vm_allocate_with_pager(kernel_map, &v19, v16, 1, v17, a4); /*0x15cc0d*/
      if ( v10 ) /*0x15cc14*/
        return 5; /*0x15cc1b*/
      v11 = 1; /*0x15cc44*/
      break; /*0x15cc44*/
    default:
      return 4;
  }
  while ( 1 ) /*0x15cc4c*/
  {
    v15 = 28; /*0x15cc4c*/
    v14 = a3[4] - 1; /*0x15cc5a*/
    if ( a3[4] ) /*0x15cc56*/
      break; /*0x15cc56*/
LABEL_41:
    if ( ++v11 > 2 ) /*0x15cda7*/
    {
      if ( v18 ) /*0x15cdb1*/
        v10 = sub_15D3FC(v18, a2, v20, a8); /*0x15cdc8*/
LABEL_44:
      vm_map_remove(kernel_map, v19, v19 + v16); /*0x15cdcd*/
      if ( !v10 && v20 == 1 && !*(_DWORD *)(a8 + 12) ) /*0x15cdf0*/
        return 4; /*0x15cdf6*/
      return v10; /*0x15cdfb*/
    }
  }
  while ( 1 ) /*0x15cc71*/
  {
    v12 = (_DWORD *)(v19 + v15); /*0x15cc71*/
    v15 += *(_DWORD *)(v19 + v15 + 4); /*0x15cc76*/
    if ( v15 > a3[5] + 28 ) /*0x15cc85*/
      break; /*0x15cc85*/
    switch ( *v12 ) /*0x15cc93*/
    {
      case 1: /*0x15cc93*/
        if ( v11 == 1 ) /*0x15ccd7*/
          v10 = sub_15CE08(v12, v17, a4, a5, *(_DWORD *)(*(_DWORD *)a1 + 20), a2, a8); /*0x15cd00*/
        goto LABEL_39; /*0x15cd05*/
      case 4: /*0x15cc93*/
        if ( v11 != 2 ) /*0x15cd0f*/
          goto LABEL_39; /*0x15cd0f*/
        v13 = sub_15D158(v12, a8); /*0x15cd16*/
        goto LABEL_32; /*0x15cd1b*/
      case 5: /*0x15cc93*/
        if ( v11 != 2 ) /*0x15cd23*/
          goto LABEL_39; /*0x15cd23*/
        v13 = sub_15D0D4(v12, a8); /*0x15cd2a*/
        goto LABEL_32; /*0x15cd2f*/
      case 6: /*0x15cc93*/
        if ( v11 == 1 ) /*0x15cd37*/
          v10 = sub_15D338(v12, a2, v20); /*0x15cd47*/
        goto LABEL_39; /*0x15cd4c*/
      case 7: /*0x15cc93*/
        if ( v11 != 1 || !a7 ) /*0x15cd59*/
          goto LABEL_39; /*0x15cd59*/
        v13 = sub_15D3E8(v12, a7); /*0x15cd60*/
LABEL_32:
        v10 = v13; /*0x15cd65*/
        goto LABEL_39; /*0x15cd6a*/
      case 0xE: /*0x15cc93*/
        if ( v11 != 2 ) /*0x15cd6f*/
          goto LABEL_39; /*0x15cd6f*/
        if ( v20 != 1 && v18 ) /*0x15cd7b*/
        {
          v10 = 4; /*0x15cd84*/
          goto LABEL_44; /*0x15cd89*/
        }
        v18 = v12; /*0x15cd7d*/
LABEL_39:
        if ( v10 ) /*0x15cd90*/
          goto LABEL_44; /*0x15cd90*/
        if ( --v14 == -1 ) /*0x15cd99*/
          goto LABEL_41; /*0x15cd99*/
        break; /*0x15cd99*/
      default:
        v10 = 0; /*0x15cd8c*/
        goto LABEL_39; /*0x15cd8c*/
    }
  }
  vm_map_remove(kernel_map, v19, v19 + v16); /*0x15cc32*/
  return 2; /*0x15ce00*/
}
