/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a80ec */

undefined4 FUN_001a80ec(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = 0xfffffd42;
  iVar1 = _IOMalloc(param_4 * 8);
  uVar2 = 0;
  if (param_4 != 0) {
    do {
      *(undefined4 *)(iVar1 + uVar2 * 8) = *(undefined4 *)(param_3 + uVar2 * 8);
      *(undefined4 *)(iVar1 + 4 + uVar2 * 8) = *(undefined4 *)(param_3 + 4 + uVar2 * 8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_4);
  }
  uVar3 = _objc_msgSend(param_1,PTR_s__delegate_001f9c08,
                        PTR_s_allocateRanges_numRanges_forKey__001f9bf8,iVar1,param_4,"Memory Maps")
  ;
  iVar4 = _objc_msgSend(uVar3);
  if (iVar4 != 0) {
    iVar4 = *(int *)(param_1 + 0x10);
    if (*(int *)(iVar4 + 0xc) != 0) {
      _IOFree(*(undefined4 *)(iVar4 + 8),*(int *)(iVar4 + 0xc) << 3);
    }
    *(undefined4 *)(iVar4 + 0xc) = 0;
    local_8 = 0;
  }
  _IOFree(iVar1,param_4 * 8);
  return local_8;
}

