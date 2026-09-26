/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a030. */
kern_return_t __cdecl mach_ports_register(
        task_t target_task,
        mach_port_array_t init_port_set,
        mach_msg_type_number_t init_port_setCnt)
{
  signed int i; // ebx
  volatile __int32 *v4; // ebx
  int j; // ebx
  int v7; // eax
  int k; // ebx
  int v9; // eax
  _DWORD v10[4]; // [esp+Ch] [ebp-10h]

  if ( !target_task || init_port_setCnt > 4 ) /*0x15a046*/
    return 4; /*0x15a046*/
  for ( i = 0; i < init_port_setCnt; ++i ) /*0x15a04c*/
    v10[i] = init_port_set[i]; /*0x15a056*/
  while ( i <= 3 ) /*0x15a070*/
    v10[i++] = 0; /*0x15a064*/
  v4 = (volatile __int32 *)(target_task + 100); /*0x15a072*/
  do /*0x15a08a*/
  {
    while ( *v4 ) /*0x15a078*/
      ; /*0x15a07a*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x15a08a*/
  if ( !*(_DWORD *)(target_task + 104) ) /*0x15a08c*/
  {
    _InterlockedExchange((volatile __int32 *)(target_task + 100), 0); /*0x15a094*/
    return 4; /*0x15a09c*/
  }
  for ( j = 0; j <= 3; ++j ) /*0x15a0a0*/
  {
    v7 = *(_DWORD *)(target_task + 4 * j + 120); /*0x15a0a4*/
    *(_DWORD *)(target_task + 4 * j + 120) = v10[j]; /*0x15a0ac*/
    v10[j] = v7; /*0x15a0b0*/
  }
  _InterlockedExchange((volatile __int32 *)(target_task + 100), 0); /*0x15a0bc*/
  for ( k = 0; k <= 3; ++k ) /*0x15a0bf*/
  {
    v9 = v10[k]; /*0x15a0c4*/
    if ( v9 && v9 != -1 ) /*0x15a0cf*/
      ipc_port_release_send(v10[k]); /*0x15a0d2*/
  }
  if ( init_port_setCnt ) /*0x15a0e2*/
    kfree((int)init_port_set, 4 * init_port_setCnt); /*0x15a0f0*/
  return 0; /*0x15a0fa*/
}
