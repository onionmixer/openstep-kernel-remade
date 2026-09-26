/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14cb80. */
int __cdecl ipc_port_destroy(int a1)
{
  int v1; // ebx
  int v3; // eax
  int v4; // eax
  volatile __int32 *v5; // esi
  int v6; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  unsigned int v10; // esi
  int v11; // ebx
  int *v12; // [esp+10h] [ebp-18h]
  unsigned int v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h]
  unsigned int *v15; // [esp+1Ch] [ebp-Ch]
  int v16; // [esp+20h] [ebp-8h]
  int v17; // [esp+24h] [ebp-4h] BYREF

  v1 = *(_DWORD *)(a1 + 40); /*0x14cb8c*/
  if ( v1 ) /*0x14cb91*/
  {
    *(_DWORD *)(a1 + 40) = 0; /*0x14cb97*/
    *(_DWORD *)(a1 + 16) = 0; /*0x14cb9e*/
    *(_DWORD *)(a1 + 12) = 0; /*0x14cba5*/
    _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14cbae*/
    if ( (v1 & 1) != 0 ) /*0x14cbb3*/
    {
      LOBYTE(v1) = v1 & 0xFE; /*0x14cbb5*/
      if ( !ipc_port_check_circularity(a1, v1) ) /*0x14cbba*/
        return ipc_notify_port_destroyed_compat(v1, a1); /*0x14cbd0*/
      ipc_port_release_send(v1); /*0x14cbd9*/
    }
    else
    {
      if ( !ipc_port_check_circularity(a1, v1) ) /*0x14cbe5*/
        return ipc_notify_port_destroyed(v1, a1); /*0x14cbfb*/
      ipc_port_release_sonce(v1); /*0x14cc01*/
    }
    do /*0x14cc24*/
    {
      while ( *(_DWORD *)a1 ) /*0x14cc0f*/
        ; /*0x14cc11*/
    }
    while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x14cc24*/
  }
  while ( 1 ) /*0x14cc2d*/
  {
    v3 = ipc_thread_dequeue(a1 + 76); /*0x14cc2d*/
    if ( !v3 ) /*0x14cc37*/
      break; /*0x14cc37*/
    *(_DWORD *)(v3 + 152) = 0; /*0x14cc39*/
    thread_go(v3); /*0x14cc44*/
  }
  *(_DWORD *)(a1 + 8) &= ~0x80000000; /*0x14cc53*/
  do /*0x14cc75*/
  {
    while ( ipc_port_timestamp_lock_data ) /*0x14cc63*/
      ; /*0x14cc61*/
  }
  while ( _InterlockedExchange(&ipc_port_timestamp_lock_data, 1) == 1 ); /*0x14cc75*/
  v4 = ipc_port_timestamp_data++; /*0x14cc77*/
  _InterlockedExchange(&ipc_port_timestamp_lock_data, 0); /*0x14cc84*/
  *(_DWORD *)(a1 + 12) = v4; /*0x14cc8d*/
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x14cc92*/
  if ( *(_DWORD *)(a1 + 36) ) /*0x14cc94*/
    ipc_notify_send_once(*(_DWORD *)(a1 + 36)); /*0x14cc9c*/
  v5 = (volatile __int32 *)(a1 + 64); /*0x14cca7*/
  do /*0x14ccbe*/
  {
    while ( *v5 ) /*0x14ccac*/
      ; /*0x14ccae*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14ccbe*/
  while ( 1 ) /*0x14ccca*/
  {
    v6 = ipc_kmsg_dequeue(a1 + 68); /*0x14ccca*/
    if ( !v6 ) /*0x14ccd1*/
      break; /*0x14ccd1*/
    _InterlockedExchange(v5, 0); /*0x14ccd5*/
    ipc_object_release(a1); /*0x14ccdb*/
    *(_DWORD *)(v6 + 28) = 0; /*0x14cce0*/
    ipc_kmsg_destroy(v6); /*0x14cce8*/
    do /*0x14cd02*/
    {
      while ( *v5 ) /*0x14ccf0*/
        ; /*0x14ccf2*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14cd02*/
  }
  _InterlockedExchange(v5, 0); /*0x14cd0a*/
  v7 = *(_DWORD *)(a1 + 44); /*0x14cd0f*/
  v16 = v7; /*0x14cd12*/
  if ( v7 ) /*0x14cd17*/
  {
    v15 = *(unsigned int **)(v7 + 4); /*0x14cd20*/
    v14 = *v15; /*0x14cd25*/
    v13 = 1; /*0x14cd28*/
    if ( *v15 > 1 ) /*0x14cd32*/
    {
      v12 = (int *)(v7 + 8); /*0x14cd3e*/
      do /*0x14cdd3*/
      {
        v8 = v12[1]; /*0x14cd47*/
        if ( v8 ) /*0x14cd4c*/
        {
          v9 = *v12; /*0x14cd4e*/
          if ( (*v12 & 1) != 0 ) /*0x14cd52*/
          {
            v10 = v9 & 0xFFFFFFFE; /*0x14cd56*/
            if ( !ipc_right_lookup_write(v9 & 0xFFFFFFFE, v8, &v17) ) /*0x14cd5f*/
            {
              if ( *(_DWORD *)(v17 + 4) == a1 ) /*0x14cd74*/
              {
                v11 = ipc_port_copy_send(*(_DWORD *)(v10 + 68)); /*0x14cd7f*/
                ipc_right_destroy(v10, v8, v17); /*0x14cd87*/
              }
              else
              {
                _InterlockedExchange((volatile __int32 *)(v10 + 8), 0); /*0x14cd96*/
                v11 = 0; /*0x14cd99*/
              }
              if ( v11 && v11 != -1 ) /*0x14cda2*/
                ipc_notify_port_deleted_compat(v11, v8); /*0x14cda6*/
            }
            ipc_space_release(v10); /*0x14cdaf*/
          }
          else
          {
            ipc_notify_dead_name(v9, v12[1]); /*0x14cdbe*/
          }
        }
        v12 += 2; /*0x14cdc6*/
        ++v13; /*0x14cdca*/
      }
      while ( v13 < v14 ); /*0x14cdd3*/
    }
    ipc_table_free(8 * *v15, v16); /*0x14cdea*/
  }
  if ( *(_WORD *)(a1 + 8) ) /*0x14cdf5*/
    ipc_kobject_destroy(a1); /*0x14cdfd*/
  return ipc_object_release(a1); /*0x14ce11*/
}
