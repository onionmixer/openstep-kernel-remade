/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1688f4. */
kern_return_t __cdecl thread_policy(
        thread_act_t thr_act,
        policy_t policy,
        policy_base_t base,
        mach_msg_type_number_t baseCnt,
        boolean_t set_limit)
{
  int v6; // edi
  int v7; // edi
  volatile __int32 *v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+14h] [ebp-8h]
  kern_return_t v10; // [esp+18h] [ebp-4h]

  v10 = 0; /*0x168906*/
  if ( !thr_act || (unsigned int)(policy - 1) > 3 ) /*0x168917*/
    return 4; /*0x168919*/
  v9 = splsched(); /*0x168929*/
  v8 = (volatile __int32 *)(thr_act + 32); /*0x16892f*/
  do /*0x16894c*/
  {
    while ( *v8 ) /*0x168937*/
      ; /*0x168939*/
  }
  while ( _InterlockedExchange(v8, 1) == 1 ); /*0x16894c*/
  if ( *(_DWORD *)(thr_act + 96) == policy ) /*0x168951*/
  {
    if ( policy == 2 ) /*0x168956*/
    {
      v6 = 1000 * (_DWORD)base; /*0x16896b*/
      if ( 1000 * (int)base % tick ) /*0x168980*/
        v6 += tick; /*0x168986*/
      *(_DWORD *)(thr_act + 92) = v6 / tick; /*0x168991*/
    }
  }
  else if ( (policy & *(_DWORD *)(*(_DWORD *)(thr_act + 384) + 360)) != 0 ) /*0x1689a4*/
  {
    *(_DWORD *)(thr_act + 96) = policy; /*0x1689b0*/
    if ( policy == 2 ) /*0x1689b6*/
    {
      v7 = 1000 * (_DWORD)base; /*0x1689c7*/
      if ( 1000 * (int)base % tick ) /*0x1689dc*/
        v7 += tick; /*0x1689e2*/
      *(_DWORD *)(thr_act + 92) = v7 / tick; /*0x1689ed*/
    }
    compute_priority((_DWORD *)thr_act, 1); /*0x1689f3*/
  }
  else
  {
    v10 = 5; /*0x1689a6*/
  }
  _InterlockedExchange((volatile __int32 *)(thr_act + 32), 0); /*0x1689fd*/
  splx(v9); /*0x168a04*/
  return v10; /*0x168a0f*/
}
