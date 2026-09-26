/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184a74. */
int __cdecl IOSetDDMMask(int a1, int a2)
{
  int result; // eax

  result = a1; /*0x184a77*/
  if ( a1 > 4 ) /*0x184a7d*/
    return IOLog(aXprsetbitmaskI); /*0x184a85*/
  IODDMMasks[a1] = a2; /*0x184a93*/
  return result; /*0x184a8c*/
}
