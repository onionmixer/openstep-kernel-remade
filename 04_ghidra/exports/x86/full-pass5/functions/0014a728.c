/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014a728 */

void _ipc_mqueue_changed(int param_1,undefined4 param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = _ipc_thread_dequeue(param_1 + 8);
    if (iVar1 == 0) break;
    *(undefined4 *)(iVar1 + 0x98) = param_2;
    _thread_go(iVar1);
  }
  return;
}

