/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1765fc. */
int __cdecl vm_map_check_protection(int a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v4; // ebx
  volatile __int32 *v5; // edx
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  volatile __int32 *v8; // edx
  volatile __int32 *v9; // edx
  _DWORD *v11; // edx
  _DWORD *v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+Ch] [ebp-4h]

  v4 = a2; /*0x176608*/
  v5 = (volatile __int32 *)(a1 + 60); /*0x17660b*/
  do /*0x176622*/
  {
    while ( *v5 ) /*0x176610*/
      ; /*0x176612*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x176622*/
  v6 = *(_DWORD **)(a1 + 56); /*0x176624*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x176629*/
  v7 = (_DWORD *)(a1 + 12); /*0x17662c*/
  if ( v6 == (_DWORD *)(a1 + 12) ) /*0x176631*/
    v6 = *(_DWORD **)(a1 + 16); /*0x176633*/
  if ( v6[2] > a2 ) /*0x176639*/
  {
    v7 = (_DWORD *)v6[1]; /*0x17664c*/
    v6 = *(_DWORD **)(a1 + 16); /*0x17664f*/
LABEL_18:
    while ( v6 != v7 ) /*0x176689*/
    {
      if ( v6[3] > a2 ) /*0x176657*/
      {
        if ( v6[2] > a2 ) /*0x17665c*/
          goto LABEL_19; /*0x17665c*/
        v12 = v6; /*0x17665e*/
        v8 = (volatile __int32 *)(a1 + 60); /*0x176661*/
        do /*0x176676*/
        {
          while ( *v8 ) /*0x176664*/
            ; /*0x176666*/
        }
        while ( _InterlockedExchange(v8, 1) == 1 ); /*0x176676*/
        *(_DWORD *)(a1 + 56) = v6; /*0x176678*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x17667d*/
        goto LABEL_24; /*0x176680*/
      }
      v6 = (_DWORD *)v6[1]; /*0x176684*/
    }
    goto LABEL_19; /*0x176689*/
  }
  if ( v6 == v7 ) /*0x17663d*/
  {
LABEL_19:
    v13 = *v6; /*0x17668b*/
    v9 = (volatile __int32 *)(a1 + 60); /*0x176690*/
    do /*0x1766a6*/
    {
      while ( *v9 ) /*0x176694*/
        ; /*0x176696*/
    }
    while ( _InterlockedExchange(v9, 1) == 1 ); /*0x1766a6*/
    *(_DWORD *)(a1 + 56) = v13; /*0x1766ab*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1766b0*/
    return 0; /*0x1766b5*/
  }
  if ( v6[3] <= a2 ) /*0x176642*/
    goto LABEL_18; /*0x176642*/
  v12 = v6; /*0x176644*/
LABEL_24:
  v11 = v12; /*0x1766b8*/
  if ( a3 > a2 ) /*0x1766be*/
  {
    while ( v11 != (_DWORD *)(a1 + 12) && v11[2] <= v4 && a4 == (v11[7] & a4) ) /*0x1766d6*/
    {
      v4 = v11[3]; /*0x1766d8*/
      v11 = (_DWORD *)v11[1]; /*0x1766db*/
      if ( a3 <= v4 ) /*0x1766e1*/
        return 1; /*0x1766e1*/
    }
    return 0; /*0x1766d6*/
  }
  return 1; /*0x1766eb*/
}
