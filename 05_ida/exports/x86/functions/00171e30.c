/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x171e30. */
int ux_handler_init()
{
  task_t v0; // eax

  dword_1E7280 = 0; /*0x171e33*/
  ux_exception_port = 0; /*0x171e3d*/
  v0 = kernel_task_create(kernel_task, 0); /*0x171e50*/
  kernel_thread(v0, (int)sub_171CB4, 0); /*0x171e5d*/
  do /*0x171e81*/
  {
    while ( dword_1E7280 ) /*0x171e6f*/
      ; /*0x171e6d*/
  }
  while ( _InterlockedExchange(&dword_1E7280, 1) == 1 ); /*0x171e81*/
  if ( ux_exception_port ) /*0x171e8a*/
    return _InterlockedExchange(&dword_1E7280, 0); /*0x171ea6*/
  else
    return thread_sleep((int)&ux_exception_port, &dword_1E7280, 0); /*0x171e98*/
}
