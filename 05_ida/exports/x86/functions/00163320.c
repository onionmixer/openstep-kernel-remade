/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163320. */
int __cdecl thread_sleep(int a1, volatile __int32 *a2, int a3)
{
  thread_act_t v3; // ebx
  int v4; // edx
  volatile __int32 *v5; // edx
  volatile __int32 *v6; // edx
  int *v8; // [esp+Ch] [ebp-Ch]
  int *v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v3 = active_threads; /*0x16332c*/
  if ( *(_DWORD *)(active_threads + 60) )
  {
    printf("assert_wait: already asserted event 0x%x\n", *(_DWORD *)(active_threads + 60));
    panic(aAssertWait); /*0x163349*/
  }
  v10 = splsched(); /*0x163356*/
  if ( a1 ) /*0x16335b*/
  {
    if ( a1 < 0 ) /*0x163361*/
      v4 = ~a1 % 59; /*0x16337a*/
    else
      v4 = a1 % 59; /*0x16336b*/
    v9 = &wait_queue[2 * v4]; /*0x163383*/
    v8 = &wait_lock[v4]; /*0x16338d*/
    do /*0x1633a8*/
    {
      while ( *v8 ) /*0x163393*/
        ; /*0x163395*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x1633a8*/
    v5 = (volatile __int32 *)(v3 + 32); /*0x1633aa*/
    do /*0x1633c2*/
    {
      while ( *v5 ) /*0x1633b0*/
        ; /*0x1633b2*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1633c2*/
    *(_DWORD *)v3 = v9; /*0x1633c7*/
    *(_DWORD *)(v3 + 4) = v9[1]; /*0x1633cc*/
    **(_DWORD **)(v3 + 4) = v3; /*0x1633d2*/
    v9[1] = v3; /*0x1633d4*/
    *(_DWORD *)(v3 + 60) = a1; /*0x1633d7*/
    if ( a3 ) /*0x1633de*/
      *(_BYTE *)(v3 + 76) |= 1u; /*0x1633e0*/
    else
      *(_BYTE *)(v3 + 76) |= 9u; /*0x1633e8*/
    _InterlockedExchange((volatile __int32 *)(v3 + 32), 0); /*0x1633ee*/
    _InterlockedExchange(v8, 0); /*0x1633f6*/
  }
  else
  {
    v6 = (volatile __int32 *)(v3 + 32); /*0x1633fc*/
    do /*0x163412*/
    {
      while ( *v6 ) /*0x163400*/
        ; /*0x163402*/
    }
    while ( _InterlockedExchange(v6, 1) == 1 ); /*0x163412*/
    if ( a3 ) /*0x163418*/
      *(_BYTE *)(v3 + 76) |= 1u; /*0x16341a*/
    else
      *(_BYTE *)(v3 + 76) |= 9u; /*0x163420*/
    _InterlockedExchange((volatile __int32 *)(v3 + 32), 0); /*0x163426*/
  }
  splx(v10); /*0x16342d*/
  _InterlockedExchange(a2, 0); /*0x16343a*/
  return thread_block_with_continuation(0); /*0x163446*/
}
