/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1681c0. */
kern_return_t __cdecl thread_info(
        thread_inspect_t target_act,
        thread_flavor_t flavor,
        thread_info_t thread_info_out,
        mach_msg_type_number_t *thread_info_outCnt)
{
  int v4; // edi
  volatile __int32 *v5; // edx
  int v6; // eax
  int v7; // edx
  integer_t v8; // eax
  int v10; // edi
  volatile __int32 *v11; // edx
  int v12; // eax
  integer_t v13; // [esp+Ch] [ebp-4h]

  if ( !target_act ) /*0x1681d4*/
    return 4; /*0x1681d4*/
  if ( flavor != 1 ) /*0x1681dd*/
  {
    if ( flavor != 2 ) /*0x16830f*/
      return 4; /*0x1683b8*/
    if ( *thread_info_outCnt > 6 ) /*0x16831b*/
    {
      v10 = splsched(); /*0x16832f*/
      v11 = (volatile __int32 *)(target_act + 32); /*0x168331*/
      do /*0x168346*/
      {
        while ( *v11 ) /*0x168334*/
          ; /*0x168336*/
      }
      while ( _InterlockedExchange(v11, 1) == 1 ); /*0x168346*/
      *thread_info_out = *(_DWORD *)(target_act + 96); /*0x16834b*/
      v12 = *(_DWORD *)(target_act + 96); /*0x16834d*/
      if ( v12 == 2 || v12 == 4 ) /*0x168358*/
        thread_info_out[1] = tick * *(_DWORD *)(target_act + 92) / 1000; /*0x16836c*/
      else
        thread_info_out[1] = 0; /*0x168374*/
      thread_info_out[2] = *(_DWORD *)(target_act + 80); /*0x16837e*/
      thread_info_out[3] = *(_DWORD *)(target_act + 84); /*0x168384*/
      thread_info_out[4] = *(_DWORD *)(target_act + 88); /*0x16838a*/
      thread_info_out[5] = *(_DWORD *)(target_act + 100) >= 0; /*0x168395*/
      thread_info_out[6] = *(_DWORD *)(target_act + 100); /*0x16839b*/
      _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1683a0*/
      splx(v10); /*0x1683a4*/
      *thread_info_outCnt = 7; /*0x1683ac*/
      return 0; /*0x1683b4*/
    }
    return 4; /*0x168322*/
  }
  if ( *thread_info_outCnt <= 0xA ) /*0x1681e9*/
    return 4; /*0x1681e9*/
  v4 = splsched(); /*0x1681f6*/
  v5 = (volatile __int32 *)(target_act + 32); /*0x1681f8*/
  do /*0x16820e*/
  {
    while ( *v5 ) /*0x1681fc*/
      ; /*0x1681fe*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x16820e*/
  if ( (*(_BYTE *)(target_act + 76) & 4) == 0 && *(_DWORD *)(target_act + 112) != sched_tick ) /*0x16821e*/
    update_priority((_DWORD *)target_act); /*0x168221*/
  thread_read_times(target_act, thread_info_out, thread_info_out + 2); /*0x16822f*/
  thread_info_out[5] = *(_DWORD *)(target_act + 80); /*0x168237*/
  thread_info_out[6] = *(_DWORD *)(target_act + 88); /*0x16823d*/
  thread_info_out[4] = (int)(3 * (*(_DWORD *)(target_act + 104) / 0x3E8u)) / 5; /*0x168257*/
  v6 = *(_DWORD *)(target_act + 76); /*0x16825a*/
  if ( (v6 & 0x100) != 0 ) /*0x168263*/
  {
    v13 = 1; /*0x168265*/
  }
  else
  {
    v13 = 0; /*0x168270*/
    if ( (v6 & 0x80u) != 0 ) /*0x168279*/
      v13 = 2; /*0x16827b*/
  }
  v7 = *(_DWORD *)(target_act + 76); /*0x168282*/
  if ( (v7 & 0x10) != 0 ) /*0x168288*/
  {
    v8 = 5; /*0x16828a*/
  }
  else if ( (v7 & 4) != 0 ) /*0x168297*/
  {
    v8 = 1; /*0x168299*/
  }
  else if ( (v7 & 8) != 0 ) /*0x1682a3*/
  {
    v8 = 4; /*0x1682a5*/
  }
  else if ( (v7 & 2) != 0 ) /*0x1682af*/
  {
    v8 = 2; /*0x1682b1*/
  }
  else
  {
    v8 = 0; /*0x1682b8*/
    if ( (v7 & 1) != 0 ) /*0x1682bd*/
      v8 = 3; /*0x1682bf*/
  }
  thread_info_out[7] = v8; /*0x1682c4*/
  thread_info_out[8] = v13; /*0x1682ca*/
  thread_info_out[9] = *(_DWORD *)(target_act + 140); /*0x1682d3*/
  if ( v8 == 1 ) /*0x1682d9*/
    thread_info_out[10] = 0; /*0x1682db*/
  else
    thread_info_out[10] = sched_tick - *(_DWORD *)(target_act + 112); /*0x1682ed*/
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x1682f2*/
  splx(v4); /*0x1682f6*/
  *thread_info_outCnt = 11; /*0x1682fe*/
  return 0; /*0x1683c0*/
}
