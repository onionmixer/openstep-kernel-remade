/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1592ac. */
int __cdecl thread_handoff(int a1, int a2, int a3)
{
  int v3; // edi
  volatile __int32 *v4; // edx
  volatile __int32 *v6; // edx
  int v7; // eax

  v3 = splsched(); /*0x1592bd*/
  v4 = (volatile __int32 *)(a3 + 32); /*0x1592bf*/
  do /*0x1592d6*/
  {
    while ( *v4 ) /*0x1592c4*/
      ; /*0x1592c6*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x1592d6*/
  if ( *(_DWORD *)(a1 + 48) == active_stacks || *(_DWORD *)(a3 + 76) != 257 ) /*0x1592e9*/
  {
    _InterlockedExchange((volatile __int32 *)(a3 + 32), 0); /*0x1592ed*/
    splx(v3); /*0x1592f1*/
    ++c_thread_handoff_misses; /*0x1592f6*/
    return 0; /*0x1592fe*/
  }
  if ( *(_DWORD *)(a3 + 324) ) /*0x159304*/
    reset_timeout(a3 + 280); /*0x159314*/
  *(_DWORD *)(a3 + 76) = 4; /*0x15931c*/
  _InterlockedExchange((volatile __int32 *)(a3 + 32), 0); /*0x159325*/
  need_ast[0] = *(_DWORD *)(a3 + 380) | need_ast[0] & 0xBFFFFFFC; /*0x159338*/
  switch_unix_context(a3); /*0x159343*/
  stack_handoff(a1, a3); /*0x15934a*/
  v6 = (volatile __int32 *)(a1 + 32); /*0x15934f*/
  do /*0x15936a*/
  {
    while ( *v6 ) /*0x159358*/
      ; /*0x15935a*/
  }
  while ( _InterlockedExchange(v6, 1) == 1 ); /*0x15936a*/
  *(_DWORD *)(a1 + 52) = a2; /*0x15936f*/
  v7 = *(_DWORD *)(a1 + 76); /*0x159372*/
  if ( v7 == 4 ) /*0x159378*/
  {
    *(_DWORD *)(a1 + 76) = 257; /*0x15937a*/
LABEL_18:
    _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1593c1*/
    goto LABEL_19; /*0x1593c3*/
  }
  if ( v7 != 6 ) /*0x159387*/
    panic(aThreadHandoff); /*0x1593b9*/
  *(_DWORD *)(a1 + 76) = 259; /*0x159389*/
  if ( !*(_DWORD *)(a1 + 72) ) /*0x159394*/
    goto LABEL_18; /*0x159394*/
  *(_DWORD *)(a1 + 72) = 0; /*0x159396*/
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x15939f*/
  thread_wakeup_prim(a1 + 72, 0, 0); /*0x1593aa*/
LABEL_19:
  splx(v3); /*0x1593c6*/
  ++c_thread_handoff_hits; /*0x1593cc*/
  return 1; /*0x1593da*/
}
