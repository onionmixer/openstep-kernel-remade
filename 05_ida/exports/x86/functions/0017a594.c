/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a594. */
__int32 __cdecl sub_17A594(int a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edx
  int v7; // esi
  unsigned int v8; // ecx
  volatile __int32 *v9; // edx
  int j; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  int v15; // [esp+Ch] [ebp-10h]
  unsigned int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  lock_read(a1); /*0x17a5a1*/
  for ( i = *(_DWORD *)(a1 + 16); i != a1 + 12; i = *(_DWORD *)(i + 4) ) /*0x17a5b7*/
  {
    if ( (*(_BYTE *)(i + 24) & 5) != 0 ) /*0x17a5c7*/
    {
      sub_17A594(*(_DWORD *)(i + 16), a2, a3, a4); /*0x17a5dc*/
    }
    else
    {
      v4 = *(_DWORD *)(i + 8); /*0x17a5ef*/
      if ( a3 >= v4 ) /*0x17a5f5*/
      {
        v5 = *(_DWORD *)(i + 12); /*0x17a5fb*/
        if ( a2 < v5 ) /*0x17a601*/
        {
          if ( a2 < v4 ) /*0x17a60a*/
            a2 = *(_DWORD *)(i + 8); /*0x17a60c*/
          v6 = a3; /*0x17a60f*/
          if ( v5 < a3 ) /*0x17a614*/
            v6 = *(_DWORD *)(i + 12); /*0x17a616*/
          v7 = *(_DWORD *)(i + 16); /*0x17a61b*/
          v16 = *(_DWORD *)(i + 20) + a2 - v4; /*0x17a628*/
          v8 = *(_DWORD *)(i + 20) - v4 + v6; /*0x17a62d*/
          if ( v7 ) /*0x17a632*/
          {
            v9 = (volatile __int32 *)(v7 + 16); /*0x17a638*/
            do /*0x17a64e*/
            {
              while ( *v9 ) /*0x17a63c*/
                ; /*0x17a63e*/
            }
            while ( _InterlockedExchange(v9, 1) == 1 ); /*0x17a64e*/
            for ( j = *(_DWORD *)v7; v7 != j; j = *(_DWORD *)(j + 8) ) /*0x17a654*/
            {
              v11 = *(_DWORD *)(j + 24); /*0x17a658*/
              if ( v16 <= v11 && v11 < v8 ) /*0x17a662*/
              {
                v15 = j; /*0x17a66a*/
                v17 = v8; /*0x17a66d*/
                vm_policy_apply(v7, j, a4); /*0x17a670*/
                v8 = v17; /*0x17a678*/
                j = v15; /*0x17a67b*/
              }
            }
            v12 = v8 - v16; /*0x17a687*/
            v13 = *(_DWORD *)(v7 + 20); /*0x17a68a*/
            if ( v13 && v12 > v13 ) /*0x17a693*/
              v12 = *(_DWORD *)(v7 + 20); /*0x17a695*/
            sub_17A4F0(*(_DWORD *)(v7 + 32), *(_DWORD *)(v7 + 36) + v16, v12 + *(_DWORD *)(v7 + 36) + v16, a4); /*0x17a6af*/
            _InterlockedExchange((volatile __int32 *)(v7 + 16), 0); /*0x17a6b9*/
            thread_wakeup_prim(v7, 0, 0); /*0x17a6c1*/
          }
        }
      }
    }
  }
  return lock_done(a1); /*0x17a6ec*/
}
