/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19b9e0. */
__int16 __cdecl sub_19B9E0(int a1, _WORD *a2)
{
  _WORD *v2; // eax
  __int16 result; // ax

  v2 = *(_WORD **)(a1 + 28); /*0x19b9e9*/
  a2[1] = v2[74]; /*0x19b9f3*/
  *a2 = v2[78]; /*0x19b9fe*/
  a2[2] = v2[2]; /*0x19ba05*/
  result = v2[4]; /*0x19ba09*/
  a2[3] = result; /*0x19ba0d*/
  return result; /*0x19ba13*/
}
