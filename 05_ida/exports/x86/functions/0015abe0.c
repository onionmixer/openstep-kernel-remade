/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15abe0. */
int __cdecl freeStack(int a1)
{
  unsigned int v1; // edi
  int v2; // eax
  int result; // eax
  int v4; // ebx
  int v5; // edx
  int i; // esi
  int **v7; // ebx
  int j; // esi
  int *v9; // edx
  int *v10; // eax

  --dword_1F63B4; /*0x15abe9*/
  v1 = a1 - 12; /*0x15abf2*/
  lock_write((int)&stack_queue_lock); /*0x15abfa*/
  *(_DWORD *)(a1 - 12 + 8) = 0; /*0x15ac02*/
  v2 = dword_1E5B9C; /*0x15ac09*/
  if ( (int *)dword_1E5B9C == &dword_1E5B98 ) /*0x15ac13*/
    dword_1E5B98 = a1 - 12; /*0x15ac15*/
  else
    *(_DWORD *)dword_1E5B9C = v1; /*0x15ac20*/
  *(_DWORD *)(v1 + 4) = v2; /*0x15ac22*/
  *(_DWORD *)v1 = &dword_1E5B98; /*0x15ac25*/
  dword_1E5B9C = a1 - 12; /*0x15ac2b*/
  ++dword_1DED68; /*0x15ac31*/
  ++dword_1F63B8; /*0x15ac37*/
  lock_done(&stack_queue_lock); /*0x15ac42*/
  if ( dword_1DED70 ) /*0x15ac51*/
  {
    dword_1DED70 = 0; /*0x15ac53*/
    thread_wakeup_prim(&dword_1E5B98, 0, 0); /*0x15ac66*/
  }
  result = dword_1DED6C; /*0x15ac6e*/
  if ( dword_1DED68 > dword_1DED6C ) /*0x15ac79*/
  {
    v4 = ~page_mask & v1; /*0x15ac88*/
    v5 = 1; /*0x15ac8d*/
    for ( i = 0; i < dword_1E5BA4; ++i ) /*0x15ac9b*/
    {
      if ( *(_DWORD *)(v4 + 8) ) /*0x15aca8*/
        v5 = 0; /*0x15acae*/
      v4 += dword_1E5BA0; /*0x15acb0*/
    }
    if ( v5 ) /*0x15acba*/
    {
      v7 = (int **)(~page_mask & v1); /*0x15acd8*/
      for ( j = 0; dword_1E5BA4 > j; ++j ) /*0x15ace3*/
      {
        v9 = *v7; /*0x15ace8*/
        v10 = v7[1]; /*0x15acea*/
        if ( *v7 == &dword_1E5B98 ) /*0x15acf3*/
          dword_1E5B9C = (int)v7[1]; /*0x15acf5*/
        else
          v9[1] = (int)v10; /*0x15acfc*/
        if ( v10 == &dword_1E5B98 ) /*0x15ad04*/
          dword_1E5B98 = (int)v9; /*0x15ad06*/
        else
          *v10 = (int)v9; /*0x15ad10*/
        --dword_1DED68; /*0x15ad12*/
        --dword_1F63B8; /*0x15ad18*/
        stack_finalize(v7 + 3); /*0x15ad22*/
        v7 = (int **)((char *)v7 + dword_1E5BA0); /*0x15ad27*/
      }
      result = kmem_free(kernel_map, v1, dword_1E5BA0); /*0x15ad48*/
      --stackStats; /*0x15ad4d*/
    }
    else
    {
      result = canSwap(v1); /*0x15acbd*/
      if ( result ) /*0x15acc7*/
        return doSwapout(v1); /*0x15acce*/
    }
  }
  return result; /*0x15ad56*/
}
