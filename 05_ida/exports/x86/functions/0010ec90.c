/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ec90. */
int __cdecl ttnread(int a1)
{
  FILE *v1; // ebx
  int v2; // edx

  v1 = *(FILE **)a1; /*0x10ec98*/
  if ( (*(_BYTE *)(*(_DWORD *)a1 + 63) & 0x20) != 0 ) /*0x10ec9e*/
    ttypend(*(FILE **)a1); /*0x10eca1*/
  v2 = *(_DWORD *)&v1->_flags; /*0x10eca6*/
  if ( (v1->_ur & 0x22) != 0 ) /*0x10ecad*/
  {
    v2 += (int)v1->_p; /*0x10ecaf*/
    if ( v2 < *(unsigned __int8 *)(a1 + 21) ) /*0x10ecb7*/
      return 0; /*0x10ecb9*/
  }
  return v2; /*0x10ecc0*/
}
