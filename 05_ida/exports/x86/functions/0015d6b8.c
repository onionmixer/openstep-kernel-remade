/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d6b8. */
void __cdecl sub_15D6B8(int a1)
{
  unsigned int v1; // eax
  vm_size_t v2; // edi
  int v3; // ebx
  int *v4; // esi
  int *v5; // ebx
  vm_size_t v6; // eax
  size_t v7; // ebx
  __int16 v8; // dx
  int v9; // [esp+0h] [ebp-20h]
  int v10; // [esp+Ch] [ebp-14h]
  char *i; // [esp+10h] [ebp-10h]
  int *v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-4h] BYREF

  if ( !*(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x15d6d2*/
  {
    v1 = *(_DWORD *)(a1 + 16) + *(_DWORD *)(a1 + 24); /*0x15d6e0*/
    *(_DWORD *)(a1 + 24) = v1; /*0x15d6e3*/
    if ( *(int *)(a1 + 20) >= 0 && v1 > 0x2B ) /*0x15d6f3*/
    {
      v2 = *(__int16 *)(a1 + 46); /*0x15d6f9*/
      if ( v2 > 0x14 && v2 <= v1 - 24 ) /*0x15d70b*/
      {
        v13 = 0; /*0x15d711*/
        v12 = &v13; /*0x15d71b*/
        for ( i = (char *)(a1 + 44); (int)v2 > 0; v12 = v4 ) /*0x15d726*/
        {
          v3 = splimp(); /*0x15d731*/
          v4 = (int *)mfree; /*0x15d733*/
          if ( mfree ) /*0x15d73b*/
          {
            if ( *(_WORD *)(mfree + 10) ) /*0x15d73d*/
              panic(aMget_16); /*0x15d749*/
            *(_WORD *)(mfree + 10) = 1; /*0x15d751*/
            --word_1E917C[0]; /*0x15d757*/
            ++word_1E917E; /*0x15d75e*/
            mfree = *v4; /*0x15d767*/
            *v4 = 0; /*0x15d76d*/
            v4[1] = 12; /*0x15d773*/
          }
          else
          {
            v4 = m_more(1, 1); /*0x15d785*/
          }
          splx(v3); /*0x15d78b*/
          if ( !v4 ) /*0x15d795*/
          {
            m_freem(v13); /*0x15d89c*/
            return; /*0x15d8a1*/
          }
          if ( v2 < page_size >> 1 ) /*0x15d7a4*/
            goto LABEL_24; /*0x15d7a4*/
          v10 = splimp(); /*0x15d7af*/
          if ( !mclfree ) /*0x15d7b9*/
            m_clalloc(1, 1); /*0x15d7c1*/
          v5 = (int *)mclfree; /*0x15d7c9*/
          if ( mclfree ) /*0x15d7d1*/
          {
            ++mclrefcnt[(mclfree - mbutl) >> 10]; /*0x15d7de*/
            --dword_1E916C; /*0x15d7e4*/
            mclfree = *v5; /*0x15d7ec*/
          }
          splx(v10); /*0x15d7f6*/
          if ( v5 ) /*0x15d800*/
          {
            v4[1] = (char *)v5 - (char *)v4; /*0x15d804*/
            *((_WORD *)v4 + 4) = 1024; /*0x15d807*/
            *((_WORD *)v4 + 6) = 1; /*0x15d80d*/
          }
          else
          {
            *((_WORD *)v4 + 4) = 112; /*0x15d818*/
          }
          v6 = *((__int16 *)v4 + 4); /*0x15d81e*/
          if ( page_size == v6 ) /*0x15d828*/
          {
            v7 = *((__int16 *)v4 + 4); /*0x15d82a*/
            if ( v6 >= v2 ) /*0x15d82e*/
              goto LABEL_25; /*0x15d82e*/
          }
          else
          {
LABEL_24:
            v7 = 112; /*0x15d834*/
            if ( (int)v2 <= 112 ) /*0x15d83c*/
LABEL_25:
              v7 = v2; /*0x15d83e*/
          }
          *((_WORD *)v4 + 4) = v7; /*0x15d840*/
          bcopy(i, (char *)v4 + v4[1], v7); /*0x15d84f*/
          i += v7; /*0x15d854*/
          v2 -= v7; /*0x15d857*/
          *v12 = (int)v4; /*0x15d85c*/
        }
        if ( dword_1DEF18 != *(_DWORD *)(a1 + 60) ) /*0x15d878*/
        {
          if ( dword_1DEF10 ) /*0x15d881*/
          {
            v8 = *(_WORD *)(dword_1DEF10 + 38); /*0x15d883*/
            if ( v8 == 1 ) /*0x15d88b*/
              rtfree(dword_1DEF10); /*0x15d88e*/
            else
              *(_WORD *)(dword_1DEF10 + 38) = v8 - 1; /*0x15d8a6*/
          }
          dword_1DEF10 = 0; /*0x15d8aa*/
        }
        ip_output(v13, 0, &dword_1DEF10, 33, v9); /*0x15d8c1*/
      }
    }
  }
}
