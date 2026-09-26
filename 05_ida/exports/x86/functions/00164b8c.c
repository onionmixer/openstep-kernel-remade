/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164b8c. */
void __noreturn sched_thread()
{
  thread_act_t v0; // ebx
  int v1; // esi
  volatile __int32 *v2; // edx
  int v3; // esi
  int *v4; // ebx
  int v5; // edi
  int v6; // eax
  thread_act_t v7; // eax

  sched_thread_id = active_threads; /*0x164b98*/
  v0 = active_threads; /*0x164b9e*/
  if ( *(_DWORD *)(active_threads + 60) )
  {
    printf("assert_wait: already asserted event 0x%x\n", *(_DWORD *)(active_threads + 60));
    panic(aAssertWait); /*0x164bbb*/
  }
  v1 = splsched(); /*0x164bc8*/
  v2 = (volatile __int32 *)(v0 + 32); /*0x164bca*/
  while ( 1 ) /*0x164bd0*/
  {
    while ( *v2 ) /*0x164bd0*/
      ; /*0x164bd2*/
    if ( _InterlockedExchange(v2, 1) != 1 ) /*0x164bdd*/
    {
      *(_BYTE *)(v0 + 76) |= 9u; /*0x164be4*/
      _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x164bea*/
      splx(v1); /*0x164bee*/
      v3 = active_threads; /*0x164bf6*/
      v4 = (int *)processor_ptr[0]; /*0x164bfc*/
      v5 = splsched(); /*0x164c07*/
      v6 = need_ast[0]; /*0x164c09*/
      LOBYTE(v6) = need_ast[0] & 0xFB; /*0x164c0e*/
      need_ast[0] = v6; /*0x164c10*/
      do /*0x164c36*/
        v7 = thread_select(v4); /*0x164c1d*/
      while ( !thread_invoke(v3, (int)sched_thread_continue, v7) ); /*0x164c36*/
      splx(v5); /*0x164c39*/
      sched_thread_continue(); /*0x164c41*/
    }
  }
}
