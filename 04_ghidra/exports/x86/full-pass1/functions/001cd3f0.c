/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd3f0 */

undefined4 _class_respondsToMethod(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2 != 0) {
    iVar2 = *(int *)(param_1 + 0x20) + 8;
    uVar5 = param_2;
    while (uVar5 = **(uint **)(param_1 + 0x20) & uVar5, iVar6 = param_1,
          *(int *)(iVar2 + uVar5 * 4) != 0) {
      puVar4 = *(uint **)(iVar2 + uVar5 * 4);
      if (*puVar4 == param_2) {
        if ((undefined *)puVar4[2] == &__objc_msgForward) {
          return 0;
        }
        return 1;
      }
      uVar5 = uVar5 + 1;
    }
    do {
      for (puVar1 = *(undefined4 **)(iVar6 + 0x1c); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        puVar4 = puVar1 + 2;
        iVar2 = puVar1[1];
        while (iVar2 = iVar2 + -1, -1 < iVar2) {
          if (*puVar4 == param_2) {
            FUN_001cd76c(param_1,puVar4);
            return 1;
          }
          puVar4 = puVar4 + 3;
        }
      }
      iVar6 = *(int *)(iVar6 + 4);
    } while (iVar6 != 0);
    iVar2 = _NXDefaultMallocZone();
    uVar3 = _NXDefaultMallocZone(0xc);
    puVar4 = (uint *)(**(code **)(iVar2 + 4))(uVar3);
    *puVar4 = param_2;
    puVar4[1] = (uint)"";
    puVar4[2] = (uint)&__objc_msgForward;
    FUN_001cd76c(param_1,puVar4);
  }
  return 0;
}

