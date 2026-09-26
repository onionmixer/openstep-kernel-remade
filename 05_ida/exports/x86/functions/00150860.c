/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x150860. */
int __cdecl ipc_space_destroy(unsigned int a1)
{
  volatile __int32 *v1; // edx
  int result; // eax
  volatile __int32 *v3; // ebx
  volatile __int32 *v4; // ebx
  unsigned int v5; // esi
  int v6; // edx
  _DWORD *v7; // ebx
  _DWORD *i; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // [esp+Ch] [ebp-Ch]
  unsigned int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  v1 = (volatile __int32 *)(a1 + 8); /*0x15086c*/
  do /*0x150882*/
  {
    while ( *v1 ) /*0x150870*/
      ; /*0x150872*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x150882*/
  result = *(_DWORD *)(a1 + 12); /*0x150884*/
  *(_DWORD *)(a1 + 12) = 0; /*0x150887*/
  v3 = (volatile __int32 *)(a1 + 8); /*0x15088e*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x150893*/
  if ( result ) /*0x150898*/
  {
    do /*0x1508b2*/
    {
      while ( *v3 ) /*0x1508a0*/
        ; /*0x1508a2*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1508b2*/
    if ( *(_DWORD *)(a1 + 16) ) /*0x1508b4*/
    {
      v4 = (volatile __int32 *)(a1 + 8); /*0x1508ba*/
      do /*0x1508f0*/
      {
        assert_wait(a1, 0); /*0x1508c3*/
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1508cd*/
        thread_block_with_continuation(0); /*0x1508d2*/
        do /*0x1508ee*/
        {
          while ( *v4 ) /*0x1508dc*/
            ; /*0x1508de*/
        }
        while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1508ee*/
      }
      while ( *(_DWORD *)(a1 + 16) ); /*0x1508f0*/
    }
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1508f8*/
    v14 = *(_DWORD *)(a1 + 20); /*0x1508fe*/
    v13 = *(_DWORD *)(a1 + 24); /*0x150904*/
    v5 = 0; /*0x150907*/
    if ( v13 ) /*0x15090b*/
    {
      v6 = 0; /*0x15090d*/
      v7 = *(_DWORD **)(a1 + 20); /*0x15090f*/
      do /*0x150940*/
      {
        if ( (*v7 & 0x1F0000) != 0 ) /*0x15091b*/
        {
          v12 = v6; /*0x150925*/
          ipc_right_clean(a1, v6 | HIBYTE(*v7), (int)v7); /*0x150928*/
          v6 = v12; /*0x150930*/
        }
        v6 += 256; /*0x150933*/
        v7 += 4; /*0x150939*/
        ++v5; /*0x15093c*/
      }
      while ( v13 > v5 ); /*0x150940*/
    }
    ipc_table_free(16 * *(_DWORD *)(*(_DWORD *)(a1 + 28) - 4), v14); /*0x150950*/
    for ( i = (_DWORD *)ipc_splay_traverse_start(a1 + 32); i; i = (_DWORD *)ipc_splay_traverse_next(a1 + 32, 1) ) /*0x150965*/
    {
      v9 = i[4]; /*0x15096f*/
      if ( (*i & 0x1F0000) == 0x10000 ) /*0x150977*/
        ipc_hash_global_delete(a1, i[1], v9, (int)i); /*0x150980*/
      ipc_right_clean(a1, v9, (int)i); /*0x15098b*/
    }
    ipc_splay_traverse_finish(a1 + 32); /*0x1509ab*/
    v10 = *(_DWORD *)(a1 + 68); /*0x1509b3*/
    if ( v10 && v10 != -1 ) /*0x1509bd*/
      ipc_port_release_send(*(_DWORD *)(a1 + 68)); /*0x1509c0*/
    do /*0x1509da*/
    {
      while ( *(_DWORD *)a1 ) /*0x1509c8*/
        ; /*0x1509ca*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1509da*/
    v11 = *(_DWORD *)(a1 + 4) - 1; /*0x1509df*/
    *(_DWORD *)(a1 + 4) = v11; /*0x1509e2*/
    result = v11; /*0x1509e5*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x1509e8*/
    if ( !v11 ) /*0x1509ec*/
      return zfree(ipc_space_zone, a1); /*0x1509f6*/
  }
  return result; /*0x1509fe*/
}
