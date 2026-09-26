/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157d74. */
_DWORD *__cdecl ipc_pset_init(int a1)
{
  _DWORD *v1; // eax
  _DWORD *result; // eax

  v1 = ipc_port_alloc_special(ipc_space_kernel); /*0x157d83*/
  if ( !v1 ) /*0x157d8f*/
    panic(aIpcPsetInit); /*0x157d96*/
  *(_DWORD *)(a1 + 348) = v1; /*0x157d9e*/
  result = ipc_port_alloc_special(ipc_space_kernel); /*0x157dab*/
  if ( !result ) /*0x157db7*/
    panic(aIpcPsetInit_0); /*0x157dbe*/
  *(_DWORD *)(a1 + 352) = result; /*0x157dc3*/
  return result; /*0x157dcc*/
}
