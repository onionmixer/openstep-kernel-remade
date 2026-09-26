/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017efe8 */

undefined4 FUN_0017efe8(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)(param_1 + 0x18);
  cVar4 = _objc_msgSend(param_3,PTR_s_isKindOf__001f9260,*(undefined4 *)(param_1 + 0x10));
  if (cVar4 != '\0') {
    for (iVar2 = *(int *)(param_1 + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      if (param_3 == iVar2) {
        *puVar1 = *(undefined4 *)(iVar2 + 4);
        iVar3 = *(int *)(param_1 + 0x14);
        *(int *)(param_1 + 0x14) = iVar3 + -1;
        if (iVar3 == 1) {
          _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__resourceInactive_001f9264);
        }
        uVar5 = _objc_msgSend(iVar2,PTR_s_dealloc_001f9268);
        return uVar5;
      }
      puVar1 = (undefined4 *)(iVar2 + 4);
    }
  }
  return 0;
}

