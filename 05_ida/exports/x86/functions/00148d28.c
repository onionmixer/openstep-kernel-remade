/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x148d28. */
int __cdecl ipc_kmsg_copyout_body(vm_address_t *a1, unsigned int a2, int a3, vm_map_t target_task)
{
  vm_address_t *v4; // ebx
  int v5; // eax
  vm_address_t *v6; // esi
  int v7; // eax
  unsigned int v8; // edi
  _DWORD *v9; // esi
  vm_address_t *i; // eax
  unsigned int j; // ebx
  int v12; // eax
  unsigned int v13; // eax
  vm_address_t v14; // eax
  int *v15; // eax
  int *v16; // edi
  unsigned int v17; // esi
  int v18; // ebx
  int v19; // eax
  unsigned int v20; // eax
  void *v21; // ebx
  volatile __int32 *v23; // [esp+10h] [ebp-4Ch]
  _DWORD *v24; // [esp+18h] [ebp-44h]
  unsigned int v25; // [esp+18h] [ebp-44h]
  unsigned int v26; // [esp+24h] [ebp-38h]
  int v27; // [esp+28h] [ebp-34h]
  _BOOL4 v28; // [esp+2Ch] [ebp-30h]
  unsigned int size; // [esp+30h] [ebp-2Ch]
  _BOOL4 v30; // [esp+38h] [ebp-24h]
  _BOOL4 v31; // [esp+3Ch] [ebp-20h]
  unsigned int v32; // [esp+40h] [ebp-1Ch]
  int v33; // [esp+44h] [ebp-18h]
  vm_address_t *v34; // [esp+48h] [ebp-14h]
  kern_return_t v35; // [esp+4Ch] [ebp-10h]
  int v36; // [esp+50h] [ebp-Ch]
  _DWORD *v37; // [esp+54h] [ebp-8h] BYREF
  vm_address_t address; // [esp+58h] [ebp-4h] BYREF
  vm_address_t *v39; // [esp+64h] [ebp+8h]

  v36 = 0; /*0x148d31*/
  while ( (unsigned int)a1 < a2 ) /*0x149142*/
  {
    v4 = a1; /*0x148d40*/
    v34 = a1; /*0x148d43*/
    v31 = (*((_BYTE *)a1 + 3) & 0x10) != 0; /*0x148d53*/
    v30 = (*((_BYTE *)a1 + 3) & 0x20) != 0; /*0x148d5f*/
    if ( (*((_BYTE *)a1 + 3) & 0x20) != 0 ) /*0x148d62*/
    {
      v33 = *((unsigned __int16 *)a1 + 2); /*0x148d68*/
      v5 = *((unsigned __int16 *)a1 + 3); /*0x148d6b*/
      v32 = a1[2]; /*0x148d72*/
      v39 = a1 + 3; /*0x148d75*/
    }
    else
    {
      v33 = *(unsigned __int8 *)a1; /*0x148d82*/
      v5 = *((unsigned __int8 *)a1 + 1); /*0x148d88*/
      v32 = *((_WORD *)a1 + 1) & 0xFFF; /*0x148d96*/
      v39 = a1 + 1; /*0x148d9c*/
    }
    size = (v32 * v5 + 7) >> 3; /*0x148da9*/
    if ( (unsigned int)(v33 - 16) <= 5 ) /*0x148dc5*/
    {
      if ( !v31 ) /*0x148dcf*/
      {
        if ( size ) /*0x148dd9*/
        {
          v35 = vm_allocate(target_task, &address, size, 1); /*0x148df2*/
          if ( v35 ) /*0x148dfa*/
          {
            v6 = v4; /*0x148e00*/
            while ( v39 > v6 ) /*0x148e05*/
            {
              v28 = (*((_BYTE *)v6 + 3) & 0x10) != 0; /*0x148e17*/
              if ( (*((_BYTE *)v6 + 3) & 0x20) != 0 ) /*0x148e20*/
              {
                v27 = *((unsigned __int16 *)v6 + 2); /*0x148e26*/
                v7 = *((unsigned __int16 *)v6 + 3); /*0x148e29*/
                v8 = v6[2]; /*0x148e2d*/
                v9 = v6 + 3; /*0x148e30*/
              }
              else
              {
                v27 = *(unsigned __int8 *)v6; /*0x148e3b*/
                v7 = *((unsigned __int8 *)v6 + 1); /*0x148e3e*/
                v8 = *((_WORD *)v6 + 1) & 0xFFF; /*0x148e46*/
                v9 = v6 + 1; /*0x148e4c*/
              }
              v26 = (v8 * v7 + 7) >> 3; /*0x148e58*/
              if ( (unsigned int)(v27 - 16) <= 5 ) /*0x148e74*/
              {
                if ( v28 ) /*0x148e7a*/
                {
                  v24 = v9; /*0x148e7c*/
                  for ( i = &v9[v8]; v39 < i; --v8 ) /*0x148e85*/
                    --i; /*0x148e88*/
                }
                else
                {
                  v24 = (_DWORD *)*v9; /*0x148e96*/
                }
                for ( j = 0; j < v8; ++j ) /*0x148e9d*/
                {
                  v12 = v24[j]; /*0x148ea3*/
                  if ( v12 && v12 != -1 ) /*0x148ead*/
                    ipc_object_destroy(v12, v27); /*0x148eb4*/
                }
              }
              if ( v28 ) /*0x148ec5*/
              {
                v13 = v26 + 3; /*0x148eca*/
                LOBYTE(v13) = (v26 + 3) & 0xFC; /*0x148ecd*/
                v6 = (_DWORD *)((char *)v9 + v13); /*0x148ecf*/
              }
              else
              {
                v14 = *v9; /*0x148ed4*/
                if ( v26 ) /*0x148eda*/
                {
                  if ( (unsigned int)(v27 - 16) > 5 ) /*0x148ee0*/
                    vm_deallocate(ipc_soft_map, v14, v26); /*0x148f00*/
                  else
                    kfree(v14, v26); /*0x148ee7*/
                }
                v6 = v9 + 1; /*0x148f08*/
              }
            }
LABEL_68:
            address = 0; /*0x1490f0*/
            if ( v30 ) /*0x1490fb*/
              *((_WORD *)v34 + 3) = 0; /*0x149100*/
            else
              *((_BYTE *)v34 + 1) = 0; /*0x14910b*/
            if ( v35 == 6 ) /*0x149113*/
              v36 |= 0x400u; /*0x149115*/
            else
              v36 |= 0x1000u; /*0x149120*/
            goto LABEL_74; /*0x14911c*/
          }
        }
      }
      v15 = (int *)v39; /*0x148f1c*/
      if ( !v31 ) /*0x148f23*/
        v15 = (int *)*v39; /*0x148f25*/
      v25 = 0; /*0x148f27*/
      if ( v32 ) /*0x148f34*/
      {
        v16 = v15; /*0x148f3a*/
        do /*0x148f3c*/
        {
          v17 = *v16; /*0x148f3c*/
          if ( *v16 && v17 != -1 ) /*0x148f45*/
          {
            if ( v33 == 17 ) /*0x148f54*/
            {
              v23 = (volatile __int32 *)(a3 + 8); /*0x148f62*/
              do /*0x148f80*/
              {
                while ( *v23 ) /*0x148f6b*/
                  ; /*0x148f6d*/
              }
              while ( _InterlockedExchange(v23, 1) == 1 ); /*0x148f80*/
              if ( *(_DWORD *)(a3 + 12) ) /*0x148f85*/
              {
                do /*0x148fa6*/
                {
                  while ( *(_DWORD *)v17 ) /*0x148f94*/
                    ; /*0x148f96*/
                }
                while ( _InterlockedExchange((volatile __int32 *)v17, 1) == 1 ); /*0x148fa6*/
                if ( *(int *)(v17 + 8) < 0 && ipc_hash_local_lookup(a3, v17, v16, &v37) ) /*0x148fb8*/
                {
                  --*(_DWORD *)(v17 + 28); /*0x148fd4*/
                  --*(_DWORD *)(v17 + 4); /*0x148fd7*/
                  _InterlockedExchange((volatile __int32 *)v17, 0); /*0x148fdc*/
                  if ( *(_WORD *)v37 != 0xFFFE ) /*0x148fe8*/
                    ++*v37; /*0x148fea*/
                  _InterlockedExchange((volatile __int32 *)(a3 + 8), 0); /*0x148ff1*/
                  goto LABEL_59; /*0x148ff4*/
                }
                _InterlockedExchange((volatile __int32 *)v17, 0); /*0x148fc6*/
                _InterlockedExchange((volatile __int32 *)(a3 + 8), 0); /*0x148fcd*/
              }
              else
              {
                _InterlockedExchange((volatile __int32 *)(a3 + 8), 0); /*0x148f8d*/
              }
            }
            v18 = ipc_object_copyout(a3, v17, v33, 1, v16); /*0x149009*/
            if ( v18 ) /*0x149010*/
            {
              ipc_object_destroy(v17, v33); /*0x149017*/
              if ( v18 != 20 ) /*0x149022*/
              {
                *v16 = 0; /*0x149024*/
                v19 = 0x2000; /*0x14902a*/
                if ( v18 == 6 ) /*0x149032*/
                  v19 = 2048; /*0x149034*/
                goto LABEL_60; /*0x149039*/
              }
              *v16 = -1; /*0x14903c*/
            }
          }
          else
          {
            *v16 = *v16; /*0x148f49*/
          }
LABEL_59:
          v19 = 0; /*0x149042*/
LABEL_60:
          v36 |= v19; /*0x149044*/
          ++v16; /*0x149047*/
          ++v25; /*0x14904a*/
        }
        while ( v25 < v32 ); /*0x148f3c*/
      }
    }
    if ( v31 ) /*0x14905d*/
    {
      *((_BYTE *)v34 + 3) &= ~0x40u; /*0x149062*/
      v20 = size + 3; /*0x149069*/
      LOBYTE(v20) = (size + 3) & 0xFC; /*0x14906c*/
      a1 = (vm_address_t *)((char *)v39 + v20); /*0x14906e*/
    }
    else
    {
      v21 = (void *)*v39; /*0x14907b*/
      if ( !size ) /*0x149081*/
      {
        address = 0; /*0x149083*/
        goto LABEL_74; /*0x14908a*/
      }
      if ( (unsigned int)(v33 - 16) <= 5 ) /*0x149094*/
      {
        copyoutmap(target_task, v21, (void *)address, size); /*0x1490a3*/
        kfree((int)v21, size); /*0x1490ad*/
        goto LABEL_74; /*0x1490b5*/
      }
      v35 = vm_move(ipc_soft_map, (int)v21, target_task, size, 0, (int)&address); /*0x1490d3*/
      vm_deallocate(ipc_soft_map, (vm_address_t)v21, size); /*0x1490e2*/
      if ( v35 ) /*0x1490ee*/
        goto LABEL_68; /*0x1490ee*/
LABEL_74:
      *((_BYTE *)v34 + 3) |= 0x40u; /*0x149127*/
      *v39 = address; /*0x149134*/
      a1 = v39 + 1; /*0x149139*/
    }
  }
  return v36; /*0x14914e*/
}
