
uint * _memcpy(uint *param_1,uint *param_2,uint param_3)

{
  undefined uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined *puVar7;
  uint uVar8;
  uint uVar9;
  
  puVar5 = param_1;
  if ((int)param_3 < 10) {
    puVar7 = (undefined *)((int)param_2 - (int)param_1);
    goto loc_F0007424;
  }
  uVar9 = (uint)param_2 & 3;
  if (uVar9 != 0) {
    if (uVar9 != 2) {
      uVar1 = *(undefined *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(undefined *)param_1 = uVar1;
      puVar5 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      if (uVar9 == 3) goto loc_F0007300;
    }
    uVar2 = *(undefined2 *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    *(char *)puVar5 = (char)((word)uVar2 >> 8);
    *(char *)((int)puVar5 + 1) = (char)uVar2;
    puVar5 = (uint *)((int)puVar5 + 2);
    param_3 = param_3 - 2;
  }
loc_F0007300:
  uVar9 = (uint)puVar5 & 3;
  if (uVar9 == 0) {
    puVar7 = (undefined *)((int)param_2 - (int)puVar5);
    uVar9 = param_3 & 0xfffffffc;
    do {
      uVar8 = uVar9 - 4;
      *puVar5 = *(uint *)(puVar7 + (int)puVar5);
      bVar3 = 3 < (int)uVar9;
      puVar5 = puVar5 + 1;
      uVar9 = uVar8;
    } while (uVar8 != 0 && bVar3);
    param_3 = param_3 & 3;
  }
  else if (uVar9 == 2) {
    uVar8 = *param_2;
    *(sword *)puVar5 = (sword)(uVar8 >> 0x10);
    puVar5 = (uint *)((int)puVar5 + 2);
    uVar9 = param_3 - 2 & 0xfffffffc;
    puVar7 = (undefined *)((int)param_2 + (4 - (int)puVar5));
    do {
      uVar4 = uVar8 << 0x10;
      uVar8 = *(uint *)(puVar7 + (int)puVar5);
      uVar9 = uVar9 - 4;
      *puVar5 = uVar8 >> 0x10 | uVar4;
      puVar5 = puVar5 + 1;
    } while (uVar9 != 0);
    puVar7 = puVar7 + -2;
    param_3 = param_3 - 2 & 3;
  }
  else {
    uVar8 = *param_2;
    *(char *)puVar5 = (char)(uVar8 >> 0x18);
    puVar6 = (uint *)((int)puVar5 + 1);
    if (uVar9 == 3) {
      uVar9 = param_3 - 1 & 0xfffffffc;
      puVar7 = (undefined *)((int)param_2 + (4 - (int)puVar6));
      do {
        uVar4 = uVar8 << 8;
        uVar8 = *(uint *)(puVar7 + (int)puVar6);
        uVar9 = uVar9 - 4;
        *puVar6 = uVar8 >> 0x18 | uVar4;
        puVar6 = puVar6 + 1;
      } while (uVar9 != 0);
      puVar7 = puVar7 + -3;
      puVar5 = puVar6;
      param_3 = param_3 - 1 & 3;
    }
    else {
      *(sword *)puVar6 = (sword)(uVar8 >> 8);
      puVar5 = (uint *)((int)puVar5 + 3);
      uVar9 = param_3 - 3 & 0xfffffffc;
      puVar7 = (undefined *)((int)param_2 + (4 - (int)puVar5));
      do {
        uVar4 = uVar8 << 0x18;
        uVar8 = *(uint *)(puVar7 + (int)puVar5);
        uVar9 = uVar9 - 4;
        *puVar5 = uVar8 >> 8 | uVar4;
        puVar5 = puVar5 + 1;
      } while (uVar9 != 0);
      puVar7 = puVar7 + -1;
      param_3 = param_3 - 3 & 3;
    }
  }
loc_F0007424:
  while (0 < (int)param_3) {
    *(undefined *)puVar5 = puVar7[(int)puVar5];
    puVar5 = (uint *)((int)puVar5 + 1);
    param_3 = param_3 - 1;
  }
  return param_1;
}
