/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18b524. */
int __cdecl intr_enbl(int a1)
{
  unsigned int v1; // kr00_4

  v1 = __readeflags(); /*0x18b52a*/
  if ( a1 ) /*0x18b52e*/
    _enable(); /*0x18b530*/
  else
    _disable(); /*0x18b534*/
  return (v1 >> 9) & 1; /*0x18b53f*/
}
