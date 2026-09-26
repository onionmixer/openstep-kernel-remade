/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113ce0. */
int __cdecl m_expand(int a1)
{
  int v1; // eax
  int v2; // ebx
  signed int v3; // edi
  _WORD *v4; // esi
  _DWORD *v6; // esi
  unsigned int i; // ebx
  void (*v8)(void); // eax
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 0; /*0x113ce9*/
  while ( 1 ) /*0x113d09*/
  {
    v1 = kmem_mb_alloc(mb_map, ~page_mask & (page_mask + page_size)); /*0x113d09*/
    v2 = v1; /*0x113d0e*/
    if ( v1 ) /*0x113d15*/
    {
      v3 = page_size >> 7; /*0x113d1d*/
      if ( page_size >> 7 ) /*0x113d1d*/
      {
        v4 = (_WORD *)(v1 + 10); /*0x113d24*/
        do /*0x113d59*/
        {
          *(_DWORD *)(v4 - 3) = 0; /*0x113d28*/
          *v4 = 1; /*0x113d2f*/
          ++word_1E917E; /*0x113d34*/
          ++mbstat; /*0x113d3b*/
          m_free(v2); /*0x113d42*/
          v4 += 64; /*0x113d47*/
          v2 += 128; /*0x113d4d*/
          --v3; /*0x113d56*/
        }
        while ( v3 > 0 ); /*0x113d59*/
      }
      if ( v2 ) /*0x113d5d*/
        return 1; /*0x113d64*/
    }
    if ( !a1 ) /*0x113d6c*/
      break; /*0x113d6c*/
    if ( ++v9 != 1 ) /*0x113d75*/
      break; /*0x113d75*/
    v6 = (_DWORD *)domains; /*0x113d7c*/
    if ( domains ) /*0x113d84*/
    {
      do /*0x113da6*/
      {
        for ( i = v6[5]; v6[6] > i; i += 48 ) /*0x113d8e*/
        {
          v8 = *(void (**)(void))(i + 44); /*0x113d90*/
          if ( v8 ) /*0x113d95*/
            v8(); /*0x113d97*/
        }
        v6 = (_DWORD *)v6[7]; /*0x113da1*/
      }
      while ( v6 ); /*0x113da6*/
    }
    ++dword_1E9178; /*0x113da8*/
  }
  return 0; /*0x113db7*/
}
