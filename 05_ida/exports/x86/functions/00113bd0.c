/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113bd0. */
_DWORD *__cdecl m_clalloc(int a1, int a2)
{
  _DWORD *v2; // edi
  signed int v4; // esi
  signed int v5; // ebx
  signed int v6; // ebx
  _WORD *v7; // esi

  v2 = (_DWORD *)kmem_mb_alloc(mb_map, ~page_mask & (page_mask + page_size * a1)); /*0x113bfd*/
  if ( !v2 ) /*0x113c04*/
    return nullptr; /*0x113c06*/
  if ( a2 == 1 ) /*0x113c13*/
  {
    v4 = (page_size * a1) >> 10; /*0x113c3b*/
    v5 = 0; /*0x113c3e*/
    if ( v4 ) /*0x113c42*/
    {
      do /*0x113c68*/
      {
        v2[1] = 0; /*0x113c44*/
        *v2 = mclfree; /*0x113c51*/
        mclfree = (int)v2; /*0x113c53*/
        v2 += 256; /*0x113c59*/
        ++dword_1E916C; /*0x113c5f*/
        ++v5; /*0x113c65*/
      }
      while ( v5 < v4 ); /*0x113c68*/
    }
    dword_1E9164 += v4; /*0x113c6a*/
  }
  else if ( a2 > 1 ) /*0x113c15*/
  {
    if ( a2 == 2 ) /*0x113c23*/
      dword_1E9168 += a1; /*0x113cc4*/
  }
  else if ( !a2 ) /*0x113c19*/
  {
    v6 = (page_size * a1) >> 7; /*0x113c7f*/
    if ( v6 ) /*0x113c84*/
    {
      v7 = (_WORD *)v2 + 5; /*0x113c86*/
      do /*0x113cbd*/
      {
        *(_DWORD *)(v7 - 3) = 0; /*0x113c8c*/
        *v7 = 1; /*0x113c93*/
        ++word_1E917E; /*0x113c98*/
        ++mbstat; /*0x113c9f*/
        m_free(v2); /*0x113ca6*/
        v7 += 64; /*0x113cab*/
        v2 += 32; /*0x113cb1*/
        --v6; /*0x113cba*/
      }
      while ( v6 > 0 ); /*0x113cbd*/
    }
  }
  return v2; /*0x113ccf*/
}
