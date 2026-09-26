/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163a70 */

void _thread_run(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = _processor_ptr;
  uVar1 = _active_threads;
  uVar3 = _splsched();
  while( true ) {
    iVar4 = _thread_invoke(uVar1,param_1,param_2);
    if (iVar4 != 0) break;
    param_2 = _thread_select(uVar2);
  }
  _splx(uVar3);
  return;
}

