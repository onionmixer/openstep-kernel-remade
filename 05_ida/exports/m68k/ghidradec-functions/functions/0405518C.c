
uint * _zone_free_space_add(undefined8 *param_1,int param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  if (param_1 == (undefined8 *)0x0) {
    param_1 = &__zone_default_space;
  }
  puVar2 = (uint *)(param_1 + 1);
  do {
    puVar5 = puVar2;
    puVar2 = (uint *)*puVar5;
    if (puVar2 == (uint *)0x0) goto loc_40551D8;
  } while ((puVar2 < param_3) && (param_3 != (uint *)(puVar2[1] + (int)puVar2)));
  if ((puVar2 == (uint *)0x0) || ((uint *)(puVar2[1] + (int)puVar2) < param_3)) {
loc_40551D8:
    if (0xf < (uint)(param_4 - param_2)) {
      if (puVar2 != (uint *)0x0) {
        puVar5 = puVar2;
      }
      puVar2 = (uint *)((int)param_3 + param_2);
      puVar2[1] = param_4 - param_2;
      uVar3 = *puVar5;
      *puVar2 = uVar3;
      if (uVar3 != 0) {
        *(uint **)(uVar3 + 8) = puVar2;
      }
      puVar2[2] = (uint)puVar5;
      *puVar5 = (uint)puVar2;
      *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + 1;
      uVar3 = puVar2[1] >> (*(uint *)(param_1 + 2) & 0x3f);
      if ((int)*(uint *)(param_1 + 3) < (int)uVar3) {
        uVar3 = *(uint *)(param_1 + 3);
      }
      puVar4 = (undefined4 *)(uVar3 * 0x10 + *(int *)((int)param_1 + 0x14) + -0x10);
      puVar5 = (uint *)*puVar4;
      if ((puVar5 == (uint *)0x0) || (puVar2 < puVar5)) {
        *puVar4 = puVar2;
      }
    }
  }
  else if (param_3 == (uint *)(puVar2[1] + (int)puVar2)) {
    sub_4054D62(param_1,puVar2);
    puVar1 = (uint *)((int)puVar2 + param_2);
    puVar1[1] = (param_4 + puVar2[1]) - param_2;
    uVar3 = *puVar2;
    *puVar1 = uVar3;
    if (uVar3 != 0) {
      *(uint **)(uVar3 + 8) = puVar1;
    }
    puVar1[2] = (uint)puVar5;
    *puVar5 = (uint)puVar1;
    uVar3 = puVar1[1] >> (*(uint *)(param_1 + 2) & 0x3f);
    if ((int)*(uint *)(param_1 + 3) < (int)uVar3) {
      uVar3 = *(uint *)(param_1 + 3);
    }
    puVar4 = (undefined4 *)(uVar3 * 0x10 + *(int *)((int)param_1 + 0x14) + -0x10);
    puVar5 = (uint *)*puVar4;
    param_3 = puVar2;
    if ((puVar5 == (uint *)0x0) || (puVar1 < puVar5)) {
      *puVar4 = puVar1;
    }
  }
  return param_3;
}
