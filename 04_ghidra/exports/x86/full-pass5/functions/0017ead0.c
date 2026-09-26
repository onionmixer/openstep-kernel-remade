/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ead0 */

undefined4 FUN_0017ead0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x18);
  cVar3 = _objc_msgSend(param_3,PTR_s_isKindOf__001f9260,*(undefined4 *)(param_1 + 0x10));
  if ((cVar3 == '\0') ||
     (piVar1 = (int *)(iVar2 + (*(int *)(param_3 + 8) - *(int *)(param_1 + 0xc)) * 4), *piVar1 == 0)
     ) {
    uVar4 = 0;
  }
  else {
    *piVar1 = 0;
    iVar2 = *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar2 + -1;
    if (iVar2 == 1) {
      _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s__resourceInactive_001f9264);
    }
    uVar4 = _objc_msgSend(param_3,PTR_s_dealloc_001f9268);
  }
  return uVar4;
}

