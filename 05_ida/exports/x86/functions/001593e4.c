/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1593e4. */
int __cdecl ipc_task_init(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  int result; // eax
  int j; // ebx
  volatile __int32 *v5; // edx
  int i; // ebx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  if ( ipc_space_create((unsigned int *)ipc_table_entries, &v7) ) /*0x1593fe*/
    panic(aIpcTaskInit); /*0x15940f*/
  v2 = ipc_port_alloc_special(ipc_space_kernel); /*0x15941e*/
  if ( !v2 ) /*0x15942a*/
    panic(aIpcTaskInit_0); /*0x159431*/
  a1[25] = 0; /*0x159439*/
  a1[26] = v2; /*0x159440*/
  result = ipc_port_make_send((int)v2); /*0x159444*/
  a1[27] = result; /*0x159449*/
  a1[34] = v7; /*0x15944f*/
  if ( a2 ) /*0x15945a*/
  {
    v5 = (volatile __int32 *)(a2 + 100); /*0x159480*/
    do /*0x159496*/
    {
      while ( *v5 ) /*0x159484*/
        ; /*0x159486*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x159496*/
    for ( i = 0; i <= 3; ++i ) /*0x159498*/
      a1[i + 30] = ipc_port_copy_send(*(_DWORD *)(a2 + 4 * i + 120)); /*0x1594a6*/
    a1[28] = ipc_port_copy_send(*(_DWORD *)(a2 + 112)); /*0x1594bc*/
    a1[29] = ipc_port_copy_send(*(_DWORD *)(a2 + 116)); /*0x1594c8*/
    return _InterlockedExchange((volatile __int32 *)(a2 + 100), 0); /*0x1594cd*/
  }
  else
  {
    a1[28] = 0; /*0x15945c*/
    a1[29] = 0; /*0x159463*/
    for ( j = 3; j >= 0; --j ) /*0x15946a*/
      a1[j + 30] = 0; /*0x159470*/
  }
  return result; /*0x1594d3*/
}
