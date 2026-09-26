/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a803c */

undefined4 FUN_001a803c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar1 + 0xc) == 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s__delegate_001f9c08,PTR_s_resourcesForKey__001f9344,
                          "Memory Maps",iVar1 + 0xc);
    uVar2 = _objc_msgSend(uVar2);
    uVar2 = _objc_msgSend(param_1,PTR_s__fetchRangeList_returnedNum__001f9bfc,uVar2);
    *(undefined4 *)(iVar1 + 8) = uVar2;
  }
  return *(undefined4 *)(iVar1 + 8);
}

