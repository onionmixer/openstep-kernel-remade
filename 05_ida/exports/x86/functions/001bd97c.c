/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd97c. */
unsigned __int32 __cdecl put_dl_un(unsigned int *a1, unsigned __int32 *a2)
{
  unsigned int *v3; // edx
  unsigned __int32 result; // eax

  v3 = a1; /*0x1bd983*/
  do /*0x1bd99a*/
  {
    result = _byteswap_ulong(*v3); /*0x1bd98e*/
    *a2++ = result; /*0x1bd990*/
    ++v3; /*0x1bd995*/
  }
  while ( (int)v3 <= (int)(a1 + 1669) ); /*0x1bd99a*/
  return result; /*0x1bd99c*/
}
