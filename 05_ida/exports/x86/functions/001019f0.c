/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1019f0. */
unsigned int __cdecl page_copy(void *a1, const void *a2, unsigned int a3)
{
  qmemcpy(a1, a2, 4 * (a3 >> 2)); /*0x101a03*/
  return a3 >> 2; /*0x101a08*/
}
