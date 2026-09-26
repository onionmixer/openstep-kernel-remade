/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194c24. */
int __usercall mmrw@<eax>(unsigned int a1@<edi>, __int16 a2, _DWORD *a3, int a4)
{
  int v4; // ebx
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // ebx
  int v12; // [esp+14h] [ebp-8h]
  unsigned int v13; // [esp+18h] [ebp-4h] BYREF

  v4 = 0; /*0x194c31*/
  if ( (int)a3[5] <= 0 ) /*0x194c3a*/
    return v4; /*0x194ddd*/
  while ( 1 ) /*0x194c4b*/
  {
    v5 = (_DWORD *)*a3; /*0x194c4b*/
    v6 = *(_DWORD *)(*a3 + 4); /*0x194c4d*/
    if ( !v6 ) /*0x194c52*/
    {
      *a3 = v5 + 2; /*0x194c57*/
      v7 = a3[1] - 1; /*0x194c5c*/
      a3[1] = v7; /*0x194c5f*/
      if ( v7 < 0 ) /*0x194c63*/
        panic(aMmrw); /*0x194c6e*/
      goto LABEL_17; /*0x194c63*/
    }
    if ( (unsigned __int8)a2 != 1 ) /*0x194c81*/
      break; /*0x194c81*/
    a1 = *(_DWORD *)(*a3 + 4); /*0x194d74*/
    if ( !kernacc(a3[2], v6, a4 == 0) ) /*0x194d95*/
      return 14; /*0x194d95*/
    v4 = uiomove(a3[2], a1, a4, a3); /*0x194da9*/
LABEL_17:
    if ( (int)a3[5] <= 0 || v4 ) /*0x194dd5*/
      return v4; /*0x194dd5*/
  }
  if ( (unsigned __int8)a2 > 1u ) /*0x194c87*/
  {
    if ( (unsigned __int8)a2 == 2 ) /*0x194c9d*/
    {
      if ( !a4 ) /*0x194db4*/
        return 0; /*0x194de2*/
      a1 = *(_DWORD *)(*a3 + 4); /*0x194db6*/
    }
    *v5 += a1; /*0x194dbc*/
    v5[1] -= a1; /*0x194dbe*/
    a3[2] += a1; /*0x194dc4*/
    a3[5] -= a1; /*0x194dc7*/
    goto LABEL_17; /*0x194dc7*/
  }
  v8 = a3[2]; /*0x194cb3*/
  v9 = v8 & ~page_mask; /*0x194cb8*/
  if ( mem_size <= v8 ) /*0x194cc0*/
    return 14; /*0x194cc0*/
  v12 = splvm(); /*0x194ccb*/
  v13 = *(_DWORD *)(kernel_map + 20); /*0x194cda*/
  if ( !vm_map_find(kernel_map, 0, 0, &v13, page_size, 1) ) /*0x194cf2*/
  {
    pmap_enter(*(_DWORD **)(kernel_map + 36), v13, v9, 3, 1); /*0x194d14*/
    v10 = a3[2] - v9; /*0x194d21*/
    a1 = min(page_size - v10, v5[1]); /*0x194d34*/
    v4 = uiomove(v13 + v10, a1, a4, a3); /*0x194d48*/
    vm_map_remove((_DWORD *)kernel_map, v13, page_size + v13); /*0x194d61*/
    splx(v12); /*0x194d6a*/
    goto LABEL_17; /*0x194d72*/
  }
  splx(v12); /*0x194de8*/
  return 14; /*0x194df5*/
}
