
void _fragacct(int param_1,int param_2,int *param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  iVar6 = *(int *)(param_1 + 0x38);
  bVar1 = *(byte *)(*(int *)(_fragtbl + iVar6 * 4) + param_2);
  uVar5 = 1;
  if (1 < iVar6) {
    puVar8 = unk_40AF35E;
    puVar7 = unk_40AF33A;
    do {
      param_3 = param_3 + 1;
      if (((uint)bVar1 * 2 & 1 << (uVar5 + iVar6 % 8 & 0x1f)) != 0) {
        uVar4 = *(uint *)puVar7;
        uVar3 = *(uint *)puVar8;
        uVar2 = uVar5;
        if ((int)uVar5 <= iVar6) {
          do {
            if (uVar3 == (uVar4 & param_2 * 2)) {
              *param_3 = param_4 + *param_3;
              uVar2 = uVar5 + uVar2;
              uVar4 = uVar4 << (uVar5 & 0x3f);
              uVar3 = uVar3 << (uVar5 & 0x3f);
            }
            uVar4 = uVar4 * 2;
            uVar3 = uVar3 * 2;
            uVar2 = uVar2 + 1;
          } while ((int)uVar2 <= *(int *)(param_1 + 0x38));
        }
      }
      puVar8 = (undefined *)((int)puVar8 + 4);
      puVar7 = (undefined *)((int)puVar7 + 4);
      uVar5 = uVar5 + 1;
      iVar6 = *(int *)(param_1 + 0x38);
    } while ((int)uVar5 < iVar6);
  }
  return;
}

