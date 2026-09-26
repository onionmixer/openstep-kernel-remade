/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163a18 */

void _thread_block_with_continuation(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar2 = _processor_ptr;
  uVar1 = _active_threads;
  uVar3 = _splsched();
  _need_ast = _need_ast & 0xfffffffb;
  do {
    uVar4 = _thread_select(uVar2);
    iVar5 = _thread_invoke(uVar1,param_1,uVar4);
  } while (iVar5 == 0);
  _splx(uVar3);
  return;
}

