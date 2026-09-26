/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162f20. */
int __cdecl assert_wait(int a1, int a2)
{
  thread_act_t v2; // ebx
  int v3; // edx
  volatile __int32 *v4; // edx
  volatile __int32 *v5; // edx
  int *v7; // [esp+Ch] [ebp-Ch]
  int *v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v2 = active_threads; /*0x162f2c*/
  if ( *(_DWORD *)(active_threads + 60) )
  {
    printf("assert_wait: already asserted event 0x%x\n", *(_DWORD *)(active_threads + 60));
    panic(aAssertWait); /*0x162f49*/
  }
  v9 = splsched(); /*0x162f56*/
  if ( a1 ) /*0x162f5b*/
  {
    if ( a1 < 0 ) /*0x162f61*/
      v3 = ~a1 % 59; /*0x162f7a*/
    else
      v3 = a1 % 59; /*0x162f6b*/
    v8 = &wait_queue[2 * v3]; /*0x162f83*/
    v7 = &wait_lock[v3]; /*0x162f8d*/
    do /*0x162fa8*/
    {
      while ( *v7 ) /*0x162f93*/
        ; /*0x162f95*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x162fa8*/
    v4 = (volatile __int32 *)(v2 + 32); /*0x162faa*/
    do /*0x162fc2*/
    {
      while ( *v4 ) /*0x162fb0*/
        ; /*0x162fb2*/
    }
    while ( _InterlockedExchange(v4, 1) == 1 ); /*0x162fc2*/
    *(_DWORD *)v2 = v8; /*0x162fc7*/
    *(_DWORD *)(v2 + 4) = v8[1]; /*0x162fcc*/
    **(_DWORD **)(v2 + 4) = v2; /*0x162fd2*/
    v8[1] = v2; /*0x162fd4*/
    *(_DWORD *)(v2 + 60) = a1; /*0x162fd7*/
    if ( a2 ) /*0x162fde*/
      *(_BYTE *)(v2 + 76) |= 1u; /*0x162fe0*/
    else
      *(_BYTE *)(v2 + 76) |= 9u; /*0x162fe8*/
    _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x162fee*/
    _InterlockedExchange(v7, 0); /*0x162ff6*/
  }
  else
  {
    v5 = (volatile __int32 *)(v2 + 32); /*0x162ffc*/
    do /*0x163012*/
    {
      while ( *v5 ) /*0x163000*/
        ; /*0x163002*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x163012*/
    if ( a2 ) /*0x163018*/
      *(_BYTE *)(v2 + 76) |= 1u; /*0x16301a*/
    else
      *(_BYTE *)(v2 + 76) |= 9u; /*0x163020*/
    _InterlockedExchange((volatile __int32 *)(v2 + 32), 0); /*0x163026*/
  }
  return splx(v9); /*0x163035*/
}
