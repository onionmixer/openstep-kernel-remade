/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1877f8. */
int __cdecl checksum_16(__int16 *a1, int a2)
{
  unsigned int i; // ecx
  __int16 v5; // ax
  int v6; // ecx

  for ( i = 0; --a2 != -1; i += (unsigned __int16)__ROR2__(v5, 8) ) /*0x1877ff*/
    v5 = *a1++; /*0x187808*/
  v6 = HIWORD(i) + (unsigned __int16)i; /*0x187827*/
  if ( v6 > 0xFFFF ) /*0x187830*/
    LOWORD(v6) = v6 + 1; /*0x187832*/
  return (unsigned __int16)v6; /*0x18783b*/
}
