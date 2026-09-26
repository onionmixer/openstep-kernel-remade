/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18fee4. */
void __cdecl pmap_protect(int a1, char *a2, unsigned int a3, int a4)
{
  vm_size_t v4; // ebx
  unsigned int v5; // esi
  char *v6; // edx
  unsigned __int32 v7; // eax
  int v8; // eax
  vm_size_t v9; // ebx
  int v10; // edi
  volatile __int32 *v11; // edx
  char *v12; // edx
  unsigned __int32 v13; // eax
  int v14; // eax
  _DWORD *v15; // eax
  unsigned int v16; // ecx
  _DWORD *v17; // eax
  int v18; // ebx
  char v19; // si
  char v20; // dl
  int v21; // eax
  int v22; // [esp+Ch] [ebp-Ch]
  unsigned int v23; // [esp+Ch] [ebp-Ch]
  int v24; // [esp+10h] [ebp-8h]
  vm_size_t v25; // [esp+14h] [ebp-4h]

  v4 = (vm_size_t)a2; /*0x18feed*/
  if ( a1 ) /*0x18fef4*/
  {
    if ( a4 ) /*0x18fefe*/
    {
      v24 = splvm(); /*0x18ffb1*/
      v11 = (volatile __int32 *)(a1 + 12); /*0x18ffb7*/
      do /*0x18ffce*/
      {
        while ( *v11 ) /*0x18ffbc*/
          ; /*0x18ffbe*/
      }
      while ( _InterlockedExchange(v11, 1) == 1 ); /*0x18ffce*/
      v12 = a2; /*0x18ffd0*/
      if ( a1 == kernel_pmap || *(_DWORD *)(a1 + 24) ) /*0x18ffe0*/
      {
        ++tlb_stat; /*0x18ffea*/
        if ( page_size >= a3 - (unsigned int)a2 ) /*0x18fffb*/
        {
          if ( a3 > (unsigned int)a2 ) /*0x19000b*/
          {
            v14 = kernel_pmap; /*0x19000d*/
            do /*0x190029*/
            {
              if ( a1 == v14 ) /*0x190013*/
                __invlpg(v12); /*0x190015*/
              else
                __invlpg(MK_FP(__FS__, v12)); /*0x19001c*/
              v12 += 4096; /*0x190020*/
            }
            while ( a3 > (unsigned int)v12 ); /*0x190029*/
          }
          ++dword_1F7AF4; /*0x19002b*/
        }
        else
        {
          v13 = __readcr3(); /*0x18fffd*/
          __writecr3(v13); /*0x190000*/
        }
      }
      while ( a3 > v4 ) /*0x190167*/
      {
        v25 = -section_size & (section_size + page_size + v4 - 1); /*0x19004d*/
        if ( v25 > a3 ) /*0x190055*/
          v25 = a3; /*0x190057*/
        v15 = (_DWORD *)(*(_DWORD *)a1 + 4 * (v4 >> 22)); /*0x190064*/
        if ( (*(_BYTE *)v15 & 1) != 0 ) /*0x19006a*/
        {
          v16 = ((v4 >> 10) & 0xFFC) + (*v15 & 0xFFFFF000); /*0x190082*/
          if ( v16 ) /*0x190087*/
          {
            v17 = (_DWORD *)(*(_DWORD *)a1 + 4 * (v25 >> 22)); /*0x190093*/
            if ( (*(_BYTE *)v17 & 1) != 0 ) /*0x190099*/
              v23 = ((v25 >> 10) & 0xFFC) + (*v17 & 0xFFFFF000); /*0x1900b9*/
            else
              v23 = 0; /*0x19009b*/
            if ( (~page_mask & v16) != (~page_mask & v23) ) /*0x1900d1*/
              v23 = ~page_mask & (page_mask + v16 + 4 * ptes_per_vm_page); /*0x1900ea*/
            while ( v23 > v16 ) /*0x19015f*/
            {
              if ( (*(_BYTE *)v16 & 1) != 0 ) /*0x1900f3*/
              {
                v18 = ptes_per_vm_page; /*0x190108*/
                while ( 1 ) /*0x190155*/
                {
                  v21 = v18--; /*0x190155*/
                  if ( v21 <= 0 ) /*0x19015a*/
                    break; /*0x19015a*/
                  v19 = *(_BYTE *)v16 & 1; /*0x190117*/
                  if ( kernel_pmap == a1 ) /*0x190122*/
                    v20 = kernel_prot_codes[a4]; /*0x190127*/
                  else
                    v20 = user_prot_codes[4 * a4]; /*0x190133*/
                  *(_BYTE *)v16 = (2 * (v20 & 3)) | *(_BYTE *)v16 & 0xF9; /*0x190143*/
                  *(_BYTE *)v16 = v19 & 1 | *(_BYTE *)v16 & 0xFE; /*0x190150*/
                  v16 += 4; /*0x190152*/
                }
              }
              else
              {
                v16 += 4 * ptes_per_vm_page; /*0x190102*/
              }
            }
          }
        }
        v4 = v25; /*0x190161*/
      }
      _InterlockedExchange((volatile __int32 *)(a1 + 12), 0); /*0x190172*/
      v10 = v24; /*0x190175*/
    }
    else
    {
      v5 = (unsigned int)a2; /*0x18ff04*/
      v22 = splvm(); /*0x18ff0b*/
      v6 = a2; /*0x18ff0e*/
      if ( a1 == kernel_pmap || *(_DWORD *)(a1 + 24) ) /*0x18ff1e*/
      {
        ++tlb_stat; /*0x18ff24*/
        if ( page_size >= a3 - (unsigned int)a2 ) /*0x18ff35*/
        {
          if ( a3 > (unsigned int)a2 ) /*0x18ff43*/
          {
            v8 = kernel_pmap; /*0x18ff45*/
            do /*0x18ff61*/
            {
              if ( a1 == v8 ) /*0x18ff4b*/
                __invlpg(v6); /*0x18ff4d*/
              else
                __invlpg(MK_FP(__FS__, v6)); /*0x18ff54*/
              v6 += 4096; /*0x18ff58*/
            }
            while ( a3 > (unsigned int)v6 ); /*0x18ff61*/
          }
          ++dword_1F7AF4; /*0x18ff63*/
        }
        else
        {
          v7 = __readcr3(); /*0x18ff37*/
          __writecr3(v7); /*0x18ff3a*/
        }
      }
      while ( a3 > v5 ) /*0x18ffa0*/
      {
        v9 = -section_size & (section_size + page_size + v5 - 1); /*0x18ff81*/
        if ( a3 < v9 ) /*0x18ff86*/
          v9 = a3; /*0x18ff88*/
        sub_18F7F8((_DWORD *)a1, v5, v9, 1); /*0x18ff93*/
        v5 = v9; /*0x18ff98*/
      }
      v10 = v22; /*0x18ffa2*/
    }
    splx(v10); /*0x190179*/
  }
}
