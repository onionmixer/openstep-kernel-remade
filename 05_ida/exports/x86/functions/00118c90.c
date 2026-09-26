/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118c90. */
int __cdecl unp_dispose(int a1)
{
  int result; // eax

  result = a1; /*0x118c93*/
  if ( a1 ) /*0x118c98*/
    return unp_scan(a1, unp_discard); /*0x118ca0*/
  return result; /*0x118ca7*/
}
