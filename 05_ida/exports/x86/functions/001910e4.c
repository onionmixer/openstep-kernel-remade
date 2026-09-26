/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1910e4. */
void __cdecl sub_1910E4(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  int v3; // eax

  --a1[5]; /*0x1910ea*/
  if ( (_DWORD *)kernel_pmap != a1 ) /*0x1910f3*/
  {
    v2 = (_DWORD *)(*a1 + 4 * ((a2 & (unsigned int)-section_size) >> 22)); /*0x191105*/
    if ( (*(_BYTE *)v2 & 1) != 0 ) /*0x19110a*/
    {
      v3 = *(_DWORD *)(pg_desc_tbl + 20 * (((*v2 & 0xFFFFF000) - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)) + 12); /*0x19112e*/
      --*(_WORD *)(v3 + 26); /*0x191132*/
    }
  }
}
