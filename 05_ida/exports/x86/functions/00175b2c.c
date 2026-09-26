/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x175b2c. */
int __cdecl vm_map_pageable(int a1, unsigned int a2, unsigned int a3, int a4)
{
  volatile __int32 *v4; // edx
  _DWORD *v5; // ecx
  _DWORD *v6; // eax
  volatile __int32 *v7; // edx
  volatile __int32 *v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // edx
  volatile __int32 *v12; // ecx
  _DWORD *v13; // ebx
  int i; // ebx
  int v15; // eax
  int v16; // edx
  int v17; // edx
  volatile __int32 *v18; // ecx
  __int16 v19; // ax
  int v20; // eax
  int v21; // edx
  int v22; // edx
  volatile __int32 *v23; // ecx
  __int16 v24; // ax
  char v25; // al
  int j; // ebx
  int *v28; // [esp+18h] [ebp-18h]
  int *v29; // [esp+1Ch] [ebp-14h]
  int *v30; // [esp+20h] [ebp-10h]
  int v31; // [esp+28h] [ebp-8h]
  _DWORD *v32; // [esp+2Ch] [ebp-4h]
  int v33; // [esp+2Ch] [ebp-4h]
  int v34; // [esp+2Ch] [ebp-4h]

  v31 = 1; /*0x175b35*/
  lock_write(a1); /*0x175b40*/
  ++*(_DWORD *)(a1 + 76); /*0x175b45*/
  if ( a2 < *(_DWORD *)(a1 + 20) ) /*0x175b51*/
    a2 = *(_DWORD *)(a1 + 20); /*0x175b53*/
  if ( a3 > *(_DWORD *)(a1 + 24) ) /*0x175b5f*/
    a3 = *(_DWORD *)(a1 + 24); /*0x175b61*/
  if ( a2 > a3 ) /*0x175b6a*/
    a2 = a3; /*0x175b6c*/
  v4 = (volatile __int32 *)(a1 + 60); /*0x175b72*/
  do /*0x175b8a*/
  {
    while ( *v4 ) /*0x175b78*/
      ; /*0x175b7a*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x175b8a*/
  v5 = *(_DWORD **)(a1 + 56); /*0x175b8f*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x175b94*/
  v6 = (_DWORD *)(a1 + 12); /*0x175b99*/
  if ( v5 == (_DWORD *)(a1 + 12) ) /*0x175b9e*/
    v5 = *(_DWORD **)(a1 + 16); /*0x175ba0*/
  if ( v5[2] > a2 ) /*0x175ba9*/
  {
    v6 = (_DWORD *)v5[1]; /*0x175bbc*/
    v5 = *(_DWORD **)(a1 + 16); /*0x175bc2*/
LABEL_24:
    while ( v5 != v6 ) /*0x175c09*/
    {
      if ( v5[3] > a2 ) /*0x175bce*/
      {
        if ( v5[2] > a2 ) /*0x175bd3*/
          goto LABEL_25; /*0x175bd3*/
        v32 = v5; /*0x175bd5*/
        v7 = (volatile __int32 *)(a1 + 60); /*0x175bdb*/
        do /*0x175bf2*/
        {
          while ( *v7 ) /*0x175be0*/
            ; /*0x175be2*/
        }
        while ( _InterlockedExchange(v7, 1) == 1 ); /*0x175bf2*/
        *(_DWORD *)(a1 + 56) = v5; /*0x175bf7*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x175bfc*/
        goto LABEL_29; /*0x175bff*/
      }
      v5 = (_DWORD *)v5[1]; /*0x175c04*/
    }
    goto LABEL_25; /*0x175c09*/
  }
  if ( v5 == v6 ) /*0x175bad*/
  {
LABEL_25:
    v33 = *v5; /*0x175c0b*/
    v8 = (volatile __int32 *)(a1 + 60); /*0x175c13*/
    do /*0x175c2a*/
    {
      while ( *v8 ) /*0x175c18*/
        ; /*0x175c1a*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x175c2a*/
    *(_DWORD *)(a1 + 56) = v33; /*0x175c32*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x175c37*/
    v13 = *(_DWORD **)(v33 + 4); /*0x175d1b*/
    goto LABEL_42; /*0x175c2c*/
  }
  if ( v5[3] <= a2 ) /*0x175bb2*/
    goto LABEL_24; /*0x175bb2*/
  v32 = v5; /*0x175bb4*/
LABEL_29:
  v13 = v32; /*0x175c40*/
  if ( v32[2] < a2 ) /*0x175c49*/
  {
    if ( *(_DWORD *)(a1 + 32) ) /*0x175c5b*/
      v9 = vm_map_entry_zone; /*0x175c61*/
    else
      v9 = vm_map_kentry_zone; /*0x175c68*/
    v30 = (int *)zalloc(v9); /*0x175c73*/
    if ( !v30 ) /*0x175c7b*/
      panic(aVmMapEntryCrea); /*0x175c82*/
    qmemcpy(v30, v32, 0x2Cu); /*0x175c9f*/
    v30[3] = a2; /*0x175ca4*/
    v32[5] += a2 - v32[2]; /*0x175cad*/
    v32[2] = a2; /*0x175cb0*/
    ++*(_DWORD *)(a1 + 28); /*0x175cb6*/
    *v30 = *v32; /*0x175cbe*/
    v30[1] = *(_DWORD *)(*v32 + 4); /*0x175cc5*/
    v10 = *v30; /*0x175cc8*/
    *(_DWORD *)v30[1] = v30; /*0x175ccd*/
    *(_DWORD *)(v10 + 4) = v30; /*0x175ccf*/
    if ( (v32[6] & 5) != 0 ) /*0x175cd6*/
    {
      v11 = v30[4]; /*0x175cd8*/
      if ( v11 ) /*0x175cdd*/
      {
        v12 = (volatile __int32 *)(v11 + 52); /*0x175cdf*/
        do /*0x175cf6*/
        {
          while ( *v12 ) /*0x175ce4*/
            ; /*0x175ce6*/
        }
        while ( _InterlockedExchange(v12, 1) == 1 ); /*0x175cf6*/
        ++*(_DWORD *)(v11 + 48); /*0x175cf8*/
        _InterlockedExchange((volatile __int32 *)(v11 + 52), 0); /*0x175cfd*/
      }
    }
    else
    {
      vm_object_reference(v30[4]); /*0x175d0b*/
    }
  }
LABEL_42:
  v34 = (int)v13; /*0x175d1e*/
  if ( a4 ) /*0x175d25*/
  {
    if ( v13 != (_DWORD *)(a1 + 12) ) /*0x175d33*/
    {
      while ( v13[2] < a3 ) /*0x175d3e*/
      {
        if ( !*((_WORD *)v13 + 20) ) /*0x175d45*/
        {
          lock_done(a1); /*0x175fe0*/
          return 4; /*0x175fea*/
        }
        v13 = (_DWORD *)v13[1]; /*0x175d4b*/
        if ( v13 == (_DWORD *)(a1 + 12) ) /*0x175d50*/
          break; /*0x175d50*/
      }
    }
    for ( i = v34; i != a1 + 12 && *(_DWORD *)(i + 8) < a3; i = *(_DWORD *)(i + 4) ) /*0x175d52*/
    {
      if ( *(_DWORD *)(i + 12) > a3 ) /*0x175d72*/
      {
        if ( *(_DWORD *)(a1 + 32) ) /*0x175d81*/
          v15 = vm_map_entry_zone; /*0x175d87*/
        else
          v15 = vm_map_kentry_zone; /*0x175d90*/
        v29 = (int *)zalloc(v15); /*0x175d9e*/
        if ( !v29 ) /*0x175da9*/
          panic(aVmMapEntryCrea); /*0x175db3*/
        qmemcpy(v29, (const void *)i, 0x2Cu); /*0x175dd4*/
        *(_DWORD *)(i + 12) = a3; /*0x175dd9*/
        v29[2] = a3; /*0x175ddf*/
        v29[5] += a3 - *(_DWORD *)(i + 8); /*0x175de8*/
        ++*(_DWORD *)(a1 + 28); /*0x175deb*/
        *v29 = i; /*0x175dee*/
        v29[1] = *(_DWORD *)(i + 4); /*0x175df3*/
        v16 = *v29; /*0x175df6*/
        *(_DWORD *)v29[1] = v29; /*0x175dfb*/
        *(_DWORD *)(v16 + 4) = v29; /*0x175dfd*/
        if ( (*(_BYTE *)(i + 24) & 5) != 0 ) /*0x175e04*/
        {
          v17 = v29[4]; /*0x175e06*/
          if ( v17 ) /*0x175e0b*/
          {
            v18 = (volatile __int32 *)(v17 + 52); /*0x175e0d*/
            do /*0x175e22*/
            {
              while ( *v18 ) /*0x175e10*/
                ; /*0x175e12*/
            }
            while ( _InterlockedExchange(v18, 1) == 1 ); /*0x175e22*/
            ++*(_DWORD *)(v17 + 48); /*0x175e24*/
            _InterlockedExchange((volatile __int32 *)(v17 + 52), 0); /*0x175e29*/
          }
        }
        else
        {
          vm_object_reference(v29[4]); /*0x175e37*/
        }
      }
      v19 = *(_WORD *)(i + 40); /*0x175e3f*/
      *(_WORD *)(i + 40) = v19 - 1; /*0x175e47*/
      if ( v19 == 1 ) /*0x175e4f*/
        vm_fault_unwire(a1, i); /*0x175e56*/
    }
  }
  else
  {
    while ( v13 != (_DWORD *)(a1 + 12) && v13[2] < a3 ) /*0x175e76*/
    {
      if ( v13[3] > a3 ) /*0x175e7f*/
      {
        if ( *(_DWORD *)(a1 + 32) ) /*0x175e8e*/
          v20 = vm_map_entry_zone; /*0x175e94*/
        else
          v20 = vm_map_kentry_zone; /*0x175e9c*/
        v28 = (int *)zalloc(v20); /*0x175eaa*/
        if ( !v28 ) /*0x175eb5*/
          panic(aVmMapEntryCrea); /*0x175ebf*/
        qmemcpy(v28, v13, 0x2Cu); /*0x175ee0*/
        v13[3] = a3; /*0x175ee5*/
        v28[2] = a3; /*0x175eeb*/
        v28[5] += a3 - v13[2]; /*0x175ef4*/
        ++*(_DWORD *)(a1 + 28); /*0x175ef7*/
        *v28 = (int)v13; /*0x175efa*/
        v28[1] = v13[1]; /*0x175eff*/
        v21 = *v28; /*0x175f02*/
        *(_DWORD *)v28[1] = v28; /*0x175f07*/
        *(_DWORD *)(v21 + 4) = v28; /*0x175f09*/
        if ( (v13[6] & 5) != 0 ) /*0x175f10*/
        {
          v22 = v28[4]; /*0x175f12*/
          if ( v22 ) /*0x175f17*/
          {
            v23 = (volatile __int32 *)(v22 + 52); /*0x175f19*/
            do /*0x175f2e*/
            {
              while ( *v23 ) /*0x175f1c*/
                ; /*0x175f1e*/
            }
            while ( _InterlockedExchange(v23, 1) == 1 ); /*0x175f2e*/
            ++*(_DWORD *)(v22 + 48); /*0x175f30*/
            _InterlockedExchange((volatile __int32 *)(v22 + 52), 0); /*0x175f35*/
          }
        }
        else
        {
          vm_object_reference(v28[4]); /*0x175f43*/
        }
      }
      v24 = *((_WORD *)v13 + 20); /*0x175f4b*/
      *((_WORD *)v13 + 20) = v24 + 1; /*0x175f53*/
      if ( !v24 ) /*0x175f5a*/
      {
        v25 = *((_BYTE *)v13 + 24); /*0x175f5c*/
        if ( (v25 & 1) == 0 ) /*0x175f61*/
        {
          if ( (v25 & 0x40) != 0 && (v13[7] & 2) != 0 ) /*0x175f6b*/
          {
            vm_object_shadow(v13 + 4, v13 + 5, v13[3] - v13[2]); /*0x175f7c*/
            *((_BYTE *)v13 + 24) &= ~0x40u; /*0x175f81*/
          }
          else if ( !v13[4] ) /*0x175f8c*/
          {
            v13[4] = vm_object_allocate(v13[3] - v13[2]); /*0x175f9e*/
            v13[5] = 0; /*0x175fa1*/
          }
        }
      }
      v13 = (_DWORD *)v13[1]; /*0x175fab*/
    }
    if ( kernel_map == a1 ) /*0x175fc5*/
    {
      v31 = 0; /*0x175fc7*/
      lock_done(a1); /*0x175fcf*/
    }
    else
    {
      lock_set_recursive(a1); /*0x175ff0*/
      lock_write_to_read(a1); /*0x175ff6*/
    }
    for ( j = v34; a1 + 12 != j; j = *(_DWORD *)(j + 4) ) /*0x176009*/
    {
      if ( *(_DWORD *)(j + 8) >= a3 ) /*0x176016*/
        break; /*0x176016*/
      if ( *(_WORD *)(j + 40) == 1 ) /*0x17601d*/
        vm_fault_wire(a1, j); /*0x176024*/
    }
    if ( !v31 ) /*0x176038*/
      return 0; /*0x176038*/
    lock_clear_recursive(a1); /*0x17603e*/
  }
  lock_done(a1); /*0x176050*/
  return 0; /*0x17605a*/
}
