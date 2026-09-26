
void _memmove(uint *param_1,uint *param_2,uint param_3)

{
  undefined uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if ((int)param_2 <= (int)param_1) {
    iVar7 = (int)param_2 - (int)param_1;
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    if (iVar7 < (int)param_3) {
      puVar6 = (undefined *)((int)param_1 + param_3);
      iVar7 = param_3 - (int)puVar6;
      do {
        puVar6 = puVar6 + -1;
        uVar9 = param_3 - 1;
        bVar3 = 0 < (int)param_3;
        *puVar6 = puVar6[(int)((int)param_2 + iVar7)];
        param_3 = uVar9;
      } while (uVar9 != 0 && bVar3);
      return;
    }
  }
  uVar9 = (uint)param_2 & 3;
  if ((int)param_3 < 10) {
    puVar6 = (undefined *)((int)param_2 - (int)param_1);
    goto loc_F0008170;
  }
  puVar5 = param_1;
  if (uVar9 != 0) {
    if (uVar9 != 2) {
      uVar1 = *(undefined *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(undefined *)param_1 = uVar1;
      param_1 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      puVar5 = param_1;
      if (uVar9 == 3) goto loc_F000804C;
    }
    uVar2 = *(undefined2 *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    *(char *)param_1 = (char)((word)uVar2 >> 8);
    *(char *)((int)param_1 + 1) = (char)uVar2;
    param_3 = param_3 - 2;
    puVar5 = (uint *)((int)param_1 + 2);
  }
loc_F000804C:
  uVar9 = (uint)puVar5 & 3;
  if (uVar9 == 0) {
    puVar6 = (undefined *)((int)param_2 - (int)puVar5);
    param_1 = puVar5;
    uVar9 = param_3 & 0xfffffffc;
    do {
      uVar8 = uVar9 - 4;
      *param_1 = *(uint *)(puVar6 + (int)param_1);
      bVar3 = 3 < (int)uVar9;
      param_1 = param_1 + 1;
      uVar9 = uVar8;
    } while (uVar8 != 0 && bVar3);
    param_3 = param_3 & 3;
  }
  else if (uVar9 == 2) {
    uVar8 = *param_2;
    *(sword *)puVar5 = (sword)(uVar8 >> 0x10);
    param_1 = (uint *)((int)puVar5 + 2);
    uVar9 = param_3 - 2 & 0xfffffffc;
    puVar6 = (undefined *)((int)param_2 + (4 - (int)param_1));
    do {
      uVar4 = uVar8 << 0x10;
      uVar8 = *(uint *)(puVar6 + (int)param_1);
      uVar9 = uVar9 - 4;
      *param_1 = uVar8 >> 0x10 | uVar4;
      param_1 = param_1 + 1;
    } while (uVar9 != 0);
    puVar6 = puVar6 + -2;
    param_3 = param_3 - 2 & 3;
  }
  else {
    uVar8 = *param_2;
    *(char *)puVar5 = (char)(uVar8 >> 0x18);
    param_1 = (uint *)((int)puVar5 + 1);
    if (uVar9 == 3) {
      uVar9 = param_3 - 1 & 0xfffffffc;
      puVar6 = (undefined *)((int)param_2 + (4 - (int)param_1));
      do {
        uVar4 = uVar8 << 8;
        uVar8 = *(uint *)(puVar6 + (int)param_1);
        uVar9 = uVar9 - 4;
        *param_1 = uVar8 >> 0x18 | uVar4;
        param_1 = param_1 + 1;
      } while (uVar9 != 0);
      puVar6 = puVar6 + -3;
      param_3 = param_3 - 1 & 3;
    }
    else {
      *(sword *)param_1 = (sword)(uVar8 >> 8);
      param_1 = (uint *)((int)puVar5 + 3);
      uVar9 = param_3 - 3 & 0xfffffffc;
      puVar6 = (undefined *)((int)param_2 + (4 - (int)param_1));
      do {
        uVar4 = uVar8 << 0x18;
        uVar8 = *(uint *)(puVar6 + (int)param_1);
        uVar9 = uVar9 - 4;
        *param_1 = uVar8 >> 8 | uVar4;
        param_1 = param_1 + 1;
      } while (uVar9 != 0);
      puVar6 = puVar6 + -1;
      param_3 = param_3 - 3 & 3;
    }
  }
loc_F0008170:
  while (0 < (int)param_3) {
    *(undefined *)param_1 = puVar6[(int)param_1];
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
  }
  return;
}

