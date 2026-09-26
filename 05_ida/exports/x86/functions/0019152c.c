/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19152c. */
unsigned int __cdecl pmap_clear_reference(unsigned int a1)
{
  unsigned int result; // eax

  result = a1; /*0x19152f*/
  if ( vm_first_phys <= a1 && vm_last_phys > a1 ) /*0x191540*/
    return sub_19157C(a1, 2); /*0x191545*/
  return result; /*0x19154c*/
}
