/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135c08. */
__int16 __cdecl ckuwakeup(int a1)
{
  int v1; // edx

  v1 = *(_DWORD *)(a1 + 20); /*0x135c0e*/
  *(_BYTE *)a1 |= 1u; /*0x135c11*/
  return sbwakeup(v1 + 36); /*0x135c1f*/
}
