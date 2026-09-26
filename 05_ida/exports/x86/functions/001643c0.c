/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1643c0. */
_DWORD *__cdecl choose_thread(int a1)
{
  volatile __int32 *v1; // edx
  _DWORD **v2; // ecx
  int v3; // ebx
  _DWORD *v4; // edx
  int v6; // ecx
  volatile __int32 *v7; // edx

  v1 = (volatile __int32 *)(a1 + 256); /*0x1643cb*/
  do /*0x1643e6*/
  {
    while ( *v1 ) /*0x1643d4*/
      ; /*0x1643d6*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x1643e6*/
  if ( *(int *)(a1 + 264) <= 0 ) /*0x1643ef*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 256), 0); /*0x16444d*/
    v6 = *(_DWORD *)(a1 + 300); /*0x164456*/
    v7 = (volatile __int32 *)(v6 + 256); /*0x16445c*/
    do /*0x164476*/
    {
      while ( *v7 ) /*0x164464*/
        ; /*0x164466*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x164476*/
    return (_DWORD *)choose_pset_thread(a1, v6); /*0x16447d*/
  }
  else
  {
    v2 = (_DWORD **)(a1 + 8 * *(_DWORD *)(a1 + 260)); /*0x1643f7*/
    v3 = *(_DWORD *)(a1 + 260); /*0x1643fa*/
    if ( v3 < 0 ) /*0x1643fe*/
LABEL_9:
      panic(aChooseThread); /*0x16443e*/
    while ( 1 ) /*0x164400*/
    {
      v4 = *v2; /*0x164400*/
      if ( v2 != *v2 ) /*0x164404*/
        break; /*0x164404*/
      v2 -= 2; /*0x164438*/
      if ( --v3 < 0 ) /*0x16443c*/
        goto LABEL_9; /*0x16443c*/
    }
    *(_DWORD *)(*v4 + 4) = v2; /*0x164412*/
    *v2 = (_DWORD *)*v4; /*0x164417*/
    v4[2] = 0; /*0x164419*/
    --*(_DWORD *)(a1 + 264); /*0x164420*/
    *(_DWORD *)(a1 + 260) = v3; /*0x164426*/
    _InterlockedExchange((volatile __int32 *)(a1 + 256), 0); /*0x16442e*/
    return v4; /*0x164434*/
  }
}
