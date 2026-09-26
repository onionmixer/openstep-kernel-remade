/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1752f8. */
int __cdecl vm_map_protect(int a1, unsigned int a2, unsigned int a3, int a4, int a5)
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
  _DWORD *i; // ebx
  _DWORD *j; // ebx
  int v17; // eax
  int v18; // edx
  int v19; // edx
  volatile __int32 *v20; // ecx
  int v21; // eax
  int v22; // edx
  unsigned int v23; // ecx
  volatile __int32 *v24; // edx
  _DWORD *v25; // edx
  _DWORD *v26; // eax
  volatile __int32 *v27; // ecx
  volatile __int32 *v28; // edx
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // edx
  int v32; // ecx
  unsigned int v33; // eax
  int v34; // eax
  int v35; // [esp-8h] [ebp-34h]
  int v36; // [esp-4h] [ebp-30h]
  int v37; // [esp+Ch] [ebp-20h]
  unsigned int v38; // [esp+10h] [ebp-1Ch]
  int *v39; // [esp+18h] [ebp-14h]
  int *v40; // [esp+1Ch] [ebp-10h]
  _DWORD *v41; // [esp+24h] [ebp-8h]
  _DWORD *v42; // [esp+28h] [ebp-4h]
  int v43; // [esp+28h] [ebp-4h]

  lock_write(a1); /*0x175305*/
  ++*(_DWORD *)(a1 + 76); /*0x17530a*/
  if ( a2 < *(_DWORD *)(a1 + 20) ) /*0x175316*/
    a2 = *(_DWORD *)(a1 + 20); /*0x175318*/
  if ( a3 > *(_DWORD *)(a1 + 24) ) /*0x175324*/
    a3 = *(_DWORD *)(a1 + 24); /*0x175326*/
  if ( a2 > a3 ) /*0x17532f*/
    a2 = a3; /*0x175331*/
  v5 = (volatile __int32 *)(a1 + 60); /*0x175337*/
  do /*0x17534e*/
  {
    while ( *v5 ) /*0x17533c*/
      ; /*0x17533e*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x17534e*/
  v6 = *(_DWORD **)(a1 + 56); /*0x175353*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x175358*/
  v7 = (_DWORD *)(a1 + 12); /*0x17535d*/
  if ( v6 == (_DWORD *)(a1 + 12) ) /*0x175362*/
    v6 = *(_DWORD **)(a1 + 16); /*0x175364*/
  if ( v6[2] > a2 ) /*0x17536d*/
  {
    v7 = (_DWORD *)v6[1]; /*0x175380*/
    v6 = *(_DWORD **)(a1 + 16); /*0x175386*/
LABEL_24:
    while ( v6 != v7 ) /*0x1753cd*/
    {
      if ( v6[3] > a2 ) /*0x175392*/
      {
        if ( v6[2] > a2 ) /*0x175397*/
          break; /*0x175397*/
        v42 = v6; /*0x175399*/
        v8 = (volatile __int32 *)(a1 + 60); /*0x17539f*/
        do /*0x1753b6*/
        {
          while ( *v8 ) /*0x1753a4*/
            ; /*0x1753a6*/
        }
        while ( _InterlockedExchange(v8, 1) == 1 ); /*0x1753b6*/
        *(_DWORD *)(a1 + 56) = v6; /*0x1753bb*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1753c0*/
        goto LABEL_29; /*0x1753c3*/
      }
      v6 = (_DWORD *)v6[1]; /*0x1753c8*/
    }
  }
  else if ( v6 != v7 ) /*0x175371*/
  {
    if ( v6[3] <= a2 ) /*0x175376*/
      goto LABEL_24; /*0x175376*/
    v42 = v6; /*0x175378*/
LABEL_29:
    if ( v42[2] < a2 ) /*0x17540d*/
    {
      if ( *(_DWORD *)(a1 + 32) ) /*0x175421*/
        v10 = vm_map_entry_zone; /*0x175427*/
      else
        v10 = vm_map_kentry_zone; /*0x175430*/
      v40 = (int *)zalloc(v10); /*0x17543b*/
      if ( !v40 ) /*0x175443*/
        panic(aVmMapEntryCrea); /*0x17544a*/
      qmemcpy(v40, v42, 0x2Cu); /*0x175467*/
      v40[3] = a2; /*0x17546c*/
      v42[5] += a2 - v42[2]; /*0x175475*/
      v42[2] = a2; /*0x175478*/
      ++*(_DWORD *)(a1 + 28); /*0x17547e*/
      *v40 = *v42; /*0x175486*/
      v40[1] = *(_DWORD *)(*v42 + 4); /*0x17548d*/
      v11 = *v40; /*0x175490*/
      *(_DWORD *)v40[1] = v40; /*0x175495*/
      *(_DWORD *)(v11 + 4) = v40; /*0x175497*/
      if ( (v42[6] & 5) != 0 ) /*0x17549e*/
      {
        v12 = v40[4]; /*0x1754a0*/
        if ( v12 ) /*0x1754a5*/
        {
          v13 = (volatile __int32 *)(v12 + 52); /*0x1754a7*/
          do /*0x1754be*/
          {
            while ( *v13 ) /*0x1754ac*/
              ; /*0x1754ae*/
          }
          while ( _InterlockedExchange(v13, 1) == 1 ); /*0x1754be*/
          ++*(_DWORD *)(v12 + 48); /*0x1754c0*/
          _InterlockedExchange((volatile __int32 *)(v12 + 52), 0); /*0x1754c5*/
        }
      }
      else
      {
        vm_object_reference(v40[4]); /*0x1754d3*/
      }
    }
    goto LABEL_44; /*0x1754c8*/
  }
  v43 = *v6; /*0x1753cf*/
  v9 = (volatile __int32 *)(a1 + 60); /*0x1753d7*/
  do /*0x1753ee*/
  {
    while ( *v9 ) /*0x1753dc*/
      ; /*0x1753de*/
  }
  while ( _InterlockedExchange(v9, 1) == 1 ); /*0x1753ee*/
  *(_DWORD *)(a1 + 56) = v43; /*0x1753f6*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1753fb*/
  v42 = *(_DWORD **)(v43 + 4); /*0x17550e*/
LABEL_44:
  for ( i = v42; i != (_DWORD *)(a1 + 12); i = (_DWORD *)i[1] ) /*0x17551c*/
  {
    if ( i[2] >= a3 ) /*0x175526*/
      break; /*0x175526*/
    if ( (i[6] & 4) != 0 ) /*0x17552c*/
    {
      lock_done(a1); /*0x1754e4*/
      return 4; /*0x1754ee*/
    }
    if ( a4 != (i[8] & a4) ) /*0x175537*/
    {
      lock_done(a1); /*0x1754f8*/
      return 2; /*0x175502*/
    }
  }
  for ( j = v42; j != (_DWORD *)(a1 + 12) && j[2] < a3; j = (_DWORD *)j[1] ) /*0x175540*/
  {
    if ( j[3] > a3 ) /*0x175557*/
    {
      if ( *(_DWORD *)(a1 + 32) ) /*0x175566*/
        v17 = vm_map_entry_zone; /*0x17556c*/
      else
        v17 = vm_map_kentry_zone; /*0x175574*/
      v39 = (int *)zalloc(v17); /*0x175582*/
      if ( !v39 ) /*0x17558d*/
        panic(aVmMapEntryCrea); /*0x175597*/
      qmemcpy(v39, j, 0x2Cu); /*0x1755b8*/
      j[3] = a3; /*0x1755bd*/
      v39[2] = a3; /*0x1755c3*/
      v39[5] += a3 - j[2]; /*0x1755cc*/
      ++*(_DWORD *)(a1 + 28); /*0x1755cf*/
      *v39 = (int)j; /*0x1755d2*/
      v39[1] = j[1]; /*0x1755d7*/
      v18 = *v39; /*0x1755da*/
      *(_DWORD *)v39[1] = v39; /*0x1755df*/
      *(_DWORD *)(v18 + 4) = v39; /*0x1755e1*/
      if ( (j[6] & 5) != 0 ) /*0x1755e8*/
      {
        v19 = v39[4]; /*0x1755ea*/
        if ( v19 ) /*0x1755ef*/
        {
          v20 = (volatile __int32 *)(v19 + 52); /*0x1755f1*/
          do /*0x175606*/
          {
            while ( *v20 ) /*0x1755f4*/
              ; /*0x1755f6*/
          }
          while ( _InterlockedExchange(v20, 1) == 1 ); /*0x175606*/
          ++*(_DWORD *)(v19 + 48); /*0x175608*/
          _InterlockedExchange((volatile __int32 *)(v19 + 52), 0); /*0x17560d*/
        }
      }
      else
      {
        vm_object_reference(v39[4]); /*0x17561b*/
      }
    }
    v21 = j[7]; /*0x175623*/
    if ( a5 ) /*0x17562a*/
    {
      j[8] = a4; /*0x17562f*/
      j[7] = v21 & a4; /*0x175634*/
    }
    else
    {
      j[7] = a4; /*0x17563f*/
    }
    v22 = j[7]; /*0x175642*/
    if ( v22 != v21 ) /*0x175647*/
    {
      if ( (j[6] & 1) == 0 ) /*0x175651*/
      {
        if ( (v42[6] & 8) != 0 ) /*0x1757c7*/
        {
          v34 = j[7]; /*0x1757c9*/
          LOBYTE(v34) = v22 & 0xFD; /*0x1757cb*/
        }
        else
        {
          v34 = j[7] & 7; /*0x1757d2*/
        }
        pmap_protect(*(_DWORD *)(a1 + 36), j[2], j[3], v34); /*0x1757e5*/
        continue; /*0x1757e5*/
      }
      lock_write(j[4]); /*0x17565b*/
      ++*(_DWORD *)(j[4] + 76); /*0x175663*/
      v37 = j[4]; /*0x17566c*/
      v23 = j[5]; /*0x17566f*/
      v24 = (volatile __int32 *)(v37 + 60); /*0x175674*/
      do /*0x17568a*/
      {
        while ( *v24 ) /*0x175678*/
          ; /*0x17567a*/
      }
      while ( _InterlockedExchange(v24, 1) == 1 ); /*0x17568a*/
      v25 = *(_DWORD **)(v37 + 56); /*0x17568f*/
      _InterlockedExchange((volatile __int32 *)(v37 + 60), 0); /*0x175694*/
      v26 = (_DWORD *)(v37 + 12); /*0x175699*/
      if ( v25 == (_DWORD *)(v37 + 12) ) /*0x17569e*/
        v25 = *(_DWORD **)(v37 + 16); /*0x1756a0*/
      if ( v25[2] > v23 ) /*0x1756a6*/
      {
        v26 = (_DWORD *)v25[1]; /*0x1756b8*/
        v25 = *(_DWORD **)(v37 + 16); /*0x1756be*/
LABEL_86:
        while ( v25 != v26 ) /*0x175701*/
        {
          if ( v25[3] > v23 ) /*0x1756c7*/
          {
            if ( v25[2] > v23 ) /*0x1756cc*/
              break; /*0x1756cc*/
            v41 = v25; /*0x1756ce*/
            v27 = (volatile __int32 *)(v37 + 60); /*0x1756d4*/
            do /*0x1756ea*/
            {
              while ( *v27 ) /*0x1756d8*/
                ; /*0x1756da*/
            }
            while ( _InterlockedExchange(v27, 1) == 1 ); /*0x1756ea*/
            *(_DWORD *)(v37 + 56) = v25; /*0x1756ef*/
            _InterlockedExchange((volatile __int32 *)(v37 + 60), 0); /*0x1756f4*/
            goto LABEL_91; /*0x1756f7*/
          }
          v25 = (_DWORD *)v25[1]; /*0x1756fc*/
        }
      }
      else if ( v25 != v26 ) /*0x1756aa*/
      {
        if ( v25[3] <= v23 ) /*0x1756af*/
          goto LABEL_86; /*0x1756af*/
        v41 = v25; /*0x1756b1*/
        goto LABEL_91; /*0x1756b4*/
      }
      v41 = (_DWORD *)*v25; /*0x175703*/
      v28 = (volatile __int32 *)(v37 + 60); /*0x17570b*/
      do /*0x175722*/
      {
        while ( *v28 ) /*0x175710*/
          ; /*0x175712*/
      }
      while ( _InterlockedExchange(v28, 1) == 1 ); /*0x175722*/
      *(_DWORD *)(v37 + 56) = v41; /*0x17572a*/
      _InterlockedExchange((volatile __int32 *)(v37 + 60), 0); /*0x17572f*/
LABEL_91:
      v38 = j[5] + j[3] - j[2]; /*0x175732*/
      while ( v41 != (_DWORD *)(j[4] + 12) && v41[2] < v38 ) /*0x175749*/
      {
        if ( (v41[6] & 8) != 0 ) /*0x175752*/
        {
          v29 = j[7]; /*0x175754*/
          LOBYTE(v29) = v29 & 0xFD; /*0x175756*/
        }
        else
        {
          v29 = j[7] & 7; /*0x17575e*/
        }
        v36 = v29; /*0x175761*/
        v30 = v41[3]; /*0x175768*/
        if ( v38 > v30 ) /*0x17576e*/
          v30 = v38; /*0x175770*/
        v31 = j[5]; /*0x175773*/
        v32 = j[2]; /*0x175778*/
        v35 = v32 + v30 - v31; /*0x17577d*/
        v33 = v41[2]; /*0x175781*/
        if ( v33 < v31 ) /*0x175786*/
          v33 = j[5]; /*0x175788*/
        pmap_protect(*(_DWORD *)(a1 + 36), v32 + v33 - v31, v35, v36); /*0x175796*/
        v41 = (_DWORD *)v41[1]; /*0x1757a1*/
      }
      lock_done(j[4]); /*0x1757b6*/
      continue; /*0x1757be*/
    }
  }
  lock_done(a1); /*0x175802*/
  return 0; /*0x17580c*/
}
