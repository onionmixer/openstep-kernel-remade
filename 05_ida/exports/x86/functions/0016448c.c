/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16448c. */
_DWORD *__cdecl choose_pset_thread(_DWORD *a1, int a2)
{
  int v2; // eax
  _DWORD **v3; // ecx
  _DWORD *v4; // edx
  int v5; // ebx
  volatile __int32 *v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // [esp+Ch] [ebp-8h]

  if ( *(int *)(a2 + 264) <= 0 ) /*0x1644a2*/
  {
    _InterlockedExchange((volatile __int32 *)(a2 + 256), 0); /*0x16453b*/
    v7 = (volatile __int32 *)(a2 + 280); /*0x164541*/
    do /*0x16455a*/
    {
      while ( *v7 ) /*0x164548*/
        ; /*0x16454a*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x16455a*/
    if ( a1[69] == 1 ) /*0x164566*/
    {
      a1[69] = 2; /*0x16456c*/
      if ( (_DWORD *)master_processor == a1 ) /*0x16457c*/
      {
        v8 = *(_DWORD *)(a2 + 272); /*0x16457e*/
        if ( a2 + 268 == v8 ) /*0x16458c*/
          *(_DWORD *)(a2 + 268) = a1; /*0x16458e*/
        else
          *(_DWORD *)(v8 + 268) = a1; /*0x16459b*/
        a1[68] = v8; /*0x1645a4*/
        a1[67] = a2 + 268; /*0x1645b0*/
        *(_DWORD *)(a2 + 272) = a1; /*0x1645b6*/
      }
      else
      {
        v9 = *(_DWORD *)(a2 + 268); /*0x1645c0*/
        if ( a2 + 268 == v9 ) /*0x1645ce*/
          *(_DWORD *)(a2 + 272) = a1; /*0x1645d3*/
        else
          *(_DWORD *)(v9 + 272) = a1; /*0x1645df*/
        a1[67] = v9; /*0x1645e8*/
        a1[68] = a2 + 268; /*0x1645f4*/
        *(_DWORD *)(a2 + 268) = a1; /*0x1645fa*/
      }
      ++*(_DWORD *)(a2 + 276); /*0x164600*/
    }
    _InterlockedExchange((volatile __int32 *)(a2 + 280), 0); /*0x164608*/
    return (_DWORD *)a1[71]; /*0x164611*/
  }
  else
  {
    v2 = *(_DWORD *)(a2 + 260); /*0x1644a8*/
    v3 = (_DWORD **)(a2 + 8 * v2); /*0x1644ae*/
    v10 = v2; /*0x1644b1*/
    if ( v2 < 0 ) /*0x1644b6*/
LABEL_10:
      panic(aChoosePsetThre); /*0x16452c*/
    while ( 1 ) /*0x1644b8*/
    {
      v4 = *v3; /*0x1644b8*/
      if ( v3 != *v3 ) /*0x1644bc*/
        break; /*0x1644bc*/
      v3 -= 2; /*0x164524*/
      if ( --v10 < 0 ) /*0x16452a*/
        goto LABEL_10; /*0x16452a*/
    }
    *(_DWORD *)(*v4 + 4) = v3; /*0x1644ca*/
    *v3 = (_DWORD *)*v4; /*0x1644cf*/
    v4[2] = 0; /*0x1644d1*/
    v5 = *(_DWORD *)(a2 + 264) - 1; /*0x1644e1*/
    *(_DWORD *)(a2 + 264) = v5; /*0x1644e4*/
    if ( v5 > 0 && (*(_BYTE *)(a2 + 360) & 2) != 0 && *v3 == v3 ) /*0x1644fa*/
    {
      do /*0x164504*/
      {
        v3 -= 2; /*0x1644fc*/
        --v10; /*0x1644ff*/
      }
      while ( *v3 == v3 ); /*0x164504*/
    }
    *(_DWORD *)(a2 + 260) = v10; /*0x16450c*/
    _InterlockedExchange((volatile __int32 *)(a2 + 256), 0); /*0x164514*/
    return v4; /*0x16451a*/
  }
}
