/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e3b8. */
int _io_vm_task_current()
{
  return *(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12); /*0x17e3c8*/
}
