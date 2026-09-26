/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9220 */

void _IOExitThread(void)

{
  thread_act_t target_act;
  
  target_act = _current_thread_EXTERNAL();
  _thread_terminate(target_act);
  _thread_halt_self();
  return;
}

