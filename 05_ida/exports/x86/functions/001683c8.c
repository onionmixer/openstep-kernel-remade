/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1683c8. */
kern_return_t __cdecl thread_abort(thread_act_t target_act)
{
  int v2; // esi
  volatile __int32 *v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // edx

  if ( !target_act || active_threads == target_act ) /*0x1683da*/
    return 4; /*0x1683dc*/
  if ( thread_halt(target_act, 0) ) /*0x1683eb*/
    return 14; /*0x1683f7*/
  mach_msg_abort_rpc(target_act); /*0x168401*/
  v2 = splsched(); /*0x16840e*/
  v3 = (volatile __int32 *)(target_act + 32); /*0x168410*/
  do /*0x168426*/
  {
    while ( *v3 ) /*0x168414*/
      ; /*0x168416*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x168426*/
  v4 = *(_DWORD *)(target_act + 64); /*0x168428*/
  *(_DWORD *)(target_act + 64) = v4 - 1; /*0x16842e*/
  if ( v4 == 1 ) /*0x168434*/
  {
    v5 = *(_DWORD *)(target_act + 76); /*0x168436*/
    v6 = v5; /*0x168439*/
    LOBYTE(v6) = v5 & 0xED; /*0x16843b*/
    *(_DWORD *)(target_act + 76) = v6; /*0x16843e*/
    if ( (v5 & 5) == 0 ) /*0x168443*/
    {
      LOBYTE(v6) = v5 & 0xE9 | 4; /*0x168445*/
      *(_DWORD *)(target_act + 76) = v6; /*0x168448*/
      thread_setrun((char **)target_act, 1); /*0x16844e*/
    }
  }
  _InterlockedExchange((volatile __int32 *)(target_act + 32), 0); /*0x168458*/
  splx(v2); /*0x16845c*/
  if ( *(_DWORD *)(target_act + 100) != -1 ) /*0x168468*/
    thread_depress_abort(target_act); /*0x16846b*/
  return 0; /*0x168475*/
}
