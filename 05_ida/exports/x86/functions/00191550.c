/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191550. */
int __cdecl pmap_is_referenced(unsigned int a1)
{
  if ( vm_first_phys > a1 || vm_last_phys <= a1 ) /*0x191564*/
    return 0; /*0x191574*/
  else
    return sub_1916E0(a1, 2); /*0x191569*/
}
