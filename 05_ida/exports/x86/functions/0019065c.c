/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19065c. */
void __cdecl pmap_enter(_DWORD *a1, unsigned int a2, unsigned int a3, int a4, int a5)
{
  char *v5; // edx
  unsigned __int32 v6; // eax
  int v7; // eax
  vm_size_t v8; // ebx
  _DWORD *v9; // eax
  _BYTE *v10; // ebx
  char v11; // dl
  char *v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  char *v17; // edx
  unsigned int v18; // ecx
  int v19; // eax
  _DWORD *v20; // eax
  char v21; // dl
  int v22; // ecx
  int v23; // eax
  unsigned int v24; // [esp+Ch] [ebp-18h]
  unsigned int v25; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h]
  _DWORD *v27; // [esp+18h] [ebp-Ch]
  int v28; // [esp+1Ch] [ebp-8h]
  __int16 v29; // [esp+20h] [ebp-4h]
  unsigned int v30; // [esp+20h] [ebp-4h]
  unsigned int v31; // [esp+20h] [ebp-4h]

  if ( a1 ) /*0x190669*/
  {
    if ( a4 ) /*0x190673*/
    {
      v27 = nullptr; /*0x190748*/
      HIBYTE(v29) = 0; /*0x190759*/
      while ( 1 ) /*0x190761*/
      {
        for ( i = splvm(); ; i = splvm() ) /*0x190761*/
        {
          v9 = (_DWORD *)(*a1 + 4 * (a2 >> 22)); /*0x190786*/
          if ( (*(_BYTE *)v9 & 1) != 0 ) /*0x19078b*/
          {
            v10 = (_BYTE *)((*v9 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC)); /*0x190797*/
            if ( v10 ) /*0x190799*/
              break; /*0x190799*/
          }
          splx(i); /*0x19079f*/
          sub_190CFC(a1, a2); /*0x1907ac*/
        }
        if ( (*v10 & 1) != 0 ) /*0x1907ca*/
        {
          if ( a3 == (*(_DWORD *)v10 & 0xFFFFF000) ) /*0x1907d3*/
          {
            if ( a5 ) /*0x1907dd*/
            {
              if ( (*(_BYTE *)((*v9 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC) + 1) & 2) == 0 ) /*0x1907e3*/
                sub_19108C(a1, a2); /*0x1907ed*/
            }
            else if ( (*(_BYTE *)((*v9 & 0xFFFFF000) + ((a2 >> 10) & 0xFFC) + 1) & 2) != 0 ) /*0x1907f8*/
            {
              sub_1910E4(a1, a2); /*0x190802*/
            }
            if ( (_DWORD *)kernel_pmap == a1 ) /*0x190813*/
              v11 = kernel_prot_codes[a4]; /*0x190818*/
            else
              v11 = user_prot_codes[4 * a4]; /*0x190827*/
            LOBYTE(v29) = (2 * (v11 & 3)) | 1; /*0x19083d*/
            v30 = a3 & 0xFFFFF000 | v29 & 0xFFF; /*0x190854*/
            if ( a5 ) /*0x19085b*/
              BYTE1(v30) |= 2u; /*0x19085d*/
            v12 = (char *)a2; /*0x190861*/
            v13 = page_size + a2; /*0x19086f*/
            if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x190882*/
            {
              ++tlb_stat; /*0x190888*/
              if ( a2 < v13 ) /*0x1908a3*/
              {
                v14 = kernel_pmap; /*0x1908a5*/
                do /*0x1908c0*/
                {
                  if ( a1 == (_DWORD *)v14 ) /*0x1908ab*/
                    __invlpg(v12); /*0x1908ad*/
                  else
                    __invlpg(MK_FP(__FS__, v12)); /*0x1908b4*/
                  v12 += 4096; /*0x1908b8*/
                }
                while ( (unsigned int)v12 < v13 ); /*0x1908c0*/
              }
              ++dword_1F7AF4; /*0x1908c2*/
            }
            v15 = ptes_per_vm_page - 1; /*0x1908d0*/
            if ( ptes_per_vm_page > 0 ) /*0x1908d3*/
            {
              do /*0x19090d*/
              {
                if ( (*v10 & 0x40) != 0 ) /*0x1908df*/
                  LOBYTE(v30) = v30 | 0x40; /*0x1908e1*/
                *(_DWORD *)v10 = v30; /*0x1908e8*/
                v30 = ((v30 & 0xFFFFF000) + 4096) | v30 & 0xFFF; /*0x190902*/
                v10 += 4; /*0x190905*/
                v16 = v15--; /*0x190908*/
              }
              while ( v16 > 0 ); /*0x19090d*/
            }
            goto LABEL_75; /*0x19090d*/
          }
          v17 = (char *)a2; /*0x190914*/
          v18 = page_size + a2; /*0x190922*/
          if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x190935*/
          {
            ++tlb_stat; /*0x19093b*/
            if ( a2 < v18 ) /*0x190957*/
            {
              v19 = kernel_pmap; /*0x190959*/
              do /*0x190974*/
              {
                if ( a1 == (_DWORD *)v19 ) /*0x19095f*/
                  __invlpg(v17); /*0x190961*/
                else
                  __invlpg(MK_FP(__FS__, v17)); /*0x190968*/
                v17 += 4096; /*0x19096c*/
              }
              while ( (unsigned int)v17 < v18 ); /*0x190974*/
            }
            ++dword_1F7AF4; /*0x190976*/
          }
          sub_18F7F8(a1, a2, page_size + a2, 0); /*0x190990*/
        }
        if ( vm_first_phys > a3 || vm_last_phys <= a3 ) /*0x1909ad*/
          break; /*0x1909ad*/
        v20 = (_DWORD *)(pg_desc_tbl + 20 * ((a3 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1))); /*0x1909d0*/
        if ( !v20[1] ) /*0x1909d5*/
        {
          v20[2] = a2; /*0x1909de*/
          v20[1] = a1; /*0x1909e4*/
          *v20 = 0; /*0x1909e7*/
          break; /*0x1909ed*/
        }
        if ( v27 ) /*0x1909f4*/
        {
          v27[2] = a2; /*0x190a1e*/
          v27[1] = a1; /*0x190a24*/
          *v27 = *v20; /*0x190a29*/
          *v20 = v27; /*0x190a2b*/
          v27 = nullptr; /*0x190a2d*/
          break; /*0x190a2d*/
        }
        splx(i); /*0x1909fa*/
        v27 = (_DWORD *)zalloc(pv_entry_zone); /*0x190a0b*/
      }
      sub_190F24(a1, a2, a5); /*0x190a34*/
      if ( (_DWORD *)kernel_pmap == a1 ) /*0x190a4e*/
        v21 = kernel_prot_codes[a4]; /*0x190a53*/
      else
        v21 = user_prot_codes[4 * a4]; /*0x190a5f*/
      LOBYTE(v29) = (2 * (v21 & 3)) | 1; /*0x190a75*/
      v31 = a3 & 0xFFFFF000 | v29 & 0xFFF; /*0x190a8c*/
      if ( a5 ) /*0x190a93*/
        BYTE1(v31) |= 2u; /*0x190a95*/
      v22 = ptes_per_vm_page; /*0x190a99*/
      while ( 1 ) /*0x190ac7*/
      {
        v23 = v22--; /*0x190ac7*/
        if ( v23 <= 0 ) /*0x190acc*/
          break; /*0x190acc*/
        *(_DWORD *)v10 = v31; /*0x190aa7*/
        v31 = ((v31 & 0xFFFFF000) + 4096) | v31 & 0xFFF; /*0x190ac1*/
        v10 += 4; /*0x190ac4*/
      }
LABEL_75:
      splx(i); /*0x190ace*/
      if ( v27 ) /*0x190ade*/
        zfree(pv_entry_zone, v27); /*0x190aeb*/
    }
    else
    {
      v25 = a2; /*0x19067c*/
      v24 = page_size + a2; /*0x190685*/
      v28 = splvm(); /*0x19068d*/
      v5 = (char *)a2; /*0x190690*/
      if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x1906a1*/
      {
        ++tlb_stat; /*0x1906a7*/
        if ( page_size >= v24 - a2 ) /*0x1906b9*/
        {
          if ( a2 < v24 ) /*0x1906ca*/
          {
            v7 = kernel_pmap; /*0x1906cc*/
            do /*0x1906e9*/
            {
              if ( a1 == (_DWORD *)v7 ) /*0x1906d3*/
                __invlpg(v5); /*0x1906d5*/
              else
                __invlpg(MK_FP(__FS__, v5)); /*0x1906dc*/
              v5 += 4096; /*0x1906e0*/
            }
            while ( v24 > (unsigned int)v5 ); /*0x1906e9*/
          }
          ++dword_1F7AF4; /*0x1906eb*/
        }
        else
        {
          v6 = __readcr3(); /*0x1906bb*/
          __writecr3(v6); /*0x1906be*/
        }
      }
      if ( a2 < v24 ) /*0x1906f7*/
      {
        do /*0x190737*/
        {
          v8 = -section_size & (section_size + page_size + v25 - 1); /*0x190712*/
          if ( v24 < v8 ) /*0x190717*/
            v8 = v24; /*0x190719*/
          sub_18F7F8(a1, v25, v8, 1); /*0x190727*/
          v25 = v8; /*0x19072c*/
        }
        while ( v8 < v24 ); /*0x190737*/
      }
      splx(v28); /*0x19073d*/
    }
  }
}
