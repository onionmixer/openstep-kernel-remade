/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179914. */
void __cdecl vm_object_collapse(int a1)
{
  int *v1; // esi
  volatile __int32 *v2; // edx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int *v6; // edx
  int *v7; // eax
  int *v8; // edi
  int v9; // eax
  volatile __int32 *v10; // edx
  unsigned int v11; // [esp+Ch] [ebp-Ch]
  unsigned int v12; // [esp+10h] [ebp-8h]
  unsigned int v13; // [esp+14h] [ebp-4h]

  if ( vm_object_collapse_allowed ) /*0x179924*/
  {
    while ( 1 ) /*0x17992c*/
    {
LABEL_2:
      if ( !a1 ) /*0x179930*/
        return; /*0x179930*/
      if ( *(_WORD *)(a1 + 68) ) /*0x179939*/
        return; /*0x179939*/
      if ( *(_DWORD *)(a1 + 40) ) /*0x179944*/
        return; /*0x179944*/
      v1 = *(int **)(a1 + 32); /*0x17994e*/
      if ( !v1 ) /*0x179953*/
        return; /*0x179953*/
      v2 = v1 + 4; /*0x179959*/
      do /*0x17996e*/
      {
        while ( *v2 ) /*0x17995c*/
          ; /*0x17995e*/
      }
      while ( _InterlockedExchange(v2, 1) == 1 ); /*0x17996e*/
      if ( (int *)(v1[17] & 0x10FFFF) != &dword_100000 ) /*0x17997d*/
        goto LABEL_43; /*0x17997d*/
      v3 = v1[8]; /*0x179983*/
      if ( v3 ) /*0x179988*/
      {
        if ( *(_DWORD *)(v3 + 28) ) /*0x17998a*/
          goto LABEL_43; /*0x17998e*/
      }
      v13 = *(_DWORD *)(a1 + 36); /*0x1799aa*/
      v12 = *(_DWORD *)(a1 + 20); /*0x1799b3*/
      if ( *((_WORD *)v1 + 12) == 1 ) /*0x1799bb*/
        break; /*0x1799bb*/
      if ( v1[10] ) /*0x179b20*/
        goto LABEL_43; /*0x179b24*/
      v8 = (int *)*v1; /*0x179b26*/
      if ( v1 != (int *)*v1 ) /*0x179b2a*/
      {
        while ( v13 > v8[6] || v12 < v8[6] - v13 || vm_page_lookup(a1, v8[6] - v13) ) /*0x179b4d*/
        {
          v8 = (int *)v8[2]; /*0x179b58*/
          if ( v1 == v8 ) /*0x179b5d*/
            goto LABEL_45; /*0x179b5d*/
        }
LABEL_43:
        _InterlockedExchange(v1 + 4, 0); /*0x179b4f*/
        return; /*0x179b54*/
      }
LABEL_45:
      v9 = v1[8]; /*0x179b5f*/
      *(_DWORD *)(a1 + 32) = v9; /*0x179b65*/
      if ( v9 ) /*0x179b6c*/
      {
        v10 = (volatile __int32 *)(v9 + 16); /*0x179b6e*/
        do /*0x179b86*/
        {
          while ( *v10 ) /*0x179b74*/
            ; /*0x179b76*/
        }
        while ( _InterlockedExchange(v10, 1) == 1 ); /*0x179b86*/
        ++*(_WORD *)(v9 + 24); /*0x179b88*/
        _InterlockedExchange((volatile __int32 *)(v9 + 16), 0); /*0x179b8e*/
      }
      *(_DWORD *)(a1 + 36) += v1[9]; /*0x179b97*/
      --*((_WORD *)v1 + 12); /*0x179b9a*/
      _InterlockedExchange(v1 + 4, 0); /*0x179ba0*/
      ++object_bypasses; /*0x179ba3*/
    }
    while ( 1 ) /*0x1799c1*/
    {
      if ( (int *)*v1 == v1 ) /*0x1799c3*/
      {
        *(_DWORD *)(a1 + 40) = v1[10]; /*0x179a66*/
        *(_DWORD *)(a1 + 44) = v1[11] + v13; /*0x179a6f*/
        v1[10] = 0; /*0x179a72*/
        v1[12] = 0; /*0x179a79*/
        v1[13] = 0; /*0x179a80*/
        *(_DWORD *)(a1 + 32) = v1[8]; /*0x179a8a*/
        *(_DWORD *)(a1 + 36) += v1[9]; /*0x179a90*/
        v5 = *(_DWORD *)(a1 + 32); /*0x179a93*/
        if ( v5 && *(_DWORD *)(v5 + 28) ) /*0x179a9a*/
          panic(aVmObjectCollap); /*0x179aa5*/
        _InterlockedExchange(v1 + 4, 0); /*0x179aaf*/
        do /*0x179acd*/
        {
          while ( vm_object_list_lock ) /*0x179abb*/
            ; /*0x179ab9*/
        }
        while ( _InterlockedExchange(&vm_object_list_lock, 1) == 1 ); /*0x179acd*/
        v6 = (int *)v1[2]; /*0x179acf*/
        v7 = (int *)v1[3]; /*0x179ad2*/
        if ( v6 == &vm_object_list ) /*0x179adb*/
          dword_1F7354 = v1[3]; /*0x179add*/
        else
          v6[3] = (int)v7; /*0x179ae4*/
        if ( v7 == &vm_object_list ) /*0x179aec*/
          vm_object_list = (int)v6; /*0x179998*/
        else
          v7[2] = (int)v6; /*0x179af2*/
        --vm_object_count; /*0x179af5*/
        _InterlockedExchange(&vm_object_list_lock, 0); /*0x179afd*/
        zfree(vm_object_zone, v1); /*0x179b0b*/
        ++object_collapses; /*0x179b10*/
        goto LABEL_2; /*0x179b19*/
      }
      v4 = *v1; /*0x1799c9*/
      if ( v13 > *(_DWORD *)(*v1 + 24) || v12 <= *(_DWORD *)(*v1 + 24) - v13 ) /*0x1799db*/
        break; /*0x1799db*/
      v11 = *(_DWORD *)(*v1 + 24) - v13; /*0x179a05*/
      if ( vm_page_lookup(a1, v11) ) /*0x179a08*/
      {
        do /*0x179a31*/
        {
          while ( vm_page_queue_lock ) /*0x179a1f*/
            ; /*0x179a1d*/
        }
        while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x179a31*/
LABEL_24:
        vm_page_free(v4); /*0x179a33*/
        _InterlockedExchange(&vm_page_queue_lock, 0); /*0x179a3e*/
      }
      else
      {
        vm_page_rename(v4, a1, v11); /*0x179a52*/
      }
    }
    do /*0x1799f9*/
    {
      while ( vm_page_queue_lock ) /*0x1799e7*/
        ; /*0x1799e5*/
    }
    while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x1799f9*/
    goto LABEL_24; /*0x1799f9*/
  }
}
