/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16303c. */
int __cdecl clear_wait(int a1, int a2, int a3)
{
  volatile __int32 *v3; // edx
  int v4; // ecx
  int v5; // eax
  int *v6; // esi
  volatile __int32 *v7; // edx
  int v8; // esi
  int v9; // eax
  int v11; // [esp+Ch] [ebp-4h]

  v11 = splsched(); /*0x16304d*/
  v3 = (volatile __int32 *)(a1 + 32); /*0x163050*/
  do /*0x163066*/
  {
    while ( *v3 ) /*0x163054*/
      ; /*0x163056*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x163066*/
  if ( !a3 || (*(_BYTE *)(a1 + 76) & 8) == 0 ) /*0x163072*/
  {
    v4 = *(_DWORD *)(a1 + 60); /*0x163078*/
    if ( !v4 ) /*0x16307d*/
      goto LABEL_19; /*0x16307d*/
    _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163081*/
    if ( v4 < 0 ) /*0x163086*/
      v5 = ~v4; /*0x16308e*/
    else
      v5 = v4; /*0x163088*/
    v6 = &wait_lock[v5 % 59]; /*0x163098*/
    do /*0x1630b2*/
    {
      while ( *v6 ) /*0x1630a0*/
        ; /*0x1630a2*/
    }
    while ( _InterlockedExchange(v6, 1) == 1 ); /*0x1630b2*/
    v7 = (volatile __int32 *)(a1 + 32); /*0x1630b4*/
    do /*0x1630ca*/
    {
      while ( *v7 ) /*0x1630b8*/
        ; /*0x1630ba*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x1630ca*/
    if ( *(_DWORD *)(a1 + 60) == v4 ) /*0x1630cf*/
    {
      *(_DWORD *)(*(_DWORD *)a1 + 4) = *(_DWORD *)(a1 + 4); /*0x1630d6*/
      **(_DWORD **)(a1 + 4) = *(_DWORD *)a1; /*0x1630de*/
      *(_DWORD *)(a1 + 60) = 0; /*0x1630e0*/
      v4 = 0; /*0x1630e7*/
    }
    _InterlockedExchange(v6, 0); /*0x1630eb*/
    if ( !v4 ) /*0x1630ef*/
    {
LABEL_19:
      v8 = *(_DWORD *)(a1 + 76); /*0x1630f5*/
      if ( *(_DWORD *)(a1 + 324) ) /*0x1630f8*/
        reset_timeout(a1 + 280); /*0x163108*/
      switch ( v8 & 0xF ) /*0x16311b*/
      {
        case 1: /*0x16311b*/
        case 9: /*0x16311b*/
        case 0xB: /*0x16311b*/
          v9 = v8; /*0x163160*/
          LOBYTE(v9) = v8 & 0xFA | 4; /*0x163164*/
          *(_DWORD *)(a1 + 76) = v9; /*0x163166*/
          *(_DWORD *)(a1 + 68) = a2; /*0x16316c*/
          thread_setrun(a1, 1); /*0x163172*/
          break; /*0x16317a*/
        case 3: /*0x16311b*/
        case 5: /*0x16311b*/
        case 7: /*0x16311b*/
        case 0xD: /*0x16311b*/
        case 0xF: /*0x16311b*/
          *(_DWORD *)(a1 + 76) = v8 & 0xFFFFFFFE; /*0x16317f*/
          *(_DWORD *)(a1 + 68) = a2; /*0x163185*/
          break; /*0x163185*/
        default:
          break;
      }
    }
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x163188*/
  return splx(v11); /*0x163199*/
}
