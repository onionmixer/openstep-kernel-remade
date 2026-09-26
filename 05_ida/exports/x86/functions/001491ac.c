/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1491ac. */
int __cdecl ipc_kmsg_copyout_pseudo(_DWORD *a1, int a2, vm_map_t target_task)
{
  volatile __int32 *v3; // edx
  int v4; // ebx
  volatile __int32 *v5; // edx
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  unsigned int v10; // [esp+Ch] [ebp-28h]
  int v11; // [esp+Ch] [ebp-28h]
  int v12; // [esp+18h] [ebp-1Ch]
  unsigned int v13; // [esp+20h] [ebp-14h]
  int v14; // [esp+24h] [ebp-10h]
  _DWORD *v15; // [esp+28h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+2Ch] [ebp-8h] BYREF
  int v17; // [esp+30h] [ebp-4h] BYREF

  v14 = a1[5]; /*0x1491be*/
  v10 = a1[7]; /*0x1491c7*/
  v13 = a1[8]; /*0x1491d0*/
  v12 = (unsigned __int16)(v14 & 0xFF00) >> 8; /*0x1491e5*/
  if ( !v10 || v10 == -1 ) /*0x1491f8*/
  {
    v17 = a1[7]; /*0x1491fd*/
    goto LABEL_23; /*0x149200*/
  }
  if ( (unsigned __int8)v14 == 17 ) /*0x14920c*/
  {
    v3 = (volatile __int32 *)(a2 + 8); /*0x149211*/
    do /*0x149226*/
    {
      while ( *v3 ) /*0x149214*/
        ; /*0x149216*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x149226*/
    if ( *(_DWORD *)(a2 + 12) ) /*0x149228*/
    {
      do /*0x149242*/
      {
        while ( *(_DWORD *)v10 ) /*0x149230*/
          ; /*0x149232*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v10, 1) == 1 ); /*0x149242*/
      if ( *(int *)(v10 + 8) < 0 && ipc_hash_local_lookup(a2, v10, &v17, &v15) ) /*0x149254*/
      {
        --*(_DWORD *)(v10 + 28); /*0x14926c*/
        --*(_DWORD *)(v10 + 4); /*0x14926f*/
        _InterlockedExchange((volatile __int32 *)v10, 0); /*0x149274*/
        if ( *(_WORD *)v15 != 0xFFFE ) /*0x149280*/
          ++*v15; /*0x149282*/
        _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x149286*/
        goto LABEL_23; /*0x149289*/
      }
      _InterlockedExchange((volatile __int32 *)v10, 0); /*0x149262*/
    }
    _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x149266*/
  }
  v4 = ipc_object_copyout(a2, v10, (unsigned __int8)v14, 1, &v17); /*0x1492a0*/
  if ( !v4 ) /*0x1492a7*/
  {
LABEL_23:
    v11 = 0; /*0x1492df*/
    goto LABEL_24; /*0x1492df*/
  }
  ipc_object_destroy(v10, (unsigned __int8)v14); /*0x1492ae*/
  if ( v4 == 20 ) /*0x1492b9*/
  {
    v17 = -1; /*0x1492d8*/
    goto LABEL_23; /*0x1492d8*/
  }
  v17 = 0; /*0x1492bb*/
  v11 = 0x2000; /*0x1492c2*/
  if ( v4 == 6 ) /*0x1492cc*/
    v11 = 2048; /*0x1492ce*/
LABEL_24:
  if ( !v13 || v13 == -1 ) /*0x1492f6*/
  {
    v16 = v13; /*0x1492fb*/
    goto LABEL_46; /*0x1492fe*/
  }
  if ( v12 == 17 ) /*0x149308*/
  {
    v5 = (volatile __int32 *)(a2 + 8); /*0x14930d*/
    do /*0x149322*/
    {
      while ( *v5 ) /*0x149310*/
        ; /*0x149312*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x149322*/
    if ( *(_DWORD *)(a2 + 12) ) /*0x149324*/
    {
      do /*0x14933e*/
      {
        while ( *(_DWORD *)v13 ) /*0x14932c*/
          ; /*0x14932e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v13, 1) == 1 ); /*0x14933e*/
      if ( *(int *)(v13 + 8) < 0 && ipc_hash_local_lookup(a2, v13, (int *)&v16, &v15) ) /*0x149350*/
      {
        --*(_DWORD *)(v13 + 28); /*0x149368*/
        --*(_DWORD *)(v13 + 4); /*0x14936b*/
        _InterlockedExchange((volatile __int32 *)v13, 0); /*0x149370*/
        if ( *(_WORD *)v15 != 0xFFFE ) /*0x14937c*/
          ++*v15; /*0x14937e*/
        _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x149382*/
        goto LABEL_46; /*0x149385*/
      }
      _InterlockedExchange((volatile __int32 *)v13, 0); /*0x14935e*/
    }
    _InterlockedExchange((volatile __int32 *)(a2 + 8), 0); /*0x149362*/
  }
  v6 = ipc_object_copyout(a2, v13, v12, 1, &v16); /*0x14939c*/
  if ( !v6 ) /*0x1493a3*/
  {
LABEL_46:
    v7 = 0; /*0x1493d7*/
    goto LABEL_47; /*0x1493d7*/
  }
  ipc_object_destroy(v13, v12); /*0x1493aa*/
  if ( v6 == 20 ) /*0x1493b5*/
  {
    v16 = -1; /*0x1493d0*/
    goto LABEL_46; /*0x1493d0*/
  }
  v16 = 0; /*0x1493b7*/
  v7 = 0x2000; /*0x1493be*/
  if ( v6 == 6 ) /*0x1493c6*/
    v7 = 2048; /*0x1493c8*/
LABEL_47:
  v8 = v7 | v11; /*0x1493d9*/
  a1[5] = v14 & 0xBFFFFFFF; /*0x1493ea*/
  a1[7] = v17; /*0x1493f0*/
  a1[8] = v16; /*0x1493f6*/
  if ( v14 < 0 ) /*0x1493fd*/
    return ipc_kmsg_copyout_body(a1 + 11, (unsigned int)a1 + a1[6] + 20, a2, target_task) | v8; /*0x149419*/
  return v8; /*0x149420*/
}
