/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x176064. */
int __cdecl vm_map_entry_unwire(int a1, int a2)
{
  int result; // eax

  result = vm_fault_unwire(a1, a2); /*0x176070*/
  *(_WORD *)(a2 + 40) = 0; /*0x176075*/
  return result; /*0x17607b*/
}
