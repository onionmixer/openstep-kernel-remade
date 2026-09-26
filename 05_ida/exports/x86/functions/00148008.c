/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x148008. */
int __cdecl ipc_kmsg_copyin(_DWORD *a1, int a2, vm_map_t target_task, unsigned int a4)
{
  int result; // eax
  unsigned __int8 *v5; // edi
  _BOOL4 v6; // ebx
  int v7; // edx
  void **v8; // edi
  unsigned int v9; // edx
  unsigned int v10; // edx
  void **v11; // ebx
  void **v12; // eax
  int v13; // eax
  unsigned int v14; // edx
  kern_return_t v15; // eax
  void *v16; // edx
  vm_size_t size; // [esp+Ch] [ebp-44h]
  unsigned int i; // [esp+10h] [ebp-40h]
  unsigned __int8 *v19; // [esp+14h] [ebp-3Ch]
  int v20; // [esp+1Ch] [ebp-34h]
  void *address; // [esp+20h] [ebp-30h]
  _BOOL4 v22; // [esp+28h] [ebp-28h]
  _BOOL4 v23; // [esp+2Ch] [ebp-24h]
  unsigned int v24; // [esp+30h] [ebp-20h]
  int v25; // [esp+34h] [ebp-1Ch]
  unsigned __int8 *v26; // [esp+38h] [ebp-18h]
  int v27; // [esp+3Ch] [ebp-14h]
  unsigned int v28; // [esp+40h] [ebp-10h]
  int v29; // [esp+44h] [ebp-Ch]
  void *v30; // [esp+48h] [ebp-8h] BYREF
  int v31; // [esp+4Ch] [ebp-4h] BYREF

  result = ipc_kmsg_copyin_header(a1 + 5, a2, a4); /*0x148020*/
  if ( result ) /*0x14802a*/
    return result; /*0x14802a*/
  if ( (int)a1[5] >= 0 ) /*0x148037*/
    return 0; /*0x14803b*/
  v29 = a1[7]; /*0x14809e*/
  v27 = 0; /*0x1480a1*/
  v5 = (unsigned __int8 *)(a1 + 11); /*0x1480ab*/
  v28 = (unsigned int)a1 + a1[6] + 20; /*0x1480b9*/
  if ( (unsigned int)(a1 + 11) >= v28 ) /*0x1480be*/
  {
LABEL_54:
    if ( !v27 ) /*0x148383*/
      a1[5] &= ~0x80000000; /*0x148388*/
    return 0; /*0x14838f*/
  }
  while ( 1 ) /*0x1480c4*/
  {
    v26 = v5; /*0x1480c4*/
    v19 = v5; /*0x1480c7*/
    if ( v28 - (unsigned int)v5 <= 3 /*0x1480e7*/
      || (v23 = (v5[3] & 0x20) != 0, (v5[3] & 0x20) != 0) && v28 - (unsigned int)v5 <= 0xB )
    {
      ipc_kmsg_clean_partial(a1, v5, 0, 0); /*0x1480f2*/
      return 268435464; /*0x1480fc*/
    }
    v6 = (v5[3] & 0x10) != 0; /*0x148111*/
    v22 = (v5[3] & 0x40) != 0; /*0x14811c*/
    if ( (v5[3] & 0x20) != 0 ) /*0x148123*/
    {
      v25 = *((unsigned __int16 *)v5 + 2); /*0x148129*/
      v7 = *((unsigned __int16 *)v5 + 3); /*0x14812f*/
      v24 = *((_DWORD *)v5 + 2); /*0x148136*/
      v8 = (void **)(v5 + 12); /*0x148139*/
    }
    else
    {
      v25 = *v5; /*0x148146*/
      v7 = v5[1]; /*0x14814c*/
      v24 = *((_WORD *)v5 + 1) & 0xFFF; /*0x14815a*/
      v8 = (void **)(v5 + 4); /*0x14815d*/
    }
    if ( (unsigned int)(v25 - 16) <= 5 && v7 != 32 /*0x1481a2*/
      || v23 && (*(_DWORD *)v19 & 0xFFFFFFF) != 0
      || (v19[3] & 0x80u) != 0
      || v22 && v6 )
    {
      ipc_kmsg_clean_partial(a1, v26, 0, 0); /*0x1481b0*/
      return 268435471; /*0x1481ba*/
    }
    v9 = (v7 * v24 + 7) >> 3; /*0x1481cb*/
    if ( v6 ) /*0x1481d0*/
    {
      v10 = v9 + 3; /*0x1481d5*/
      LOBYTE(v10) = v10 & 0xFC; /*0x1481d7*/
      if ( v28 - (unsigned int)v8 < v10 ) /*0x1481e1*/
        goto LABEL_4; /*0x1481e1*/
      v11 = v8; /*0x1481e7*/
      v5 = (unsigned __int8 *)v8 + v10; /*0x1481e9*/
      goto LABEL_39; /*0x1481eb*/
    }
    if ( v28 - (unsigned int)v8 <= 3 ) /*0x1481f8*/
    {
LABEL_4:
      ipc_kmsg_clean_partial(a1, v26, 0, 0); /*0x148040*/
      return 268435464; /*0x148056*/
    }
    address = *v8; /*0x148200*/
    if ( !v9 ) /*0x148205*/
    {
      v11 = nullptr; /*0x148207*/
      goto LABEL_38; /*0x148209*/
    }
    if ( (unsigned int)(v25 - 16) > 5 ) /*0x148214*/
    {
      if ( vm_move(target_task, (int)address, ipc_soft_map, v9, v22, (int)&v31) ) /*0x14828c*/
        goto LABEL_36; /*0x148296*/
      v11 = (void **)v31; /*0x1482b4*/
      goto LABEL_38; /*0x1482b4*/
    }
    size = v9; /*0x148217*/
    v12 = (void **)kalloc(v9); /*0x14821a*/
    v11 = v12; /*0x14821f*/
    if ( !v12 ) /*0x148229*/
      goto LABEL_36; /*0x148229*/
    v13 = copyinmap(target_task, address, v12, size); /*0x148238*/
    v14 = size; /*0x148240*/
    if ( v13 ) /*0x148245*/
      break; /*0x148245*/
    if ( v22 ) /*0x14824b*/
    {
      v15 = vm_deallocate(target_task, (vm_address_t)address, size); /*0x148256*/
      v14 = size; /*0x14825e*/
      if ( v15 ) /*0x148263*/
        break; /*0x148263*/
    }
LABEL_38:
    *v8 = v11; /*0x1482b7*/
    v5 = (unsigned __int8 *)(v8 + 1); /*0x1482b9*/
    v27 = 1; /*0x1482bc*/
LABEL_39:
    if ( (unsigned int)(v25 - 16) <= 5 ) /*0x1482c7*/
    {
      v20 = ipc_object_copyin_type(v25); /*0x1482d6*/
      if ( v23 ) /*0x1482e2*/
        *((_WORD *)v19 + 2) = v20; /*0x1482eb*/
      else
        *v19 = v20; /*0x1482fa*/
      for ( i = 0; i < v24; ++i ) /*0x148309*/
      {
        v16 = *v11; /*0x148310*/
        if ( *v11 && v16 != (void *)-1 ) /*0x148319*/
        {
          if ( ipc_object_copyin(a2, v16, v25, &v30) ) /*0x148328*/
          {
            ipc_kmsg_clean_partial(a1, v26, 1, i); /*0x148086*/
            return 268435466; /*0x148090*/
          }
          if ( v20 == 16 && ipc_port_check_circularity(v30, v29) ) /*0x148346*/
            a1[5] |= 0x40000000u; /*0x148355*/
          *v11 = v30; /*0x14835f*/
        }
        ++v11; /*0x148361*/
      }
      v27 = 1; /*0x14836f*/
    }
    if ( v28 <= (unsigned int)v5 ) /*0x148379*/
      goto LABEL_54; /*0x148379*/
  }
  kfree((int)v11, v14); /*0x148267*/
LABEL_36:
  ipc_kmsg_clean_partial(a1, v26, 0, 0); /*0x148298*/
  return 268435468; /*0x148394*/
}
