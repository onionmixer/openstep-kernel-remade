/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ad9c. */
int __cdecl alloc_cnvmem(int a1, int a2)
{
  int result; // eax

  if ( !dword_1E75FC ) /*0x18ada9*/
  {
    dword_1E75FC = dword_1E7610; /*0x18adb1*/
    dword_1E7600 = dword_1E7614; /*0x18adbd*/
  }
  result = -a2 & (a2 + dword_1E75FC - 1); /*0x18adcd*/
  if ( dword_1E7600 < (unsigned int)(a1 + result) ) /*0x18adda*/
    return 0; /*0x18ade8*/
  dword_1E75FC = a1 + (-a2 & (a2 + dword_1E75FC - 1)); /*0x18addc*/
  return result; /*0x18ade4*/
}
