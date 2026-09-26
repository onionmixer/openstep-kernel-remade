/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18fb0c. */
void __cdecl pmap_remove_all(unsigned int a1)
{
  volatile __int32 *v1; // edx
  _BYTE *v2; // eax
  _BYTE *v3; // esi
  char *v4; // edx
  int v5; // eax
  _DWORD *v6; // eax
  int v7; // ebx
  int v8; // eax
  int v9; // eax
  unsigned int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  unsigned int v13; // [esp+1Ch] [ebp-Ch]
  unsigned int v14; // [esp+24h] [ebp-4h]

  if ( vm_first_phys <= a1 && vm_last_phys > a1 ) /*0x18fb2a*/
  {
    v11 = splvm(); /*0x18fb35*/
    v14 = pg_desc_tbl + 20 * ((a1 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x18fb5b*/
    for ( i = *(_DWORD *)(v14 + 4); i; i = *(_DWORD *)(v14 + 4) ) /*0x18fb69*/
    {
      v13 = *(_DWORD *)(v14 + 8); /*0x18fb76*/
      v1 = (volatile __int32 *)(i + 12); /*0x18fb7c*/
      do /*0x18fb92*/
      {
        while ( *v1 ) /*0x18fb80*/
          ; /*0x18fb82*/
      }
      while ( _InterlockedExchange(v1, 1) == 1 ); /*0x18fb92*/
      v2 = (_BYTE *)(*(_DWORD *)i + 4 * (v13 >> 22)); /*0x18fba0*/
      if ( (*v2 & 1) == 0 /*0x18fbc9*/
        || (v3 = (_BYTE *)(((v13 >> 10) & 0xFFC) + (*(_DWORD *)v2 & 0xFFFFF000))) == nullptr
        || (*v3 & 1) == 0 )
      {
        panic(aPmapRemoveAll); /*0x18fbd0*/
      }
      if ( a1 != (*(_DWORD *)v3 & 0xFFFFF000) ) /*0x18fbe2*/
        panic(aPmapRemoveAll2); /*0x18fbe9*/
      if ( (*(_BYTE *)(((v13 >> 10) & 0xFFC) + (*(_DWORD *)v2 & 0xFFFFF000) + 1) & 2) != 0 ) /*0x18fbf5*/
        panic(aPmapRemoveAll3); /*0x18fbfc*/
      v4 = (char *)v13; /*0x18fc04*/
      v10 = page_size + v13; /*0x18fc11*/
      if ( i == kernel_pmap || *(_DWORD *)(i + 24) ) /*0x18fc25*/
      {
        ++tlb_stat; /*0x18fc2b*/
        if ( v13 < v10 ) /*0x18fc4a*/
        {
          v5 = kernel_pmap; /*0x18fc4c*/
          do /*0x18fc69*/
          {
            if ( i == v5 ) /*0x18fc53*/
              __invlpg(v4); /*0x18fc55*/
            else
              __invlpg(MK_FP(__FS__, v4)); /*0x18fc5c*/
            v4 += 4096; /*0x18fc60*/
          }
          while ( v10 > (unsigned int)v4 ); /*0x18fc69*/
        }
        ++dword_1F7AF4; /*0x18fc6b*/
      }
      v6 = *(_DWORD **)v14; /*0x18fc74*/
      if ( *(_DWORD *)v14 ) /*0x18fc74*/
      {
        *(_DWORD *)v14 = *v6; /*0x18fc7c*/
        *(_DWORD *)(v14 + 4) = v6[1]; /*0x18fc81*/
        *(_DWORD *)(v14 + 8) = v6[2]; /*0x18fc87*/
        zfree(pv_entry_zone, v6); /*0x18fc92*/
      }
      else
      {
        *(_DWORD *)(v14 + 4) = 0; /*0x18fc9f*/
      }
      v7 = ptes_per_vm_page; /*0x18fca6*/
      while ( 1 ) /*0x18fce1*/
      {
        v9 = v7--; /*0x18fce1*/
        if ( v9 <= 0 ) /*0x18fce6*/
          break; /*0x18fce6*/
        if ( (*v3 & 0x40) != 0 ) /*0x18fcb3*/
        {
          v8 = vm_phys_to_vm_page(a1); /*0x18fcb9*/
          *(_BYTE *)(v8 + 30) &= ~0x20u; /*0x18fcbe*/
          *(_BYTE *)(v14 + 16) |= 1u; /*0x18fcc5*/
        }
        if ( (*v3 & 0x20) != 0 ) /*0x18fccf*/
          *(_BYTE *)(v14 + 16) |= 2u; /*0x18fcd4*/
        *(_DWORD *)v3 = 0; /*0x18fcd8*/
        v3 += 4; /*0x18fcde*/
      }
      sub_190F90(i, v13, 1, 0, 1); /*0x18fcf6*/
      _InterlockedExchange((volatile __int32 *)(i + 12), 0); /*0x18fd03*/
    }
    splx(v11); /*0x18fd1b*/
  }
}
