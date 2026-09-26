/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181ce8. */
int __cdecl create_dev_port(int a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ebx

  v1 = ipc_port_alloc_special(ipc_space_kernel); /*0x181cf3*/
  v2 = v1; /*0x181cf8*/
  if ( !v1 ) /*0x181cff*/
    return 0; /*0x181d1c*/
  ipc_kobject_set((int)v1, a1, 12); /*0x181d08*/
  return IOConvertPort(v2, 0, 1); /*0x181d1e*/
}
