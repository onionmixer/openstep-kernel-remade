/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x186f04. */
// positive sp value has been detected, the output may be wrong!
void _return_with_state()
{
  _disable(); /*0x186f06*/
  empty_stacks = 1; /*0x186f09*/
  _enable(); /*0x186f13*/
  __asm { iret } /*0x186f1e*/
}
