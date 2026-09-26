/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16a30c. */
int __cdecl timer_delta(int *a1, _DWORD *a2)
{
  int result; // eax
  int v3; // [esp+Ch] [ebp-8h]
  int v4; // [esp+10h] [ebp-4h]

  do /*0x16a32d*/
  {
    v4 = a1[1]; /*0x16a31f*/
    v3 = *a1; /*0x16a324*/
  }
  while ( a1[2] != v4 ); /*0x16a32d*/
  result = *a1 + 1000000 * (v4 - a2[1]) - *a2; /*0x16a34a*/
  a2[1] = v4; /*0x16a34c*/
  *a2 = v3; /*0x16a352*/
  return result; /*0x16a357*/
}
