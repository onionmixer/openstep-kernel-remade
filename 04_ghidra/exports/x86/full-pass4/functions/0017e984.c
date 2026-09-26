/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e984 */

int FUN_0017e984(int param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  if (((param_3 < uVar2) || (uVar2 + *(int *)(param_1 + 8) <= param_3)) ||
     (piVar1 = (int *)(*(int *)(param_1 + 0x18) + (param_3 - uVar2) * 4), *piVar1 != 0)) {
    iVar3 = 0;
  }
  else {
    uVar4 = _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_alloc_001f9210,
                          PTR_s_initForResource_item_shareable__001f9254,param_1,param_3,0);
    iVar3 = _objc_msgSend(uVar4);
    *piVar1 = iVar3;
    if ((iVar3 != 0) &&
       (iVar3 = *(int *)(param_1 + 0x14), *(int *)(param_1 + 0x14) = iVar3 + 1, iVar3 == 0)) {
      _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__resourceActive_001f9258);
    }
    iVar3 = *piVar1;
  }
  return iVar3;
}

