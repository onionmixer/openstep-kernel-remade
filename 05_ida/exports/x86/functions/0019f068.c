/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f068. */
__int16 __cdecl sub_19F068(int a1, _WORD *a2)
{
  _WORD *v2; // eax
  __int16 result; // ax

  v2 = *(_WORD **)(a1 + 28); /*0x19f071*/
  a2[1] = v2[74]; /*0x19f07b*/
  *a2 = v2[78]; /*0x19f086*/
  a2[2] = v2[2]; /*0x19f08d*/
  result = v2[4]; /*0x19f091*/
  a2[3] = result; /*0x19f095*/
  return result; /*0x19f09b*/
}
