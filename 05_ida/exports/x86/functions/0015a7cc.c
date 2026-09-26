/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a7cc. */
int __cdecl kget(unsigned int a1)
{
  unsigned int v1; // eax
  int i; // edx

  if ( k_zone_maxsize < a1 ) /*0x15a7db*/
    goto LABEL_6; /*0x15a7db*/
  v1 = k_zone_elemsize[0]; /*0x15a7dd*/
  for ( i = 0; v1 < a1; v1 = k_zone_elemsize[i] ) /*0x15a7e6*/
    ++i; /*0x15a7e8*/
  if ( k_zone_maxsize < v1 ) /*0x15a7fa*/
LABEL_6:
    panic(aKget); /*0x15a815*/
  return zget(k_zone[i]); /*0x15a81c*/
}
