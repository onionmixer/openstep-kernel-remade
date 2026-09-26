/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178d60. */
int __cdecl vm_object_terminate(int *a1)
{
  int v1; // ebx
  volatile __int32 *v2; // edx
  int *v3; // eax
  volatile __int32 *v4; // ebx
  int *v5; // ecx
  int *v6; // edx
  int *v7; // eax
  int v8; // edx
  int *v9; // eax
  int *v10; // ebx
  int v11; // ecx
  int *v12; // edx
  int *v13; // eax

  v1 = a1[8]; /*0x178d69*/
  if ( v1 ) /*0x178d6e*/
  {
    v2 = (volatile __int32 *)(v1 + 16); /*0x178d70*/
    do /*0x178d86*/
    {
      while ( *v2 ) /*0x178d74*/
        ; /*0x178d76*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x178d86*/
    v3 = *(int **)(v1 + 28); /*0x178d88*/
    if ( v3 == a1 ) /*0x178d8d*/
    {
      *(_DWORD *)(v1 + 28) = 0; /*0x178d8f*/
    }
    else if ( v3 ) /*0x178da6*/
    {
      panic(aVmObjectTermin); /*0x178dad*/
    }
    _InterlockedExchange((volatile __int32 *)(v1 + 16), 0); /*0x178db7*/
  }
  if ( *((_WORD *)a1 + 34) ) /*0x178dba*/
  {
    v4 = a1 + 4; /*0x178dc1*/
    do /*0x178de4*/
    {
      thread_sleep(a1, a1 + 4, 0); /*0x178dc8*/
      do /*0x178de2*/
      {
        while ( *v4 ) /*0x178dd0*/
          ; /*0x178dd2*/
      }
      while ( _InterlockedExchange(v4, 1) == 1 ); /*0x178de2*/
    }
    while ( *((_WORD *)a1 + 34) ); /*0x178de4*/
  }
  v5 = (int *)*a1; /*0x178deb*/
  if ( a1 != (int *)*a1 ) /*0x178def*/
  {
    do /*0x178eaa*/
    {
      do /*0x178e11*/
      {
        while ( vm_page_queue_lock ) /*0x178dff*/
          ; /*0x178dfd*/
      }
      while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x178e11*/
      if ( (*((_BYTE *)v5 + 30) & 2) != 0 ) /*0x178e17*/
      {
        v6 = (int *)*v5; /*0x178e19*/
        v7 = (int *)v5[1]; /*0x178e1b*/
        if ( (int *)*v5 == &vm_page_queue_active ) /*0x178e24*/
          dword_1F6E44 = v5[1]; /*0x178e26*/
        else
          v6[1] = (int)v7; /*0x178e30*/
        if ( v7 == &vm_page_queue_active ) /*0x178e38*/
          vm_page_queue_active = (int)v6; /*0x178e3a*/
        else
          *v7 = (int)v6; /*0x178e44*/
        *((_BYTE *)v5 + 30) &= ~2u; /*0x178e46*/
        --vm_page_active_count; /*0x178e4a*/
      }
      if ( (*((_BYTE *)v5 + 30) & 1) != 0 ) /*0x178e54*/
      {
        v8 = *v5; /*0x178e56*/
        v9 = (int *)v5[1]; /*0x178e58*/
        if ( (int *)*v5 == &vm_page_queue_inactive ) /*0x178e61*/
          dword_1F64E4 = v5[1]; /*0x178e63*/
        else
          *(_DWORD *)(v8 + 4) = v9; /*0x178e6c*/
        if ( v9 == &vm_page_queue_inactive ) /*0x178e74*/
          vm_page_queue_inactive = v8; /*0x178e76*/
        else
          *v9 = v8; /*0x178e80*/
        *((_BYTE *)v5 + 30) &= ~1u; /*0x178e82*/
        --vm_page_inactive_count; /*0x178e86*/
      }
      v10 = (int *)v5[2]; /*0x178e8c*/
      if ( (*((_BYTE *)v5 + 30) & 8) != 0 ) /*0x178e93*/
        vm_page_free(v5); /*0x178e96*/
      _InterlockedExchange(&vm_page_queue_lock, 0); /*0x178ea0*/
      v5 = v10; /*0x178ea6*/
    }
    while ( a1 != v10 ); /*0x178eaa*/
  }
  _InterlockedExchange(a1 + 4, 0); /*0x178eb2*/
  if ( a1[10] ) /*0x178eb5*/
    vm_pager_deallocate(a1[10]); /*0x178ebd*/
  if ( *((_WORD *)a1 + 34) ) /*0x178ec5*/
    panic(aVmObjectDeallo); /*0x178ed1*/
  while ( (int *)*a1 != a1 ) /*0x178f0e*/
  {
    v11 = *a1; /*0x178edc*/
    do /*0x178ef9*/
    {
      while ( vm_page_queue_lock ) /*0x178ee7*/
        ; /*0x178ee5*/
    }
    while ( _InterlockedExchange(&vm_page_queue_lock, 1) == 1 ); /*0x178ef9*/
    vm_page_free(v11); /*0x178efc*/
    _InterlockedExchange(&vm_page_queue_lock, 0); /*0x178f06*/
  }
  do /*0x178f2c*/
  {
    while ( vm_object_list_lock ) /*0x178f1a*/
      ; /*0x178f18*/
  }
  while ( _InterlockedExchange(&vm_object_list_lock, 1) == 1 ); /*0x178f2c*/
  v12 = (int *)a1[2]; /*0x178f2e*/
  v13 = (int *)a1[3]; /*0x178f31*/
  if ( v12 == &vm_object_list ) /*0x178f3a*/
    dword_1F7354 = a1[3]; /*0x178f3c*/
  else
    v12[3] = (int)v13; /*0x178f44*/
  if ( v13 == &vm_object_list ) /*0x178f4c*/
    vm_object_list = (int)v12; /*0x178d98*/
  else
    v13[2] = (int)v12; /*0x178f52*/
  --vm_object_count; /*0x178f55*/
  _InterlockedExchange(&vm_object_list_lock, 0); /*0x178f5d*/
  return zfree(vm_object_zone, a1); /*0x178f73*/
}
