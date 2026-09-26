/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18fa44. */
void __cdecl pmap_remove(_DWORD *a1, char *a2, vm_size_t a3)
{
  unsigned int v3; // esi
  char *v4; // edx
  unsigned __int32 v5; // eax
  int v6; // eax
  vm_size_t v7; // ebx
  int v8; // [esp+Ch] [ebp-4h]

  v3 = (unsigned int)a2; /*0x18fa4d*/
  if ( a1 ) /*0x18fa57*/
  {
    v8 = splvm(); /*0x18fa62*/
    v4 = a2; /*0x18fa65*/
    if ( a1 == (_DWORD *)kernel_pmap || a1[6] ) /*0x18fa75*/
    {
      ++tlb_stat; /*0x18fa7b*/
      if ( page_size >= a3 - (unsigned int)a2 ) /*0x18fa8b*/
      {
        if ( (unsigned int)a2 < a3 ) /*0x18fa9a*/
        {
          v6 = kernel_pmap; /*0x18fa9c*/
          do /*0x18fab8*/
          {
            if ( a1 == (_DWORD *)v6 ) /*0x18faa3*/
              __invlpg(v4); /*0x18faa5*/
            else
              __invlpg(MK_FP(__FS__, v4)); /*0x18faac*/
            v4 += 4096; /*0x18fab0*/
          }
          while ( (unsigned int)v4 < a3 ); /*0x18fab8*/
        }
        ++dword_1F7AF4; /*0x18faba*/
      }
      else
      {
        v5 = __readcr3(); /*0x18fa8d*/
        __writecr3(v5); /*0x18fa90*/
      }
    }
    while ( v3 < a3 ) /*0x18faf5*/
    {
      v7 = -section_size & (section_size + page_size + v3 - 1); /*0x18fad9*/
      if ( v7 > a3 ) /*0x18fadd*/
        v7 = a3; /*0x18fadf*/
      sub_18F7F8(a1, v3, v7, 1); /*0x18fae9*/
      v3 = v7; /*0x18faee*/
    }
    splx(v8); /*0x18fafb*/
  }
}
