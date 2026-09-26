
uint _sfa_relinquish(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  uint uVar7;
  char in_XF;
  bool bVar8;
  
  uVar7 = *(uint *)(param_2 + 0x10);
  if ((uVar7 & 1) != 0) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(param_2 + 0x10) = uVar7;
    bVar6 = in_XF << 4 | ((int)uVar7 < 0) << 3 | (uVar7 == 0) << 2;
    if (param_3 != 0) {
      *(int *)(param_1 + 0x12) = param_3;
    }
    iVar2 = *(int *)(param_1 + 0x1a);
    *(int *)(param_1 + 0x1a) = iVar2 + -1;
    if ((*(byte *)(param_2 + 0x13) & 4) != 0) {
      *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) & 0xfffffffe;
    }
    if (*(char *)(param_1 + 4) == '\0') {
      uVar7 = (uint)(byte)((iVar2 == 0) << 4 | (*(char *)(param_1 + 4) < '\0') << 3 | 4);
    }
    else {
      puVar5 = (undefined4 *)(param_1 + 6);
      puVar1 = (undefined4 *)*puVar5;
      while (uVar7 = (uint)bVar6, puVar5 != puVar1) {
        puVar3 = *(undefined4 **)(param_1 + 6);
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          bVar8 = *(int *)(param_1 + 0x1a) == 0;
          if (!bVar8) {
            return (uint)(byte)((puVar5 < puVar1) << 4 | (*(int *)(param_1 + 0x1a) < 0) << 3 |
                               bVar8 << 2);
          }
        }
        *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + -1;
        *(int *)(param_1 + 0x1a) = *(int *)(param_1 + 0x1a) + 1;
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + -1;
          *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | 1;
        }
        puVar1 = (undefined4 *)puVar3[2];
        puVar4 = (undefined4 *)puVar3[3];
        if (puVar1 == puVar5) {
          *(undefined4 **)(param_1 + 10) = puVar4;
        }
        else {
          puVar1[3] = puVar4;
        }
        if (puVar4 == puVar5) {
          *puVar5 = puVar1;
        }
        else {
          puVar4[2] = puVar1;
        }
        puVar3[4] = puVar3[4] | 1;
        uVar7 = (*(code *)*puVar3)(puVar3[1]);
        if ((*(byte *)((int)puVar3 + 0x13) & 4) != 0) {
          return uVar7;
        }
        puVar1 = (undefined4 *)*puVar5;
        if (puVar5 == puVar1) {
          return uVar7;
        }
        bVar6 = (puVar5 < puVar1) << 4 | ((int)puVar5 - (int)puVar1 < 0) << 3 |
                SBORROW4((int)puVar5,(int)puVar1) << 1 | puVar5 < puVar1;
        puVar1 = (undefined4 *)*puVar5;
      }
    }
  }
  return uVar7;
}

