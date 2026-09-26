/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1793b0. */
void __cdecl vm_object_copy(int a1, unsigned int a2, int a3, int *a4, unsigned int *a5, _DWORD *a6)
{
  volatile __int32 *v6; // edx
  int j; // eax
  unsigned int v8; // edx
  int v9; // ebx
  volatile __int32 *v10; // edx
  unsigned int v11; // edi
  int v12; // ebx
  volatile __int32 *v13; // edx
  int v14; // ebx
  unsigned int v15; // ebx
  int i; // eax
  int v17; // [esp+Ch] [ebp-4h]

  if ( !a1 ) /*0x1793be*/
  {
    *a4 = 0; /*0x1793c3*/
    *a5 = 0; /*0x1793cc*/
LABEL_42:
    *a6 = 0; /*0x17958c*/
    return; /*0x17958f*/
  }
  v6 = (volatile __int32 *)(a1 + 16); /*0x1793d8*/
  do /*0x1793ee*/
  {
    while ( *v6 ) /*0x1793dc*/
      ; /*0x1793de*/
  }
  while ( _InterlockedExchange(v6, 1) == 1 ); /*0x1793ee*/
  if ( *(_DWORD *)(a1 + 40) && (*(_BYTE *)(a1 + 70) & 0x10) == 0 ) /*0x1793fa*/
  {
    vm_object_collapse(a1); /*0x179445*/
    while ( 1 ) /*0x17944d*/
    {
      v9 = *(_DWORD *)(a1 + 28); /*0x17944d*/
      if ( !v9 ) /*0x179452*/
        break; /*0x179452*/
      if ( _InterlockedExchange((volatile __int32 *)(v9 + 16), 1) != 1 ) /*0x17945c*/
      {
        if ( !*(_WORD *)(v9 + 26) && !*(_DWORD *)(v9 + 40) ) /*0x17948f*/
        {
          ++*(_WORD *)(v9 + 24); /*0x179495*/
          _InterlockedExchange((volatile __int32 *)(v9 + 16), 0); /*0x17949b*/
          _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x1794a0*/
          *a4 = v9; /*0x1794a6*/
          v11 = a2; /*0x1794a8*/
          goto LABEL_41; /*0x1794ab*/
        }
        _InterlockedExchange((volatile __int32 *)(v9 + 16), 0); /*0x1794b2*/
        break; /*0x1794b2*/
      }
      _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x179468*/
      v10 = (volatile __int32 *)(a1 + 16); /*0x17946b*/
      do /*0x179482*/
      {
        while ( *v10 ) /*0x179470*/
          ; /*0x179472*/
      }
      while ( _InterlockedExchange(v10, 1) == 1 ); /*0x179482*/
    }
    _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x1794b5*/
    v12 = *(_DWORD *)(a1 + 20); /*0x1794ba*/
    v17 = zalloc(vm_object_zone); /*0x1794c9*/
    _vm_object_allocate(v12, (_DWORD *)v17); /*0x1794ce*/
    while ( 1 ) /*0x1794dc*/
    {
      v13 = (volatile __int32 *)(a1 + 16); /*0x1794dc*/
      do /*0x1794f2*/
      {
        while ( *v13 ) /*0x1794e0*/
          ; /*0x1794e2*/
      }
      while ( _InterlockedExchange(v13, 1) == 1 ); /*0x1794f2*/
      v14 = *(_DWORD *)(a1 + 28); /*0x1794f4*/
      if ( !v14 ) /*0x1794f9*/
        break; /*0x1794f9*/
      if ( _InterlockedExchange((volatile __int32 *)(v14 + 16), 1) != 1 ) /*0x179503*/
      {
        if ( *(_DWORD *)(v14 + 32) != a1 || *(_DWORD *)(v14 + 36) ) /*0x179519*/
          panic(aVmObjectCopyCo); /*0x179524*/
        --*(_WORD *)(a1 + 24); /*0x179529*/
        *(_DWORD *)(v14 + 32) = v17; /*0x179530*/
        ++*(_WORD *)(v17 + 24); /*0x179533*/
        _InterlockedExchange((volatile __int32 *)(v14 + 16), 0); /*0x179539*/
        break; /*0x179539*/
      }
      _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x17950c*/
    }
    v15 = *(_DWORD *)(v17 + 20); /*0x17953c*/
    *(_DWORD *)(v17 + 32) = a1; /*0x179542*/
    *(_DWORD *)(v17 + 36) = 0; /*0x179545*/
    ++*(_WORD *)(a1 + 24); /*0x17954c*/
    *(_DWORD *)(a1 + 28) = v17; /*0x179550*/
    for ( i = *(_DWORD *)a1; a1 != i; i = *(_DWORD *)(i + 8) ) /*0x179557*/
    {
      if ( *(_DWORD *)(i + 24) < v15 ) /*0x179567*/
        *(_BYTE *)(i + 33) |= 4u; /*0x179569*/
    }
    _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x179576*/
    *a4 = v17; /*0x17957f*/
    v11 = a2; /*0x179581*/
LABEL_41:
    *a5 = v11; /*0x179587*/
    goto LABEL_42; /*0x17958a*/
  }
  ++*(_WORD *)(a1 + 24); /*0x1793fc*/
  for ( j = *(_DWORD *)a1; a1 != j; j = *(_DWORD *)(j + 8) ) /*0x179404*/
  {
    v8 = *(_DWORD *)(j + 24); /*0x17940c*/
    if ( a2 <= v8 && v8 < a3 + a2 ) /*0x179416*/
      *(_BYTE *)(j + 33) |= 4u; /*0x179418*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x179425*/
  *a4 = a1; /*0x17942b*/
  *a5 = a2; /*0x179433*/
  *a6 = 1; /*0x179438*/
}
