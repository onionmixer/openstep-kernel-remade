/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f468. */
int __cdecl setdirmode(int a1, int a2)
{
  int v2; // edx

  v2 = a2; /*0x12f46e*/
  BYTE1(v2) = BYTE1(a2) & 0xFB; /*0x12f471*/
  if ( (*(_BYTE *)(*(_DWORD *)(a1 + 48) + 133) & 4) != 0 ) /*0x12f47e*/
    BYTE1(v2) |= 4u; /*0x12f480*/
  return v2; /*0x12f487*/
}
