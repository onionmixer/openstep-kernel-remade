/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d270. */
int __cdecl sub_15D270(int a1, int *a2, int a3, _DWORD *a4)
{
  int v5; // edi
  int v6; // edx
  int *v7; // ebx
  int v8; // esi
  _DWORD *v9; // ebx

  v5 = a3; /*0x15d279*/
  *a4 = 0; /*0x15d27f*/
  if ( !a3 ) /*0x15d287*/
    return 0; /*0x15d2c7*/
  while ( 1 ) /*0x15d28c*/
  {
    v6 = *a2; /*0x15d28c*/
    v7 = a2 + 1; /*0x15d28e*/
    v8 = *v7; /*0x15d291*/
    v9 = v7 + 1; /*0x15d293*/
    v5 -= 4 * v8 + 8; /*0x15d29d*/
    if ( thread_userstack(a1, v6, v9, v8, a4) ) /*0x15d2aa*/
      break; /*0x15d2aa*/
    a2 = &v9[v8]; /*0x15d2c0*/
    if ( !v5 ) /*0x15d2c5*/
      return 0; /*0x15d2c5*/
  }
  return 4; /*0x15d2cc*/
}
