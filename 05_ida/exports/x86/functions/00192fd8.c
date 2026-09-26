/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192fd8. */
unsigned __int32 __cdecl byte_swap_csum(unsigned int *a1)
{
  unsigned int *v1; // edx
  unsigned __int32 result; // eax

  v1 = a1; /*0x192fdb*/
  do /*0x192fef*/
  {
    result = _byteswap_ulong(*v1); /*0x192fe6*/
    *v1++ = result; /*0x192fe8*/
  }
  while ( (int)v1 < (int)(a1 + 4) ); /*0x192fef*/
  return result; /*0x192ff3*/
}
