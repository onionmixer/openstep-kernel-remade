/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a3c4 */

uint _fp_kernel_extension_fault(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_001e75f8;
  uVar2 = FUN_0018a428();
  uVar3 = *(uint *)(iVar1 + 0x17c) | 0x40000000;
  *(uint *)(iVar1 + 0x17c) = uVar3;
  if (_active_threads == iVar1) {
    uVar2 = _need_ast | uVar3;
    _need_ast = uVar2;
  }
  return uVar2;
}

