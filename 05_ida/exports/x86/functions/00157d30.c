/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157d30. */
int __cdecl ipc_processor_init(int a1)
{
  _DWORD *v1; // eax

  v1 = ipc_port_alloc_special(ipc_space_kernel); /*0x157d3f*/
  if ( !v1 ) /*0x157d4b*/
    panic(aIpcProcessorIn); /*0x157d52*/
  *(_DWORD *)(a1 + 320) = v1; /*0x157d5a*/
  return ipc_kobject_set(v1, a1, 5); /*0x157d6c*/
}
