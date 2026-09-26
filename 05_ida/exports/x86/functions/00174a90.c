/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174a90. */
int __cdecl vm_map_find(int a1, int a2, int a3, unsigned int *a4, int a5, int a6)
{
  unsigned int v6; // esi
  unsigned int v7; // eax
  _DWORD *v9; // ebx
  volatile __int32 *v10; // edx
  _DWORD *i; // ecx
  _DWORD *v12; // eax
  volatile __int32 *v13; // edx
  volatile __int32 *v14; // edx
  unsigned int v15; // ecx
  int v16; // edx
  volatile __int32 *v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // [esp+Ch] [ebp-18h]
  int v27; // [esp+Ch] [ebp-18h]
  unsigned int v28; // [esp+10h] [ebp-14h]
  int v29; // [esp+14h] [ebp-10h]
  unsigned int v30; // [esp+18h] [ebp-Ch]
  int v31; // [esp+1Ch] [ebp-8h] BYREF
  _DWORD *v32; // [esp+20h] [ebp-4h]

  v6 = *a4; /*0x174a9f*/
  v28 = *a4; /*0x174aa1*/
  lock_write(a1); /*0x174aa8*/
  ++*(_DWORD *)(a1 + 76); /*0x174aad*/
  if ( a6 ) /*0x174ab5*/
  {
    v7 = *(_DWORD *)(a1 + 20); /*0x174abb*/
    if ( v6 < v7 ) /*0x174ac0*/
      v28 = *(_DWORD *)(a1 + 20); /*0x174ac2*/
    if ( *(_DWORD *)(a1 + 24) < v28 ) /*0x174ace*/
    {
LABEL_5:
      lock_done(a1); /*0x174ad0*/
      return 3; /*0x174adb*/
    }
    if ( v28 == v7 ) /*0x174ae3*/
    {
      v9 = *(_DWORD **)(a1 + 64); /*0x174ae8*/
      if ( v9 == (_DWORD *)(a1 + 12) ) /*0x174af2*/
        goto LABEL_33; /*0x174af2*/
      while ( 1 ) /*0x174c17*/
      {
        v28 = v9[3]; /*0x174c17*/
LABEL_33:
        v15 = a5 + v28; /*0x174bdb*/
        if ( *(_DWORD *)(a1 + 24) < a5 + v28 || v28 > v15 ) /*0x174be9*/
          goto LABEL_5; /*0x174be9*/
        v16 = v9[1]; /*0x174c00*/
        if ( v16 == a1 + 12 || *(_DWORD *)(v16 + 8) >= v15 ) /*0x174c10*/
        {
          *a4 = v28; /*0x174c22*/
          v17 = (volatile __int32 *)(a1 + 60); /*0x174c27*/
          do /*0x174c3e*/
          {
            while ( *v17 ) /*0x174c2c*/
              ; /*0x174c2e*/
          }
          while ( _InterlockedExchange(v17, 1) == 1 ); /*0x174c3e*/
          *(_DWORD *)(a1 + 56) = v9; /*0x174c43*/
          _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x174c48*/
          goto LABEL_44; /*0x174c48*/
        }
        v9 = (_DWORD *)v9[1]; /*0x174c12*/
      }
    }
    v10 = (volatile __int32 *)(a1 + 60); /*0x174b03*/
    do /*0x174b1a*/
    {
      while ( *v10 ) /*0x174b08*/
        ; /*0x174b0a*/
    }
    while ( _InterlockedExchange(v10, 1) == 1 ); /*0x174b1a*/
    i = *(_DWORD **)(a1 + 56); /*0x174b1f*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x174b24*/
    v12 = (_DWORD *)(a1 + 12); /*0x174b29*/
    if ( i == (_DWORD *)(a1 + 12) ) /*0x174b2e*/
      i = *(_DWORD **)(a1 + 16); /*0x174b30*/
    if ( i[2] > v28 ) /*0x174b39*/
    {
      v12 = (_DWORD *)i[1]; /*0x174b4c*/
      for ( i = *(_DWORD **)(a1 + 16); ; i = (_DWORD *)i[1] ) /*0x174b52*/
      {
LABEL_26:
        if ( i == v12 ) /*0x174b99*/
          goto LABEL_27; /*0x174b99*/
        if ( i[3] > v28 ) /*0x174b5e*/
          break; /*0x174b5e*/
      }
      if ( i[2] <= v28 ) /*0x174b63*/
      {
        v32 = i; /*0x174b65*/
        v13 = (volatile __int32 *)(a1 + 60); /*0x174b6b*/
        do /*0x174b82*/
        {
          while ( *v13 ) /*0x174b70*/
            ; /*0x174b72*/
        }
        while ( _InterlockedExchange(v13, 1) == 1 ); /*0x174b82*/
        *(_DWORD *)(a1 + 56) = i; /*0x174b87*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x174b8c*/
LABEL_31:
        v28 = v32[3]; /*0x174bcc*/
LABEL_32:
        v9 = v32; /*0x174bd5*/
        goto LABEL_33; /*0x174bd5*/
      }
    }
    else if ( i != v12 ) /*0x174b3d*/
    {
      if ( i[3] <= v28 ) /*0x174b42*/
        goto LABEL_26; /*0x174b42*/
      v32 = i; /*0x174b44*/
      goto LABEL_31; /*0x174b47*/
    }
LABEL_27:
    v32 = (_DWORD *)*i; /*0x174b9b*/
    v14 = (volatile __int32 *)(a1 + 60); /*0x174ba3*/
    do /*0x174bba*/
    {
      while ( *v14 ) /*0x174ba8*/
        ; /*0x174baa*/
    }
    while ( _InterlockedExchange(v14, 1) == 1 ); /*0x174bba*/
    *(_DWORD *)(a1 + 56) = v32; /*0x174bc2*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x174bc7*/
    goto LABEL_32; /*0x174bca*/
  }
LABEL_44:
  v30 = v28 + a5; /*0x174c4b*/
  if ( *(_DWORD *)(a1 + 20) <= v28 && *(_DWORD *)(a1 + 24) >= v30 && v28 < v30 ) /*0x174c6a*/
  {
    if ( !vm_map_lookup_entry(a1, v28, &v31) /*0x174ca6*/
      && ((v19 = v31, v20 = *(_DWORD *)(v31 + 4), v20 == a1 + 12) || *(_DWORD *)(v20 + 8) >= v30) )
    {
      if ( !a2 /*0x174d14*/
        && v31 != a1 + 12
        && *(_DWORD *)(v31 + 12) == v28
        && (*(_BYTE *)(v31 + 24) & 5) == 0
        && *(_DWORD *)(v31 + 36) == 1
        && *(_DWORD *)(v31 + 28) == 3
        && *(_DWORD *)(v31 + 32) == 7
        && !*(_WORD *)(v31 + 40)
        && (v26 = v31,
            v21 = vm_object_coalesce(*(_DWORD *)(v31 + 16), 0, *(_DWORD *)(v31 + 20), 0, v28 - *(_DWORD *)(v31 + 8), a5),
            v19 = v26,
            v21) )
      {
        *(_DWORD *)(a1 + 40) += v30 - *(_DWORD *)(v26 + 12); /*0x174d1f*/
        *(_DWORD *)(v26 + 12) = v30; /*0x174d25*/
      }
      else
      {
        if ( *(_DWORD *)(a1 + 32) ) /*0x174d33*/
          v22 = vm_map_entry_zone; /*0x174d39*/
        else
          v22 = vm_map_kentry_zone; /*0x174d40*/
        v27 = v19; /*0x174d46*/
        v23 = zalloc(v22); /*0x174d49*/
        v24 = v23; /*0x174d4e*/
        if ( !v23 ) /*0x174d58*/
          panic(aVmMapEntryCrea); /*0x174d62*/
        *(_DWORD *)(v23 + 8) = v28; /*0x174d72*/
        *(_DWORD *)(v23 + 12) = v30; /*0x174d78*/
        *(_BYTE *)(v23 + 24) &= 0xFAu; /*0x174d7b*/
        *(_DWORD *)(v23 + 16) = a2; /*0x174d82*/
        *(_DWORD *)(v23 + 20) = a3; /*0x174d88*/
        *(_BYTE *)(v23 + 24) &= 0xB7u; /*0x174d8b*/
        if ( *(_DWORD *)(a1 + 44) ) /*0x174d92*/
        {
          *(_DWORD *)(v23 + 36) = 1; /*0x174d98*/
          *(_DWORD *)(v23 + 28) = 3; /*0x174d9f*/
          *(_DWORD *)(v23 + 32) = 7; /*0x174da6*/
          *(_WORD *)(v23 + 40) = 0; /*0x174dad*/
        }
        ++*(_DWORD *)(a1 + 28); /*0x174db6*/
        *(_DWORD *)v23 = v27; /*0x174db9*/
        *(_DWORD *)(v23 + 4) = *(_DWORD *)(v27 + 4); /*0x174dbe*/
        v25 = *(_DWORD *)v23; /*0x174dc1*/
        **(_DWORD **)(v24 + 4) = v24; /*0x174dc6*/
        *(_DWORD *)(v25 + 4) = v24; /*0x174dc8*/
        *(_DWORD *)(a1 + 40) += *(_DWORD *)(v24 + 12) - *(_DWORD *)(v24 + 8); /*0x174dd1*/
        if ( *(_DWORD *)(a1 + 64) == v27 && *(_DWORD *)(v27 + 12) >= *(_DWORD *)(v24 + 8) ) /*0x174ddf*/
          *(_DWORD *)(a1 + 64) = v24; /*0x174de1*/
      }
      v18 = 0; /*0x174de4*/
    }
    else
    {
      v18 = 3; /*0x174ca8*/
    }
  }
  else
  {
    v18 = 1; /*0x174c6c*/
  }
  v29 = v18; /*0x174dea*/
  lock_done(a1); /*0x174ded*/
  return v29; /*0x174df8*/
}
