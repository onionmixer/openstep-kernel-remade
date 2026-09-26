/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c100. */
__int32 compute_mach_factor()
{
  int i; // esi
  volatile __int32 *v1; // edx
  int v2; // ebx
  int v3; // ecx
  int v4; // ecx
  int *v5; // ecx
  int *v6; // ebx
  int j; // [esp+14h] [ebp-14h]
  _DWORD *v9; // [esp+14h] [ebp-14h]
  int v10; // [esp+1Ch] [ebp-Ch]
  int v11; // [esp+20h] [ebp-8h]
  int v12; // [esp+24h] [ebp-4h]

  do /*0x15c126*/
  {
    while ( all_psets_lock ) /*0x15c114*/
      ; /*0x15c112*/
  }
  while ( _InterlockedExchange(&all_psets_lock, 1) == 1 ); /*0x15c126*/
  for ( i = all_psets; (int *)i != &all_psets; i = *(_DWORD *)(i + 332) ) /*0x15c134*/
  {
    v1 = (volatile __int32 *)(i + 344); /*0x15c13c*/
    do /*0x15c156*/
    {
      while ( *v1 ) /*0x15c144*/
        ; /*0x15c146*/
    }
    while ( _InterlockedExchange(v1, 1) == 1 ); /*0x15c156*/
    v2 = *(_DWORD *)(i + 292); /*0x15c158*/
    if ( v2 > 0 ) /*0x15c160*/
    {
      v3 = *(_DWORD *)(i + 264); /*0x15c166*/
      for ( j = *(_DWORD *)(i + 284); i + 284 != j; j = *(_DWORD *)(j + 308) ) /*0x15c17d*/
        v3 += *(_DWORD *)(j + 264); /*0x15c183*/
      v4 = v2 - *(_DWORD *)(i + 276) + v3; /*0x15c19e*/
      if ( (_UNKNOWN *)i == &default_pset ) /*0x15c1a6*/
        --v4; /*0x15c1a8*/
      if ( v4 <= v2 ) /*0x15c1ab*/
      {
        v12 = 1000 * (v2 - v4); /*0x15c1f4*/
        v10 = 128; /*0x15c1f7*/
      }
      else
      {
        v12 = 1000 * v2 / (v4 + 1); /*0x15c1cf*/
        v10 = (v4 << 7) / v2; /*0x15c1dc*/
      }
      v11 = 1000 * v4; /*0x15c214*/
      *(_DWORD *)(i + 368) = (v12 + 4 * *(_DWORD *)(i + 368)) / 5; /*0x15c231*/
      *(_DWORD *)(i + 372) = (1000 * v4 + 4 * *(_DWORD *)(i + 372)) / 5; /*0x15c24c*/
      if ( (_UNKNOWN *)i == &default_pset ) /*0x15c258*/
      {
        v5 = (int *)&avenrun; /*0x15c25a*/
        v9 = &unk_1DEE80; /*0x15c25f*/
        v6 = (int *)&mach_factor; /*0x15c266*/
        do /*0x15c2bd*/
        {
          *v6 = (v12 * (1000 - *v9) + *v6 * *v9) / 1000; /*0x15c28d*/
          *v5 = (v11 * (1000 - *v9) + *v5 * *v9) / 1000; /*0x15c2ab*/
          ++v5; /*0x15c2ad*/
          ++v9; /*0x15c2b0*/
          ++v6; /*0x15c2b4*/
        }
        while ( (int)v5 <= (int)&dword_1DEE70 ); /*0x15c2bd*/
      }
      *(_DWORD *)(i + 376) = (*(_DWORD *)(i + 376) + v10) >> 1; /*0x15c2ca*/
    }
    _InterlockedExchange((volatile __int32 *)(i + 344), 0); /*0x15c2d2*/
  }
  return _InterlockedExchange(&all_psets_lock, 0); /*0x15c2f5*/
}
