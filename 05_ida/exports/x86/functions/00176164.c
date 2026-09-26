/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x176164. */
int __cdecl vm_map_delete(int a1, unsigned int a2, unsigned int a3)
{
  volatile __int32 *v3; // edx
  _DWORD *v4; // ebx
  _DWORD *v5; // eax
  volatile __int32 *v6; // edx
  volatile __int32 *v7; // edx
  int v8; // ebx
  int v9; // eax
  int v10; // edx
  int v11; // edx
  volatile __int32 *v12; // esi
  volatile __int32 *v13; // edx
  int v14; // eax
  int v15; // edx
  int v16; // edx
  volatile __int32 *v17; // esi
  int v18; // esi
  int v19; // esi
  volatile __int32 *v20; // edx
  int v21; // edi
  int v22; // eax
  int v24; // [esp+Ch] [ebp-20h]
  int *v25; // [esp+14h] [ebp-18h]
  int v26; // [esp+18h] [ebp-14h]
  int v27; // [esp+1Ch] [ebp-10h]
  int *v28; // [esp+20h] [ebp-Ch]
  _DWORD *v29; // [esp+28h] [ebp-4h]
  int v30; // [esp+28h] [ebp-4h]

  v3 = (volatile __int32 *)(a1 + 60); /*0x176170*/
  do /*0x176186*/
  {
    while ( *v3 ) /*0x176174*/
      ; /*0x176176*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x176186*/
  v4 = *(_DWORD **)(a1 + 56); /*0x17618b*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176190*/
  v5 = (_DWORD *)(a1 + 12); /*0x176195*/
  if ( v4 == (_DWORD *)(a1 + 12) ) /*0x17619a*/
    v4 = *(_DWORD **)(a1 + 16); /*0x17619c*/
  if ( v4[2] > a2 ) /*0x1761a5*/
  {
    v5 = (_DWORD *)v4[1]; /*0x1761b8*/
    v4 = *(_DWORD **)(a1 + 16); /*0x1761be*/
LABEL_18:
    while ( v4 != v5 ) /*0x176205*/
    {
      if ( v4[3] > a2 ) /*0x1761ca*/
      {
        if ( v4[2] > a2 ) /*0x1761cf*/
          goto LABEL_19; /*0x1761cf*/
        v29 = v4; /*0x1761d1*/
        v6 = (volatile __int32 *)(a1 + 60); /*0x1761d7*/
        do /*0x1761ee*/
        {
          while ( *v6 ) /*0x1761dc*/
            ; /*0x1761de*/
        }
        while ( _InterlockedExchange(v6, 1) == 1 ); /*0x1761ee*/
        *(_DWORD *)(a1 + 56) = v4; /*0x1761f3*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1761f8*/
        goto LABEL_23; /*0x1761fb*/
      }
      v4 = (_DWORD *)v4[1]; /*0x176200*/
    }
    goto LABEL_19; /*0x176205*/
  }
  if ( v4 == v5 ) /*0x1761a9*/
  {
LABEL_19:
    v30 = *v4; /*0x176207*/
    v7 = (volatile __int32 *)(a1 + 60); /*0x17620f*/
    do /*0x176226*/
    {
      while ( *v7 ) /*0x176214*/
        ; /*0x176216*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x176226*/
    *(_DWORD *)(a1 + 56) = v30; /*0x17622e*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176233*/
    v8 = *(_DWORD *)(v30 + 4); /*0x176239*/
    goto LABEL_40; /*0x17623c*/
  }
  if ( v4[3] <= a2 ) /*0x1761ae*/
    goto LABEL_18; /*0x1761ae*/
  v29 = v4; /*0x1761b0*/
LABEL_23:
  v8 = (int)v29; /*0x176244*/
  if ( v29[2] < a2 ) /*0x17624d*/
  {
    if ( *(_DWORD *)(a1 + 32) ) /*0x17625f*/
      v9 = vm_map_entry_zone; /*0x176265*/
    else
      v9 = vm_map_kentry_zone; /*0x17626c*/
    v28 = (int *)zalloc(v9); /*0x176277*/
    if ( !v28 ) /*0x17627f*/
      panic(aVmMapEntryCrea); /*0x176286*/
    qmemcpy(v28, v29, 0x2Cu); /*0x1762a1*/
    v28[3] = a2; /*0x1762a6*/
    v29[5] += a2 - v29[2]; /*0x1762af*/
    v29[2] = a2; /*0x1762b2*/
    ++*(_DWORD *)(a1 + 28); /*0x1762b8*/
    *v28 = *v29; /*0x1762c0*/
    v28[1] = *(_DWORD *)(*v29 + 4); /*0x1762c7*/
    v10 = *v28; /*0x1762ca*/
    *(_DWORD *)v28[1] = v28; /*0x1762cf*/
    *(_DWORD *)(v10 + 4) = v28; /*0x1762d1*/
    if ( (v29[6] & 5) != 0 ) /*0x1762d8*/
    {
      v11 = v28[4]; /*0x1762da*/
      if ( v11 ) /*0x1762df*/
      {
        v12 = (volatile __int32 *)(v11 + 52); /*0x1762e1*/
        do /*0x1762f6*/
        {
          while ( *v12 ) /*0x1762e4*/
            ; /*0x1762e6*/
        }
        while ( _InterlockedExchange(v12, 1) == 1 ); /*0x1762f6*/
        ++*(_DWORD *)(v11 + 48); /*0x1762f8*/
        _InterlockedExchange((volatile __int32 *)(v11 + 52), 0); /*0x1762fd*/
      }
    }
    else
    {
      vm_object_reference(v28[4]); /*0x17630b*/
    }
  }
  v13 = (volatile __int32 *)(a1 + 60); /*0x176316*/
  do /*0x17632e*/
  {
    while ( *v13 ) /*0x17631c*/
      ; /*0x17631e*/
  }
  while ( _InterlockedExchange(v13, 1) == 1 ); /*0x17632e*/
  *(_DWORD *)(a1 + 56) = *v29; /*0x176335*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x17633a*/
LABEL_40:
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 64) + 8) >= a2 ) /*0x176349*/
    *(_DWORD *)(a1 + 64) = *(_DWORD *)v8; /*0x176351*/
  while ( v8 != a1 + 12 && *(_DWORD *)(v8 + 8) < a3 ) /*0x176362*/
  {
    if ( *(_DWORD *)(v8 + 12) > a3 ) /*0x17636b*/
    {
      if ( *(_DWORD *)(a1 + 32) ) /*0x17637a*/
        v14 = vm_map_entry_zone; /*0x176380*/
      else
        v14 = vm_map_kentry_zone; /*0x176388*/
      v25 = (int *)zalloc(v14); /*0x176396*/
      if ( !v25 ) /*0x1763a1*/
        panic(aVmMapEntryCrea); /*0x1763ab*/
      qmemcpy(v25, (const void *)v8, 0x2Cu); /*0x1763c9*/
      *(_DWORD *)(v8 + 12) = a3; /*0x1763ce*/
      v25[2] = a3; /*0x1763d4*/
      v25[5] += a3 - *(_DWORD *)(v8 + 8); /*0x1763dd*/
      ++*(_DWORD *)(a1 + 28); /*0x1763e0*/
      *v25 = v8; /*0x1763e3*/
      v25[1] = *(_DWORD *)(v8 + 4); /*0x1763e8*/
      v15 = *v25; /*0x1763eb*/
      *(_DWORD *)v25[1] = v25; /*0x1763f0*/
      *(_DWORD *)(v15 + 4) = v25; /*0x1763f2*/
      if ( (*(_BYTE *)(v8 + 24) & 5) != 0 ) /*0x1763f9*/
      {
        v16 = v25[4]; /*0x1763fb*/
        if ( v16 ) /*0x176400*/
        {
          v17 = (volatile __int32 *)(v16 + 52); /*0x176402*/
          do /*0x17641a*/
          {
            while ( *v17 ) /*0x176408*/
              ; /*0x17640a*/
          }
          while ( _InterlockedExchange(v17, 1) == 1 ); /*0x17641a*/
          ++*(_DWORD *)(v16 + 48); /*0x17641c*/
          _InterlockedExchange((volatile __int32 *)(v16 + 52), 0); /*0x176421*/
        }
      }
      else
      {
        vm_object_reference(v25[4]); /*0x17642f*/
      }
    }
    v27 = *(_DWORD *)(v8 + 4); /*0x17643a*/
    v26 = *(_DWORD *)(v8 + 8); /*0x176440*/
    v24 = *(_DWORD *)(v8 + 12); /*0x176446*/
    v18 = *(_DWORD *)(v8 + 16); /*0x176449*/
    if ( *(_WORD *)(v8 + 40) ) /*0x17644c*/
    {
      vm_fault_unwire(a1, v8); /*0x176458*/
      *(_WORD *)(v8 + 40) = 0; /*0x17645d*/
    }
    if ( kernel_object == v18 ) /*0x17646c*/
      vm_object_page_remove(v18, *(_DWORD *)(v8 + 20), *(_DWORD *)(v8 + 20) + v24 - v26); /*0x17647c*/
    if ( !*(_DWORD *)(a1 + 44) ) /*0x176487*/
      vm_object_pmap_remove(v18, *(_DWORD *)(v8 + 20), *(_DWORD *)(v8 + 20) + v24 - v26); /*0x17649b*/
    pmap_remove(*(_DWORD *)(a1 + 36), v26, v24); /*0x1764b2*/
    if ( *(_WORD *)(v8 + 40) ) /*0x1764ba*/
    {
      vm_fault_unwire(a1, v8); /*0x1764c6*/
      *(_WORD *)(v8 + 40) = 0; /*0x1764cb*/
    }
    --*(_DWORD *)(a1 + 28); /*0x1764d7*/
    **(_DWORD **)(v8 + 4) = *(_DWORD *)v8; /*0x1764df*/
    *(_DWORD *)(*(_DWORD *)v8 + 4) = *(_DWORD *)(v8 + 4); /*0x1764e6*/
    *(_DWORD *)(a1 + 40) -= *(_DWORD *)(v8 + 12) - *(_DWORD *)(v8 + 8); /*0x1764f2*/
    if ( (*(_BYTE *)(v8 + 24) & 5) != 0 ) /*0x1764f9*/
    {
      v19 = *(_DWORD *)(v8 + 16); /*0x1764fb*/
      if ( v19 ) /*0x176500*/
      {
        v20 = (volatile __int32 *)(v19 + 52); /*0x176502*/
        do /*0x17651a*/
        {
          while ( *v20 ) /*0x176508*/
            ; /*0x17650a*/
        }
        while ( _InterlockedExchange(v20, 1) == 1 ); /*0x17651a*/
        v21 = *(_DWORD *)(v19 + 48) - 1; /*0x17651f*/
        *(_DWORD *)(v19 + 48) = v21; /*0x176522*/
        _InterlockedExchange((volatile __int32 *)(v19 + 52), 0); /*0x176528*/
        if ( v21 <= 0 ) /*0x17652d*/
        {
          lock_write(v19); /*0x176530*/
          ++*(_DWORD *)(v19 + 76); /*0x176535*/
          vm_map_delete(v19, *(_DWORD *)(v19 + 20), *(_DWORD *)(v19 + 24)); /*0x176544*/
          pmap_destroy(*(_DWORD *)(v19 + 36)); /*0x17654d*/
          zfree(vm_map_zone, (_DWORD *)v19); /*0x17655a*/
        }
      }
    }
    else
    {
      vm_object_deallocate(*(_DWORD *)(v8 + 16)); /*0x176568*/
    }
    if ( *(_DWORD *)(a1 + 32) ) /*0x176573*/
      v22 = vm_map_entry_zone; /*0x176579*/
    else
      v22 = vm_map_kentry_zone; /*0x176580*/
    zfree(v22, (_DWORD *)v8); /*0x176587*/
    v8 = v27; /*0x17658f*/
  }
  return 0; /*0x1765a5*/
}
