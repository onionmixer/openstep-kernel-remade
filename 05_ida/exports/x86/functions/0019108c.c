/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19108c. */
void __cdecl sub_19108C(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  int v3; // eax

  ++a1[5]; /*0x191092*/
  if ( (_DWORD *)kernel_pmap != a1 ) /*0x19109b*/
  {
    v2 = (_DWORD *)(*a1 + 4 * ((a2 & (unsigned int)-section_size) >> 22)); /*0x1910ad*/
    if ( (*(_BYTE *)v2 & 1) != 0 ) /*0x1910b2*/
    {
      v3 = *(_DWORD *)(pg_desc_tbl + 20 * (((*v2 & 0xFFFFF000) - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)) + 12); /*0x1910d6*/
      ++*(_WORD *)(v3 + 26); /*0x1910da*/
    }
  }
}
