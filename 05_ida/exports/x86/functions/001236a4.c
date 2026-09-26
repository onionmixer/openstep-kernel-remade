/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1236a4. */
_BOOL4 __cdecl in_canforward(unsigned int a1)
{
  int v1; // edx

  v1 = _byteswap_ulong(a1); /*0x1236ac*/
  return (v1 & 0xE0000000) != 0xE0000000 && (v1 < 0 || (v1 & 0xFF000000) != 0 && (v1 & 0x7F000000) != 0x7F); /*0x1236c0*/
}
