/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1148c0. */
_BOOL4 __cdecl mclget(int a1)
{
  _DWORD *v1; // eax
  signed int v2; // ecx
  signed int v3; // edx
  int *v4; // ebx
  int v6; // [esp+Ch] [ebp-4h]

  v6 = splimp(); /*0x1148d1*/
  if ( !mclfree ) /*0x1148db*/
  {
    v1 = (_DWORD *)kmem_mb_alloc(mb_map, ~page_mask & (page_mask + page_size)); /*0x1148f6*/
    if ( v1 ) /*0x114900*/
    {
      v2 = page_size >> 10; /*0x114908*/
      v3 = 0; /*0x11490b*/
      if ( page_size >> 10 ) /*0x114908*/
      {
        do /*0x114936*/
        {
          v1[1] = 0; /*0x114914*/
          *v1 = mclfree; /*0x114921*/
          mclfree = (int)v1; /*0x114923*/
          v1 += 256; /*0x114928*/
          ++dword_1E916C; /*0x11492d*/
          ++v3; /*0x114933*/
        }
        while ( v3 < v2 ); /*0x114936*/
      }
      dword_1E9164 += v2; /*0x114938*/
    }
  }
  v4 = (int *)mclfree; /*0x114940*/
  if ( mclfree ) /*0x114948*/
  {
    ++mclrefcnt[(mclfree - mbutl) >> 10]; /*0x114955*/
    --dword_1E916C; /*0x11495b*/
    mclfree = *v4; /*0x114963*/
    *(_WORD *)(a1 + 8) = 1024; /*0x114969*/
    *(_DWORD *)(a1 + 4) = (char *)v4 - a1; /*0x114973*/
    *(_WORD *)(a1 + 12) = 1; /*0x114976*/
  }
  splx(v6); /*0x114980*/
  return v4 != nullptr; /*0x114992*/
}
