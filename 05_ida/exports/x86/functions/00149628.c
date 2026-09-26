/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x149628. */
int __cdecl ipc_kmsg_copyin_compat(_DWORD *a1, int a2, vm_map_t target_task)
{
  int v3; // edi
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // edi
  int v7; // edx
  void **v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // edx
  int v11; // eax
  vm_size_t v12; // edx
  kern_return_t v13; // eax
  int v14; // eax
  void **v15; // edi
  void *v16; // edx
  int v17; // eax
  int v18; // eax
  vm_size_t size; // [esp+Ch] [ebp-68h]
  unsigned int v20; // [esp+10h] [ebp-64h]
  _BOOL4 v21; // [esp+14h] [ebp-60h]
  void **v22; // [esp+14h] [ebp-60h]
  void **v23; // [esp+18h] [ebp-5Ch]
  void **v24; // [esp+18h] [ebp-5Ch]
  unsigned __int8 *v25; // [esp+18h] [ebp-5Ch]
  unsigned __int8 *v26; // [esp+18h] [ebp-5Ch]
  int v27; // [esp+1Ch] [ebp-58h]
  void *address; // [esp+20h] [ebp-54h]
  _BOOL4 v29; // [esp+28h] [ebp-4Ch]
  _BOOL4 v30; // [esp+2Ch] [ebp-48h]
  unsigned int v31; // [esp+30h] [ebp-44h]
  int v32; // [esp+34h] [ebp-40h]
  unsigned __int8 *v33; // [esp+38h] [ebp-3Ch]
  int v34; // [esp+3Ch] [ebp-38h]
  unsigned int v35; // [esp+40h] [ebp-34h]
  void *v36; // [esp+44h] [ebp-30h] BYREF
  int v37; // [esp+48h] [ebp-2Ch] BYREF
  int v38; // [esp+4Ch] [ebp-28h] BYREF
  int v39; // [esp+50h] [ebp-24h] BYREF
  int v40; // [esp+54h] [ebp-20h] BYREF
  int v41; // [esp+58h] [ebp-1Ch] BYREF
  _DWORD v42[6]; // [esp+5Ch] [ebp-18h] BYREF

  qmemcpy(v42, a1 + 5, sizeof(v42)); /*0x149642*/
  v3 = v42[3]; /*0x149644*/
  if ( ipc_object_copyin_header(a2, v42[4], &v41, &v40) ) /*0x149657*/
    return 268435459; /*0x149668*/
  if ( v3 ) /*0x149672*/
  {
    if ( ipc_object_copyin_header(a2, v3, &v39, &v38) ) /*0x149681*/
    {
      ipc_object_destroy(v41, v40); /*0x149695*/
      return 268435465; /*0x14969f*/
    }
  }
  else
  {
    v39 = 0; /*0x1496a4*/
    v38 = 0; /*0x1496ab*/
  }
  a1[5] = v40 | (v38 << 8); /*0x1496be*/
  a1[6] = v42[1]; /*0x1496c4*/
  a1[7] = v41; /*0x1496ca*/
  a1[8] = v39; /*0x1496d0*/
  a1[9] = v42[2]; /*0x1496d6*/
  a1[10] = v42[5]; /*0x1496dc*/
  if ( HIBYTE(v42[0]) ) /*0x1496e3*/
    return 0; /*0x1496e7*/
  v34 = 0; /*0x149760*/
  v5 = (unsigned __int8 *)(a1 + 11); /*0x14976a*/
  v35 = (unsigned int)a1 + a1[6] + 20; /*0x149778*/
  if ( (unsigned int)(a1 + 11) >= v35 ) /*0x14977d*/
  {
LABEL_57:
    if ( v34 ) /*0x149a4b*/
      a1[5] |= 0x80000000; /*0x149a50*/
    return 0; /*0x149a57*/
  }
  while ( 1 ) /*0x149784*/
  {
    v33 = v5; /*0x149784*/
    v6 = v5; /*0x149787*/
    if ( v35 - (unsigned int)v5 <= 3 /*0x1497a6*/
      || (v30 = (v5[3] & 0x20) != 0, (v5[3] & 0x20) != 0) && v35 - (unsigned int)v5 <= 0xB )
    {
      ipc_kmsg_clean_partial(a1, v5, 0, 0); /*0x1497b1*/
      return 268435464; /*0x1497bb*/
    }
    v21 = (v5[3] & 0x10) != 0; /*0x1497cd*/
    v29 = (v5[3] & 0x40) != 0; /*0x1497d8*/
    if ( (v5[3] & 0x20) != 0 ) /*0x1497df*/
    {
      v32 = *((unsigned __int16 *)v5 + 2); /*0x1497e5*/
      v7 = *((unsigned __int16 *)v5 + 3); /*0x1497e8*/
      v31 = *((_DWORD *)v5 + 2); /*0x1497ef*/
      v8 = (void **)(v5 + 12); /*0x1497f2*/
    }
    else
    {
      v32 = *v5; /*0x1497fb*/
      v7 = v5[1]; /*0x1497fe*/
      v31 = *((_WORD *)v5 + 1) & 0xFFF; /*0x14980c*/
      v8 = (void **)(v5 + 4); /*0x14980f*/
    }
    if ( (unsigned int)(v32 - 5) <= 1 && v7 != 32 ) /*0x149830*/
    {
      ipc_kmsg_clean_partial(a1, v33, 0, 0); /*0x1496f8*/
      return 268435471; /*0x149702*/
    }
    v6[3] &= ~0x80u; /*0x149836*/
    if ( v30 ) /*0x14983e*/
    {
      *v6 = 0; /*0x149840*/
      v6[1] = 0; /*0x149843*/
      *((_WORD *)v6 + 1) &= 0xF000u; /*0x149847*/
    }
    v9 = (v7 * v31 + 7) >> 3; /*0x149858*/
    if ( v21 ) /*0x14985f*/
    {
      v10 = v9 + 3; /*0x149864*/
      LOBYTE(v10) = v10 & 0xFC; /*0x149866*/
      if ( v35 - (unsigned int)v8 < v10 ) /*0x149870*/
        goto LABEL_10; /*0x149870*/
      v22 = v8; /*0x149876*/
      v5 = (unsigned __int8 *)v8 + v10; /*0x149879*/
      goto LABEL_41; /*0x14987b*/
    }
    if ( v35 - (unsigned int)v8 <= 3 ) /*0x149888*/
    {
LABEL_10:
      ipc_kmsg_clean_partial(a1, v33, 0, 0); /*0x149708*/
      return 268435464; /*0x14971e*/
    }
    address = *v8; /*0x149890*/
    if ( !v9 ) /*0x149895*/
    {
      v22 = nullptr; /*0x149897*/
      goto LABEL_40; /*0x14989e*/
    }
    if ( (unsigned int)(v32 - 5) > 1 ) /*0x1498a8*/
    {
      v24 = v8; /*0x149938*/
      v14 = vm_move(target_task, (int)address, ipc_soft_map, v9, v29, (int)&v37); /*0x14993b*/
      v8 = v24; /*0x149943*/
      if ( v14 ) /*0x149948*/
        goto LABEL_38; /*0x149948*/
      v22 = (void **)v37; /*0x14996b*/
      goto LABEL_40; /*0x14996b*/
    }
    size = v9; /*0x1498ab*/
    v23 = v8; /*0x1498ae*/
    v22 = (void **)kalloc(v9); /*0x1498b6*/
    if ( !v22 ) /*0x1498c4*/
      goto LABEL_38; /*0x1498c4*/
    v11 = copyinmap(target_task, address, v22, size); /*0x1498dd*/
    v12 = size; /*0x1498e5*/
    v8 = v23; /*0x1498e8*/
    if ( v11 ) /*0x1498ed*/
      break; /*0x1498ed*/
    if ( v29 ) /*0x1498f3*/
    {
      v13 = vm_deallocate(target_task, (vm_address_t)address, size); /*0x1498fe*/
      v12 = size; /*0x149906*/
      v8 = v23; /*0x149909*/
      if ( v13 ) /*0x14990e*/
        break; /*0x14990e*/
    }
LABEL_40:
    *v8 = v22; /*0x14996e*/
    v5 = (unsigned __int8 *)(v8 + 1); /*0x149973*/
    v34 = 1; /*0x149976*/
LABEL_41:
    if ( (unsigned int)(v32 - 5) <= 1 ) /*0x149981*/
    {
      v25 = v5; /*0x14998b*/
      v27 = ipc_object_copyin_type(v32); /*0x149993*/
      v5 = v25; /*0x14999c*/
      if ( v30 ) /*0x1499a3*/
        *((_WORD *)v6 + 2) = v27; /*0x1499a9*/
      else
        *v6 = v27; /*0x1499b3*/
      v20 = 0; /*0x1499b5*/
      if ( v31 ) /*0x1499c2*/
      {
        v15 = v22; /*0x1499c4*/
        do /*0x1499c8*/
        {
          v16 = *v15; /*0x1499c8*/
          if ( *v15 && v16 != (void *)-1 ) /*0x1499d1*/
          {
            v26 = v5; /*0x1499e4*/
            v17 = ipc_object_copyin_compat(a2, v16, v32, v29, &v36); /*0x1499e7*/
            v5 = v26; /*0x1499ef*/
            if ( v17 ) /*0x1499f4*/
            {
              ipc_kmsg_clean_partial(a1, v33, 1, v20); /*0x14974e*/
              return 268435466; /*0x149758*/
            }
            if ( v27 == 16 ) /*0x1499fe*/
            {
              v18 = ipc_port_check_circularity(v36, v41); /*0x149a0b*/
              v5 = v26; /*0x149a13*/
              if ( v18 ) /*0x149a18*/
                a1[5] |= 0x40000000u; /*0x149a1d*/
            }
            *v15 = v36; /*0x149a27*/
          }
          ++v15; /*0x149a29*/
          ++v20; /*0x149a2c*/
        }
        while ( v20 < v31 ); /*0x1499c8*/
      }
      v34 = 1; /*0x149a37*/
    }
    if ( v35 <= (unsigned int)v5 ) /*0x149a41*/
      goto LABEL_57; /*0x149a41*/
  }
  kfree(v22, v12); /*0x149915*/
LABEL_38:
  ipc_kmsg_clean_partial(a1, v33, 0, 0); /*0x14994a*/
  return 268435468; /*0x149a5c*/
}
