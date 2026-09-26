/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca8a0. */
int __cdecl sub_1CA8A0(int a1, int a2)
{
  int result; // eax
  int v3; // ebx
  int v4; // edx
  int v5; // edx

  result = 0; /*0x1ca8ac*/
  v3 = 0; /*0x1ca8ae*/
  if ( *(int *)(a1 + 4) <= 0 ) /*0x1ca8b3*/
    return 0; /*0x1ca8f4*/
  while ( 1 ) /*0x1ca8b8*/
  {
    v4 = *(_DWORD *)(a1 + 4 * v3 + 8); /*0x1ca8b8*/
    if ( *(_DWORD *)(v4 + 12) ) /*0x1ca8bc*/
      result = sub_1CA868(*(int **)(v4 + 12), a2); /*0x1ca8c7*/
    if ( result ) /*0x1ca8d1*/
      break; /*0x1ca8d1*/
    v5 = *(_DWORD *)(a1 + 4 * v3 + 8); /*0x1ca8d3*/
    if ( *(_DWORD *)(v5 + 8) ) /*0x1ca8d7*/
      result = sub_1CA8A0(*(_DWORD *)(v5 + 8), a2); /*0x1ca8e2*/
    if ( result ) /*0x1ca8ec*/
      break; /*0x1ca8ec*/
    if ( *(_DWORD *)(a1 + 4) <= ++v3 ) /*0x1ca8f2*/
      return 0; /*0x1ca8f2*/
  }
  return result; /*0x1ca8f9*/
}
