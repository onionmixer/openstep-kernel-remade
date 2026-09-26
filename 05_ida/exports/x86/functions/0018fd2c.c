/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18fd2c. */
void __cdecl pmap_copy_on_write(unsigned int a1)
{
  unsigned int v1; // esi
  volatile __int32 *v2; // edx
  _BYTE *v3; // eax
  _BYTE *v4; // ebx
  char *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  char v8; // al
  int v9; // ecx
  char v10; // si
  char v11; // dl
  int v12; // eax
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  _DWORD *v15; // [esp+18h] [ebp-4h]

  if ( vm_first_phys <= a1 && vm_last_phys > a1 ) /*0x18fd4a*/
  {
    v14 = splvm(); /*0x18fd55*/
    v15 = (_DWORD *)(pg_desc_tbl + 20 * ((a1 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1))); /*0x18fd78*/
    if ( v15[1] && v15 ) /*0x18fd89*/
    {
      do /*0x18feca*/
      {
        v13 = v15[1]; /*0x18fd96*/
        v1 = v15[2]; /*0x18fd9c*/
        v2 = (volatile __int32 *)(v13 + 12); /*0x18fda2*/
        do /*0x18fdba*/
        {
          while ( *v2 ) /*0x18fda8*/
            ; /*0x18fdaa*/
        }
        while ( _InterlockedExchange(v2, 1) == 1 ); /*0x18fdba*/
        v3 = (_BYTE *)(*(_DWORD *)v13 + 4 * (v1 >> 22)); /*0x18fdc7*/
        if ( (*v3 & 1) == 0 /*0x18fdf0*/
          || (v4 = (_BYTE *)(((v1 >> 10) & 0xFFC) + (*(_DWORD *)v3 & 0xFFFFF000))) == nullptr
          || (*v4 & 1) == 0 )
        {
          panic(aPmapCopyOnWrit); /*0x18fdf7*/
        }
        v5 = (char *)v1; /*0x18fdff*/
        v6 = page_size + v1; /*0x18fe07*/
        if ( v13 == kernel_pmap || *(_DWORD *)(v13 + 24) ) /*0x18fe1b*/
        {
          ++tlb_stat; /*0x18fe21*/
          if ( v1 < v6 ) /*0x18fe3a*/
          {
            v7 = kernel_pmap; /*0x18fe3c*/
            do /*0x18fe58*/
            {
              if ( v13 == v7 ) /*0x18fe43*/
                __invlpg(v5); /*0x18fe45*/
              else
                __invlpg(MK_FP(__FS__, v5)); /*0x18fe4c*/
              v5 += 4096; /*0x18fe50*/
            }
            while ( (unsigned int)v5 < v6 ); /*0x18fe58*/
          }
          ++dword_1F7AF4; /*0x18fe5a*/
        }
        v8 = *v4 & 6; /*0x18fe62*/
        if ( v8 == 6 || v8 == 2 ) /*0x18fe6a*/
        {
          v9 = ptes_per_vm_page; /*0x18fe6c*/
          while ( 1 ) /*0x18feb1*/
          {
            v12 = v9--; /*0x18feb1*/
            if ( v12 <= 0 ) /*0x18feb6*/
              break; /*0x18feb6*/
            v10 = *v4 & 1; /*0x18fe7b*/
            if ( kernel_pmap == v13 ) /*0x18fe86*/
              v11 = byte_1F7A84; /*0x18fe88*/
            else
              v11 = byte_1F7B04; /*0x18fe90*/
            *v4 = (2 * (v11 & 3)) | *v4 & 0xF9; /*0x18fe9f*/
            *v4 = v10 & 1 | *v4 & 0xFE; /*0x18feac*/
            v4 += 4; /*0x18feae*/
          }
        }
        _InterlockedExchange((volatile __int32 *)(v13 + 12), 0); /*0x18febd*/
        v15 = (_DWORD *)*v15; /*0x18fec5*/
      }
      while ( v15 ); /*0x18feca*/
    }
    splx(v14); /*0x18fed4*/
  }
}
