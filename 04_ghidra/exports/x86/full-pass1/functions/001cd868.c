/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd868 */

code * __class_lookupMethodAndLoadCache(undefined *param_1,int param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined *puVar6;
  
  if (param_1 == &DAT_001d6728) {
    pcVar2 = FUN_001cd25c;
  }
  else {
    puVar6 = param_1;
    if (((param_1[0x10] & 2) != 0) && ((param_1[0x10] & 4) == 0)) {
      uVar3 = _objc_getClass(*(undefined4 *)(param_1 + 8));
      FUN_001cd284(uVar3);
    }
    do {
      for (puVar1 = *(undefined4 **)(puVar6 + 0x1c); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        piVar5 = puVar1 + 2;
        iVar4 = puVar1[1];
        while (iVar4 = iVar4 + -1, -1 < iVar4) {
          if (*piVar5 == param_2) goto LAB_001cd8cd;
          piVar5 = piVar5 + 3;
        }
      }
      piVar5 = (int *)0x0;
LAB_001cd8cd:
      if (piVar5 != (int *)0x0) {
        FUN_001cd76c(param_1,piVar5);
        return (code *)piVar5[2];
      }
      puVar6 = *(undefined **)(puVar6 + 4);
    } while (puVar6 != (undefined *)0x0);
    iVar4 = _NXDefaultMallocZone();
    uVar3 = _NXDefaultMallocZone(0xc);
    piVar5 = (int *)(**(code **)(iVar4 + 4))(uVar3);
    *piVar5 = param_2;
    piVar5[1] = (int)"";
    piVar5[2] = (int)&__objc_msgForward;
    FUN_001cd76c(param_1,piVar5);
    pcVar2 = (code *)&__objc_msgForward;
  }
  return pcVar2;
}

