/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d2d4. */
int __cdecl sub_15D2D4(int a1, int *a2, int a3, _DWORD *a4)
{
  int v5; // edi
  int v6; // edx
  int *v7; // ebx
  int v8; // esi
  _DWORD *v9; // ebx

  v5 = a3; /*0x15d2dd*/
  *a4 = 0; /*0x15d2e3*/
  if ( !a3 ) /*0x15d2eb*/
    return 0; /*0x15d32b*/
  while ( 1 ) /*0x15d2f0*/
  {
    v6 = *a2; /*0x15d2f0*/
    v7 = a2 + 1; /*0x15d2f2*/
    v8 = *v7; /*0x15d2f5*/
    v9 = v7 + 1; /*0x15d2f7*/
    v5 -= 4 * v8 + 8; /*0x15d301*/
    if ( thread_entrypoint(a1, v6, v9, v8, a4) ) /*0x15d30e*/
      break; /*0x15d30e*/
    a2 = &v9[v8]; /*0x15d324*/
    if ( !v5 ) /*0x15d329*/
      return 0; /*0x15d329*/
  }
  return 4; /*0x15d330*/
}
