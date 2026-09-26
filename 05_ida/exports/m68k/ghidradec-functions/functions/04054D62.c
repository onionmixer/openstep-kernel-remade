
void sub_4054D62(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = (uint)param_2[1] >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  piVar3 = (int *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
  if (param_2 == (undefined4 *)*piVar3) {
    if ((int)uVar2 < (int)uVar1) {
      for (puVar4 = (undefined4 *)*param_2;
          (puVar4 != (undefined4 *)0x0 && (param_2[1] != puVar4[1])); puVar4 = (undefined4 *)*puVar4
          ) {
      }
    }
    else {
      puVar4 = (undefined4 *)*param_2;
      if (puVar4 != (undefined4 *)0x0) {
        do {
          if (*(uint *)(param_1 + 4) <= (uint)puVar4[1]) break;
          puVar4 = (undefined4 *)*puVar4;
        } while (puVar4 != (undefined4 *)0x0);
      }
    }
    *piVar3 = (int)puVar4;
  }
  return;
}
