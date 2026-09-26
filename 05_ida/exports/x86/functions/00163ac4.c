/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163ac4. */
__int32 __cdecl thread_dispatch(int a1)
{
  volatile __int32 *v1; // esi
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // ebx
  int *v6; // esi
  int v7; // ebx
  int v8; // eax
  int v9; // ecx
  __int32 result; // eax
  volatile __int32 *v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+Ch] [ebp-10h]
  int *v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  int *v15; // [esp+18h] [ebp-4h]

  v1 = (volatile __int32 *)(a1 + 32); /*0x163ad0*/
  do /*0x163ae6*/
  {
    while ( *v1 ) /*0x163ad4*/
      ; /*0x163ad6*/
  }
  while ( _InterlockedExchange(v1, 1) == 1 ); /*0x163ae6*/
  if ( *(_DWORD *)(a1 + 52) ) /*0x163ae8*/
  {
    *(_DWORD *)(a1 + 76) |= 0x100u; /*0x163aee*/
    stack_free(a1); /*0x163af6*/
  }
  v2 = *(_DWORD *)(a1 + 76); /*0x163afe*/
  BYTE1(v2) &= 0xFCu; /*0x163b01*/
  if ( v2 == 12 ) /*0x163b07*/
    goto LABEL_43; /*0x163b07*/
  if ( v2 > 12 ) /*0x163b0d*/
  {
    if ( v2 == 15 ) /*0x163b37*/
      goto LABEL_44; /*0x163b37*/
    if ( v2 > 15 ) /*0x163b3d*/
    {
      if ( v2 == 22 ) /*0x163b5b*/
        goto LABEL_22; /*0x163b5b*/
      if ( v2 == 132 ) /*0x163b62*/
        return _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163d18*/
      goto LABEL_45; /*0x163b62*/
    }
    if ( v2 == 13 ) /*0x163b42*/
      goto LABEL_44; /*0x163b42*/
    if ( v2 != 14 ) /*0x163b4b*/
LABEL_45:
      panic(aThreadDispatch); /*0x163d0c*/
LABEL_43:
    thread_setrun(a1, 0); /*0x163cf8*/
    return _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163d00*/
  }
  if ( v2 == 5 ) /*0x163b12*/
  {
LABEL_44:
    *(_DWORD *)(a1 + 76) &= ~4u; /*0x163d04*/
    return _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163d08*/
  }
  if ( v2 <= 5 ) /*0x163b18*/
  {
    if ( v2 != 4 ) /*0x163b1d*/
      goto LABEL_45; /*0x163b1d*/
    goto LABEL_43; /*0x163b1d*/
  }
  if ( v2 > 7 ) /*0x163b2b*/
    goto LABEL_45; /*0x163b2b*/
LABEL_22:
  *(_DWORD *)(a1 + 76) &= ~4u; /*0x163b70*/
  if ( !*(_DWORD *)(a1 + 72) ) /*0x163b78*/
    return _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163b78*/
  *(_DWORD *)(a1 + 72) = 0; /*0x163b7e*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163b87*/
  v3 = a1 + 72; /*0x163b8a*/
  if ( a1 + 72 < 0 ) /*0x163b8f*/
    v4 = ~v3; /*0x163b9a*/
  else
    v4 = a1 + 72; /*0x163b91*/
  v5 = v4 % 59; /*0x163ba4*/
  v15 = &wait_queue[2 * (v4 % 59)]; /*0x163bad*/
  v14 = splsched(); /*0x163bb5*/
  v6 = &wait_lock[v5]; /*0x163bb8*/
  do /*0x163bd2*/
  {
    while ( *v6 ) /*0x163bc0*/
      ; /*0x163bc2*/
  }
  while ( _InterlockedExchange(v6, 1) == 1 ); /*0x163bd2*/
  v7 = *v15; /*0x163bd7*/
  if ( v15 != (int *)*v15 ) /*0x163bdb*/
  {
    do /*0x163ce0*/
    {
      v13 = *(int **)v7; /*0x163be6*/
      if ( *(_DWORD *)(v7 + 60) == v3 ) /*0x163bec*/
      {
        v11 = (volatile __int32 *)(v7 + 32); /*0x163bf5*/
        do /*0x163c10*/
        {
          while ( *v11 ) /*0x163bfb*/
            ; /*0x163bfd*/
        }
        while ( _InterlockedExchange(v11, 1) == 1 ); /*0x163c10*/
        *(_DWORD *)(*(_DWORD *)v7 + 4) = *(_DWORD *)(v7 + 4); /*0x163c17*/
        **(_DWORD **)(v7 + 4) = *(_DWORD *)v7; /*0x163c1f*/
        *(_DWORD *)(v7 + 60) = 0; /*0x163c21*/
        if ( *(_DWORD *)(v7 + 324) ) /*0x163c28*/
          reset_timeout(v7 + 280); /*0x163c38*/
        v12 = *(_DWORD *)(v7 + 76); /*0x163c43*/
        switch ( v12 & 0xF ) /*0x163c51*/
        {
          case 1: /*0x163c51*/
          case 9: /*0x163c51*/
          case 0xB: /*0x163c51*/
            v8 = *(_DWORD *)(v7 + 76); /*0x163c94*/
            LOBYTE(v8) = v12 & 0xFA | 4; /*0x163c99*/
            *(_DWORD *)(v7 + 76) = v8; /*0x163c9b*/
            *(_DWORD *)(v7 + 68) = 0; /*0x163c9e*/
            thread_setrun(v7, 1); /*0x163ca8*/
            break; /*0x163cb0*/
          case 3: /*0x163c51*/
          case 5: /*0x163c51*/
          case 7: /*0x163c51*/
          case 0xD: /*0x163c51*/
          case 0xF: /*0x163c51*/
            v9 = *(_DWORD *)(v7 + 76); /*0x163cb4*/
            LOBYTE(v9) = v12 & 0xFE; /*0x163cb7*/
            *(_DWORD *)(v7 + 76) = v9; /*0x163cba*/
            *(_DWORD *)(v7 + 68) = 0; /*0x163cbd*/
            break; /*0x163cc4*/
          default:
            panic(aThreadWakeup); /*0x163ccd*/
            return result; /*0x163ccd*/
        }
        _InterlockedExchange((volatile __int32 *)(v7 + 32), 0); /*0x163cd7*/
      }
      v7 = (int)v13; /*0x163cda*/
    }
    while ( v15 != v13 ); /*0x163ce0*/
  }
  _InterlockedExchange(v6, 0); /*0x163ce8*/
  return splx(v14); /*0x163d1e*/
}
