/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd64c. */
unsigned __int32 __cdecl get_dl_un(unsigned int *a1, unsigned __int32 *a2)
{
  unsigned __int32 *v3; // edx
  unsigned __int32 result; // eax

  v3 = a2; /*0x1bd653*/
  do /*0x1bd66a*/
  {
    result = _byteswap_ulong(*a1); /*0x1bd65e*/
    *v3 = result; /*0x1bd660*/
    ++a1; /*0x1bd662*/
    ++v3; /*0x1bd665*/
  }
  while ( (int)v3 <= (int)(a2 + 1669) ); /*0x1bd66a*/
  return result; /*0x1bd66c*/
}
