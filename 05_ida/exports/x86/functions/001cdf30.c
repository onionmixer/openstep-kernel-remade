/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cdf30. */
_DWORD *__cdecl sub_1CDF30(int a1)
{
  _DWORD *v1; // edx
  _DWORD *i; // eax

  v1 = nullptr; /*0x1cdf36*/
  for ( i = *(_DWORD **)(a1 + 28); i; i = (_DWORD *)*i ) /*0x1cdf3d*/
    v1 = i; /*0x1cdf40*/
  return v1; /*0x1cdf4c*/
}
