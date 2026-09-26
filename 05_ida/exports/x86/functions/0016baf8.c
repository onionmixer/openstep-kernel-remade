/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16baf8. */
int __cdecl host_zone_info(int a1, int *a2, unsigned int *a3, int *a4, unsigned int *a5)
{
  int result; // eax
  int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  _BOOL4 v10; // edx
  int v11; // [esp+Ch] [ebp-70h]
  char *__dst; // [esp+10h] [ebp-6Ch]
  _DWORD *v13; // [esp+14h] [ebp-68h]
  unsigned int v14; // [esp+18h] [ebp-64h]
  unsigned int v15; // [esp+1Ch] [ebp-60h]
  int v16; // [esp+20h] [ebp-5Ch]
  int v17; // [esp+24h] [ebp-58h]
  int v18; // [esp+28h] [ebp-54h]
  int v19; // [esp+2Ch] [ebp-50h]
  _DWORD v20[17]; // [esp+30h] [ebp-4Ch] BYREF
  int v21; // [esp+74h] [ebp-8h] BYREF
  int v22; // [esp+78h] [ebp-4h] BYREF

  v18 = 0; /*0x16bb01*/
  v16 = 0; /*0x16bb08*/
  if ( !a1 ) /*0x16bb13*/
    return 22; /*0x16bb1a*/
  do /*0x16bb39*/
  {
    while ( all_zones_lock ) /*0x16bb27*/
      ; /*0x16bb25*/
  }
  while ( _InterlockedExchange(&all_zones_lock, 1) == 1 ); /*0x16bb39*/
  v15 = num_zones; /*0x16bb41*/
  v6 = first_zone; /*0x16bb44*/
  _InterlockedExchange(&all_zones_lock, 0); /*0x16bb4c*/
  if ( *a3 < num_zones ) /*0x16bb57*/
  {
    v18 = ~page_mask & (page_mask + 80 * num_zones); /*0x16bb79*/
    result = kmem_alloc_pageable(ipc_kernel_map, &v22, v18); /*0x16bb88*/
    if ( result ) /*0x16bb92*/
      return result; /*0x16bb92*/
    v19 = v22; /*0x16bb9b*/
  }
  else
  {
    v19 = *a2; /*0x16bb5e*/
  }
  if ( *a5 >= v15 ) /*0x16bba6*/
  {
    v7 = *a4; /*0x16bbab*/
LABEL_15:
    v17 = v7; /*0x16bc0f*/
    v14 = 0; /*0x16bc12*/
    if ( v15 ) /*0x16bc1f*/
    {
      v13 = (_DWORD *)v7; /*0x16bc28*/
      __dst = (char *)v19; /*0x16bc2e*/
      do /*0x16bd44*/
      {
        if ( (*(_BYTE *)(v6 + 44) & 1) != 0 ) /*0x16bc38*/
        {
          lock_write(v6 + 48); /*0x16bc3e*/
        }
        else
        {
          v8 = splhigh(); /*0x16bc4d*/
          do /*0x16bc62*/
          {
            while ( *(_DWORD *)v6 ) /*0x16bc50*/
              ; /*0x16bc52*/
          }
          while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x16bc62*/
          *(_DWORD *)(v6 + 4) = v8; /*0x16bc64*/
        }
        qmemcpy(v20, (const void *)v6, sizeof(v20)); /*0x16bc72*/
        if ( (*(_BYTE *)(v6 + 44) & 1) != 0 ) /*0x16bc78*/
        {
          lock_done(v6 + 48); /*0x16bc7e*/
        }
        else
        {
          v9 = *(_DWORD *)(v6 + 4); /*0x16bc88*/
          _InterlockedExchange((volatile __int32 *)v6, 0); /*0x16bc8d*/
          splx(v9); /*0x16bc90*/
        }
        do /*0x16bcb4*/
        {
          while ( all_zones_lock ) /*0x16bca2*/
            ; /*0x16bca0*/
        }
        while ( _InterlockedExchange(&all_zones_lock, 1) == 1 ); /*0x16bcb4*/
        v6 = *(_DWORD *)(v6 + 64); /*0x16bcb6*/
        _InterlockedExchange(&all_zones_lock, 0); /*0x16bcbb*/
        strncpy(__dst, (const char *)v20[10], 0x50u); /*0x16bccb*/
        *v13 = v20[2]; /*0x16bcd6*/
        v13[1] = v20[5]; /*0x16bcdb*/
        v13[2] = v20[6]; /*0x16bce1*/
        v13[3] = v20[7]; /*0x16bce7*/
        v13[4] = v20[8]; /*0x16bced*/
        v13[5] = v20[11] & 1; /*0x16bcf9*/
        v13[6] = (v20[11] & 2) != 0; /*0x16bd06*/
        v13[7] = (v20[11] & 4) != 0; /*0x16bd14*/
        v10 = 0; /*0x16bd1a*/
        if ( v20[15] ) /*0x16bd21*/
          v10 = v20[15] != (_DWORD)_zone_default_space; /*0x16bd2a*/
        v13[8] = v10; /*0x16bd2e*/
        v13 += 9; /*0x16bd34*/
        __dst += 80; /*0x16bd37*/
        ++v14; /*0x16bd3b*/
      }
      while ( v14 < v15 ); /*0x16bd44*/
    }
    if ( *a2 != v19 ) /*0x16bd52*/
    {
      if ( v18 != 80 * v15 ) /*0x16bd62*/
        bzero((void *)(80 * v15 + v22), v18 - 80 * v15); /*0x16bd70*/
      vm_move(ipc_kernel_map, v22, ipc_soft_map, v18, 1, (int)&v22); /*0x16bd94*/
      *a2 = v22; /*0x16bd9f*/
    }
    *a3 = v15; /*0x16bdaa*/
    if ( *a4 != v17 ) /*0x16bdb4*/
    {
      if ( v16 != 36 * v15 ) /*0x16bdc6*/
        bzero((void *)(36 * v15 + v21), v16 - 36 * v15); /*0x16bdd4*/
      vm_move(ipc_kernel_map, v21, ipc_soft_map, v16, 1, (int)&v21); /*0x16bdf8*/
      *a4 = v21; /*0x16be03*/
    }
    *a5 = v15; /*0x16be0b*/
    return 0; /*0x16be0d*/
  }
  v16 = ~page_mask & (page_mask + 36 * v15); /*0x16bbc3*/
  result = kmem_alloc_pageable(ipc_kernel_map, &v21, v16); /*0x16bbd2*/
  if ( !result ) /*0x16bbdc*/
  {
    v7 = v21; /*0x16bc0c*/
    goto LABEL_15; /*0x16bc0c*/
  }
  if ( *a2 != v19 ) /*0x16bbe6*/
  {
    v11 = result; /*0x16bbfb*/
    kmem_free(ipc_kernel_map, v22, v18); /*0x16bbfe*/
    return v11; /*0x16bc03*/
  }
  return result; /*0x16be12*/
}
