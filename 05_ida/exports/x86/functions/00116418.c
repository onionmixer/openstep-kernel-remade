/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116418. */
unsigned int __cdecl sbwait(unsigned int a1)
{
  *(_BYTE *)(a1 + 20) |= 4u; /*0x11641e*/
  return sleep(a1); /*0x11642c*/
}
