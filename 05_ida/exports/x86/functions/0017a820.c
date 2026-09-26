/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17a820. */
int __cdecl vm_deactivate(_DWORD *a1, unsigned int a2, unsigned int a3, int a4)
{
  unsigned int v4; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  int v9; // esi
  unsigned int v10; // ecx
  volatile __int32 *v11; // edx
  int j; // edx
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // eax
  int v16; // [esp+Ch] [ebp-14h]
  unsigned int v17; // [esp+10h] [ebp-10h]
  unsigned int v18; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  unsigned int v20; // [esp+1Ch] [ebp-4h]

  v4 = a2; /*0x17a829*/
  if ( !a1 ) /*0x17a830*/
    return 5; /*0x17a832*/
  if ( !a3 ) /*0x17a840*/
    a3 = a1[6] - a1[5]; /*0x17a84b*/
  if ( !a2 ) /*0x17a850*/
    v4 = a1[5]; /*0x17a855*/
  v20 = v4; /*0x17a858*/
  lock_read((int)a1); /*0x17a85f*/
  for ( i = a1[4]; (_DWORD *)i != a1 + 3; i = *(_DWORD *)(i + 4) ) /*0x17a875*/
  {
    if ( (*(_BYTE *)(i + 24) & 5) != 0 ) /*0x17a883*/
    {
      sub_17A594(*(_DWORD *)(i + 16), v20, a3, a4); /*0x17a898*/
    }
    else
    {
      v6 = *(_DWORD *)(i + 8); /*0x17a8ab*/
      if ( a3 >= v6 ) /*0x17a8b1*/
      {
        v7 = *(_DWORD *)(i + 12); /*0x17a8b7*/
        if ( v20 < v7 ) /*0x17a8bd*/
        {
          if ( v20 < v6 ) /*0x17a8c6*/
            v20 = *(_DWORD *)(i + 8); /*0x17a8c8*/
          v8 = a3; /*0x17a8cb*/
          if ( v7 < a3 ) /*0x17a8d0*/
            v8 = *(_DWORD *)(i + 12); /*0x17a8d2*/
          v9 = *(_DWORD *)(i + 16); /*0x17a8d7*/
          v17 = *(_DWORD *)(i + 20) + v20 - v6; /*0x17a8e4*/
          v10 = *(_DWORD *)(i + 20) - v6 + v8; /*0x17a8e9*/
          if ( v9 ) /*0x17a8ee*/
          {
            v11 = (volatile __int32 *)(v9 + 16); /*0x17a8f4*/
            do /*0x17a90a*/
            {
              while ( *v11 ) /*0x17a8f8*/
                ; /*0x17a8fa*/
            }
            while ( _InterlockedExchange(v11, 1) == 1 ); /*0x17a90a*/
            for ( j = *(_DWORD *)v9; v9 != j; j = *(_DWORD *)(j + 8) ) /*0x17a910*/
            {
              v13 = *(_DWORD *)(j + 24); /*0x17a914*/
              if ( v17 <= v13 && v13 < v10 ) /*0x17a91e*/
              {
                v16 = j; /*0x17a926*/
                v18 = v10; /*0x17a929*/
                vm_policy_apply(v9, j, a4); /*0x17a92c*/
                v10 = v18; /*0x17a934*/
                j = v16; /*0x17a937*/
              }
            }
            v14 = v10 - v17; /*0x17a943*/
            v15 = *(_DWORD *)(v9 + 20); /*0x17a946*/
            if ( v15 ) /*0x17a94b*/
            {
              if ( v14 > v15 ) /*0x17a94f*/
                v14 = *(_DWORD *)(v9 + 20); /*0x17a951*/
            }
            sub_17A4F0(*(_DWORD *)(v9 + 32), *(_DWORD *)(v9 + 36) + v17, v14 + *(_DWORD *)(v9 + 36) + v17, a4); /*0x17a96b*/
            _InterlockedExchange((volatile __int32 *)(v9 + 16), 0); /*0x17a975*/
            thread_wakeup_prim(v9, 0, 0); /*0x17a97d*/
          }
        }
      }
    }
  }
  lock_done((int)a1); /*0x17a9a0*/
  return 0; /*0x17a9aa*/
}
