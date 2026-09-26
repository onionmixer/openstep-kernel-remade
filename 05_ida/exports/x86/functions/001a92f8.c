/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a92f8. */
int __cdecl IOVmTaskForBuf(_DWORD *a1)
{
  if ( (*a1 & 0x4000010) == 0x10 ) /*0x1a9308*/
    return _io_vm_task(*(_DWORD *)(a1[11] + 104)); /*0x1a9311*/
  else
    return _io_vm_task_self(); /*0x1a931c*/
}
