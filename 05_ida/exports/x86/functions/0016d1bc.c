/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d1bc. */
int kern_serv_kernel_task_port()
{
  int v0; // eax
  int v2; // [esp+0h] [ebp-4h] BYREF

  task_reference(kernel_task); /*0x16d1c9*/
  v0 = convert_task_to_port(kernel_task); /*0x16d1d5*/
  v2 = v0; /*0x16d1dc*/
  if ( !v0 ) /*0x16d1e4*/
    return 0; /*0x16d204*/
  object_copyout(*(_DWORD *)(active_threads + 12), v0, 6, &v2); /*0x16d1f6*/
  return v2; /*0x16d1fe*/
}
