/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a22c. */
unsigned int __cdecl timer_read(unsigned int *a1, _DWORD *a2)
{
  unsigned int v3; // [esp+Ch] [ebp-Ch]
  unsigned int v4; // [esp+10h] [ebp-8h]

  do /*0x16a250*/
  {
    v4 = *a1; /*0x16a244*/
    v3 = a1[1]; /*0x16a24a*/
  }
  while ( a1[2] != v3 ); /*0x16a250*/
  *a2 = v3 + v4 / 0xF4240; /*0x16a265*/
  a2[1] = v4 % 0xF4240; /*0x16a272*/
  return v4 / 0xF4240; /*0x16a278*/
}
