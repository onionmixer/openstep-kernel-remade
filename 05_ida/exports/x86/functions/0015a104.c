/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a104. */
kern_return_t __cdecl mach_ports_lookup(
        task_t target_task,
        mach_port_array_t *init_port_set,
        mach_msg_type_number_t *init_port_setCnt)
{
  int v4; // ebx
  volatile __int32 *v5; // edx
  mach_port_t *v6; // esi
  int i; // ebx

  if ( !target_task ) /*0x15a10f*/
    return 4; /*0x15a111*/
  v4 = kalloc(0x10u); /*0x15a11f*/
  if ( !v4 ) /*0x15a126*/
    return 6; /*0x15a128*/
  v5 = (volatile __int32 *)(target_task + 100); /*0x15a130*/
  do /*0x15a146*/
  {
    while ( *v5 ) /*0x15a134*/
      ; /*0x15a136*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x15a146*/
  if ( *(_DWORD *)(target_task + 104) ) /*0x15a148*/
  {
    v6 = (mach_port_t *)v4; /*0x15a164*/
    for ( i = 0; i <= 3; ++i ) /*0x15a166*/
      v6[i] = ipc_port_copy_send(*(_DWORD *)(target_task + 4 * i + 120)); /*0x15a172*/
    _InterlockedExchange((volatile __int32 *)(target_task + 100), 0); /*0x15a180*/
    *init_port_set = v6; /*0x15a186*/
    *init_port_setCnt = 4; /*0x15a18b*/
    return 0; /*0x15a191*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(target_task + 100), 0); /*0x15a150*/
    kfree(v4, 0x10u); /*0x15a156*/
    return 4; /*0x15a15b*/
  }
}
