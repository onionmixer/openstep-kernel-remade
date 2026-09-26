/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b73a8 */

void FUN_001b73a8(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_channelBufferAddress_001f97dc);
  *param_3 = uVar1;
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_descriptorSize_001f988c);
  iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_dmaCount_001f98ac);
  *param_4 = iVar2 * iVar3;
  return;
}

