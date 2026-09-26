/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca900. */
int __cdecl sub_1CA900(int a1, int a2)
{
  int result; // eax
  int v3; // ebx
  int v4; // edx
  int v5; // edx

  result = 0; /*0x1ca90c*/
  v3 = 0; /*0x1ca90e*/
  if ( *(int *)(a1 + 4) <= 0 ) /*0x1ca913*/
    return 0; /*0x1ca954*/
  while ( 1 ) /*0x1ca918*/
  {
    v4 = *(_DWORD *)(a1 + 4 * v3 + 8); /*0x1ca918*/
    if ( *(_DWORD *)(v4 + 16) ) /*0x1ca91c*/
      result = sub_1CA868(*(int **)(v4 + 16), a2); /*0x1ca927*/
    if ( result ) /*0x1ca931*/
      break; /*0x1ca931*/
    v5 = *(_DWORD *)(a1 + 4 * v3 + 8); /*0x1ca933*/
    if ( *(_DWORD *)(v5 + 8) ) /*0x1ca937*/
      result = sub_1CA900(*(_DWORD *)(v5 + 8), a2); /*0x1ca942*/
    if ( result ) /*0x1ca94c*/
      break; /*0x1ca94c*/
    if ( *(_DWORD *)(a1 + 4) <= ++v3 ) /*0x1ca952*/
      return 0; /*0x1ca952*/
  }
  return result; /*0x1ca959*/
}
