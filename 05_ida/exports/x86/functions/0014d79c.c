/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14d79c. */
int __cdecl ipc_pset_move(int a1, int a2, unsigned int a3)
{
  unsigned int v3; // esi
  volatile __int32 *v4; // edx
  volatile __int32 *v5; // edx
  volatile __int32 *v6; // edx
  volatile __int32 *v7; // edx
  int v8; // eax
  volatile __int32 *v9; // edx
  volatile __int32 *v10; // edx
  volatile __int32 *v11; // ebx
  volatile __int32 *v12; // edx
  int v13; // eax
  int result; // eax

  do /*0x14d7c0*/
  {
    while ( *(_DWORD *)a2 ) /*0x14d7ab*/
      ; /*0x14d7ad*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a2, 1) == 1 ); /*0x14d7c0*/
  v3 = *(_DWORD *)(a2 + 48); /*0x14d7c2*/
  if ( v3 == a3 ) /*0x14d7c7*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14d7cb*/
  }
  else if ( v3 ) /*0x14d7d6*/
  {
    if ( a3 ) /*0x14d86a*/
    {
      if ( v3 >= a3 ) /*0x14d92e*/
      {
        do /*0x14d96e*/
        {
          while ( *(_DWORD *)a3 ) /*0x14d95c*/
            ; /*0x14d95e*/
        }
        while ( _InterlockedExchange((volatile __int32 *)a3, 1) == 1 ); /*0x14d96e*/
        do /*0x14d982*/
        {
          while ( *(_DWORD *)v3 ) /*0x14d970*/
            ; /*0x14d972*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x14d982*/
      }
      else
      {
        do /*0x14d942*/
        {
          while ( *(_DWORD *)v3 ) /*0x14d930*/
            ; /*0x14d932*/
        }
        while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x14d942*/
        do /*0x14d956*/
        {
          while ( *(_DWORD *)a3 ) /*0x14d944*/
            ; /*0x14d946*/
        }
        while ( _InterlockedExchange((volatile __int32 *)a3, 1) == 1 ); /*0x14d956*/
      }
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14d986*/
      *(_DWORD *)(a2 + 48) = 0; /*0x14d98c*/
      --*(_DWORD *)(v3 + 4); /*0x14d993*/
      v9 = (volatile __int32 *)(a2 + 64); /*0x14d999*/
      do /*0x14d9ae*/
      {
        while ( *v9 ) /*0x14d99c*/
          ; /*0x14d99e*/
      }
      while ( _InterlockedExchange(v9, 1) == 1 ); /*0x14d9ae*/
      v10 = (volatile __int32 *)(v3 + 16); /*0x14d9b0*/
      do /*0x14d9c6*/
      {
        while ( *v10 ) /*0x14d9b4*/
          ; /*0x14d9b6*/
      }
      while ( _InterlockedExchange(v10, 1) == 1 ); /*0x14d9c6*/
      v11 = (volatile __int32 *)(a2 + 64); /*0x14d9d3*/
      ipc_mqueue_move(a2 + 64, v3 + 16, a2); /*0x14d9d7*/
      _InterlockedExchange((volatile __int32 *)(v3 + 16), 0); /*0x14d9e1*/
      _InterlockedExchange((volatile __int32 *)(a2 + 64), 0); /*0x14d9e9*/
      *(_DWORD *)(a2 + 48) = a3; /*0x14d9ec*/
      ++*(_DWORD *)(a3 + 4); /*0x14d9ef*/
      do /*0x14da06*/
      {
        while ( *v11 ) /*0x14d9f4*/
          ; /*0x14d9f6*/
      }
      while ( _InterlockedExchange(v11, 1) == 1 ); /*0x14da06*/
      v12 = (volatile __int32 *)(a3 + 16); /*0x14da08*/
      do /*0x14da1e*/
      {
        while ( *v12 ) /*0x14da0c*/
          ; /*0x14da0e*/
      }
      while ( _InterlockedExchange(v12, 1) == 1 ); /*0x14da1e*/
      ipc_mqueue_move(a3 + 16, a2 + 64, a2); /*0x14da2f*/
      _InterlockedExchange((volatile __int32 *)(a3 + 16), 0); /*0x14da39*/
      ipc_mqueue_changed(a2 + 64, 268451846); /*0x14da42*/
      _InterlockedExchange((volatile __int32 *)(a2 + 64), 0); /*0x14da4f*/
      _InterlockedExchange((volatile __int32 *)a3, 0); /*0x14da54*/
      v13 = *(_DWORD *)(v3 + 4); /*0x14da56*/
      _InterlockedExchange((volatile __int32 *)v3, 0); /*0x14da5b*/
      if ( !v13 ) /*0x14da5f*/
        zfree(ipc_object_zones[*(_WORD *)(v3 + 10) & 0x7FFF], v3); /*0x14da73*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14d872*/
      do /*0x14d88a*/
      {
        while ( *(_DWORD *)v3 ) /*0x14d878*/
          ; /*0x14d87a*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x14d88a*/
      *(_DWORD *)(a2 + 48) = 0; /*0x14d88f*/
      --*(_DWORD *)(v3 + 4); /*0x14d896*/
      v6 = (volatile __int32 *)(a2 + 64); /*0x14d89c*/
      do /*0x14d8b2*/
      {
        while ( *v6 ) /*0x14d8a0*/
          ; /*0x14d8a2*/
      }
      while ( _InterlockedExchange(v6, 1) == 1 ); /*0x14d8b2*/
      v7 = (volatile __int32 *)(v3 + 16); /*0x14d8b4*/
      do /*0x14d8ca*/
      {
        while ( *v7 ) /*0x14d8b8*/
          ; /*0x14d8ba*/
      }
      while ( _InterlockedExchange(v7, 1) == 1 ); /*0x14d8ca*/
      ipc_mqueue_move(a2 + 64, v3 + 16, a2); /*0x14d8db*/
      _InterlockedExchange((volatile __int32 *)(v3 + 16), 0); /*0x14d8e5*/
      _InterlockedExchange((volatile __int32 *)(a2 + 64), 0); /*0x14d8ed*/
      if ( *(int *)(v3 + 8) >= 0 ) /*0x14d8f4*/
      {
        v8 = *(_DWORD *)(v3 + 4); /*0x14d900*/
        _InterlockedExchange((volatile __int32 *)v3, 0); /*0x14d905*/
        if ( !v8 ) /*0x14d909*/
          zfree(ipc_object_zones[*(_WORD *)(v3 + 10) & 0x7FFF], v3); /*0x14d91d*/
        v3 = 0; /*0x14d922*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)v3, 0); /*0x14d8f8*/
      }
    }
  }
  else
  {
    do /*0x14d7ee*/
    {
      while ( *(_DWORD *)a3 ) /*0x14d7dc*/
        ; /*0x14d7de*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a3, 1) == 1 ); /*0x14d7ee*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14d7f2*/
    *(_DWORD *)(a2 + 48) = a3; /*0x14d7f8*/
    ++*(_DWORD *)(a3 + 4); /*0x14d7fb*/
    v4 = (volatile __int32 *)(a2 + 64); /*0x14d801*/
    do /*0x14d816*/
    {
      while ( *v4 ) /*0x14d804*/
        ; /*0x14d806*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x14d816*/
    v5 = (volatile __int32 *)(a3 + 16); /*0x14d818*/
    do /*0x14d82e*/
    {
      while ( *v5 ) /*0x14d81c*/
        ; /*0x14d81e*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14d82e*/
    ipc_mqueue_move(a3 + 16, a2 + 64, a2); /*0x14d83f*/
    _InterlockedExchange((volatile __int32 *)(a3 + 16), 0); /*0x14d849*/
    ipc_mqueue_changed(a2 + 64, 268451846); /*0x14d852*/
    _InterlockedExchange((volatile __int32 *)(a2 + 64), 0); /*0x14d85c*/
    _InterlockedExchange((volatile __int32 *)a3, 0); /*0x14d861*/
  }
  _InterlockedExchange((volatile __int32 *)a2, 0); /*0x14da7d*/
  result = 0; /*0x14da7f*/
  if ( !a3 && !v3 ) /*0x14da87*/
    return 12; /*0x14da89*/
  return result; /*0x14da91*/
}
