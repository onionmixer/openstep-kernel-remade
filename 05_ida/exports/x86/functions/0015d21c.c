/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d21c. */
int __cdecl sub_15D21C(int a1, int *a2, int a3)
{
  int v4; // edi
  int v5; // edx
  int *v6; // ebx
  int v7; // esi
  _DWORD *v8; // ebx

  v4 = a3; /*0x15d225*/
  if ( !a3 ) /*0x15d22a*/
    return 0; /*0x15d263*/
  while ( 1 ) /*0x15d22c*/
  {
    v5 = *a2; /*0x15d22c*/
    v6 = a2 + 1; /*0x15d22e*/
    v7 = *v6; /*0x15d231*/
    v8 = v6 + 1; /*0x15d233*/
    v4 -= 4 * v7 + 8; /*0x15d23d*/
    if ( thread_setstatus(a1, v5, v8, v7) ) /*0x15d246*/
      break; /*0x15d246*/
    a2 = &v8[v7]; /*0x15d25c*/
    if ( !v4 ) /*0x15d261*/
      return 0; /*0x15d261*/
  }
  return 4; /*0x15d268*/
}
