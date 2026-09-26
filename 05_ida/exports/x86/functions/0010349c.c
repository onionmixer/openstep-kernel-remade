/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10349c. */
int __cdecl hardclock(int a1, int a2)
{
  thread_act_t v2; // ebx
  int v3; // eax
  int v4; // edx
  int v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF

  v2 = active_threads; /*0x1034a7*/
  if ( (a2 & 3) == 3 ) /*0x1034b5*/
  {
    if ( *(_DWORD *)active_u && *(_DWORD *)(active_u + 604) ) /*0x1034c3*/
    {
      *(_DWORD *)(*(_DWORD *)active_u + 40) |= 0x200000u; /*0x1034cc*/
      v3 = need_ast; /*0x1034d3*/
      LOBYTE(v3) = need_ast | 0x20; /*0x1034d8*/
      need_ast = v3; /*0x1034da*/
    }
    if ( (*(_DWORD *)(active_u + 536) || *(_DWORD *)(active_u + 540)) && !itimerdecr(active_u + 528, tick) ) /*0x103508*/
      psignal(*(_DWORD *)active_u, (const char *)0x1A); /*0x10351e*/
  }
  if ( *(_DWORD *)active_u && *(char *)(v2 + 76) >= 0 ) /*0x103538*/
  {
    if ( *(_DWORD *)(active_u + 612) != 0x7FFFFFFF ) /*0x103548*/
    {
      thread_read_times(v2, &v7, &v6); /*0x103553*/
      if ( *(_DWORD *)(active_u + 612) < v7 + v6 + 1 ) /*0x10356e*/
      {
        psignal(*(_DWORD *)active_u, (const char *)0x18); /*0x103575*/
        v4 = *(_DWORD *)(active_u + 612); /*0x10357f*/
        if ( *(_DWORD *)(active_u + 616) > v4 ) /*0x10358e*/
          *(_DWORD *)(active_u + 612) = v4 + 5; /*0x103593*/
      }
    }
    if ( (*(_DWORD *)(active_u + 552) || *(_DWORD *)(active_u + 556)) && !itimerdecr(active_u + 544, tick) ) /*0x1035bd*/
      psignal(*(_DWORD *)active_u, (const char *)0x1B); /*0x1035d3*/
  }
  return gatherstats(a1, a2); /*0x1035e8*/
}
