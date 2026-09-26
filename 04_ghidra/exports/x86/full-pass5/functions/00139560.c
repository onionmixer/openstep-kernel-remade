/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139560 */

undefined4 FUN_00139560(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(short *)(param_2 + 0x8a) = *(short *)(param_2 + 0x8a) + -1;
  if (*(undefined4 **)(param_2 + 0x6c) == param_1) {
    *(undefined4 *)(param_2 + 0x6c) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = *param_1;
  }
  _kmem_free(_kernel_map,param_1,DAT_001de6b4);
  if (DAT_001de6b8 <= _fifo_alloc) {
    _wakeup(&_fifo_alloc);
  }
  _fifo_alloc = _fifo_alloc - DAT_001de6b4;
  return uVar1;
}

