/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x157eb8. */
int __cdecl ipc_pset_terminate(int a1)
{
  ipc_port_dealloc_special(*(_DWORD *)(a1 + 348)); /*0x157ecc*/
  return ipc_port_dealloc_special(*(_DWORD *)(a1 + 352)); /*0x157ee3*/
}
