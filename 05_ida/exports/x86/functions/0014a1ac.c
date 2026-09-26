/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a1ac. */
int __cdecl ipc_marequest_create(unsigned int a1, volatile __int32 *a2, int a3, unsigned int **a4)
{
  unsigned int *v4; // esi
  volatile __int32 *v6; // edx
  unsigned int v7; // ebx
  int v8; // edx
  unsigned int v9; // ebx
  int v10; // [esp+10h] [ebp-Ch]
  int *v11; // [esp+14h] [ebp-8h] BYREF
  unsigned int v12; // [esp+18h] [ebp-4h] BYREF

  v4 = (unsigned int *)zalloc(ipc_marequest_zone); /*0x14a1c7*/
  if ( !v4 ) /*0x14a1ce*/
    return 268435470; /*0x14a1d5*/
  v6 = (volatile __int32 *)(a1 + 8); /*0x14a1dc*/
  do /*0x14a1f2*/
  {
    while ( *v6 ) /*0x14a1e0*/
      ; /*0x14a1e2*/
  }
  while ( _InterlockedExchange(v6, 1) == 1 ); /*0x14a1f2*/
  if ( !*(_DWORD *)(a1 + 12) ) /*0x14a1f4*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14a1fc*/
    zfree(ipc_marequest_zone, v4); /*0x14a207*/
    return 268435467; /*0x14a211*/
  }
  if ( ipc_right_reverse(a1, a2, &v12, &v11) ) /*0x14a225*/
  {
    _InterlockedExchange(a2, 0); /*0x14a23a*/
    v10 = *v11; /*0x14a241*/
    if ( (*v11 & 0x200000) != 0 ) /*0x14a249*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14a24d*/
      zfree(ipc_marequest_zone, v4); /*0x14a258*/
      return 268435462; /*0x14a262*/
    }
    if ( a3 ) /*0x14a26a*/
    {
      v7 = ipc_port_lookup_notify(a1, a3); /*0x14a273*/
      if ( !v7 ) /*0x14a27a*/
      {
LABEL_13:
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14a27c*/
        zfree(ipc_marequest_zone, v4); /*0x14a289*/
        return 268435467; /*0x14a293*/
      }
    }
    else
    {
      v7 = 0; /*0x14a298*/
    }
    *v11 = v10 | 0x200000; /*0x14a2a6*/
    ipc_space_reference(a1); /*0x14a2a9*/
    *v4 = a1; /*0x14a2ae*/
    v4[1] = v12; /*0x14a2b3*/
    v4[2] = v7; /*0x14a2b6*/
    v8 = ipc_marequest_table + 8 * (ipc_marequest_mask & ((unsigned __int8)v12 + (v12 >> 8) + (a1 >> 4))); /*0x14a2dc*/
    do /*0x14a2f2*/
    {
      while ( *(_DWORD *)v8 ) /*0x14a2e0*/
        ; /*0x14a2e2*/
    }
    while ( _InterlockedExchange((volatile __int32 *)v8, 1) == 1 ); /*0x14a2f2*/
    v4[3] = *(_DWORD *)(v8 + 4); /*0x14a2f7*/
    *(_DWORD *)(v8 + 4) = v4; /*0x14a2fa*/
    _InterlockedExchange((volatile __int32 *)v8, 0); /*0x14a2ff*/
  }
  else
  {
    if ( a3 ) /*0x14a306*/
    {
      v9 = ipc_port_lookup_notify(a1, a3); /*0x14a30f*/
      if ( !v9 ) /*0x14a316*/
        goto LABEL_13; /*0x14a316*/
    }
    else
    {
      v9 = 0; /*0x14a334*/
    }
    ipc_space_reference(a1); /*0x14a337*/
    *v4 = a1; /*0x14a33c*/
    v4[1] = 0; /*0x14a33e*/
    v4[2] = v9; /*0x14a345*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14a34a*/
  *a4 = v4; /*0x14a350*/
  return 0; /*0x14a357*/
}
