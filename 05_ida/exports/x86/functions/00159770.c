/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x159770. */
int __cdecl ipc_thread_terminate(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edx
  unsigned int v8; // ebx
  volatile __int32 *v9; // esi
  volatile __int32 *v10; // edx
  int *v11; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  v1 = (volatile __int32 *)(a1 + 168); /*0x15977c*/
  do /*0x159796*/
  {
    while ( *v1 ) /*0x159784*/
      ; /*0x159786*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x159796*/
  v2 = *(_DWORD *)(a1 + 172); /*0x159798*/
  if ( !v2 ) /*0x1597a0*/
    return _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x1597a4*/
  *(_DWORD *)(a1 + 172) = 0; /*0x1597b0*/
  _InterlockedExchange((volatile __int32 *)(a1 + 168), 0); /*0x1597bc*/
  v4 = *(_DWORD *)(a1 + 176); /*0x1597c2*/
  if ( v4 && v4 != -1 ) /*0x1597cf*/
    ipc_port_release_send(*(_DWORD *)(a1 + 176)); /*0x1597d2*/
  v5 = *(_DWORD *)(a1 + 180); /*0x1597da*/
  if ( v5 && v5 != -1 ) /*0x1597e7*/
    ipc_port_release_send(*(_DWORD *)(a1 + 180)); /*0x1597ea*/
  v6 = *(_DWORD *)(a1 + 192); /*0x1597f2*/
  if ( v6 && v6 != -1 ) /*0x1597ff*/
    ipc_port_dealloc_special(v6); /*0x159809*/
  v7 = *(_DWORD *)(a1 + 184); /*0x159811*/
  if ( v7 && v7 != -1 ) /*0x15981e*/
  {
    v8 = *(_DWORD *)(*(_DWORD *)(a1 + 12) + 136); /*0x159823*/
    v9 = *(volatile __int32 **)(a1 + 184); /*0x159829*/
    v10 = (volatile __int32 *)(v8 + 8); /*0x15982b*/
    do /*0x159842*/
    {
      while ( *v10 ) /*0x159830*/
        ; /*0x159832*/
    }
    while ( _InterlockedExchange(v10, 1) == 1 ); /*0x159842*/
    if ( *(_DWORD *)(v8 + 12) && ipc_right_reverse((_DWORD *)v8, (int)v9, &v12, &v11) ) /*0x159854*/
    {
      _InterlockedExchange(v9, 0); /*0x159862*/
      ipc_right_destroy(v8, v12, (int)v11); /*0x15986d*/
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(v8 + 8), 0); /*0x15987a*/
    }
    ipc_port_release_send((int)v9); /*0x15987e*/
  }
  return ipc_port_dealloc_special(v2); /*0x159896*/
}
