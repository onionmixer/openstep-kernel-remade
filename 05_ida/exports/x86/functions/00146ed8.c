/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146ed8. */
int ipc_init()
{
  boolean_t v1; // [esp+0h] [ebp-8h] BYREF
  task_t *v2; // [esp+4h] [ebp-4h] BYREF

  if ( task_create(0, nullptr, (mach_msg_type_number_t)&ipc_soft_task, v1, v2) ) /*0x146ee7*/
    panic(aIpcInit); /*0x146ef8*/
  ipc_soft_map = *(_DWORD *)(ipc_soft_task + 12); /*0x146f08*/
  ipc_kernel_map = kmem_suballoc(kernel_map, &v2, &v1, ipc_kernel_map_size, 1); /*0x146f2a*/
  return ipc_host_init(); /*0x146f34*/
}
