/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190f90. */
void __cdecl sub_190F90(_DWORD *a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  _DWORD *v5; // esi
  int v6; // ebx
  __int16 v7; // ax
  int v8; // edx
  int v9; // eax

  a1[5] -= a4; /*0x190f9c*/
  a1[4] -= a3; /*0x190fa2*/
  if ( (_DWORD *)kernel_pmap != a1 ) /*0x190fab*/
  {
    v5 = (_DWORD *)(4 * ((a2 & (unsigned int)-section_size) >> 22) + *a1); /*0x190fc3*/
    if ( (*(_BYTE *)v5 & 1) != 0 ) /*0x190fc8*/
    {
      v6 = *(_DWORD *)(pg_desc_tbl + 20 * (((*v5 & 0xFFFFF000) - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)) + 12); /*0x190ff0*/
      if ( *(unsigned __int16 *)(v6 + 26) < a4 ) /*0x190ffa*/
        panic(aPmapDeallocate); /*0x191001*/
      *(_WORD *)(v6 + 26) -= a4; /*0x191009*/
      if ( a3 > *(unsigned __int16 *)(v6 + 24) ) /*0x191014*/
        panic(aPmapDeallocate_0); /*0x19101b*/
      v7 = *(_WORD *)(v6 + 24) - a3; /*0x191024*/
      *(_WORD *)(v6 + 24) = v7; /*0x191028*/
      if ( a5 && !v7 ) /*0x191035*/
      {
        v8 = ptes_per_vm_page; /*0x191037*/
        while ( 1 ) /*0x191046*/
        {
          v9 = v8--; /*0x191046*/
          if ( v9 <= 0 ) /*0x19104b*/
            break; /*0x19104b*/
          *(_BYTE *)v5++ &= ~1u; /*0x191040*/
        }
        *(_DWORD *)(*(_DWORD *)v6 + 4) = *(_DWORD *)(v6 + 4); /*0x191052*/
        **(_DWORD **)(v6 + 4) = *(_DWORD *)v6; /*0x19105a*/
        --pt_active_count; /*0x19105c*/
        *(_DWORD *)v6 = &pt_free_queue; /*0x191062*/
        *(_DWORD *)(v6 + 4) = dword_1F7ADC; /*0x19106e*/
        **(_DWORD **)(v6 + 4) = v6; /*0x191074*/
        dword_1F7ADC = v6; /*0x191076*/
        ++pt_free_count; /*0x19107c*/
      }
    }
  }
}
