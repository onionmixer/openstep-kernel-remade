/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ca60. */
int __cdecl pn_combine(int a1, int a2)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 8); /*0x11ca6f*/
  if ( (unsigned int)(v2 + *(_DWORD *)(a1 + 8)) > 0x3FF ) /*0x11ca7a*/
    return 63; /*0x11caac*/
  ovbcopy(*(void **)(a1 + 4), (void *)(v2 + *(_DWORD *)a1), *(_DWORD *)(a1 + 8)); /*0x11ca86*/
  bcopy(*(const void **)(a2 + 4), *(void **)a1, *(_DWORD *)(a2 + 8)); /*0x11ca96*/
  *(_DWORD *)(a1 + 8) += *(_DWORD *)(a2 + 8); /*0x11ca9e*/
  *(_DWORD *)(a1 + 4) = *(_DWORD *)a1; /*0x11caa3*/
  return 0; /*0x11cab4*/
}
