/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x166ea0. */
void __cdecl thread_deallocate(int a1)
{
  volatile __int32 *v1; // edx
  int v2; // edi
  volatile __int32 *v3; // edx
  int v4; // ebx
  volatile __int32 *v5; // edx
  volatile __int32 *v6; // edx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // [esp+Ch] [ebp-18h]
  int v14; // [esp+10h] [ebp-14h]
  int v15; // [esp+10h] [ebp-14h]
  _DWORD v16[2]; // [esp+14h] [ebp-10h] BYREF
  _DWORD v17[2]; // [esp+1Ch] [ebp-8h] BYREF

  if ( a1 ) /*0x166eae*/
  {
    v14 = splsched(); /*0x166eb9*/
    v1 = (volatile __int32 *)(a1 + 32); /*0x166ebc*/
    do /*0x166ed2*/
    {
      while ( *v1 ) /*0x166ec0*/
        ; /*0x166ec2*/
    }
    while ( _InterlockedExchange(v1, 1) == 1 ); /*0x166ed2*/
    v2 = *(_DWORD *)(a1 + 36) - 1; /*0x166ed7*/
    *(_DWORD *)(a1 + 36) = v2; /*0x166eda*/
    if ( v2 <= 0 ) /*0x166ee0*/
    {
      *(_DWORD *)(a1 + 36) = 1; /*0x166ef8*/
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x166f01*/
      splx(v14); /*0x166f08*/
      v13 = *(_DWORD *)(a1 + 384); /*0x166f13*/
      v3 = (volatile __int32 *)(v13 + 344); /*0x166f18*/
      do /*0x166f36*/
      {
        while ( *v3 ) /*0x166f24*/
          ; /*0x166f26*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x166f36*/
      v4 = *(_DWORD *)(a1 + 12); /*0x166f38*/
      do /*0x166f4e*/
      {
        while ( *(_DWORD *)v4 ) /*0x166f3c*/
          ; /*0x166f3e*/
      }
      while ( _InterlockedExchange((volatile __int32 *)v4, 1) == 1 ); /*0x166f4e*/
      v15 = splsched(); /*0x166f55*/
      v5 = (volatile __int32 *)(v4 + 40); /*0x166f58*/
      do /*0x166f6e*/
      {
        while ( *v5 ) /*0x166f5c*/
          ; /*0x166f5e*/
      }
      while ( _InterlockedExchange(v5, 1) == 1 ); /*0x166f6e*/
      v6 = (volatile __int32 *)(a1 + 32); /*0x166f70*/
      do /*0x166f86*/
      {
        while ( *v6 ) /*0x166f74*/
          ; /*0x166f76*/
      }
      while ( _InterlockedExchange(v6, 1) == 1 ); /*0x166f86*/
      v7 = *(_DWORD *)(a1 + 36) - 1; /*0x166f8b*/
      *(_DWORD *)(a1 + 36) = v7; /*0x166f8e*/
      if ( v7 <= 0 ) /*0x166f94*/
      {
        if ( *(_DWORD *)(a1 + 324) ) /*0x166fc8*/
          reset_timeout(a1 + 280); /*0x166fd8*/
        if ( *(_DWORD *)(a1 + 372) ) /*0x166fe0*/
          reset_timeout(a1 + 328); /*0x166ff0*/
        *(_DWORD *)(a1 + 100) = -1; /*0x166ff8*/
        thread_read_times(a1, v17, v16); /*0x167008*/
        *(_DWORD *)(v4 + 88) += v17[1]; /*0x167010*/
        *(_DWORD *)(v4 + 84) += v17[0]; /*0x167016*/
        v8 = *(_DWORD *)(v4 + 88); /*0x167019*/
        if ( v8 > 999999 ) /*0x167024*/
        {
          *(_DWORD *)(v4 + 88) = v8 - 1000000; /*0x16702b*/
          ++*(_DWORD *)(v4 + 84); /*0x16702e*/
        }
        *(_DWORD *)(v4 + 96) += v16[1]; /*0x167034*/
        *(_DWORD *)(v4 + 92) += v16[0]; /*0x16703a*/
        v9 = *(_DWORD *)(v4 + 96); /*0x16703d*/
        if ( v9 > 999999 ) /*0x167045*/
        {
          *(_DWORD *)(v4 + 96) = v9 - 1000000; /*0x16704c*/
          ++*(_DWORD *)(v4 + 92); /*0x16704f*/
        }
        --*(_DWORD *)(v4 + 36); /*0x167052*/
        v10 = *(_DWORD *)(a1 + 16); /*0x167055*/
        v11 = *(_DWORD *)(a1 + 20); /*0x167058*/
        if ( v4 + 28 == v10 ) /*0x167060*/
          *(_DWORD *)(v4 + 32) = v11; /*0x167062*/
        else
          *(_DWORD *)(v10 + 20) = v11; /*0x167068*/
        if ( v4 + 28 == v11 ) /*0x167070*/
          *(_DWORD *)(v4 + 28) = v10; /*0x166fc0*/
        else
          *(_DWORD *)(v11 + 16) = v10; /*0x167076*/
        pset_remove_thread((_DWORD *)v13, (_DWORD *)a1); /*0x16707e*/
        _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x167088*/
        _InterlockedExchange((volatile __int32 *)(v4 + 40), 0); /*0x16708d*/
        splx(v15); /*0x167094*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x16709e*/
        _InterlockedExchange((volatile __int32 *)(v13 + 344), 0); /*0x1670a5*/
        pset_deallocate(v13); /*0x1670ac*/
        v12 = *(_DWORD *)(a1 + 124); /*0x1670b4*/
        if ( v12 ) /*0x1670b9*/
          kmem_free(kernel_map, v12, page_size); /*0x1670ca*/
        if ( *(_DWORD *)(a1 + 128) ) /*0x1670d2*/
          vm_object_deallocate(*(_DWORD *)(a1 + 128)); /*0x1670dd*/
        if ( active_threads == a1 ) /*0x1670eb*/
          panic(aThreadDealloca); /*0x1670f2*/
        if ( (*(_DWORD *)(a1 + 76) & 0xFFFFFEEB) != 2 ) /*0x167105*/
          panic(aUnstoppedThrea); /*0x16710c*/
        task_deallocate(*(_DWORD *)(a1 + 12)); /*0x167118*/
        if ( (*(_BYTE *)(a1 + 77) & 1) == 0 ) /*0x167124*/
        {
          splsched(); /*0x167126*/
          stack_free(a1); /*0x16712c*/
          splx(v15); /*0x167135*/
          ++thread_deallocate_stack; /*0x16713a*/
        }
        if ( *(_DWORD *)(a1 + 48) ) /*0x167143*/
          freeStack(*(_DWORD *)(a1 + 48)); /*0x16714b*/
        pcb_terminate(a1); /*0x167154*/
        --nthreads; /*0x167159*/
        uthread_free(*(_DWORD *)(a1 + 132)); /*0x167166*/
        zfree(thread_zone, a1); /*0x167173*/
      }
      else
      {
        _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x166f98*/
        _InterlockedExchange((volatile __int32 *)(v4 + 40), 0); /*0x166f9d*/
        splx(v15); /*0x166fa4*/
        _InterlockedExchange((volatile __int32 *)v4, 0); /*0x166fab*/
        _InterlockedExchange((volatile __int32 *)(v13 + 344), 0); /*0x166fb2*/
      }
    }
    else
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x166ee4*/
      splx(v14); /*0x166eeb*/
    }
  }
}
