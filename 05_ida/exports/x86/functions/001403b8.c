/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1403b8. */
int __cdecl disksort_remove(int a1, int a2)
{
  char v2; // bl
  volatile __int32 *v4; // ebx
  int *v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // edx
  _DWORD *v9; // ebx
  int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]

  if ( dword_1F50EC ) /*0x1403cb*/
  {
    v2 = *(_BYTE *)(a1 + 12); /*0x1403cd*/
    if ( (v2 & 1) != 0 ) /*0x1403d3*/
      return dword_1F50E0(a1); /*0x140422*/
    if ( *(_DWORD *)(a1 + 16) == a1 + 16 ) /*0x1403db*/
    {
      *(_BYTE *)(a1 + 12) = v2 | 1; /*0x1403e0*/
      ((void (__cdecl *)(int))dword_1F50E4)(a1); /*0x1403e9*/
    }
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 12) & 1) == 0 ) /*0x1403f0*/
      goto LABEL_10; /*0x1403f0*/
    if ( !dword_1F50DC(a1) ) /*0x1403f8*/
    {
      *(_BYTE *)(a1 + 12) &= ~1u; /*0x140401*/
      ((void (__cdecl *)(int))dword_1F50E8)(a1); /*0x14040b*/
    }
  }
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 ) /*0x140414*/
    return dword_1F50E0(a1); /*0x140414*/
LABEL_10:
  v12 = splbio(); /*0x140428*/
  v4 = (volatile __int32 *)(a1 + 36); /*0x140430*/
  do /*0x140446*/
  {
    while ( *v4 ) /*0x140434*/
      ; /*0x140436*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x140446*/
  v5 = *(int **)(a1 + 16); /*0x14044b*/
  if ( (int *)(a1 + 16) == v5 ) /*0x140450*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 36), 0); /*0x140454*/
    splx(v12); /*0x14045b*/
    return 0; /*0x140460*/
  }
  else
  {
    while ( 1 ) /*0x140468*/
    {
      v6 = *v5; /*0x140468*/
      if ( a2 == *v5 ) /*0x14046d*/
      {
        *v5 = *(_DWORD *)(v6 + 12); /*0x140472*/
        if ( *(int **)(a1 + 16) == v5 ) /*0x140477*/
        {
          *(_BYTE *)(a1 + 12) &= ~8u; /*0x14047d*/
          *(_DWORD *)(a1 + 28) = *(_DWORD *)(v6 + 56); /*0x140484*/
        }
        goto LABEL_34; /*0x140487*/
      }
      if ( *(_DWORD *)(v6 + 12) ) /*0x14048c*/
      {
        do /*0x14049e*/
        {
          v7 = *(_DWORD *)(v6 + 12); /*0x140494*/
          if ( a2 == v7 ) /*0x14049a*/
            break; /*0x14049a*/
          v6 = *(_DWORD *)(v6 + 12); /*0x14049c*/
        }
        while ( *(_DWORD *)(v7 + 12) ); /*0x14049e*/
        if ( *(_DWORD *)(v6 + 12) ) /*0x1404a4*/
          break; /*0x1404a4*/
      }
      v5 = (int *)v5[4]; /*0x1404c0*/
      if ( (int *)(a1 + 16) == v5 ) /*0x1404c8*/
        goto LABEL_34; /*0x1404c8*/
    }
    v8 = *(_DWORD *)(a2 + 12); /*0x1404ad*/
    *(_DWORD *)(v6 + 12) = v8; /*0x1404b0*/
    if ( !v8 ) /*0x1404b5*/
      v5[1] = v6; /*0x1404b7*/
    v6 = a2; /*0x1404ba*/
LABEL_34:
    while ( 1 ) /*0x140517*/
    {
      v9 = *(_DWORD **)(a1 + 16); /*0x140517*/
      if ( (*(_BYTE *)(a1 + 12) & 8) != 0 || (_DWORD *)(a1 + 16) == v9 || *v9 ) /*0x140527*/
        break; /*0x140527*/
      v11 = v9[4]; /*0x1404cf*/
      v10 = v9[5]; /*0x1404d5*/
      if ( a1 + 16 == v11 ) /*0x1404da*/
        *(_DWORD *)(a1 + 20) = v9[5]; /*0x1404dc*/
      else
        *(_DWORD *)(v11 + 20) = v10; /*0x1404ea*/
      if ( v10 == a1 + 16 ) /*0x1404f3*/
        *(_DWORD *)(a1 + 16) = v11; /*0x1404f8*/
      else
        *(_DWORD *)(v10 + 16) = v11; /*0x140506*/
      kfree((int)v9, 0x18u); /*0x14050c*/
      ++*(_DWORD *)(a1 + 24); /*0x140511*/
    }
    _InterlockedExchange((volatile __int32 *)(a1 + 36), 0); /*0x14052e*/
    splx(v12); /*0x140535*/
    return v6; /*0x14053a*/
  }
}
