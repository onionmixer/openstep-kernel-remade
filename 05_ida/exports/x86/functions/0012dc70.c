/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12dc70. */
int __cdecl sub_12DC70(int a1, _DWORD *a2)
{
  int v2; // ecx
  int i; // edx

  v2 = 0; /*0x12dc7c*/
  if ( !*a2 ) /*0x12dc7e*/
    return 0; /*0x12dccc*/
  for ( i = a2[1]; *(_WORD *)i != *(_WORD *)a1 || *(_WORD *)a1 != 2 || *(_DWORD *)(a1 + 4) != *(_DWORD *)(i + 4); i += 16 ) /*0x12dc8e*/
  {
    if ( *a2 <= (unsigned int)++v2 ) /*0x12dcca*/
      return 0; /*0x12dcca*/
  }
  return 1; /*0x12dcd1*/
}
