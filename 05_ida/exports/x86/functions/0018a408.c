/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18a408. */
kern_return_t __cdecl fp_ast(int a1)
{
  *(_DWORD *)(a1 + 380) &= ~0x40000000u; /*0x18a40e*/
  return exception(3, (exception_data_t)0x10, 0); /*0x18a425*/
}
