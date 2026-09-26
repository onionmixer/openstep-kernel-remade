/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x175814. */
int __cdecl vm_map_inherit(int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  volatile __int32 *v5; // edx
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  volatile __int32 *v8; // edx
  volatile __int32 *v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // edx
  volatile __int32 *v13; // ecx
  _DWORD *v14; // ebx
  int v15; // eax
  int v16; // edx
  int v17; // edx
  volatile __int32 *v18; // ecx
  int *v19; // [esp+18h] [ebp-10h]
  int *v20; // [esp+1Ch] [ebp-Ch]
  _DWORD *v21; // [esp+24h] [ebp-4h]
  int v22; // [esp+24h] [ebp-4h]

  if ( a4 > 2 ) /*0x175821*/
    return 4; /*0x17582e*/
  lock_write(a1); /*0x175838*/
  ++*(_DWORD *)(a1 + 76); /*0x17583d*/
  if ( a2 < *(_DWORD *)(a1 + 20) ) /*0x175849*/
    a2 = *(_DWORD *)(a1 + 20); /*0x17584b*/
  if ( a3 > *(_DWORD *)(a1 + 24) ) /*0x175857*/
    a3 = *(_DWORD *)(a1 + 24); /*0x175859*/
  if ( a2 > a3 ) /*0x175862*/
    a2 = a3; /*0x175864*/
  v5 = (volatile __int32 *)(a1 + 60); /*0x17586a*/
  do /*0x175882*/
  {
    while ( *v5 ) /*0x175870*/
      ; /*0x175872*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x175882*/
  v6 = *(_DWORD **)(a1 + 56); /*0x175887*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x17588c*/
  v7 = (_DWORD *)(a1 + 12); /*0x175891*/
  if ( v6 == (_DWORD *)(a1 + 12) ) /*0x175896*/
    v6 = *(_DWORD **)(a1 + 16); /*0x175898*/
  if ( v6[2] > a2 ) /*0x1758a1*/
  {
    v7 = (_DWORD *)v6[1]; /*0x1758b4*/
    v6 = *(_DWORD **)(a1 + 16); /*0x1758ba*/
LABEL_26:
    while ( v6 != v7 ) /*0x175901*/
    {
      if ( v6[3] > a2 ) /*0x1758c6*/
      {
        if ( v6[2] > a2 ) /*0x1758cb*/
          break; /*0x1758cb*/
        v21 = v6; /*0x1758cd*/
        v8 = (volatile __int32 *)(a1 + 60); /*0x1758d3*/
        do /*0x1758ea*/
        {
          while ( *v8 ) /*0x1758d8*/
            ; /*0x1758da*/
        }
        while ( _InterlockedExchange(v8, 1) == 1 ); /*0x1758ea*/
        *(_DWORD *)(a1 + 56) = v6; /*0x1758ef*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1758f4*/
        goto LABEL_31; /*0x1758f7*/
      }
      v6 = (_DWORD *)v6[1]; /*0x1758fc*/
    }
  }
  else if ( v6 != v7 ) /*0x1758a5*/
  {
    if ( v6[3] <= a2 ) /*0x1758aa*/
      goto LABEL_26; /*0x1758aa*/
    v21 = v6; /*0x1758ac*/
LABEL_31:
    v14 = v21; /*0x175938*/
    if ( v21[2] < a2 ) /*0x175941*/
    {
      if ( *(_DWORD *)(a1 + 32) ) /*0x175953*/
        v10 = vm_map_entry_zone; /*0x175959*/
      else
        v10 = vm_map_kentry_zone; /*0x175960*/
      v20 = (int *)zalloc(v10); /*0x17596b*/
      if ( !v20 ) /*0x175973*/
        panic(aVmMapEntryCrea); /*0x17597a*/
      qmemcpy(v20, v21, 0x2Cu); /*0x175997*/
      v20[3] = a2; /*0x17599c*/
      v21[5] += a2 - v21[2]; /*0x1759a5*/
      v21[2] = a2; /*0x1759a8*/
      ++*(_DWORD *)(a1 + 28); /*0x1759ae*/
      *v20 = *v21; /*0x1759b6*/
      v20[1] = *(_DWORD *)(*v21 + 4); /*0x1759bd*/
      v11 = *v20; /*0x1759c0*/
      *(_DWORD *)v20[1] = v20; /*0x1759c5*/
      *(_DWORD *)(v11 + 4) = v20; /*0x1759c7*/
      if ( (v21[6] & 5) != 0 ) /*0x1759ce*/
      {
        v12 = v20[4]; /*0x1759d0*/
        if ( v12 ) /*0x1759d5*/
        {
          v13 = (volatile __int32 *)(v12 + 52); /*0x1759db*/
          do /*0x1759f2*/
          {
            while ( *v13 ) /*0x1759e0*/
              ; /*0x1759e2*/
          }
          while ( _InterlockedExchange(v13, 1) == 1 ); /*0x1759f2*/
          ++*(_DWORD *)(v12 + 48); /*0x1759f4*/
          _InterlockedExchange((volatile __int32 *)(v12 + 52), 0); /*0x1759f9*/
        }
      }
      else
      {
        vm_object_reference(v20[4]); /*0x175a0b*/
      }
    }
    goto LABEL_59; /*0x1759fc*/
  }
  v22 = *v6; /*0x175903*/
  v9 = (volatile __int32 *)(a1 + 60); /*0x17590b*/
  do /*0x175922*/
  {
    while ( *v9 ) /*0x175910*/
      ; /*0x175912*/
  }
  while ( _InterlockedExchange(v9, 1) == 1 ); /*0x175922*/
  *(_DWORD *)(a1 + 56) = v22; /*0x17592a*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x17592f*/
  v14 = *(_DWORD **)(v22 + 4); /*0x175a1b*/
LABEL_59:
  while ( v14 != (_DWORD *)(a1 + 12) && v14[2] < a3 ) /*0x175a2a*/
  {
    if ( v14[3] > a3 ) /*0x175a33*/
    {
      if ( *(_DWORD *)(a1 + 32) ) /*0x175a42*/
        v15 = vm_map_entry_zone; /*0x175a48*/
      else
        v15 = vm_map_kentry_zone; /*0x175a50*/
      v19 = (int *)zalloc(v15); /*0x175a5e*/
      if ( !v19 ) /*0x175a69*/
        panic(aVmMapEntryCrea); /*0x175a73*/
      qmemcpy(v19, v14, 0x2Cu); /*0x175a94*/
      v14[3] = a3; /*0x175a99*/
      v19[2] = a3; /*0x175a9f*/
      v19[5] += a3 - v14[2]; /*0x175aa8*/
      ++*(_DWORD *)(a1 + 28); /*0x175aab*/
      *v19 = (int)v14; /*0x175aae*/
      v19[1] = v14[1]; /*0x175ab3*/
      v16 = *v19; /*0x175ab6*/
      *(_DWORD *)v19[1] = v19; /*0x175abb*/
      *(_DWORD *)(v16 + 4) = v19; /*0x175abd*/
      if ( (v14[6] & 5) != 0 ) /*0x175ac4*/
      {
        v17 = v19[4]; /*0x175ac6*/
        if ( v17 ) /*0x175acb*/
        {
          v18 = (volatile __int32 *)(v17 + 52); /*0x175acd*/
          do /*0x175ae2*/
          {
            while ( *v18 ) /*0x175ad0*/
              ; /*0x175ad2*/
          }
          while ( _InterlockedExchange(v18, 1) == 1 ); /*0x175ae2*/
          ++*(_DWORD *)(v17 + 48); /*0x175ae4*/
          _InterlockedExchange((volatile __int32 *)(v17 + 52), 0); /*0x175ae9*/
        }
      }
      else
      {
        vm_object_reference(v19[4]); /*0x175af7*/
      }
    }
    v14[9] = a4; /*0x175b02*/
    v14 = (_DWORD *)v14[1]; /*0x175b05*/
  }
  lock_done(a1); /*0x175b1a*/
  return 0; /*0x175b24*/
}
