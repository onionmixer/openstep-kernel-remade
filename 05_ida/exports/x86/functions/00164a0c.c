/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x164a0c. */
void __noreturn idle_thread()
{
  thread_act_t v0; // ebx
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v3; // esi
  int *v4; // ebx
  int v5; // edi
  int v6; // eax
  thread_act_t v7; // eax

  v0 = active_threads; /*0x164a12*/
  stack_privilege(active_threads); /*0x164a19*/
  v1 = splsched(); /*0x164a23*/
  *(_DWORD *)(v0 + 80) = 0; /*0x164a25*/
  *(_DWORD *)(v0 + 88) = 0; /*0x164a2c*/
  v2 = (volatile __int32 *)(v0 + 32); /*0x164a33*/
  while ( 1 ) /*0x164a3c*/
  {
    while ( *v2 ) /*0x164a3c*/
      ; /*0x164a3e*/
    if ( _InterlockedExchange(v2, 1) != 1 ) /*0x164a49*/
    {
      *(_BYTE *)(v0 + 76) |= 0x80u; /*0x164a50*/
      _InterlockedExchange((volatile __int32 *)(v0 + 32), 0); /*0x164a56*/
      *(_DWORD *)(processor_ptr[0] + 284) = v0; /*0x164a5e*/
      splx(v1); /*0x164a65*/
      v3 = active_threads; /*0x164a6d*/
      v4 = (int *)processor_ptr[0]; /*0x164a73*/
      v5 = splsched(); /*0x164a7e*/
      v6 = need_ast[0]; /*0x164a80*/
      LOBYTE(v6) = need_ast[0] & 0xFB; /*0x164a85*/
      need_ast[0] = v6; /*0x164a87*/
      do /*0x164aae*/
        v7 = thread_select(v4); /*0x164a95*/
      while ( !thread_invoke(v3, (int)idle_thread_continue, v7) ); /*0x164aae*/
      splx(v5); /*0x164ab1*/
      idle_thread_continue(); /*0x164ab9*/
    }
  }
}
