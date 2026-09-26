/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11654c. */
int __cdecl soreserve(int a1, int a2, int a3)
{
  if ( sbreserve(a1 + 60, a2) ) /*0x11655c*/
  {
    if ( sbreserve(a1 + 36, a3) ) /*0x116570*/
      return 0; /*0x11657e*/
    sbrelease(a1 + 60); /*0x116581*/
  }
  return 55; /*0x11658e*/
}
