/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x177a74. */
_DWORD *__cdecl vm_map_fork(int a1)
{
  int v1; // esi
  _DWORD *v2; // ebx
  int i; // edi
  int v4; // eax
  int v5; // esi
  _DWORD *v6; // ebx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int *v10; // eax
  int v11; // ebx
  volatile __int32 *v12; // edx
  int v13; // edx
  int v14; // eax
  int *v15; // eax
  int v16; // edx
  char v17; // al
  volatile __int32 *v18; // edx
  _BOOL4 v19; // edx
  int v20; // eax
  int v21; // ebx
  int v23; // [esp+Ch] [ebp-18h]
  int v24; // [esp+Ch] [ebp-18h]
  int *v25; // [esp+Ch] [ebp-18h]
  int v26; // [esp+Ch] [ebp-18h]
  int v27; // [esp+10h] [ebp-14h]
  int v28; // [esp+14h] [ebp-10h]
  _DWORD *v29; // [esp+1Ch] [ebp-8h]
  int v30; // [esp+20h] [ebp-4h] BYREF

  lock_write(a1); /*0x177a81*/
  ++*(_DWORD *)(a1 + 76); /*0x177a89*/
  v23 = pmap_create(0); /*0x177a96*/
  v28 = *(_DWORD *)(a1 + 20); /*0x177a9c*/
  v27 = *(_DWORD *)(a1 + 24); /*0x177aa2*/
  v1 = *(_DWORD *)(a1 + 32); /*0x177aa8*/
  v2 = (_DWORD *)zalloc(vm_map_zone); /*0x177aba*/
  if ( !v2 ) /*0x177ac1*/
    panic(aVmMapCreate); /*0x177ac8*/
  v2[4] = v2 + 3; /*0x177ad3*/
  v2[3] = v2 + 3; /*0x177ad6*/
  v2[7] = 0; /*0x177ad9*/
  v2[8] = v1; /*0x177ae0*/
  v2[10] = 0; /*0x177ae3*/
  v2[12] = 1; /*0x177aea*/
  v2[9] = v23; /*0x177af4*/
  v2[11] = 1; /*0x177af7*/
  v2[5] = v28; /*0x177b01*/
  v2[6] = v27; /*0x177b07*/
  v2[18] = 0; /*0x177b0a*/
  v2[17] = 0; /*0x177b11*/
  v2[16] = v2 + 3; /*0x177b18*/
  v2[14] = v2 + 3; /*0x177b1b*/
  v2[19] = 0; /*0x177b1e*/
  lock_init(v2, 1); /*0x177b28*/
  v2[19] = 0; /*0x177b2d*/
  v2[13] = 0; /*0x177b37*/
  v2[15] = 0; /*0x177b3e*/
  v29 = v2; /*0x177b45*/
  for ( i = *(_DWORD *)(a1 + 16); i != a1 + 12; i = *(_DWORD *)(i + 4) )
  {
    if ( (*(_BYTE *)(i + 24) & 4) != 0 ) /*0x177b5b*/
      panic(aVmMapForkEncou); /*0x177b62*/
    v4 = *(_DWORD *)(i + 36); /*0x177b6d*/
    if ( v4 == 1 )
    {
      if ( v29[8] ) /*0x177d77*/
        v14 = vm_map_entry_zone; /*0x177d7d*/
      else
        v14 = vm_map_kentry_zone; /*0x177d84*/
      v15 = (int *)zalloc(v14); /*0x177d8a*/
      if ( !v15 ) /*0x177d96*/
        panic(aVmMapEntryCrea); /*0x177d9d*/
      v26 = (int)v15; /*0x177da5*/
      qmemcpy(v15, (const void *)i, 0x2Cu); /*0x177db6*/
      *((_WORD *)v15 + 20) = 0; /*0x177db8*/
      v15[4] = 0; /*0x177dc1*/
      *((_BYTE *)v15 + 24) &= ~1u; /*0x177dc8*/
      ++v29[7]; /*0x177dcf*/
      *v15 = v29[3]; /*0x177dd5*/
      v15[1] = *(_DWORD *)(v29[3] + 4); /*0x177de3*/
      v16 = *v15; /*0x177de6*/
      *(_DWORD *)v15[1] = v15; /*0x177deb*/
      *(_DWORD *)(v16 + 4) = v15; /*0x177ded*/
      v17 = *(_BYTE *)(i + 24); /*0x177df3*/
      if ( (v17 & 1) != 0 )
      {
        if ( vm_map_copy(
               (int)v29,
               *(_DWORD *)(i + 16),
               *(_DWORD *)(v26 + 8),
               *(_DWORD *)(v26 + 12) - *(_DWORD *)(v26 + 8),
               *(_DWORD *)(i + 20),
               0,
               0) )
        {
          printf("vm_map_fork: copy in share_map region failed\n");
        }
      }
      else if ( (v17 & 4) == 0 && (*(_BYTE *)(v26 + 24) & 4) == 0 ) /*0x177e4b*/
      {
        if ( *(_WORD *)(v26 + 40) ) /*0x177e51*/
        {
          vm_fault_unwire((int)v29, v26); /*0x177e5d*/
          *(_WORD *)(v26 + 40) = 0; /*0x177e62*/
        }
        if ( !v29[11] ) /*0x177e6e*/
          vm_object_pmap_remove( /*0x177e8b*/
            *(_DWORD *)(v26 + 16),
            *(_DWORD *)(v26 + 20),
            *(_DWORD *)(v26 + 20) + *(_DWORD *)(v26 + 12) - *(_DWORD *)(v26 + 8));
        pmap_remove(v29[9], *(_DWORD *)(v26 + 8), *(_DWORD *)(v26 + 12)); /*0x177ea8*/
        if ( *(_WORD *)(i + 40) ) /*0x177eb3*/
        {
          vm_fault_copy_entry((int)v29, a1, (_DWORD *)v26, i); /*0x177fe8*/
        }
        else
        {
          if ( (*(_BYTE *)(i + 24) & 0x40) == 0 ) /*0x177ec2*/
          {
            if ( *(_DWORD *)(a1 + 44) ) /*0x177ec7*/
              goto LABEL_49; /*0x177ec7*/
            v18 = (volatile __int32 *)(a1 + 52); /*0x177ecf*/
            do /*0x177ee6*/
            {
              while ( *v18 ) /*0x177ed4*/
                ; /*0x177ed6*/
            }
            while ( _InterlockedExchange(v18, 1) == 1 ); /*0x177ee6*/
            v19 = *(_DWORD *)(a1 + 48) == 1; /*0x177ef2*/
            _InterlockedExchange((volatile __int32 *)(a1 + 52), 0); /*0x177ef7*/
            if ( v19 ) /*0x177efc*/
            {
LABEL_49:
              v20 = *(_DWORD *)(i + 28); /*0x177f01*/
              LOBYTE(v20) = v20 & 0xFD; /*0x177f04*/
              pmap_protect(*(_DWORD *)(a1 + 36), *(_DWORD *)(i + 8), *(_DWORD *)(i + 12), v20); /*0x177f16*/
            }
            else
            {
              vm_object_pmap_copy( /*0x177f37*/
                *(_DWORD *)(i + 16),
                *(_DWORD *)(i + 20),
                *(_DWORD *)(i + 20) + *(_DWORD *)(i + 12) - *(_DWORD *)(i + 8));
            }
          }
          v21 = *(_DWORD *)(v26 + 16); /*0x177f42*/
          vm_object_copy( /*0x177f6f*/
            *(_DWORD *)(i + 16),
            *(_DWORD *)(i + 20),
            *(_DWORD *)(i + 12) - *(_DWORD *)(i + 8),
            v26 + 16,
            v26 + 20,
            &v30);
          if ( v30 ) /*0x177f7b*/
            *(_BYTE *)(i + 24) |= 0x40u; /*0x177f80*/
          *(_BYTE *)(v26 + 24) |= 0x40u; /*0x177f87*/
          *(_BYTE *)(i + 24) |= 8u; /*0x177f8e*/
          *(_BYTE *)(v26 + 24) |= 8u; /*0x177f92*/
          if ( (*(_BYTE *)(i + 28) & 4) != 0 ) /*0x177f9a*/
            *(_DWORD *)(v26 + 28) |= *(_DWORD *)(v26 + 32) & 4; /*0x177fa2*/
          vm_object_deallocate(v21); /*0x177fa6*/
          pmap_copy( /*0x177fcd*/
            v29[9],
            *(_DWORD *)(a1 + 36),
            *(_DWORD *)(v26 + 8),
            *(_DWORD *)(v26 + 12) - *(_DWORD *)(v26 + 8),
            *(_DWORD *)(i + 8));
        }
      }
    }
    else if ( !v4 ) /*0x177b79*/
    {
      if ( (*(_BYTE *)(i + 24) & 1) == 0 ) /*0x177b8b*/
      {
        v5 = *(_DWORD *)(i + 8); /*0x177b91*/
        v24 = *(_DWORD *)(i + 12); /*0x177b97*/
        v6 = (_DWORD *)zalloc(vm_map_zone); /*0x177ba6*/
        if ( !v6 ) /*0x177bad*/
          panic(aVmMapCreate); /*0x177bb4*/
        v6[4] = v6 + 3; /*0x177bbf*/
        v6[3] = v6 + 3; /*0x177bc2*/
        v6[7] = 0; /*0x177bc5*/
        v6[8] = 1; /*0x177bcc*/
        v6[10] = 0; /*0x177bd3*/
        v6[12] = 1; /*0x177bda*/
        v6[9] = 0; /*0x177be1*/
        v6[11] = 1; /*0x177be8*/
        v6[5] = v5; /*0x177bef*/
        v6[6] = v24; /*0x177bf5*/
        v6[18] = 0; /*0x177bf8*/
        v6[17] = 0; /*0x177bff*/
        v6[16] = v6 + 3; /*0x177c06*/
        v6[14] = v6 + 3; /*0x177c09*/
        v6[19] = 0; /*0x177c0c*/
        lock_init(v6, 1); /*0x177c16*/
        v6[19] = 0; /*0x177c1b*/
        v6[13] = 0; /*0x177c25*/
        v6[15] = 0; /*0x177c2c*/
        v6[11] = 0; /*0x177c33*/
        if ( v6[8] ) /*0x177c3a*/
          v7 = vm_map_entry_zone; /*0x177c40*/
        else
          v7 = vm_map_kentry_zone; /*0x177c48*/
        v25 = (int *)zalloc(v7); /*0x177c53*/
        if ( !v25 ) /*0x177c5b*/
          panic(aVmMapEntryCrea); /*0x177c62*/
        qmemcpy(v25, (const void *)i, 0x2Cu); /*0x177c78*/
        ++v6[7]; /*0x177c7a*/
        *v25 = v6[3]; /*0x177c83*/
        v25[1] = *(_DWORD *)(v6[3] + 4); /*0x177c8b*/
        v8 = *v25; /*0x177c8e*/
        *(_DWORD *)v25[1] = v25; /*0x177c93*/
        *(_DWORD *)(v8 + 4) = v25; /*0x177c95*/
        *(_BYTE *)(i + 24) |= 1u; /*0x177c9b*/
        *(_DWORD *)(i + 16) = v6; /*0x177c9f*/
        *(_DWORD *)(i + 20) = *(_DWORD *)(i + 8); /*0x177ca8*/
      }
      if ( v29[8] ) /*0x177cae*/
        v9 = vm_map_entry_zone; /*0x177cb4*/
      else
        v9 = vm_map_kentry_zone; /*0x177cbc*/
      v10 = (int *)zalloc(v9); /*0x177cc2*/
      if ( !v10 ) /*0x177cce*/
        panic(aVmMapEntryCrea); /*0x177cd5*/
      qmemcpy(v10, (const void *)i, 0x2Cu); /*0x177cee*/
      v11 = v10[4]; /*0x177cf0*/
      if ( v11 ) /*0x177cf5*/
      {
        v12 = (volatile __int32 *)(v11 + 52); /*0x177cf7*/
        do /*0x177d0e*/
        {
          while ( *v12 ) /*0x177cfc*/
            ; /*0x177cfe*/
        }
        while ( _InterlockedExchange(v12, 1) == 1 ); /*0x177d0e*/
        ++*(_DWORD *)(v11 + 48); /*0x177d10*/
        _InterlockedExchange((volatile __int32 *)(v11 + 52), 0); /*0x177d15*/
      }
      ++v29[7]; /*0x177d1b*/
      *v10 = v29[3]; /*0x177d24*/
      v10[1] = *(_DWORD *)(v29[3] + 4); /*0x177d32*/
      v13 = *v10; /*0x177d35*/
      *(_DWORD *)v10[1] = v10; /*0x177d3a*/
      *(_DWORD *)(v13 + 4) = v10; /*0x177d3c*/
      pmap_copy(v29[9], *(_DWORD *)(a1 + 36), v10[2], *(_DWORD *)(i + 12) - *(_DWORD *)(i + 8), *(_DWORD *)(i + 8)); /*0x177d65*/
    }
  }
  v29[10] = *(_DWORD *)(a1 + 40); /*0x178010*/
  lock_done(a1); /*0x178017*/
  return v29; /*0x178022*/
}
