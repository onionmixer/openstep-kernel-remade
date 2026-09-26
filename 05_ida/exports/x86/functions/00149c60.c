/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x149c60. */
int __cdecl ipc_kmsg_copyout_compat(_DWORD *a1, int a2, vm_map_t target_task)
{
  int v3; // ecx
  int v4; // edi
  int v5; // edx
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // edi
  _BOOL4 v8; // esi
  int v9; // eax
  void **v10; // ecx
  unsigned __int8 *v11; // esi
  int v12; // eax
  unsigned int v13; // edi
  _DWORD *v14; // esi
  void **i; // eax
  int v16; // eax
  unsigned int v17; // eax
  vm_address_t v18; // eax
  __int16 v19; // ax
  int *v20; // eax
  int *v21; // esi
  int v22; // edi
  unsigned int v23; // eax
  void *v24; // esi
  unsigned int v26; // [esp+Ch] [ebp-64h]
  kern_return_t v27; // [esp+10h] [ebp-60h]
  unsigned int j; // [esp+10h] [ebp-60h]
  int v29; // [esp+10h] [ebp-60h]
  int v30; // [esp+10h] [ebp-60h]
  void **v31; // [esp+14h] [ebp-5Ch]
  void **v32; // [esp+14h] [ebp-5Ch]
  void **v33; // [esp+14h] [ebp-5Ch]
  void **v34; // [esp+14h] [ebp-5Ch]
  void **v35; // [esp+14h] [ebp-5Ch]
  void **v36; // [esp+14h] [ebp-5Ch]
  void **v37; // [esp+14h] [ebp-5Ch]
  _DWORD *v38; // [esp+1Ch] [ebp-54h]
  unsigned int v39; // [esp+20h] [ebp-50h]
  int v40; // [esp+24h] [ebp-4Ch]
  _BOOL4 v41; // [esp+28h] [ebp-48h]
  unsigned int size; // [esp+2Ch] [ebp-44h]
  _BOOL4 v43; // [esp+34h] [ebp-3Ch]
  unsigned int v44; // [esp+38h] [ebp-38h]
  int v45; // [esp+3Ch] [ebp-34h]
  unsigned __int8 *v46; // [esp+40h] [ebp-30h]
  unsigned int v47; // [esp+44h] [ebp-2Ch]
  int v48; // [esp+48h] [ebp-28h]
  vm_address_t address; // [esp+4Ch] [ebp-24h] BYREF
  int v50; // [esp+50h] [ebp-20h] BYREF
  int v51; // [esp+54h] [ebp-1Ch] BYREF
  _DWORD v52[6]; // [esp+58h] [ebp-18h] BYREF

  v48 = a1[5]; /*0x149c6f*/
  v3 = a1[7]; /*0x149c75*/
  v4 = a1[8]; /*0x149c78*/
  do /*0x149c8e*/
  {
    while ( *(_DWORD *)v3 ) /*0x149c7c*/
      ; /*0x149c7e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x149c8e*/
  if ( *(int *)(v3 + 8) >= 0 ) /*0x149c94*/
  {
    v5 = *(_DWORD *)(v3 + 4) - 1; /*0x149cb3*/
    *(_DWORD *)(v3 + 4) = v5; /*0x149cb6*/
    _InterlockedExchange((volatile __int32 *)v3, 0); /*0x149cbc*/
    if ( !v5 ) /*0x149cc0*/
      zfree(ipc_object_zones[*(_WORD *)(v3 + 10) & 0x7FFF], v3); /*0x149cd4*/
    v51 = 0; /*0x149cdc*/
  }
  else
  {
    ipc_object_copyout_dest(a2, v3, (unsigned __int8)v48, &v51); /*0x149ca4*/
  }
  if ( !v4 || v4 == -1 ) /*0x149cea*/
  {
    v50 = 0; /*0x149d28*/
  }
  else if ( ipc_object_copyout_compat(a2, v4, (unsigned __int16)(v48 & 0xFF00) >> 8, &v50) ) /*0x149d03*/
  {
    ipc_object_destroy(v4, (unsigned __int16)(v48 & 0xFF00) >> 8); /*0x149d14*/
    v50 = 0; /*0x149d19*/
  }
  v52[0] &= 0xFF000000; /*0x149d2f*/
  HIBYTE(v52[0]) = v48 >= 0; /*0x149d3e*/
  v52[1] = a1[6]; /*0x149d47*/
  v52[2] = a1[9]; /*0x149d50*/
  v52[3] = v51; /*0x149d56*/
  v52[4] = v50; /*0x149d5c*/
  v52[5] = a1[10]; /*0x149d65*/
  qmemcpy(a1 + 5, v52, 0x18u); /*0x149d77*/
  if ( !HIBYTE(v52[0]) ) /*0x149d7d*/
  {
    v6 = (unsigned __int8 *)(a1 + 11); /*0x149d86*/
    v47 = (unsigned int)a1 + a1[6] + 20; /*0x149d94*/
    if ( (unsigned int)(a1 + 11) < v47 ) /*0x149d99*/
    {
      do /*0x149da0*/
      {
        v46 = v6; /*0x149da0*/
        v7 = v6; /*0x149da3*/
        v43 = (v6[3] & 0x10) != 0; /*0x149db0*/
        v8 = (v6[3] & 0x20) != 0; /*0x149dc1*/
        if ( (v6[3] & 0x20) != 0 ) /*0x149dc5*/
        {
          v45 = *((unsigned __int16 *)v6 + 2); /*0x149dcb*/
          v9 = *((unsigned __int16 *)v6 + 3); /*0x149dce*/
          v44 = *((_DWORD *)v6 + 2); /*0x149dd5*/
          v10 = (void **)(v6 + 12); /*0x149dd8*/
        }
        else
        {
          v45 = *v6; /*0x149de3*/
          v9 = v6[1]; /*0x149de6*/
          v44 = *((_WORD *)v6 + 1) & 0xFFF; /*0x149df4*/
          v10 = (void **)(v6 + 4); /*0x149df7*/
        }
        size = (v44 * v9 + 7) >> 3; /*0x149e04*/
        if ( (unsigned int)(v45 - 16) <= 5 ) /*0x149e20*/
        {
          if ( !v43 ) /*0x149e2a*/
          {
            if ( size ) /*0x149e34*/
            {
              v31 = v10; /*0x149e48*/
              v27 = vm_allocate(target_task, &address, size, 1); /*0x149e50*/
              v10 = v31; /*0x149e56*/
              if ( v27 ) /*0x149e5b*/
              {
                v11 = v46; /*0x149e61*/
                if ( v46 < (unsigned __int8 *)v31 ) /*0x149e66*/
                {
                  do /*0x149f87*/
                  {
                    v41 = (v11[3] & 0x10) != 0; /*0x149e77*/
                    if ( (v11[3] & 0x20) != 0 ) /*0x149e80*/
                    {
                      v40 = *((unsigned __int16 *)v11 + 2); /*0x149e86*/
                      v12 = *((unsigned __int16 *)v11 + 3); /*0x149e89*/
                      v13 = *((_DWORD *)v11 + 2); /*0x149e8d*/
                      v14 = v11 + 12; /*0x149e90*/
                    }
                    else
                    {
                      v40 = *v11; /*0x149e9b*/
                      v12 = v11[1]; /*0x149e9e*/
                      v13 = *((_WORD *)v11 + 1) & 0xFFF; /*0x149ea6*/
                      v14 = v11 + 4; /*0x149eac*/
                    }
                    v39 = (v13 * v12 + 7) >> 3; /*0x149eb8*/
                    if ( (unsigned int)(v40 - 16) <= 5 ) /*0x149ed4*/
                    {
                      if ( v41 ) /*0x149eda*/
                      {
                        v38 = v14; /*0x149edc*/
                        for ( i = (void **)&v14[v13]; v10 < i; --v13 ) /*0x149ee4*/
                          --i; /*0x149ee8*/
                      }
                      else
                      {
                        v38 = (_DWORD *)*v14; /*0x149ef6*/
                      }
                      for ( j = 0; j < v13; ++j ) /*0x149f03*/
                      {
                        v16 = v38[j]; /*0x149f0e*/
                        if ( v16 && v16 != -1 ) /*0x149f18*/
                        {
                          v32 = v10; /*0x149f1f*/
                          ipc_object_destroy(v16, v40); /*0x149f22*/
                          v10 = v32; /*0x149f2a*/
                        }
                      }
                    }
                    if ( v41 ) /*0x149f39*/
                    {
                      v17 = v39 + 3; /*0x149f3e*/
                      LOBYTE(v17) = (v39 + 3) & 0xFC; /*0x149f41*/
                      v11 = (unsigned __int8 *)v14 + v17; /*0x149f43*/
                    }
                    else
                    {
                      v18 = *v14; /*0x149f48*/
                      if ( v39 ) /*0x149f4e*/
                      {
                        v33 = v10; /*0x149f5b*/
                        if ( (unsigned int)(v40 - 16) > 5 ) /*0x149f54*/
                          vm_deallocate(ipc_soft_map, v18, v39); /*0x149f77*/
                        else
                          kfree(v18, v39); /*0x149f5e*/
                        v10 = v33; /*0x149f7f*/
                      }
                      v11 = (unsigned __int8 *)(v14 + 1); /*0x149f82*/
                    }
                  }
                  while ( v11 < (unsigned __int8 *)v10 ); /*0x149f87*/
                }
LABEL_67:
                address = 0; /*0x14a0b2*/
                goto LABEL_68; /*0x14a0b2*/
              }
            }
          }
          v34 = v10; /*0x149f98*/
          v19 = ipc_object_copyout_type_compat(v45); /*0x149f9b*/
          v10 = v34; /*0x149fa3*/
          if ( v8 ) /*0x149fa8*/
            *((_WORD *)v7 + 2) = v19; /*0x149faa*/
          else
            *v7 = v19; /*0x149fb0*/
          v20 = (int *)v34; /*0x149fb2*/
          if ( !v43 ) /*0x149fb8*/
            v20 = (int *)*v34; /*0x149fba*/
          v26 = 0; /*0x149fbc*/
          if ( v44 ) /*0x149fc9*/
          {
            v21 = v20; /*0x149fcb*/
            do /*0x14a025*/
            {
              v22 = *v21; /*0x149fd0*/
              if ( *v21 && v22 != -1 ) /*0x149fd9*/
              {
                v35 = v10; /*0x149fee*/
                v29 = ipc_object_copyout_compat(a2, v22, v45, v21); /*0x149ff6*/
                v10 = v35; /*0x149ffc*/
                if ( v29 ) /*0x14a001*/
                {
                  ipc_object_destroy(v22, v45); /*0x14a008*/
                  *v21 = 0; /*0x14a00d*/
                  v10 = v35; /*0x14a016*/
                }
              }
              else
              {
                *v21 = 0; /*0x149fdb*/
              }
              ++v21; /*0x14a019*/
              ++v26; /*0x14a01c*/
            }
            while ( v26 < v44 ); /*0x14a025*/
          }
        }
        if ( !v43 ) /*0x14a02b*/
        {
          v24 = *v10; /*0x14a03c*/
          if ( !size ) /*0x14a042*/
            goto LABEL_67; /*0x14a042*/
          if ( (unsigned int)(v45 - 16) > 5 ) /*0x14a048*/
          {
            v37 = v10; /*0x14a08a*/
            v30 = vm_move(ipc_soft_map, (int)v24, target_task, size, 0, (int)&address); /*0x14a092*/
            vm_deallocate(ipc_soft_map, (vm_address_t)v24, size); /*0x14a0a1*/
            v10 = v37; /*0x14a0a9*/
            if ( v30 ) /*0x14a0b0*/
              goto LABEL_67; /*0x14a0b0*/
          }
          else
          {
            v36 = v10; /*0x14a057*/
            copyoutmap(target_task, v24, (void *)address, size); /*0x14a05a*/
            kfree(v24, size); /*0x14a064*/
            v10 = v36; /*0x14a06c*/
          }
LABEL_68:
          *v10 = (void *)address; /*0x14a0b9*/
          v6 = (unsigned __int8 *)(v10 + 1); /*0x14a0be*/
          continue; /*0x14a0be*/
        }
        v23 = size + 3; /*0x14a030*/
        LOBYTE(v23) = (size + 3) & 0xFC; /*0x14a033*/
        v6 = (unsigned __int8 *)v10 + v23; /*0x14a035*/
      }
      while ( v47 > (unsigned int)v6 ); /*0x149da0*/
    }
  }
  return 0; /*0x14a0cf*/
}
