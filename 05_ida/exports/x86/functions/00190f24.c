/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190f24. */
void __cdecl sub_190F24(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // eax
  int v4; // eax

  ++a1[4]; /*0x190f2e*/
  if ( a3 ) /*0x190f33*/
    ++a1[5]; /*0x190f35*/
  if ( (_DWORD *)kernel_pmap != a1 ) /*0x190f3e*/
  {
    v3 = (_DWORD *)(*a1 + 4 * ((a2 & (unsigned int)-section_size) >> 22)); /*0x190f50*/
    if ( (*(_BYTE *)v3 & 1) != 0 ) /*0x190f55*/
    {
      v4 = *(_DWORD *)(pg_desc_tbl + 20 * (((*v3 & 0xFFFFF000) - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)) + 12); /*0x190f79*/
      ++*(_WORD *)(v4 + 24); /*0x190f7d*/
      if ( a3 ) /*0x190f83*/
        ++*(_WORD *)(v4 + 26); /*0x190f85*/
    }
  }
}
