/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1631a0. */
int __cdecl thread_wakeup_prim(int a1, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int *v5; // esi
  int v6; // ebx
  int *v7; // edi
  int v8; // eax
  int v9; // edx
  int result; // eax
  volatile __int32 *v11; // [esp+Ch] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int *v14; // [esp+14h] [ebp-4h]

  if ( a1 < 0 ) /*0x1631ad*/
    v3 = ~a1; /*0x1631b7*/
  else
    v3 = a1; /*0x1631af*/
  v4 = v3 % 59; /*0x1631c1*/
  v14 = &wait_queue[2 * (v3 % 59)]; /*0x1631ca*/
  v13 = splsched(); /*0x1631d2*/
  v5 = &wait_lock[v4]; /*0x1631d5*/
  do /*0x1631ee*/
  {
    while ( *v5 ) /*0x1631dc*/
      ; /*0x1631de*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1631ee*/
  v6 = *v14; /*0x1631f3*/
  if ( v14 != (int *)*v14 ) /*0x1631f7*/
  {
    do /*0x163301*/
    {
      v7 = *(int **)v6; /*0x163200*/
      if ( *(_DWORD *)(v6 + 60) == a1 ) /*0x163208*/
      {
        v11 = (volatile __int32 *)(v6 + 32); /*0x163211*/
        do /*0x16322c*/
        {
          while ( *v11 ) /*0x163217*/
            ; /*0x163219*/
        }
        while ( _InterlockedExchange(v11, 1) == 1 ); /*0x16322c*/
        *(_DWORD *)(*(_DWORD *)v6 + 4) = *(_DWORD *)(v6 + 4); /*0x163233*/
        **(_DWORD **)(v6 + 4) = *(_DWORD *)v6; /*0x16323b*/
        *(_DWORD *)(v6 + 60) = 0; /*0x16323d*/
        if ( *(_DWORD *)(v6 + 324) ) /*0x163244*/
          reset_timeout(v6 + 280); /*0x163254*/
        v12 = *(_DWORD *)(v6 + 76); /*0x16325f*/
        switch ( v12 & 0xF ) /*0x16326d*/
        {
          case 1: /*0x16326d*/
          case 9: /*0x16326d*/
          case 0xB: /*0x16326d*/
            v8 = *(_DWORD *)(v6 + 76); /*0x1632b0*/
            LOBYTE(v8) = v12 & 0xFA | 4; /*0x1632b5*/
            *(_DWORD *)(v6 + 76) = v8; /*0x1632b7*/
            *(_DWORD *)(v6 + 68) = a3; /*0x1632bd*/
            thread_setrun(v6, 1); /*0x1632c3*/
            break; /*0x1632cb*/
          case 3: /*0x16326d*/
          case 5: /*0x16326d*/
          case 7: /*0x16326d*/
          case 0xD: /*0x16326d*/
          case 0xF: /*0x16326d*/
            v9 = *(_DWORD *)(v6 + 76); /*0x1632d0*/
            LOBYTE(v9) = v12 & 0xFE; /*0x1632d3*/
            *(_DWORD *)(v6 + 76) = v9; /*0x1632d6*/
            *(_DWORD *)(v6 + 68) = a3; /*0x1632dc*/
            break; /*0x1632df*/
          default:
            panic(aThreadWakeup); /*0x1632e9*/
            return result; /*0x1632e9*/
        }
        _InterlockedExchange((volatile __int32 *)(v6 + 32), 0); /*0x1632f3*/
        if ( a2 ) /*0x1632fa*/
          break; /*0x1632fa*/
      }
      v6 = (int)v7; /*0x1632fc*/
    }
    while ( v14 != v7 ); /*0x163301*/
  }
  _InterlockedExchange(v5, 0); /*0x163309*/
  return splx(v13); /*0x163317*/
}
