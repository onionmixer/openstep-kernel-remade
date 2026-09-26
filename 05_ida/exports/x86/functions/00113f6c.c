/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113f6c. */
int *__cdecl m_more(int a1, int a2)
{
  int v2; // eax
  int v3; // esi
  signed int v4; // edi
  _WORD *v5; // ebx
  _DWORD *v6; // esi
  unsigned int i; // ebx
  void (*v8)(void); // eax
  int v10; // eax
  int *v11; // ebx
  int v12; // [esp+Ch] [ebp-4h]

  while ( 2 ) /*0x113f78*/
  {
    v12 = 0; /*0x113f78*/
    while ( 1 ) /*0x113f99*/
    {
      v2 = kmem_mb_alloc(mb_map, ~page_mask & (page_mask + page_size)); /*0x113f99*/
      v3 = v2; /*0x113f9e*/
      if ( v2 ) /*0x113fa5*/
      {
        v4 = page_size >> 7; /*0x113fad*/
        if ( page_size >> 7 ) /*0x113fad*/
        {
          v5 = (_WORD *)(v2 + 10); /*0x113fb4*/
          do /*0x113fe9*/
          {
            *(_DWORD *)(v5 - 3) = 0; /*0x113fb8*/
            *v5 = 1; /*0x113fbf*/
            ++word_1E917E; /*0x113fc4*/
            ++mbstat; /*0x113fcb*/
            m_free(v3); /*0x113fd2*/
            v5 += 64; /*0x113fd7*/
            v3 += 128; /*0x113fdd*/
            --v4; /*0x113fe6*/
          }
          while ( v4 > 0 ); /*0x113fe9*/
        }
        if ( v3 ) /*0x113fed*/
        {
          v10 = splimp(); /*0x114068*/
          v11 = (int *)mfree; /*0x11406f*/
          if ( !mfree ) /*0x114077*/
            panic(aMMore); /*0x1140c5*/
          if ( *(_WORD *)(mfree + 10) ) /*0x114079*/
            panic(aMget_1); /*0x114085*/
          *(_WORD *)(mfree + 10) = a2; /*0x114091*/
          --word_1E917C[0]; /*0x114095*/
          ++word_1E917C[a2]; /*0x11409f*/
          mfree = *v11; /*0x1140a9*/
          *v11 = 0; /*0x1140af*/
          v11[1] = 12; /*0x1140b5*/
          splx(v10); /*0x1140ce*/
          return v11; /*0x11408d*/
        }
      }
      if ( !a1 ) /*0x113ff3*/
        break; /*0x113ff3*/
      if ( ++v12 != 1 ) /*0x113ffc*/
        break; /*0x113ffc*/
      v6 = (_DWORD *)domains; /*0x113ffe*/
      if ( domains ) /*0x114006*/
      {
        do /*0x114026*/
        {
          for ( i = v6[5]; v6[6] > i; i += 48 ) /*0x11400e*/
          {
            v8 = *(void (**)(void))(i + 44); /*0x114010*/
            if ( v8 ) /*0x114015*/
              v8(); /*0x114017*/
          }
          v6 = (_DWORD *)v6[7]; /*0x114021*/
        }
        while ( v6 ); /*0x114026*/
      }
      ++dword_1E9178; /*0x114028*/
    }
    if ( a1 == 1 ) /*0x114038*/
    {
      ++dword_1E9174; /*0x11403a*/
      ++m_want; /*0x114040*/
      sleep((unsigned int)&mfree); /*0x11404d*/
      continue; /*0x114055*/
    }
    break;
  }
  ++dword_1E9170; /*0x11405c*/
  return nullptr; /*0x1140d8*/
}
