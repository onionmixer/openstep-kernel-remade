/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17802c. */
int __cdecl vm_map_lookup(
        int *a1,
        unsigned int a2,
        int a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6,
        _DWORD *a7,
        _BOOL4 *a8,
        _BOOL4 *a9)
{
  int v9; // edi
  volatile __int32 *v10; // edx
  _DWORD *v11; // edx
  volatile __int32 *v12; // edx
  _DWORD *v13; // ecx
  _DWORD *v14; // eax
  volatile __int32 *v15; // edx
  volatile __int32 *v16; // edx
  int v18; // eax
  _BOOL4 v19; // eax
  volatile __int32 *v20; // edx
  _DWORD *v21; // ecx
  _DWORD *v22; // eax
  volatile __int32 *v23; // edx
  volatile __int32 *v24; // edx
  int v25; // esi
  volatile __int32 *v26; // edx
  _DWORD *v27; // [esp+Ch] [ebp-1Ch]
  _DWORD *v28; // [esp+Ch] [ebp-1Ch]
  int v29; // [esp+10h] [ebp-18h]
  _BOOL4 v30; // [esp+14h] [ebp-14h]
  int v31; // [esp+18h] [ebp-10h]
  unsigned int v32; // [esp+1Ch] [ebp-Ch]
  _DWORD *v33; // [esp+20h] [ebp-8h]
  int v34; // [esp+20h] [ebp-8h]
  _DWORD *v35; // [esp+24h] [ebp-4h]
  int v36; // [esp+24h] [ebp-4h]

  v9 = *a1; /*0x178038*/
  while ( 1 ) /*0x17803b*/
  {
    lock_read(v9); /*0x17803b*/
    v10 = (volatile __int32 *)(v9 + 60); /*0x178040*/
    do /*0x17805a*/
    {
      while ( *v10 ) /*0x178048*/
        ; /*0x17804a*/
    }
    while ( _InterlockedExchange(v10, 1) == 1 ); /*0x17805a*/
    v11 = *(_DWORD **)(v9 + 56); /*0x17805c*/
    _InterlockedExchange((volatile __int32 *)(v9 + 60), 0); /*0x178061*/
    *a4 = v11; /*0x178067*/
    if ( v11 == (_DWORD *)(v9 + 12) || v11[2] > a2 || v11[3] <= a2 ) /*0x17807b*/
      break; /*0x17807b*/
LABEL_31:
    if ( (v11[6] & 4) != 0 ) /*0x178148*/
    {
      v18 = v9; /*0x17814a*/
      v9 = v11[4]; /*0x17814c*/
      *a1 = v9; /*0x178152*/
      lock_done(v18); /*0x178155*/
    }
    else
    {
      v31 = v11[7]; /*0x17815f*/
      if ( a3 != (v31 & a3) ) /*0x17816a*/
      {
        lock_done(v9); /*0x17816d*/
        return 2; /*0x178177*/
      }
      v19 = *((_WORD *)v11 + 20) != 0; /*0x178184*/
      *a8 = v19; /*0x17818c*/
      if ( v19 ) /*0x178190*/
      {
        v31 = v11[7]; /*0x178195*/
        a3 = v31; /*0x178198*/
      }
      v30 = (v11[6] & 1) == 0; /*0x1781a3*/
      if ( (v11[6] & 1) != 0 ) /*0x1781a6*/
      {
        v29 = v11[4]; /*0x1781bb*/
        v32 = v11[5] + a2 - v11[2]; /*0x1781c7*/
        lock_read(v29); /*0x1781cb*/
        v20 = (volatile __int32 *)(v29 + 60); /*0x1781d6*/
        do /*0x1781ee*/
        {
          while ( *v20 ) /*0x1781dc*/
            ; /*0x1781de*/
        }
        while ( _InterlockedExchange(v20, 1) == 1 ); /*0x1781ee*/
        v21 = *(_DWORD **)(v29 + 56); /*0x1781f3*/
        _InterlockedExchange((volatile __int32 *)(v29 + 60), 0); /*0x1781f8*/
        v22 = (_DWORD *)(v29 + 12); /*0x1781fd*/
        if ( v21 == (_DWORD *)(v29 + 12) ) /*0x178202*/
          v21 = *(_DWORD **)(v29 + 16); /*0x178204*/
        if ( v21[2] > v32 ) /*0x17820d*/
        {
          v22 = (_DWORD *)v21[1]; /*0x178220*/
          v21 = *(_DWORD **)(v29 + 16); /*0x178226*/
LABEL_56:
          while ( v21 != v22 ) /*0x17826d*/
          {
            if ( v21[3] > v32 ) /*0x178232*/
            {
              if ( v21[2] > v32 ) /*0x178237*/
                break; /*0x178237*/
              v33 = v21; /*0x178239*/
              v23 = (volatile __int32 *)(v29 + 60); /*0x17823f*/
              do /*0x178256*/
              {
                while ( *v23 ) /*0x178244*/
                  ; /*0x178246*/
              }
              while ( _InterlockedExchange(v23, 1) == 1 ); /*0x178256*/
              *(_DWORD *)(v29 + 56) = v21; /*0x17825b*/
              _InterlockedExchange((volatile __int32 *)(v29 + 60), 0); /*0x178260*/
              goto LABEL_61; /*0x178263*/
            }
            v21 = (_DWORD *)v21[1]; /*0x178268*/
          }
LABEL_57:
          v34 = *v21; /*0x17826f*/
          v24 = (volatile __int32 *)(v29 + 60); /*0x178277*/
          do /*0x17828e*/
          {
            while ( *v24 ) /*0x17827c*/
              ; /*0x17827e*/
          }
          while ( _InterlockedExchange(v24, 1) == 1 ); /*0x17828e*/
          *(_DWORD *)(v29 + 56) = v34; /*0x178296*/
          _InterlockedExchange((volatile __int32 *)(v29 + 60), 0); /*0x17829b*/
          lock_done(v29); /*0x17829f*/
          lock_done(v9); /*0x1782a5*/
          return 1; /*0x1782af*/
        }
        if ( v21 == v22 ) /*0x178211*/
          goto LABEL_57; /*0x178211*/
        if ( v21[3] <= v32 ) /*0x178216*/
          goto LABEL_56; /*0x178216*/
        v33 = v21; /*0x178218*/
LABEL_61:
        v11 = v33; /*0x1782b4*/
      }
      else
      {
        v29 = v9; /*0x1781a8*/
        v32 = a2; /*0x1781ae*/
      }
      if ( (v11[6] & 0x40) != 0 ) /*0x1782bb*/
      {
        if ( (a3 & 2) != 0 ) /*0x1782c3*/
        {
          v25 = v29; /*0x1782c5*/
          v27 = v11; /*0x1782c9*/
          if ( lock_read_to_write(v29) ) /*0x1782cc*/
            goto LABEL_69; /*0x1782d9*/
          vm_object_shadow(v27 + 4, v27 + 5, v27[3] - v27[2]); /*0x1782ed*/
          *((_BYTE *)v27 + 24) &= ~0x40u; /*0x1782f5*/
          lock_write_to_read(v29); /*0x1782fd*/
          v11 = v27; /*0x178305*/
        }
        else
        {
          v31 &= ~2u; /*0x17830c*/
        }
      }
      if ( v11[4] ) /*0x178310*/
        goto LABEL_72; /*0x178314*/
      v25 = v29; /*0x178316*/
      v28 = v11; /*0x17831a*/
      if ( !lock_read_to_write(v29) ) /*0x17832a*/
      {
        v28[4] = vm_object_allocate(v28[3] - v28[2]); /*0x178356*/
        v28[5] = 0; /*0x178359*/
        lock_write_to_read(v29); /*0x178364*/
        v11 = v28; /*0x178369*/
LABEL_72:
        *a6 = v11[5] + v32 - v11[2]; /*0x17836c*/
        *a5 = v11[4]; /*0x178380*/
        if ( !v30 ) /*0x178386*/
        {
          v26 = (volatile __int32 *)(v29 + 52); /*0x17838b*/
          do /*0x1783a2*/
          {
            while ( *v26 ) /*0x178390*/
              ; /*0x178392*/
          }
          while ( _InterlockedExchange(v26, 1) == 1 ); /*0x1783a2*/
          v30 = *(_DWORD *)(v29 + 48) == 1; /*0x1783b3*/
          _InterlockedExchange((volatile __int32 *)(v29 + 52), 0); /*0x1783b8*/
        }
        *a7 = v31; /*0x1783c1*/
        *a9 = v30; /*0x1783c9*/
        return 0; /*0x1783cb*/
      }
LABEL_69:
      if ( v25 != v9 ) /*0x17832e*/
        lock_done(v9); /*0x178335*/
    }
  }
  v12 = (volatile __int32 *)(v9 + 60); /*0x178081*/
  do /*0x178096*/
  {
    while ( *v12 ) /*0x178084*/
      ; /*0x178086*/
  }
  while ( _InterlockedExchange(v12, 1) == 1 ); /*0x178096*/
  v13 = *(_DWORD **)(v9 + 56); /*0x178098*/
  _InterlockedExchange((volatile __int32 *)(v9 + 60), 0); /*0x17809d*/
  v14 = (_DWORD *)(v9 + 12); /*0x1780a0*/
  if ( v13 == (_DWORD *)(v9 + 12) ) /*0x1780a5*/
    v13 = *(_DWORD **)(v9 + 16); /*0x1780a7*/
  if ( v13[2] <= a2 ) /*0x1780b0*/
  {
    if ( v13 == v14 ) /*0x1780b4*/
      goto LABEL_26; /*0x1780b4*/
    if ( v13[3] <= a2 ) /*0x1780b9*/
      goto LABEL_25; /*0x1780b9*/
    v35 = v13; /*0x1780bb*/
LABEL_30:
    v11 = v35; /*0x17813c*/
    *a4 = v35; /*0x178142*/
    goto LABEL_31; /*0x178142*/
  }
  v14 = (_DWORD *)v13[1]; /*0x1780c0*/
  v13 = *(_DWORD **)(v9 + 16); /*0x1780c3*/
LABEL_25:
  while ( v13 != v14 ) /*0x178101*/
  {
    if ( v13[3] > a2 ) /*0x1780ce*/
    {
      if ( v13[2] > a2 ) /*0x1780d3*/
        break; /*0x1780d3*/
      v35 = v13; /*0x1780d5*/
      v15 = (volatile __int32 *)(v9 + 60); /*0x1780d8*/
      do /*0x1780ee*/
      {
        while ( *v15 ) /*0x1780dc*/
          ; /*0x1780de*/
      }
      while ( _InterlockedExchange(v15, 1) == 1 ); /*0x1780ee*/
      *(_DWORD *)(v9 + 56) = v13; /*0x1780f0*/
      _InterlockedExchange((volatile __int32 *)(v9 + 60), 0); /*0x1780f5*/
      goto LABEL_30; /*0x1780f8*/
    }
    v13 = (_DWORD *)v13[1]; /*0x1780fc*/
  }
LABEL_26:
  v36 = *v13; /*0x178103*/
  v16 = (volatile __int32 *)(v9 + 60); /*0x178108*/
  do /*0x17811e*/
  {
    while ( *v16 ) /*0x17810c*/
      ; /*0x17810e*/
  }
  while ( _InterlockedExchange(v16, 1) == 1 ); /*0x17811e*/
  *(_DWORD *)(v9 + 56) = v36; /*0x178123*/
  _InterlockedExchange((volatile __int32 *)(v9 + 60), 0); /*0x178128*/
  lock_done(v9); /*0x17812c*/
  return 1; /*0x1783d0*/
}
