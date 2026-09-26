/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103824. */
_BOOL4 core()
{
  int v1; // ebx
  unsigned int v2; // edx
  unsigned int v3; // ebx
  int v4; // ebx
  _DWORD *v5; // edx
  int v6; // ebx
  _DWORD *v7; // edx
  vm_region_flavor_t v8; // edx
  _DWORD *v9; // edx
  unsigned int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // [esp+Ch] [ebp-108h]
  int v14; // [esp+10h] [ebp-104h]
  int v15; // [esp+10h] [ebp-104h]
  _DWORD *v16; // [esp+14h] [ebp-100h]
  int i; // [esp+1Ch] [ebp-F8h]
  int v18; // [esp+20h] [ebp-F4h]
  int v19; // [esp+24h] [ebp-F0h]
  int v20; // [esp+24h] [ebp-F0h]
  int v21; // [esp+28h] [ebp-ECh]
  int v22; // [esp+2Ch] [ebp-E8h]
  int v23; // [esp+30h] [ebp-E4h]
  vm_map_t target_task; // [esp+34h] [ebp-E0h]
  mach_port_t object_name; // [esp+40h] [ebp-D4h] BYREF
  mach_msg_type_number_t infoCnt; // [esp+44h] [ebp-D0h] BYREF
  int info; // [esp+48h] [ebp-CCh] BYREF
  vm_region_flavor_t flavor; // [esp+4Ch] [ebp-C8h] BYREF
  vm_size_t size; // [esp+50h] [ebp-C4h] BYREF
  vm_address_t address; // [esp+54h] [ebp-C0h] BYREF
  _DWORD *v31; // [esp+58h] [ebp-BCh] BYREF
  unsigned int v32; // [esp+5Ch] [ebp-B8h] BYREF
  int *v33; // [esp+60h] [ebp-B4h] BYREF
  _DWORD v34[20]; // [esp+64h] [ebp-B0h] BYREF
  char v35[32]; // [esp+B4h] [ebp-60h] BYREF
  int v36; // [esp+D4h] [ebp-40h] BYREF
  __int16 v37; // [esp+D8h] [ebp-3Ch]
  __int16 v38; // [esp+E8h] [ebp-2Ch]
  int v39; // [esp+ECh] [ebp-28h]

  if ( (*(_BYTE *)(*(_DWORD *)active_u + 43) & 2) != 0 ) /*0x10383b*/
    return 0; /*0x10383b*/
  *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 6); /*0x103848*/
  *(_WORD *)(*(_DWORD *)active_u + 44) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 6); /*0x10385b*/
  *(_WORD *)(*(_DWORD *)(active_u + 28) + 4) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 8); /*0x10386c*/
  *(_BYTE *)(active_u + 608) = 0; /*0x103876*/
  v18 = *(_DWORD *)(active_threads + 12); /*0x103886*/
  target_task = *(_DWORD *)(v18 + 12); /*0x10388f*/
  if ( *(_DWORD *)(target_task + 40) >= *(_DWORD *)(active_u + 644) ) /*0x1038a4*/
    return 0; /*0x1038a4*/
  task_halt(v18); /*0x1038b1*/
  pcb_synch(active_threads); /*0x1038bd*/
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x1038c8*/
  vattr_null(&v36); /*0x1038d6*/
  v36 = 1; /*0x1038db*/
  v37 = 420; /*0x1038e2*/
  sprintf(v35, "/cores/core.%d", *(__int16 *)(*(_DWORD *)active_u + 48)); /*0x1038fe*/
  *(_BYTE *)(dword_1E875C + 104) = vn_create(v35, 1, &v36, 0, 128, &v33); /*0x103936*/
  if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x103942*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 0; /*0x103948*/
    vattr_null(&v36); /*0x10394d*/
    v36 = 1; /*0x103952*/
    v37 = 420; /*0x103959*/
    *(_BYTE *)(dword_1E875C + 104) = vn_create(aCore, 1, &v36, 0, 128, &v33); /*0x103984*/
    if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x103990*/
      return 0; /*0x103996*/
  }
  if ( v38 == 1 ) /*0x1039a5*/
  {
    vattr_null(&v36); /*0x1039b8*/
    v39 = 0; /*0x1039bd*/
    (*(void (__cdecl **)(int *, int *, _DWORD))(v33[7] + 24))(v33, &v36, *(_DWORD *)(active_u + 28)); /*0x1039dc*/
    *(_BYTE *)(active_u + 580) |= 8u; /*0x1039e4*/
    v23 = *(_DWORD *)(v18 + 36); /*0x1039f4*/
    v14 = *(_DWORD *)(target_task + 28); /*0x103a03*/
    v32 = 20; /*0x103a09*/
    if ( thread_getstatus(active_threads, 0, v34, &v32) ) /*0x103a30*/
      panic(aCoreFlavorList); /*0x103a41*/
    v2 = v32 >> 1; /*0x103a4f*/
    v32 = v2; /*0x103a51*/
    v21 = 0; /*0x103a57*/
    v3 = 0; /*0x103a61*/
    if ( v2 ) /*0x103a65*/
    {
      v13 = 0; /*0x103a75*/
      do /*0x103ab1*/
      {
        v21 += 4 * v34[v13 + 1] + 8; /*0x103aa1*/
        v13 += 2; /*0x103aa7*/
        ++v3; /*0x103aae*/
      }
      while ( v3 < v2 ); /*0x103ab1*/
    }
    v4 = v23 * v21 + 8 * (v23 + 7 * v14); /*0x103ad2*/
    v22 = v4 + 28; /*0x103ad8*/
    kmem_alloc_wired(kernel_map, &v31, v4 + 28); /*0x103aed*/
    v5 = v31; /*0x103af2*/
    *v31 = -17958194; /*0x103af8*/
    v5[1] = dword_1E8E04; /*0x103b04*/
    v5[2] = dword_1E8E08; /*0x103b0d*/
    v5[3] = 4; /*0x103b10*/
    v5[4] = v14 + v23; /*0x103b23*/
    v5[5] = v4; /*0x103b26*/
    v19 = 28; /*0x103b29*/
    v6 = ~page_mask & (page_mask + v4 + 28); /*0x103b45*/
    for ( address = 0; v14 > 0; --v14 ) /*0x103b5b*/
    {
      if ( vm_region(target_task, &address, &size, (vm_region_flavor_t)&flavor, &info, &infoCnt, &object_name) == 3 ) /*0x103bae*/
        break; /*0x103bae*/
      v7 = (_DWORD *)((char *)v31 + v19); /*0x103bba*/
      *v7 = 1; /*0x103bc0*/
      v7[1] = 56; /*0x103bc6*/
      v7[6] = address; /*0x103bd3*/
      v7[7] = size; /*0x103bdc*/
      v7[8] = v6; /*0x103bdf*/
      v7[9] = size; /*0x103be8*/
      v7[10] = info; /*0x103bf1*/
      v7[11] = flavor; /*0x103bfa*/
      v7[12] = 0; /*0x103bfd*/
      v8 = flavor; /*0x103c04*/
      if ( (flavor & 1) == 0 ) /*0x103c0d*/
      {
        LOBYTE(v8) = flavor | 1; /*0x103c0f*/
        vm_protect(target_task, address, size, 0, v8); /*0x103c2a*/
      }
      if ( (info & 1) != 0 ) /*0x103c39*/
        vn_rdwr(1, v33, address, size, v6, 0, 1, nullptr); /*0x103c59*/
      v19 += 56; /*0x103c61*/
      v6 += size; /*0x103c6e*/
      address += size; /*0x103c70*/
    }
    do /*0x103caa*/
    {
      while ( *(_DWORD *)v18 ) /*0x103c92*/
        ; /*0x103c94*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v18, 1) == 1 ); /*0x103caa*/
    for ( i = *(_DWORD *)(v18 + 28); v23 > 0; --v23 ) /*0x103cbc*/
    {
      v9 = (_DWORD *)((char *)v31 + v19); /*0x103cd6*/
      *v9 = 4; /*0x103cdc*/
      v9[1] = v21 + 8; /*0x103ceb*/
      v19 += 8; /*0x103cee*/
      v10 = 0; /*0x103cf5*/
      if ( v32 ) /*0x103cfd*/
      {
        v16 = v34; /*0x103d09*/
        v15 = 0; /*0x103d0f*/
        do /*0x103d9f*/
        {
          v11 = v31; /*0x103d1c*/
          v12 = v34[2 * v10 + 1]; /*0x103d2f*/
          *(_DWORD *)((char *)v31 + v19) = v34[2 * v10]; /*0x103d36*/
          *(_DWORD *)((char *)v11 + v19 + 4) = v12; /*0x103d39*/
          v20 = v19 + 8; /*0x103d40*/
          thread_getstatus(i, *v16, (char *)v11 + v20, v16 + 1); /*0x103d63*/
          v19 = 4 * v34[v15 + 1] + v20; /*0x103d7f*/
          v16 += 2; /*0x103d88*/
          v15 += 2; /*0x103d92*/
          ++v10; /*0x103d98*/
        }
        while ( v32 > v10 ); /*0x103d9f*/
      }
      i = *(_DWORD *)(i + 16); /*0x103dae*/
    }
    _InterlockedExchange((volatile __int32 *)v18, 0); /*0x103dcf*/
    v1 = vn_rdwr(1, v33, (int)v31, v22, 0, 1, 1, nullptr); /*0x103df5*/
    kmem_free(kernel_map, v31, v22); /*0x103e09*/
  }
  else
  {
    v1 = 14; /*0x1039a7*/
  }
  vn_rele((int)v33); /*0x103e18*/
  *(_BYTE *)(dword_1E875C + 104) = v1; /*0x103e23*/
  return v1 == 0; /*0x103e34*/
}
