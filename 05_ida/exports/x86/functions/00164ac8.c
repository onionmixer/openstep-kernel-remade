/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164ac8. */
void __noreturn sched_thread_continue()
{
  thread_act_t v0; // ebx
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v3; // esi
  int *v4; // ebx
  int v5; // edi
  int v6; // eax
  thread_act_t v7; // eax

  while ( 1 )
  {
    compute_mach_factor(); /*0x164ad0*/
    if ( (sched_tick & 1) != 0 ) /*0x164adc*/
      do_thread_scan(); /*0x164ade*/
    v0 = active_threads; /*0x164ae3*/
    if ( *(_DWORD *)(active_threads + 60) )
    {
      printf("assert_wait: already asserted event 0x%x\n", *(_DWORD *)(active_threads + 60));
      panic(aAssertWait); /*0x164b00*/
    }
    v1 = splsched(); /*0x164b0d*/
    v2 = (volatile __int32 *)(v0 + 32); /*0x164b0f*/
    do /*0x164b26*/
    {
      while ( *v2 ) /*0x164b14*/
        ; /*0x164b16*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x164b26*/
    *(_BYTE *)(v0 + 76) |= 9u; /*0x164b28*/
    _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x164b2e*/
    splx(v1); /*0x164b32*/
    v3 = active_threads; /*0x164b3a*/
    v4 = (int *)processor_ptr[0]; /*0x164b40*/
    v5 = splsched(); /*0x164b4b*/
    v6 = need_ast[0]; /*0x164b4d*/
    LOBYTE(v6) = need_ast[0] & 0xFB; /*0x164b52*/
    need_ast[0] = v6; /*0x164b54*/
    do /*0x164b7a*/
      v7 = thread_select(v4); /*0x164b61*/
    while ( !thread_invoke(v3, (int)sched_thread_continue, v7) ); /*0x164b7a*/
    splx(v5); /*0x164b7d*/
  }
}
