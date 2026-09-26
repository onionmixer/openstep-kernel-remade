/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7ed4 */

void FUN_001b7ed4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  while (iVar1 != param_1 + 0x24) {
    _objc_msgSend(param_1,PTR_s_dequeueDescriptor_001f9870);
    iVar1 = *(int *)(param_1 + 0x24);
  }
  _objc_msgSend(param_1,PTR_s_initializeFreeQueue_001f9770);
  return;
}

