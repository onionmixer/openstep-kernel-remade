
undefined4 _bcopy(uint *param_1,uint *param_2,uint param_3)

{
  undefined uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  undefined *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined8 in_l0_1;
  undefined4 unaff_l3;
  undefined8 uVar10;
  undefined8 in_l4_5;
  undefined8 uVar11;
  undefined8 in_l6_7;
  undefined8 uVar12;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  uVar9 = (uint)param_1 & 3;
  if ((int)param_3 < 10) {
    puVar5 = (undefined *)((int)param_1 - (int)param_2);
    goto loc_F0094CAC;
  }
  if (uVar9 != 0) {
    if (uVar9 != 2) {
      uVar1 = *(undefined *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      *(undefined *)param_2 = uVar1;
      param_2 = (uint *)((int)param_2 + 1);
      param_3 = param_3 - 1;
      if (uVar9 == 3) goto loc_F0094B6C;
    }
    uVar2 = *(undefined2 *)param_1;
    param_1 = (uint *)((int)param_1 + 2);
    *(char *)param_2 = (char)((word)uVar2 >> 8);
    *(char *)((int)param_2 + 1) = (char)uVar2;
    param_2 = (uint *)((int)param_2 + 2);
    param_3 = param_3 - 2;
  }
loc_F0094B6C:
  uVar9 = (uint)param_2 & 3;
  if (uVar9 == 0) {
    if ((((int)param_3 < 0x200) || (((uint)param_1 & 7) != 0)) || (((uint)param_2 & 7) != 0)) {
      puVar5 = (undefined *)((int)param_1 - (int)param_2);
      uVar9 = param_3 & 0xfffffffc;
    }
    else {
      iVar7 = 0x100;
      if (!in_DECOMPILE_MODE) {
        *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
        *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
        *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
        *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
        *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
        *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
        *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
        *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
        *(int *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = (int)((qword)in_l0_1 >> 0x20);
        *(int *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
        *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
        *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
        *(int *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = (int)((qword)in_l4_5 >> 0x20);
        *(int *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = (int)in_l4_5;
        *(int *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = (int)((qword)in_l6_7 >> 0x20);
        *(int *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = (int)in_l6_7;
      }
      do {
        uVar10 = *(undefined8 *)(param_1 + 0x3c);
        uVar11 = *(undefined8 *)(param_1 + 0x3a);
        uVar12 = *(undefined8 *)(param_1 + 0x38);
        *(undefined8 *)(param_2 + 0x3e) = *(undefined8 *)(param_1 + 0x3e);
        *(undefined8 *)(param_2 + 0x3c) = uVar10;
        *(undefined8 *)(param_2 + 0x3a) = uVar11;
        *(undefined8 *)(param_2 + 0x38) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x34);
        uVar11 = *(undefined8 *)(param_1 + 0x32);
        uVar12 = *(undefined8 *)(param_1 + 0x30);
        *(undefined8 *)(param_2 + 0x36) = *(undefined8 *)(param_1 + 0x36);
        *(undefined8 *)(param_2 + 0x34) = uVar10;
        *(undefined8 *)(param_2 + 0x32) = uVar11;
        *(undefined8 *)(param_2 + 0x30) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x2c);
        uVar11 = *(undefined8 *)(param_1 + 0x2a);
        uVar12 = *(undefined8 *)(param_1 + 0x28);
        *(undefined8 *)(param_2 + 0x2e) = *(undefined8 *)(param_1 + 0x2e);
        *(undefined8 *)(param_2 + 0x2c) = uVar10;
        *(undefined8 *)(param_2 + 0x2a) = uVar11;
        *(undefined8 *)(param_2 + 0x28) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x24);
        uVar11 = *(undefined8 *)(param_1 + 0x22);
        uVar12 = *(undefined8 *)(param_1 + 0x20);
        *(undefined8 *)(param_2 + 0x26) = *(undefined8 *)(param_1 + 0x26);
        *(undefined8 *)(param_2 + 0x24) = uVar10;
        *(undefined8 *)(param_2 + 0x22) = uVar11;
        *(undefined8 *)(param_2 + 0x20) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x1c);
        uVar11 = *(undefined8 *)(param_1 + 0x1a);
        uVar12 = *(undefined8 *)(param_1 + 0x18);
        *(undefined8 *)(param_2 + 0x1e) = *(undefined8 *)(param_1 + 0x1e);
        *(undefined8 *)(param_2 + 0x1c) = uVar10;
        *(undefined8 *)(param_2 + 0x1a) = uVar11;
        *(undefined8 *)(param_2 + 0x18) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0x14);
        uVar11 = *(undefined8 *)(param_1 + 0x12);
        uVar12 = *(undefined8 *)(param_1 + 0x10);
        *(undefined8 *)(param_2 + 0x16) = *(undefined8 *)(param_1 + 0x16);
        *(undefined8 *)(param_2 + 0x14) = uVar10;
        *(undefined8 *)(param_2 + 0x12) = uVar11;
        *(undefined8 *)(param_2 + 0x10) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 0xc);
        uVar11 = *(undefined8 *)(param_1 + 10);
        uVar12 = *(undefined8 *)(param_1 + 8);
        *(undefined8 *)(param_2 + 0xe) = *(undefined8 *)(param_1 + 0xe);
        *(undefined8 *)(param_2 + 0xc) = uVar10;
        *(undefined8 *)(param_2 + 10) = uVar11;
        *(undefined8 *)(param_2 + 8) = uVar12;
        uVar10 = *(undefined8 *)(param_1 + 4);
        uVar11 = *(undefined8 *)(param_1 + 2);
        uVar12 = *(undefined8 *)param_1;
        *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 6);
        *(undefined8 *)(param_2 + 4) = uVar10;
        *(undefined8 *)(param_2 + 2) = uVar11;
        *(undefined8 *)param_2 = uVar12;
        param_3 = param_3 - iVar7;
        param_1 = (uint *)((int)param_1 + iVar7);
        param_2 = (uint *)((int)param_2 + iVar7);
      } while (0xff < (int)param_3);
      puVar5 = (undefined *)((int)param_1 - (int)param_2);
      if ((int)param_3 < 10) goto loc_F0094CAC;
      uVar9 = param_3 & 0xfffffffc;
    }
    do {
      uVar8 = uVar9 - 4;
      *param_2 = *(uint *)(puVar5 + (int)param_2);
      bVar3 = 3 < (int)uVar9;
      param_2 = param_2 + 1;
      uVar9 = uVar8;
    } while (uVar8 != 0 && bVar3);
    param_3 = param_3 & 3;
  }
  else if (uVar9 == 2) {
    uVar8 = *param_1;
    *(sword *)param_2 = (sword)(uVar8 >> 0x10);
    param_2 = (uint *)((int)param_2 + 2);
    uVar9 = param_3 - 2 & 0xfffffffc;
    puVar5 = (undefined *)((int)param_1 + (4 - (int)param_2));
    do {
      uVar4 = uVar8 << 0x10;
      uVar8 = *(uint *)(puVar5 + (int)param_2);
      uVar9 = uVar9 - 4;
      *param_2 = uVar8 >> 0x10 | uVar4;
      param_2 = param_2 + 1;
    } while (uVar9 != 0);
    puVar5 = puVar5 + -2;
    param_3 = param_3 - 2 & 3;
  }
  else {
    uVar8 = *param_1;
    *(char *)param_2 = (char)(uVar8 >> 0x18);
    puVar6 = (uint *)((int)param_2 + 1);
    if (uVar9 == 3) {
      uVar9 = param_3 - 1 & 0xfffffffc;
      puVar5 = (undefined *)((int)param_1 + (4 - (int)puVar6));
      param_2 = puVar6;
      do {
        uVar4 = uVar8 << 8;
        uVar8 = *(uint *)(puVar5 + (int)param_2);
        uVar9 = uVar9 - 4;
        *param_2 = uVar8 >> 0x18 | uVar4;
        param_2 = param_2 + 1;
      } while (uVar9 != 0);
      puVar5 = puVar5 + -3;
      param_3 = param_3 - 1 & 3;
    }
    else {
      *(sword *)puVar6 = (sword)(uVar8 >> 8);
      param_2 = (uint *)((int)param_2 + 3);
      uVar9 = param_3 - 3 & 0xfffffffc;
      puVar5 = (undefined *)((int)param_1 + (4 - (int)param_2));
      do {
        uVar4 = uVar8 << 0x18;
        uVar8 = *(uint *)(puVar5 + (int)param_2);
        uVar9 = uVar9 - 4;
        *param_2 = uVar8 >> 8 | uVar4;
        param_2 = param_2 + 1;
      } while (uVar9 != 0);
      puVar5 = puVar5 + -1;
      param_3 = param_3 - 3 & 3;
    }
  }
loc_F0094CAC:
  while (0 < (int)param_3) {
    *(undefined *)param_2 = puVar5[(int)param_2];
    param_2 = (uint *)((int)param_2 + 1);
    param_3 = param_3 - 1;
  }
  return 0;
}

