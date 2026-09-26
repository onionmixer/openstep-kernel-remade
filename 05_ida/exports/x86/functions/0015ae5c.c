/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ae5c. */
int *allocStack()
{
  int v0; // edi
  int *v1; // edx
  int *v2; // ebx
  int *v3; // ebx
  int v4; // eax
  _DWORD *v5; // ebx
  int i; // esi
  int v7; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h] BYREF

  v9 = 0; /*0x15ae65*/
  v0 = 0; /*0x15ae6c*/
  v10 = 0; /*0x15ae6e*/
  do
  {
    lock_write((int)&stack_queue_lock); /*0x15ae7d*/
    if ( dword_1DED68 ) /*0x15ae8c*/
    {
      v1 = (int *)dword_1E5B98; /*0x15ae8e*/
      if ( (int *)dword_1E5B98 == &dword_1E5B98 ) /*0x15ae9a*/
      {
        v2 = nullptr; /*0x15ae9c*/
      }
      else
      {
        *(_DWORD *)(*(_DWORD *)dword_1E5B98 + 4) = &dword_1E5B98; /*0x15aea2*/
        dword_1E5B98 = *v1; /*0x15aeab*/
        v2 = v1; /*0x15aeb1*/
      }
      v2[2] = 2; /*0x15aeb3*/
      v3 = v2 + 3; /*0x15aeba*/
      --dword_1DED68; /*0x15aebd*/
      --dword_1F63B8; /*0x15aec3*/
      ++dword_1F63B4; /*0x15aec9*/
    }
    else
    {
      v3 = nullptr; /*0x15aed4*/
    }
    lock_done(&stack_queue_lock); /*0x15aedb*/
    if ( v3 ) /*0x15aee5*/
      goto LABEL_27; /*0x15aee5*/
    if ( kmem_alloc_wired(kernel_map, &v11, dword_1E5BA0) ) /*0x15aefd*/
      goto LABEL_19; /*0x15aefd*/
    ++stackStats; /*0x15af0d*/
    v4 = v11; /*0x15af13*/
    *(_DWORD *)(v11 + 8) = 2; /*0x15af16*/
    ++dword_1F63B4; /*0x15af1d*/
    stack_init(v4 + 12); /*0x15af27*/
    if ( dword_1E5BA4 > 1 ) /*0x15af36*/
    {
      lock_write((int)&stack_queue_lock); /*0x15af49*/
      v5 = (_DWORD *)(dword_1E5BA0 + v11); /*0x15af51*/
      for ( i = 1; dword_1E5BA4 > i; ++i ) /*0x15af65*/
      {
        stack_init(v5 + 3); /*0x15af6c*/
        v5[2] = 0; /*0x15af74*/
        v7 = dword_1E5B9C; /*0x15af7b*/
        if ( (int *)dword_1E5B9C == &dword_1E5B98 ) /*0x15af85*/
          dword_1E5B98 = (int)v5; /*0x15af87*/
        else
          *(_DWORD *)dword_1E5B9C = v5; /*0x15af90*/
        v5[1] = v7; /*0x15af92*/
        *v5 = &dword_1E5B98; /*0x15af95*/
        dword_1E5B9C = (int)v5; /*0x15af9b*/
        ++dword_1DED68; /*0x15afa1*/
        ++dword_1F63B8; /*0x15afa7*/
        v5 = (_DWORD *)((char *)v5 + dword_1E5BA0); /*0x15afad*/
      }
      lock_done(&stack_queue_lock); /*0x15afc1*/
      v3 = (int *)(v11 + 12); /*0x15afc9*/
    }
    else
    {
      v3 = (int *)(v11 + 12); /*0x15af3b*/
    }
    if ( v3 )
    {
LABEL_27:
      if ( v9 ) /*0x15b070*/
        uprintf(aContinuing_0); /*0x15b077*/
    }
    else
    {
LABEL_19:
      if ( v9 )
      {
        if ( v0 ) /*0x15afdf*/
          return (int *)v10; /*0x15afdf*/
      }
      else
      {
        v9 = 1; /*0x15afe8*/
        uprintf(aMachOutOfKerne); /*0x15aff4*/
        if ( !dword_1DED70 )
          printf("stack_alloc: Kernel stacks exhausted\n");
      }
      lock_write((int)&stack_queue_lock); /*0x15b017*/
      if ( dword_1DED68 ) /*0x15b026*/
      {
        lock_done(&stack_queue_lock); /*0x15b02d*/
        v0 = 0; /*0x15b032*/
      }
      else
      {
        assert_wait(&dword_1E5B98, 0); /*0x15b03f*/
        dword_1DED70 = 1; /*0x15b044*/
        lock_done(&stack_queue_lock); /*0x15b053*/
        thread_block(); /*0x15b058*/
        v0 = *(_DWORD *)(active_threads + 68); /*0x15b062*/
      }
    }
  }
  while ( !v3 );
  return v3; /*0x15b090*/
}
