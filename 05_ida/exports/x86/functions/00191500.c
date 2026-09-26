/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x191500. */
int __cdecl pmap_is_modified(unsigned int a1)
{
  if ( vm_first_phys > a1 || vm_last_phys <= a1 ) /*0x191514*/
    return 0; /*0x191524*/
  else
    return sub_1916E0(a1, 1); /*0x191519*/
}
