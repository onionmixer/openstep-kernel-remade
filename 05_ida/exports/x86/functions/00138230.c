/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138230. */
_DWORD *__cdecl xdrmbuf_init(_DWORD *a1, int a2, int a3)
{
  *a1 = a3; /*0x13823c*/
  a1[1] = &xdrmbuf_ops; /*0x13823e*/
  a1[4] = a2; /*0x138245*/
  a1[3] = a2 + *(_DWORD *)(a2 + 4); /*0x13824d*/
  a1[2] = 0; /*0x138250*/
  a1[5] = *(__int16 *)(a2 + 8); /*0x13825b*/
  return a1; /*0x138260*/
}
