/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9334. */
int __cdecl IOPhysicalFromVirtual(int a1, int a2, _DWORD *a3)
{
  int v3; // eax
  int v4; // eax

  v3 = _io_vm_task_pmap(a1); /*0x1a9343*/
  v4 = pmap_extract(v3, a2); /*0x1a934c*/
  *a3 = v4; /*0x1a9351*/
  if ( v4 ) /*0x1a9355*/
    return 0; /*0x1a9357*/
  else
    return -706; /*0x1a935c*/
}
