/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1377c4. */
int __cdecl svckudp_freeargs(int a1, int (__stdcall *a2)(int, int), int a3)
{
  int v3; // ebx

  v3 = *(_DWORD *)(a1 + 48); /*0x1377d0*/
  if ( *(_DWORD *)(v3 + 8) ) /*0x1377d6*/
    m_freem(*(_DWORD *)(v3 + 8)); /*0x1377de*/
  *(_DWORD *)(v3 + 8) = 0; /*0x1377e6*/
  if ( !a3 ) /*0x1377ef*/
    return 1; /*0x137804*/
  *(_DWORD *)(v3 + 12) = 2; /*0x1377f1*/
  return a2(v3 + 12, a3); /*0x13780c*/
}
