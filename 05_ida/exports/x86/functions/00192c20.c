/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192c20. */
void __cdecl byte_swap_ints(unsigned int *a1, int a2)
{
  int i; // ecx

  for ( i = 0; i < a2; ++i ) /*0x192c2b*/
  {
    *a1 = _byteswap_ulong(*a1); /*0x192c34*/
    ++a1; /*0x192c36*/
  }
}
