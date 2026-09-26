/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1914dc. */
unsigned int __cdecl pmap_clear_modify(unsigned int a1)
{
  unsigned int result; // eax

  result = a1; /*0x1914df*/
  if ( vm_first_phys <= a1 && vm_last_phys > a1 ) /*0x1914f0*/
    return sub_19157C(a1, 1); /*0x1914f5*/
  return result; /*0x1914fc*/
}
