/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ab88. */
_DWORD *rqinit()
{
  _DWORD *result; // eax
  int v1; // edx

  result = &qs; /*0x10ab8b*/
  v1 = 0; /*0x10ab90*/
  do /*0x10aba8*/
  {
    dword_1E9504[v1] = (int)result; /*0x10ab98*/
    *result = result; /*0x10ab9e*/
    result += 2; /*0x10aba0*/
    v1 += 2; /*0x10aba3*/
  }
  while ( (int)result <= (int)dword_1E95F8 ); /*0x10aba8*/
  return result; /*0x10abac*/
}
