/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156c90. */
int exception_no_server()
{
  thread_act_t v0; // ebx

  v0 = active_threads; /*0x156c94*/
  while ( (*(_BYTE *)(v0 + 380) & 3) != 0 ) /*0x156ca1*/
    thread_halt_self(); /*0x156ca4*/
  task_terminate(*(_DWORD *)(v0 + 12)); /*0x156cb6*/
  return thread_halt_self(); /*0x156cc0*/
}
