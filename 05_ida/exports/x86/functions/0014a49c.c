/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a49c. */
int __cdecl ipc_marequest_destroy(unsigned int *a1)
{
  unsigned int v1; // ebx
  int v2; // edi
  volatile __int32 *v3; // edx
  unsigned int v4; // esi
  int v5; // edx
  _DWORD *i; // eax
  int *v7; // eax
  int result; // eax
  _DWORD *v9; // [esp+Ch] [ebp-8h]
  unsigned int v10; // [esp+10h] [ebp-4h]

  v1 = *a1; /*0x14a4a8*/
  v2 = 0; /*0x14a4aa*/
  v3 = (volatile __int32 *)(*a1 + 8); /*0x14a4ac*/
  do /*0x14a4c2*/
  {
    while ( *v3 ) /*0x14a4b0*/
      ; /*0x14a4b2*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x14a4c2*/
  v4 = a1[1]; /*0x14a4c7*/
  v10 = a1[2]; /*0x14a4cd*/
  if ( v4 ) /*0x14a4d2*/
  {
    v5 = ipc_marequest_table + 8 * (ipc_marequest_mask & ((unsigned __int8)v4 + (v4 >> 8) + (v1 >> 4))); /*0x14a4f7*/
    do /*0x14a50e*/
    {
      while ( *(_DWORD *)v5 ) /*0x14a4fc*/
        ; /*0x14a4fe*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v5, 1) == 1 ); /*0x14a50e*/
    v9 = (_DWORD *)(v5 + 4); /*0x14a513*/
    for ( i = *(_DWORD **)(v5 + 4); i; i = (_DWORD *)i[3] ) /*0x14a51b*/
    {
      if ( *i == v1 && i[1] == v4 ) /*0x14a527*/
        break; /*0x14a527*/
      v9 = i + 3; /*0x14a52c*/
    }
    *v9 = i[3]; /*0x14a53c*/
    _InterlockedExchange((volatile __int32 *)v5, 0); /*0x14a540*/
    if ( *(_DWORD *)(v1 + 12) ) /*0x14a542*/
    {
      v7 = ipc_entry_lookup((_DWORD *)v1, v4); /*0x14a54a*/
      *v7 &= ~0x200000u; /*0x14a54f*/
      if ( !v10 ) /*0x14a55c*/
        v2 = ipc_port_copy_send(*(_DWORD *)(v1 + 68)); /*0x14a567*/
    }
    else
    {
      v4 = 0; /*0x14a570*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(v1 + 8), 0); /*0x14a574*/
  ipc_space_release(v1); /*0x14a578*/
  result = zfree(ipc_marequest_zone, a1); /*0x14a588*/
  if ( v10 ) /*0x14a594*/
    return ipc_notify_msg_accepted(v10, v4); /*0x14a5ad*/
  if ( v2 ) /*0x14a598*/
  {
    if ( v2 != -1 ) /*0x14a59d*/
      return ipc_notify_msg_accepted_compat(v2, v4); /*0x14a5a1*/
  }
  return result; /*0x14a5b5*/
}
