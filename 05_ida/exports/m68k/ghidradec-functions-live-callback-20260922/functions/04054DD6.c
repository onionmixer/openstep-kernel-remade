
void sub_4054DD6(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = (uint)param_2[1] >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  uVar3 = param_3 >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar3) {
    uVar3 = uVar1;
  }
  piVar4 = (int *)(uVar3 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
  if (uVar2 == uVar3) {
    if (param_4 != *piVar4) {
      return;
    }
  }
  else {
    if (param_4 == *piVar4) {
      if ((int)uVar3 < (int)uVar1) {
        for (puVar5 = (undefined4 *)*param_2;
            (puVar5 != (undefined4 *)0x0 && (param_3 != puVar5[1])); puVar5 = (undefined4 *)*puVar5)
        {
        }
      }
      else {
        puVar5 = (undefined4 *)*param_2;
        if (puVar5 != (undefined4 *)0x0) {
          do {
            if (*(uint *)(param_1 + 4) <= (uint)puVar5[1]) break;
            puVar5 = (undefined4 *)*puVar5;
          } while (puVar5 != (undefined4 *)0x0);
        }
      }
      *piVar4 = (int)puVar5;
    }
    piVar4 = (int *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
    if (((undefined4 *)*piVar4 != (undefined4 *)0x0) && ((undefined4 *)*piVar4 <= param_2)) {
      return;
    }
  }
  *piVar4 = (int)param_2;
  return;
}

