/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001639ec */

void _thread_continue(int param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(_active_threads + 0x34);
  if (param_1 != 0) {
    _thread_dispatch(param_1);
  }
  _spl0();
  (*pcVar1)();
  return;
}

