/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f7f8. */
_DWORD *__cdecl sub_18F7F8(_DWORD *a1, unsigned int a2, unsigned int a3, int a4)
{
  _DWORD *result; // eax
  unsigned int v5; // edx
  unsigned int v6; // edi
  _DWORD *v7; // eax
  unsigned int v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // esi
  unsigned int v12; // ebx
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // esi
  _DWORD *v16; // ebx
  int v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+14h] [ebp-10h]
  unsigned int v19; // [esp+18h] [ebp-Ch]
  unsigned int v20; // [esp+1Ch] [ebp-8h]
  unsigned int v21; // [esp+20h] [ebp-4h]

  v19 = a2; /*0x18f807*/
  v18 = 0; /*0x18f80a*/
  v17 = 0; /*0x18f811*/
  result = (_DWORD *)(*a1 + 4 * (a2 >> 22)); /*0x18f823*/
  if ( (*(_BYTE *)result & 1) != 0 ) /*0x18f829*/
  {
    v5 = *result & 0xFFFFF000; /*0x18f831*/
    result = (_DWORD *)((a2 >> 10) & 0xFFC); /*0x18f83d*/
    v6 = (unsigned int)result + v5; /*0x18f842*/
    if ( (char *)result + v5 ) /*0x18f842*/
    {
      v7 = (_DWORD *)(*a1 + 4 * (a3 >> 22)); /*0x18f852*/
      if ( (*(_BYTE *)v7 & 1) != 0 ) /*0x18f858*/
        v21 = ((a3 >> 10) & 0xFFC) + (*v7 & 0xFFFFF000); /*0x18f878*/
      else
        v21 = 0; /*0x18f85a*/
      if ( (~page_mask & v6) != (~page_mask & v21) ) /*0x18f890*/
        v21 = ~page_mask & (page_mask + v6 + 4 * ptes_per_vm_page); /*0x18f8a9*/
      while ( 1 ) /*0x18fa16*/
      {
        if ( v21 <= v6 ) /*0x18fa19*/
          return (_DWORD *)sub_190F90(a1, a2, v18, v17, a4); /*0x18fa33*/
        if ( (*(_BYTE *)v6 & 1) == 0 ) /*0x18f8b7*/
        {
          v6 += 4 * ptes_per_vm_page; /*0x18f8c6*/
          goto LABEL_38; /*0x18f8c8*/
        }
        ++v18; /*0x18f8d0*/
        if ( (*(_BYTE *)(v6 + 1) & 2) != 0 ) /*0x18f8d7*/
          ++v17; /*0x18f8d9*/
        v8 = *(_DWORD *)v6 & 0xFFFFF000; /*0x18f8de*/
        v20 = v8; /*0x18f8e4*/
        if ( vm_first_phys <= v8 && vm_last_phys > v8 ) /*0x18f8f5*/
        {
          v11 = ptes_per_vm_page - 1; /*0x18f932*/
          v12 = pg_desc_tbl + 20 * ((v8 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x18f940*/
          if ( ptes_per_vm_page > 0 ) /*0x18f94a*/
          {
            do /*0x18f97c*/
            {
              if ( (*(_BYTE *)v6 & 0x40) != 0 ) /*0x18f94f*/
              {
                v13 = vm_phys_to_vm_page(v20); /*0x18f955*/
                *(_BYTE *)(v13 + 30) &= ~0x20u; /*0x18f95a*/
                *(_BYTE *)(v12 + 16) |= 1u; /*0x18f95e*/
              }
              if ( (*(_BYTE *)v6 & 0x20) != 0 ) /*0x18f968*/
                *(_BYTE *)(v12 + 16) |= 2u; /*0x18f96a*/
              *(_DWORD *)v6 = 0; /*0x18f96e*/
              v6 += 4; /*0x18f974*/
              v14 = v11--; /*0x18f977*/
            }
            while ( v14 > 0 ); /*0x18f97c*/
          }
          v15 = (_DWORD *)v12; /*0x18f97e*/
          if ( !*(_DWORD *)(v12 + 4) ) /*0x18f980*/
            panic(aPmapRemoveRang); /*0x18f98b*/
          if ( *(_DWORD *)(v12 + 8) == v19 && *(_DWORD **)(v12 + 4) == a1 ) /*0x18f9a1*/
          {
            v16 = *(_DWORD **)v12; /*0x18f9a3*/
            if ( !*v15 ) /*0x18f9a7*/
            {
              v15[1] = 0; /*0x18f9bc*/
              goto LABEL_38; /*0x18f9c3*/
            }
            *v15 = *v16; /*0x18f9ab*/
            v15[1] = v16[1]; /*0x18f9b0*/
            v15[2] = v16[2]; /*0x18f9b6*/
          }
          else
          {
            v16 = *(_DWORD **)v12; /*0x18f9c8*/
            if ( !*v15 ) /*0x18f9c8*/
              goto LABEL_35; /*0x18f9c8*/
            do /*0x18f9e6*/
            {
              if ( v16[2] == v19 && (_DWORD *)v16[1] == a1 ) /*0x18f9de*/
                break; /*0x18f9de*/
              v15 = v16; /*0x18f9e0*/
              v16 = (_DWORD *)*v16; /*0x18f9e2*/
            }
            while ( v16 ); /*0x18f9e6*/
            if ( !v16 ) /*0x18f9ea*/
LABEL_35:
              panic(aPmapRemoveRang_0); /*0x18f9f1*/
            *v15 = *v16; /*0x18f9fb*/
          }
          zfree(pv_entry_zone, v16); /*0x18fa05*/
        }
        else
        {
          v9 = ptes_per_vm_page - 1; /*0x18f8ff*/
          if ( ptes_per_vm_page > 0 ) /*0x18f902*/
          {
            do /*0x18f916*/
            {
              *(_DWORD *)v6 = 0; /*0x18f908*/
              v6 += 4; /*0x18f90e*/
              v10 = v9--; /*0x18f911*/
            }
            while ( v10 > 0 ); /*0x18f916*/
          }
        }
LABEL_38:
        v19 += page_size; /*0x18fa0d*/
      }
    }
  }
  return result; /*0x18fa3b*/
}
