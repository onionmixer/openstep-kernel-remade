
byte sub_4036F96(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  char cVar8;
  char cVar9;
  bool bVar10;
  char cVar11;
  char cVar12;
  byte bVar13;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  puVar2 = (uint *)(param_1 + 0xe);
  puVar7 = (uint *)*puVar2;
  cVar12 = puVar7 < puVar2;
  if (puVar7 == puVar2) {
    iVar6 = sub_4036E8C(param_1,puVar2,param_2);
    *(int *)(iVar6 + 0xc) = iVar1;
    iVar1 = *(int *)(param_1 + 0x1a);
    *(int *)(iVar6 + 8) = iVar1;
    return cVar12 << 4 | (iVar1 < 0) << 3 | (iVar1 == 0) << 2;
  }
  if (((((*(byte *)(param_1 + 0xc) & 0x10) != 0) &&
       (puVar7[2] = *(undefined4 *)(*puVar7 + 0x38), (*(byte *)(param_1 + 0xc) & 0x10) != 0)) &&
      ((int)puVar7[3] < iVar1)) && (0 < *(int *)(param_1 + 0x16))) {
    iVar6 = *puVar7;
    if (iVar6 == puVar7[1]) {
      puVar7[3] = iVar1;
    }
    else {
      *puVar7 = *(undefined4 *)(iVar6 + 0xc);
      puVar7 = (uint *)sub_4036E8C(param_1,puVar2,iVar6);
      *(int *)((int)puVar7 + 0xc) = iVar1;
      *(undefined4 *)((int)puVar7 + 8) = *(undefined4 *)(iVar6 + 0x38);
    }
  }
  for (; ((uint *)(param_1 + 0xeU) != puVar7 && (iVar1 < *(int *)((int)puVar7 + 0xc)));
      puVar7 = *(uint **)((int)puVar7 + 0x10)) {
  }
  cVar12 = puVar7 < param_1 + 0xeU;
  if (puVar7 == (uint *)(param_1 + 0xeU)) {
    if (*(int *)(param_1 + 0x16) == 0) {
      cVar8 = param_1 < 0;
      cVar9 = param_1 == 0;
      cVar11 = '\0';
      bVar13 = 0;
      sub_4036E20(param_1,*(undefined4 *)(param_1 + 0x12),param_2,
                  (*(uint *)(param_1 + 0xc) & 0x1fffffff) >> 0x1c);
      return cVar12 << 4 | cVar8 << 3 | cVar9 << 2 | cVar11 << 1 | bVar13;
    }
loc_403707E:
    if (puVar7 == (uint *)(param_1 + 0xeU)) {
      puVar7 = *(uint **)(param_1 + 0x12);
    }
    if (*(int *)((int)puVar7 + 0xc) < iVar1) {
      puVar7 = (uint *)sub_4036E8C(param_1,*(undefined4 *)((int)puVar7 + 0x14),param_2);
      *(int *)((int)puVar7 + 0xc) = iVar1;
      if (*(uint *)((int)puVar7 + 0x14) == param_1 + 0xeU) {
        *(undefined4 *)((int)puVar7 + 8) = *(undefined4 *)(param_1 + 0x1a);
      }
      else {
        *(undefined4 *)((int)puVar7 + 8) =
             *(undefined4 *)(*(int *)(*(uint *)((int)puVar7 + 0x14) + 4) + 0x38);
      }
      goto loc_4037106;
    }
    if (iVar1 != *(int *)((int)puVar7 + 0xc)) {
      iVar6 = sub_4036E8C(param_1,puVar7,param_2);
      *(int *)(iVar6 + 0xc) = iVar1;
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(*(int *)((int)puVar7 + 4) + 0x38);
      goto loc_4037106;
    }
  }
  else if (*(int *)(param_1 + 0x16) != 0) goto loc_403707E;
  sub_4036E20(param_1,puVar7,param_2,(*(uint *)(param_1 + 0xc) & 0x1fffffff) >> 0x1c);
loc_4037106:
  uVar3 = param_1 + 0xe;
  iVar1 = (int)puVar7 - uVar3;
  bVar10 = puVar7 == (uint *)uVar3;
  if (!bVar10) {
    iVar1 = *(uint *)((int)puVar7 + 0x10) - uVar3;
    uVar5 = *(uint *)((int)puVar7 + 0x10);
    uVar4 = (uint)puVar7;
    while (puVar7 = (uint *)uVar5, bVar10 = puVar7 == (uint *)uVar3, !bVar10) {
      sub_4036F4A(puVar7,*(undefined4 *)(*(int *)(uVar4 + 4) + 0x38));
      iVar1 = *(uint *)((int)puVar7 + 0x10) - uVar3;
      uVar5 = *(uint *)((int)puVar7 + 0x10);
      uVar4 = (uint)puVar7;
    }
  }
  return (puVar7 < uVar3) << 4 | (iVar1 < 0) << 3 | bVar10 << 2 | SBORROW4((int)puVar7,uVar3) << 1 |
         puVar7 < uVar3;
}

