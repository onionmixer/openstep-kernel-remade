/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18d1e4. */
int __cdecl us_spin(int a1)
{
  int v2; // edx
  int result; // eax

  while ( 1 ) /*0x18d1fb*/
  {
    result = a1--; /*0x18d1fb*/
    if ( !result ) /*0x18d200*/
      break; /*0x18d200*/
    v2 = us_spin_us_const; /*0x18d1ec*/
    while ( v2-- ) /*0x18d1f9*/
      ; /*0x18d1f4*/
  }
  return result; /*0x18d204*/
}
