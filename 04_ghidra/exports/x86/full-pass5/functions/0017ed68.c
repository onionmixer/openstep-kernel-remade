/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ed68 */

int FUN_0017ed68(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_10;
  
  local_10 = (int *)(param_1 + 0x18);
  if ((param_3 + param_4 == 0) || (param_3 < param_3 + param_4)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (((bVar2) && (*(uint *)(param_1 + 8) <= param_3)) &&
     ((*(uint *)(param_1 + 0xc) == 0 || (param_3 + param_4 <= *(uint *)(param_1 + 0xc))))) {
    while ((iVar1 = *local_10, iVar1 != 0 && (*(uint *)(iVar1 + 0xc) < param_3 + param_4))) {
      if (param_3 < *(uint *)(iVar1 + 0x10)) {
        return 0;
      }
      local_10 = (int *)(iVar1 + 4);
    }
    uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_alloc_001f9210,
                          PTR_s_initForResource_range_shareable__001f9270,param_1,param_3,param_4,0)
    ;
    iVar3 = _objc_msgSend(uVar4);
    if (iVar3 != 0) {
      *(int *)(iVar3 + 4) = iVar1;
      *local_10 = iVar3;
      iVar1 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x14) = iVar1 + 1;
      if (iVar1 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__resourceActive_001f9258);
      }
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

