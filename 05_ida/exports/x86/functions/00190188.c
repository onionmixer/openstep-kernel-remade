/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x190188. */
void __cdecl pmap_enter_cache_spec(_DWORD *a1, unsigned int a2, unsigned int a3, int a4, int a5, int a6)
{
  char *v6; // edx
  unsigned __int32 v7; // eax
  int v8; // eax
  vm_size_t v9; // ebx
  _DWORD *v10; // eax
  _BYTE *v11; // ebx
  char v12; // dl
  char *v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  char *v18; // edx
  unsigned int v19; // ecx
  int v20; // eax
  _DWORD *v21; // eax
  char v22; // dl
  int v23; // ecx
  int v24; // eax
  unsigned int v25; // [esp+Ch] [ebp-18h]
  unsigned int v26; // [esp+10h] [ebp-14h]
  int v27; // [esp+14h] [ebp-10h]
  _DWORD *v28; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  __int16 v30; // [esp+20h] [ebp-4h]
  unsigned int v31; // [esp+20h] [ebp-4h]
  unsigned int v32; // [esp+20h] [ebp-4h]

  if ( a1 ) /*0x190195*/
  {
    if ( a4 ) /*0x19019f*/
    {
      v28 = nullptr; /*0x190274*/
      HIBYTE(v30) = 0; /*0x190285*/
      while ( 1 ) /*0x19028d*/
      {
        for ( i = splvm(); ; i = splvm() ) /*0x19028d*/
        {
          v10 = (_DWORD *)(*a1 + 4 * (a2 >> 22)); /*0x1902b2*/
          if ( (*(_BYTE *)v10 & 1) != 0 ) /*0x1902b7*/
          {
            v11 = (_BYTE *)((*v10 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC)); /*0x1902c3*/
            if ( v11 ) /*0x1902c5*/
              break; /*0x1902c5*/
          }
          splx(i); /*0x1902cb*/
          sub_190CFC(a1, a2); /*0x1902d8*/
        }
        if ( (*v11 & 1) != 0 ) /*0x1902f6*/
        {
          if ( a3 == (*(_DWORD *)v11 & 0xFFFFF000) ) /*0x1902ff*/
          {
            if ( a5 ) /*0x190309*/
            {
              if ( (*(_BYTE *)((*v10 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC) + 1) & 2) == 0 ) /*0x19030f*/
                sub_19108C(a1, a2); /*0x190319*/
            }
            else if ( (*(_BYTE *)((*v10 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC) + 1) & 2) != 0 ) /*0x190324*/
            {
              sub_1910E4(a1, a2); /*0x19032e*/
            }
            if ( (_DWORD *)kernel_pmap == a1 ) /*0x19033f*/
              v12 = kernel_prot_codes[a4]; /*0x190344*/
            else
              v12 = user_prot_codes[4 * a4]; /*0x190353*/
            LOBYTE(v30) = (2 * (v12 & 3)) | 1; /*0x190369*/
            v31 = a3 & 0xFFFFF000 | v30 & 0xFFF; /*0x190380*/
            if ( a5 ) /*0x190387*/
              BYTE1(v31) |= 2u; /*0x190389*/
            if ( a6 == 2 ) /*0x190391*/
            {
              LOBYTE(v31) = v31 | 0x10; /*0x190393*/
            }
            else if ( a6 == 1 ) /*0x1903a0*/
            {
              LOBYTE(v31) = v31 | 8; /*0x1903a2*/
            }
            v13 = (char *)a2; /*0x1903a6*/
            v14 = page_size + a2; /*0x1903b4*/
            if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x1903c7*/
            {
              ++tlb_stat; /*0x1903cd*/
              if ( a2 < v14 ) /*0x1903eb*/
              {
                v15 = kernel_pmap; /*0x1903ed*/
                do /*0x190408*/
                {
                  if ( a1 == (_DWORD *)v15 ) /*0x1903f3*/
                    __invlpg(v13); /*0x1903f5*/
                  else
                    __invlpg(MK_FP(__FS__, v13)); /*0x1903fc*/
                  v13 += 4096; /*0x190400*/
                }
                while ( (unsigned int)v13 < v14 ); /*0x190408*/
              }
              ++dword_1F7AF4; /*0x19040a*/
            }
            v16 = ptes_per_vm_page - 1; /*0x190418*/
            if ( ptes_per_vm_page > 0 ) /*0x19041b*/
            {
              do /*0x190455*/
              {
                if ( (*v11 & 0x40) != 0 ) /*0x190427*/
                  LOBYTE(v31) = v31 | 0x40; /*0x190429*/
                *(_DWORD *)v11 = v31; /*0x190430*/
                v31 = ((v31 & 0xFFFFF000) + 4096) | v31 & 0xFFF; /*0x19044a*/
                v11 += 4; /*0x19044d*/
                v17 = v16--; /*0x190450*/
              }
              while ( v17 > 0 ); /*0x190455*/
            }
            goto LABEL_83; /*0x190455*/
          }
          v18 = (char *)a2; /*0x19045c*/
          v19 = page_size + a2; /*0x19046a*/
          if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x19047d*/
          {
            ++tlb_stat; /*0x190483*/
            if ( a2 < v19 ) /*0x19049f*/
            {
              v20 = kernel_pmap; /*0x1904a1*/
              do /*0x1904bc*/
              {
                if ( a1 == (_DWORD *)v20 ) /*0x1904a7*/
                  __invlpg(v18); /*0x1904a9*/
                else
                  __invlpg(MK_FP(__FS__, v18)); /*0x1904b0*/
                v18 += 4096; /*0x1904b4*/
              }
              while ( (unsigned int)v18 < v19 ); /*0x1904bc*/
            }
            ++dword_1F7AF4; /*0x1904be*/
          }
          sub_18F7F8(a1, a2, page_size + a2, 0); /*0x1904d8*/
        }
        if ( vm_first_phys > a3 || vm_last_phys <= a3 ) /*0x1904f5*/
          break; /*0x1904f5*/
        v21 = (_DWORD *)(pg_desc_tbl + 20 * ((a3 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1))); /*0x190518*/
        if ( !v21[1] ) /*0x19051d*/
        {
          v21[2] = a2; /*0x190526*/
          v21[1] = a1; /*0x19052c*/
          *v21 = 0; /*0x19052f*/
          break; /*0x190535*/
        }
        if ( v28 ) /*0x19053c*/
        {
          v28[2] = a2; /*0x190566*/
          v28[1] = a1; /*0x19056c*/
          *v28 = *v21; /*0x190571*/
          *v21 = v28; /*0x190573*/
          v28 = nullptr; /*0x190575*/
          break; /*0x190575*/
        }
        splx(i); /*0x190542*/
        v28 = (_DWORD *)zalloc(pv_entry_zone); /*0x190553*/
      }
      sub_190F24(a1, a2, a5); /*0x19057c*/
      if ( (_DWORD *)kernel_pmap == a1 ) /*0x190596*/
        v22 = kernel_prot_codes[a4]; /*0x19059b*/
      else
        v22 = user_prot_codes[4 * a4]; /*0x1905a7*/
      LOBYTE(v30) = (2 * (v22 & 3)) | 1; /*0x1905bd*/
      v32 = a3 & 0xFFFFF000 | v30 & 0xFFF; /*0x1905d4*/
      if ( a5 ) /*0x1905db*/
        BYTE1(v32) |= 2u; /*0x1905dd*/
      if ( a6 == 2 ) /*0x1905e5*/
      {
        LOBYTE(v32) = v32 | 0x10; /*0x1905e7*/
      }
      else if ( a6 == 1 ) /*0x1905f4*/
      {
        LOBYTE(v32) = v32 | 8; /*0x1905f6*/
      }
      v23 = ptes_per_vm_page; /*0x1905fa*/
      while ( 1 ) /*0x190627*/
      {
        v24 = v23--; /*0x190627*/
        if ( v24 <= 0 ) /*0x19062c*/
          break; /*0x19062c*/
        *(_DWORD *)v11 = v32; /*0x190607*/
        v32 = ((v32 & 0xFFFFF000) + 4096) | v32 & 0xFFF; /*0x190621*/
        v11 += 4; /*0x190624*/
      }
LABEL_83:
      splx(i); /*0x19062e*/
      if ( v28 ) /*0x19063e*/
        zfree(pv_entry_zone, v28); /*0x19064b*/
    }
    else
    {
      v26 = a2; /*0x1901a8*/
      v25 = page_size + a2; /*0x1901b1*/
      v27 = splvm(); /*0x1901b9*/
      v6 = (char *)a2; /*0x1901bc*/
      if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x1901cd*/
      {
        ++tlb_stat; /*0x1901d3*/
        if ( page_size >= v25 - a2 ) /*0x1901e5*/
        {
          if ( a2 < v25 ) /*0x1901f6*/
          {
            v8 = kernel_pmap; /*0x1901f8*/
            do /*0x190215*/
            {
              if ( a1 == (_DWORD *)v8 ) /*0x1901ff*/
                __invlpg(v6); /*0x190201*/
              else
                __invlpg(MK_FP(__FS__, v6)); /*0x190208*/
              v6 += 4096; /*0x19020c*/
            }
            while ( v25 > (unsigned int)v6 ); /*0x190215*/
          }
          ++dword_1F7AF4; /*0x190217*/
        }
        else
        {
          v7 = __readcr3(); /*0x1901e7*/
          __writecr3(v7); /*0x1901ea*/
        }
      }
      if ( a2 < v25 ) /*0x190223*/
      {
        do /*0x190263*/
        {
          v9 = -section_size & (section_size + page_size + v26 - 1); /*0x19023e*/
          if ( v25 < v9 ) /*0x190243*/
            v9 = v25; /*0x190245*/
          sub_18F7F8(a1, v26, v9, 1); /*0x190253*/
          v26 = v9; /*0x190258*/
        }
        while ( v9 < v25 ); /*0x190263*/
      }
      splx(v27); /*0x190269*/
    }
  }
}
