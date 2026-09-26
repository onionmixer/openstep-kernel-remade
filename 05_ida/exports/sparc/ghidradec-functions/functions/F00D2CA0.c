
/* WARNING: Removing unreachable block (ram,0xf00d2dec) */

undefined4 -[EventDriver initShmem](undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  int *piVar8;
  undefined2 *puVar9;
  int iVar11;
  qword qVar10;
  undefined4 unaff_l0;
  undefined2 *puVar12;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
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
  undefined auStackX_0 [92];
  
  uVar6 = (undefined)param_1;
  uVar4 = (undefined)((uint)param_1 >> 8);
  uVar2 = (undefined2)((uint)param_1 >> 0x10);
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = CONCAT31(CONCAT21(uVar2,uVar4),uVar6);
  *(undefined2 *)(iVar1 + 0x1a8) = 100;
  *(undefined2 *)(iVar1 + 0x1aa) = 100;
  piVar8 = *(int **)(iVar1 + 0x15c);
  *piVar8 = 8;
  piVar8[1] = *piVar8 + 0xe10;
  iVar11 = 0x4f;
  puVar12 = (undefined2 *)(*(int *)(iVar1 + 0x15c) + *piVar8);
  puVar9 = puVar12 + 0x6ca;
  *(int *)(iVar1 + 0x164) = *(int *)(iVar1 + 0x15c) + piVar8[1];
  *(undefined *)((int)puVar12 + 0x49) = 1;
  *(undefined *)(puVar12 + 0x25) = 1;
  puVar12[0x26] = 0x47;
  *(undefined8 *)(iVar1 + 0x1e8) = 75000000;
  *(undefined8 *)(iVar1 + 0x1d8) = 300000000;
  *(undefined8 *)(iVar1 + 0x1e0) = 0;
  *(undefined8 *)(iVar1 + 0x1f0) = 0;
  *(undefined4 *)(iVar1 + 0x16c) = 0x50;
  do {
    *(undefined4 *)(puVar9 + 0x2c) = 0;
    *(undefined4 *)(puVar9 + 0x32) = 0;
    *(undefined4 *)(puVar9 + 0x34) = 0;
    *(undefined4 *)(puVar9 + 0x2a) = 0;
    *(int *)(puVar9 + 0x28) = iVar11 + 1;
    iVar11 = iVar11 + -1;
    puVar9 = puVar9 + -0x16;
  } while (iVar11 != -1);
  puVar12[2] = 0;
  *(undefined4 *)(puVar12 + (*(int *)(iVar1 + 0x16c) + -1) * 0x16 + 0x28) = 0;
  *puVar12 = (sword)*(undefined4 *)(puVar12 + (sword)puVar12[2] * 0x16 + 0x28);
  puVar12[1] = (sword)*(undefined4 *)(puVar12 + (sword)puVar12[2] * 0x16 + 0x28);
  *(undefined4 *)(puVar12 + 4) = 0;
  puVar12[3] = 0xd;
  *(undefined4 *)(puVar12 + 6) = 0;
  _IOGetTimestamp((char)(undefined *)((int)register0x00000038 + -0x18));
  qVar10 = *(qword *)((int)register0x00000038 + -0x18);
  uVar3 = (undefined2)(qVar10 >> 0x28);
  uVar5 = (undefined)(qVar10 >> 0x20);
  uVar7 = (undefined)(qVar10 >> 0x18);
  if ((qVar10 & 0xffffff00000000) == 0 && (uint)qVar10 >> 0x18 == 0) {
    uVar3 = 0;
    uVar5 = 0;
    uVar7 = 1;
  }
  *(uint *)(puVar12 + 8) = CONCAT31(CONCAT21(uVar3,uVar5),uVar7);
  puVar12[0xc] = *(undefined2 *)(iVar1 + 0x1a8);
  puVar12[0xd] = *(undefined2 *)(iVar1 + 0x1aa);
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xfd;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xfb;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xef;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xf7;
  *(byte *)((int)puVar12 + 0x33) = *(byte *)((int)puVar12 + 0x33) & 0xfe;
  *(undefined4 *)(puVar12 + 0x1a) = 0;
  *(undefined4 *)(puVar12 + 10) = 0;
  *(undefined4 *)(puVar12 + 0x20) = 0;
  *(undefined2 **)(iVar1 + 0x168) = puVar12;
  *(undefined *)(iVar1 + 0x1d2) = 1;
  return CONCAT22(uVar2,CONCAT11(uVar4,uVar6));
}
