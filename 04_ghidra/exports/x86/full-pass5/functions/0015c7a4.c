/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c7a4 */

undefined8 FUN_0015c7a4(int param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  piVar2 = (int *)(param_1 + 0x1c);
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (*piVar2 == 1) goto LAB_0015c817;
      piVar2 = (int *)((int)piVar2 + piVar2[1]);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  piVar3 = (int *)0x0;
  goto LAB_0015c81b;
LAB_0015c817:
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    if (uVar4 < (uint)(piVar2[8] + piVar2[9])) {
      uVar4 = piVar2[8] + piVar2[9];
    }
    piVar3 = (int *)(param_1 + 0x1c);
    uVar1 = 0;
    if (*(uint *)(param_1 + 0x10) != 0) {
      do {
        if (piVar3 == piVar2) break;
        piVar3 = (int *)((int)piVar3 + piVar3[1]);
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(param_1 + 0x10));
    }
    if (uVar1 == *(uint *)(param_1 + 0x10)) goto LAB_0015c81b;
    piVar2 = (int *)((int)piVar3 + piVar3[1]);
    for (; uVar1 < *(uint *)(param_1 + 0x10); uVar1 = uVar1 + 1) {
      if (*piVar2 == 1) goto LAB_0015c817;
      piVar2 = (int *)((int)piVar2 + piVar2[1]);
    }
    piVar2 = (int *)0x0;
    goto LAB_0015c817;
  }
LAB_0015c81b:
  return CONCAT44(piVar3,uVar4);
}

