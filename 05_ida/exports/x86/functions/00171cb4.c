/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x171cb4. */
void __noreturn sub_171CB4()
{
  int v0; // ebx
  int v1; // eax
  int v2; // ebx
  _DWORD v3[22]; // [esp+Ch] [ebp-88h] BYREF
  _DWORD v4[12]; // [esp+64h] [ebp-30h] BYREF

  v0 = *(_DWORD *)(active_threads + 12); /*0x171cc5*/
  *(_DWORD *)(v0 + 80) = 1; /*0x171cc8*/
  dword_1E7284 = task_self(); /*0x171cd4*/
  do /*0x171cf5*/
  {
    while ( dword_1E7280 ) /*0x171ce3*/
      ; /*0x171ce1*/
  }
  while ( _InterlockedExchange(&dword_1E7280, 1) == 1 ); /*0x171cf5*/
  if ( port_set_allocate_EXTERNAL(dword_1E7284) ) /*0x171d02*/
    panic(aUxHandlerPortS); /*0x171d13*/
  if ( port_allocate_EXTERNAL(dword_1E7284) ) /*0x171d26*/
    panic(aUxHandlerPortA); /*0x171d37*/
  if ( port_set_add_EXTERNAL(dword_1E7284) ) /*0x171d4e*/
    panic(aUxHandlerPortS_0); /*0x171d5f*/
  if ( !object_copyin(v0, v4[10], 6, 0, (int)&ux_exception_port) ) /*0x171d75*/
    panic(aUxHandlerObjec); /*0x171d86*/
  thread_wakeup_prim((int)&ux_exception_port, 0, 0); /*0x171d97*/
  _InterlockedExchange(&dword_1E7280, 0); /*0x171da1*/
  task_name(aUxExcept); /*0x171dac*/
  while ( 1 ) /*0x171ddf*/
  {
    while ( 1 ) /*0x171dc3*/
    {
      v3[3] = v4[11]; /*0x171dc3*/
      v3[1] = 88; /*0x171dc6*/
      v1 = msg_receive(v3, 0, 0); /*0x171dd5*/
      if ( v1 ) /*0x171ddf*/
        break; /*0x171ddf*/
      v2 = v3[4]; /*0x171de1*/
      if ( exc_server(v3, (int)v4) ) /*0x171de6*/
        msg_send(v4, 0, 0); /*0x171df7*/
      if ( v2 ) /*0x171e01*/
        port_deallocate_EXTERNAL(dword_1E7284, v2); /*0x171e0b*/
    }
    if ( v1 != -204 ) /*0x171e1d*/
      panic(aExceptionHandl_0); /*0x171e24*/
  }
}
