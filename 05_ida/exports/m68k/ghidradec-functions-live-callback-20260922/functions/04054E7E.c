
void sub_4054E7E(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = (uint)param_2[1] >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  uVar3 = param_3 >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar3) {
    uVar3 = uVar1;
  }
  if (uVar2 != uVar3) {
    piVar4 = (int *)(uVar3 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
    if (param_2 == (undefined4 *)*piVar4) {
      if ((int)uVar3 < (int)uVar1) {
        for (puVar6 = (undefined4 *)*param_2;
            (puVar6 != (undefined4 *)0x0 && (param_3 != puVar6[1])); puVar6 = (undefined4 *)*puVar6)
        {
        }
      }
      else {
        puVar6 = (undefined4 *)*param_2;
        if (puVar6 != (undefined4 *)0x0) {
          do {
            if (*(uint *)(param_1 + 4) <= (uint)puVar6[1]) break;
            puVar6 = (undefined4 *)*puVar6;
          } while (puVar6 != (undefined4 *)0x0);
        }
      }
      *piVar4 = (int)puVar6;
    }
    puVar5 = (undefined4 *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
    puVar6 = (undefined4 *)*puVar5;
    if ((puVar6 == (undefined4 *)0x0) || (param_2 < puVar6)) {
      *puVar5 = param_2;
    }
  }
  return;
}

