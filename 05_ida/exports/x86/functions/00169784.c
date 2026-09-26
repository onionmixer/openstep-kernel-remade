/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x169784. */
_DWORD *__cdecl calloutEntryAllocate(int a1, int a2)
{
  _DWORD *result; // eax

  result = (_DWORD *)kalloc(0x20u); /*0x169791*/
  result[2] = a1; /*0x169796*/
  result[3] = 0; /*0x169799*/
  result[4] = a2; /*0x1697a0*/
  result[5] = 0; /*0x1697a3*/
  result[6] = 0; /*0x1697aa*/
  result[7] = 0; /*0x1697b1*/
  return result; /*0x1697bb*/
}
