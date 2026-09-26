/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16b364. */
int *__cdecl sub_16B364(int a1, int a2)
{
  int v2; // edx
  int *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v7; // eax
  unsigned int v8; // edx
  char v9; // al
  int v10; // eax
  int v12; // eax
  int *v13; // esi
  unsigned int v14; // edi
  int v15; // edx
  int *v16; // eax
  int **v17; // edx
  int v18; // eax
  int v19; // edx
  int *v20; // eax
  int v21; // edx
  int v22; // eax
  unsigned int v23; // [esp+Ch] [ebp-10h]
  int v24; // [esp+14h] [ebp-8h]
  int *v25; // [esp+18h] [ebp-4h] BYREF

  if ( !a1 ) /*0x16b372*/
    panic(aZallocNullZone); /*0x16b379*/
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b385*/
  {
    lock_write(a1 + 48); /*0x16b38b*/
  }
  else
  {
    v2 = splhigh(); /*0x16b39d*/
    do /*0x16b3b2*/
    {
      while ( *(_DWORD *)a1 ) /*0x16b3a0*/
        ; /*0x16b3a2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b3b2*/
    *(_DWORD *)(a1 + 4) = v2; /*0x16b3b4*/
  }
  v3 = *(int **)(a1 + 16); /*0x16b3b7*/
  v25 = v3; /*0x16b3ba*/
  if ( !v3 ) /*0x16b3bf*/
    goto LABEL_13; /*0x16b3bf*/
  ++*(_DWORD *)(a1 + 8); /*0x16b3c1*/
  *(_DWORD *)(a1 + 16) = *v3; /*0x16b3c6*/
  if ( *(int **)(a1 + 12) == v3 ) /*0x16b3cc*/
    *(_DWORD *)(a1 + 12) = 0; /*0x16b3ce*/
  if ( !v25 ) /*0x16b3d9*/
  {
LABEL_13:
    v24 = a1 + 48; /*0x16b3df*/
    do /*0x16b3e8*/
    {
      if ( *(_DWORD *)(a1 + 36) ) /*0x16b3e8*/
      {
        if ( !a2 ) /*0x16b3f6*/
        {
          if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b3fc*/
          {
            lock_done(v24); /*0x16b414*/
          }
          else
          {
            v4 = *(_DWORD *)(a1 + 4); /*0x16b3fe*/
            _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b403*/
            splx(v4); /*0x16b406*/
          }
          return nullptr; /*0x16b4fd*/
        }
        assert_wait(a1 + 36, 1); /*0x16b432*/
        if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b43e*/
        {
          lock_done(v24); /*0x16b424*/
        }
        else
        {
          v5 = *(_DWORD *)(a1 + 4); /*0x16b440*/
          _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b445*/
          splx(v5); /*0x16b448*/
        }
        thread_block_with_continuation(0); /*0x16b452*/
        if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b45e*/
        {
          lock_write(v24); /*0x16b750*/
        }
        else
        {
          v6 = splhigh(); /*0x16b469*/
          do /*0x16b47e*/
          {
            while ( *(_DWORD *)a1 ) /*0x16b46c*/
              ; /*0x16b46e*/
          }
          while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b47e*/
          *(_DWORD *)(a1 + 4) = v6; /*0x16b480*/
        }
        continue; /*0x16b483*/
      }
      v7 = *(_DWORD *)(a1 + 20); /*0x16b488*/
      v8 = *(_DWORD *)(a1 + 24); /*0x16b48b*/
      if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b492*/
      {
        if ( *(_DWORD *)(a1 + 32) + v7 > v8 ) /*0x16b499*/
          goto LABEL_31; /*0x16b499*/
      }
      else if ( *(_DWORD *)(a1 + 28) + v7 > v8 ) /*0x16b4a5*/
      {
LABEL_31:
        v9 = *(_BYTE *)(a1 + 44); /*0x16b4ab*/
        if ( (v9 & 4) != 0 ) /*0x16b4b0*/
          break; /*0x16b4b0*/
        if ( (v9 & 8) != 0 ) /*0x16b4b8*/
        {
          *(_DWORD *)(a1 + 24) += *(_DWORD *)(a1 + 24) >> 1; /*0x16b4bf*/
        }
        else if ( !zone_ignore_overflow ) /*0x16b4db*/
        {
          if ( (v9 & 1) != 0 ) /*0x16b4e3*/
          {
            lock_done(v24); /*0x16b4cc*/
          }
          else
          {
            v10 = *(_DWORD *)(a1 + 4); /*0x16b4e5*/
            _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b4ea*/
            splx(v10); /*0x16b4ed*/
          }
          if ( a2 ) /*0x16b4f9*/
          {
            printf("zone \"%s\" empty.\n", *(const char **)(a1 + 40)); /*0x16b551*/
            panic(aZalloc); /*0x16b55b*/
          }
          return nullptr; /*0x16b4f9*/
        }
      }
      if ( (*(_BYTE *)(a1 + 44) & 1) != 0 && (*(_DWORD *)(a1 + 36) = 1, (*(_BYTE *)(a1 + 44) & 1) != 0) ) /*0x16b574*/
      {
        lock_done(v24); /*0x16b508*/
      }
      else
      {
        v12 = *(_DWORD *)(a1 + 4); /*0x16b576*/
        _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b57b*/
        splx(v12); /*0x16b57e*/
      }
      if ( (*(_BYTE *)(a1 + 44) & 1) == 0 ) /*0x16b58a*/
      {
        v25 = zget_space(*(_DWORD **)(a1 + 60), *(_DWORD *)(a1 + 28), a2); /*0x16b6d5*/
        if ( !v25 ) /*0x16b6dd*/
        {
          if ( a2 ) /*0x16b6e3*/
            panic(aZalloc_1); /*0x16b70d*/
          return nullptr; /*0x16b6e3*/
        }
        if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b719*/
        {
          lock_write(v24); /*0x16b6f0*/
        }
        else
        {
          v21 = splhigh(); /*0x16b720*/
          do /*0x16b736*/
          {
            while ( *(_DWORD *)a1 ) /*0x16b724*/
              ; /*0x16b726*/
          }
          while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b736*/
          *(_DWORD *)(a1 + 4) = v21; /*0x16b738*/
        }
        ++*(_DWORD *)(a1 + 8); /*0x16b73b*/
        *(_DWORD *)(a1 + 20) += *(_DWORD *)(a1 + 28); /*0x16b741*/
        if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b748*/
        {
          lock_done(v24); /*0x16b700*/
        }
        else
        {
LABEL_93:
          v22 = *(_DWORD *)(a1 + 4); /*0x16b774*/
          _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b779*/
          splx(v22); /*0x16b77c*/
        }
        return v25; /*0x16b77c*/
      }
      if ( kmem_alloc_pageable(zone_map, &v25, *(_DWORD *)(a1 + 32)) ) /*0x16b59f*/
        panic(aZalloc_0); /*0x16b5b0*/
      v13 = v25; /*0x16b5b8*/
      v23 = *(_DWORD *)(a1 + 32); /*0x16b5be*/
      if ( !v25 ) /*0x16b5c3*/
        panic(aZcramMemoryAtZ); /*0x16b5ca*/
      v14 = *(_DWORD *)(a1 + 28); /*0x16b5d2*/
      if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b5d9*/
      {
        lock_write(v24); /*0x16b514*/
      }
      else
      {
        v15 = splhigh(); /*0x16b5e4*/
        do /*0x16b5fa*/
        {
          while ( *(_DWORD *)a1 ) /*0x16b5e8*/
            ; /*0x16b5ea*/
        }
        while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b5fa*/
        *(_DWORD *)(a1 + 4) = v15; /*0x16b5fc*/
      }
      while ( v23 >= v14 ) /*0x16b638*/
      {
        v16 = *(int **)(a1 + 12); /*0x16b604*/
        if ( !v16 || v13 <= v16 ) /*0x16b60d*/
        {
          v17 = (int **)(a1 + 16); /*0x16b60f*/
          goto LABEL_63; /*0x16b612*/
        }
        do /*0x16b616*/
        {
          v17 = (int **)v16; /*0x16b618*/
LABEL_63:
          v16 = *v17; /*0x16b61a*/
        }
        while ( *v17 && v13 > v16 ); /*0x16b616*/
        *v13 = (int)v16; /*0x16b620*/
        *v17 = v13; /*0x16b622*/
        *(_DWORD *)(a1 + 12) = v13; /*0x16b624*/
        *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 8); /*0x16b62a*/
        v23 -= v14; /*0x16b62d*/
        v13 = (int *)((char *)v13 + v14); /*0x16b630*/
        *(_DWORD *)(a1 + 20) += v14; /*0x16b632*/
      }
      if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b63e*/
      {
        lock_done(v24); /*0x16b528*/
      }
      else
      {
        v18 = *(_DWORD *)(a1 + 4); /*0x16b644*/
        _InterlockedExchange((volatile __int32 *)a1, 0); /*0x16b649*/
        splx(v18); /*0x16b64c*/
      }
      if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b658*/
      {
        lock_write(v24); /*0x16b538*/
      }
      else
      {
        v19 = splhigh(); /*0x16b663*/
        do /*0x16b67a*/
        {
          while ( *(_DWORD *)a1 ) /*0x16b668*/
            ; /*0x16b66a*/
        }
        while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x16b67a*/
        *(_DWORD *)(a1 + 4) = v19; /*0x16b67c*/
      }
      *(_DWORD *)(a1 + 36) = 0; /*0x16b67f*/
      thread_wakeup_prim(a1 + 36, 0, 0); /*0x16b68e*/
      v25 = *(int **)(a1 + 16); /*0x16b699*/
      v20 = v25; /*0x16b69c*/
      if ( !v25 ) /*0x16b6a1*/
        goto LABEL_13; /*0x16b6a1*/
      ++*(_DWORD *)(a1 + 8); /*0x16b6a7*/
      *(_DWORD *)(a1 + 16) = *v20; /*0x16b6ac*/
      if ( *(int **)(a1 + 12) == v20 ) /*0x16b6b2*/
        *(_DWORD *)(a1 + 12) = 0; /*0x16b6b8*/
    }
    while ( !v25 ); /*0x16b3e8*/
  }
  if ( (*(_BYTE *)(a1 + 44) & 1) == 0 ) /*0x16b766*/
    goto LABEL_93; /*0x16b766*/
  lock_done(a1 + 48); /*0x16b76c*/
  return v25; /*0x16b787*/
}
