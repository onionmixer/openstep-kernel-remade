
/* WARNING: Removing unreachable block (ram,0xf00e0eb8) */
/* WARNING: Removing unreachable block (ram,0xf00e0dc8) */
/* WARNING: Removing unreachable block (ram,0xf00e0c68) */
/* WARNING: Removing unreachable block (ram,0xf00e0dd8) */
/* WARNING: Removing unreachable block (ram,0xf00e0ed0) */
/* WARNING: Removing unreachable block (ram,0xf00e0c58) */

undefined8 _put_disktab(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  _bcopy(param_1,param_2,0x18);
  _bcopy(param_1 + 0x18,param_2 + 0x18,0x18);
  *(undefined *)(param_2 + 0x30) = *(undefined *)(param_1 + 0x30);
  *(undefined *)(param_2 + 0x31) = *(undefined *)(param_1 + 0x31);
  *(undefined *)(param_2 + 0x32) = *(undefined *)(param_1 + 0x32);
  *(undefined *)(param_2 + 0x33) = *(undefined *)(param_1 + 0x33);
  *(undefined *)(param_2 + 0x34) = *(undefined *)(param_1 + 0x34);
  *(undefined *)(param_2 + 0x35) = *(undefined *)(param_1 + 0x35);
  *(undefined *)(param_2 + 0x36) = *(undefined *)(param_1 + 0x36);
  *(undefined *)(param_2 + 0x37) = *(undefined *)(param_1 + 0x37);
  *(undefined *)(param_2 + 0x38) = *(undefined *)(param_1 + 0x38);
  *(undefined *)(param_2 + 0x39) = *(undefined *)(param_1 + 0x39);
  *(undefined *)(param_2 + 0x3a) = *(undefined *)(param_1 + 0x3a);
  *(undefined *)(param_2 + 0x3b) = *(undefined *)(param_1 + 0x3b);
  *(undefined *)(param_2 + 0x3c) = *(undefined *)(param_1 + 0x3c);
  *(undefined *)(param_2 + 0x3d) = *(undefined *)(param_1 + 0x3d);
  *(undefined *)(param_2 + 0x3e) = *(undefined *)(param_1 + 0x3e);
  *(undefined *)(param_2 + 0x3f) = *(undefined *)(param_1 + 0x3f);
  *(undefined *)(param_2 + 0x40) = *(undefined *)(param_1 + 0x40);
  *(undefined *)(param_2 + 0x41) = *(undefined *)(param_1 + 0x41);
  *(undefined *)(param_2 + 0x42) = *(undefined *)(param_1 + 0x42);
  *(undefined *)(param_2 + 0x43) = *(undefined *)(param_1 + 0x43);
  *(undefined *)(param_2 + 0x44) = *(undefined *)(param_1 + 0x44);
  *(undefined *)(param_2 + 0x45) = *(undefined *)(param_1 + 0x45);
  *(undefined *)(param_2 + 0x46) = *(undefined *)(param_1 + 0x46);
  *(undefined *)(param_2 + 0x47) = *(undefined *)(param_1 + 0x47);
  *(undefined *)(param_2 + 0x48) = *(undefined *)(param_1 + 0x48);
  *(undefined *)(param_2 + 0x49) = *(undefined *)(param_1 + 0x49);
  *(undefined *)(param_2 + 0x4a) = *(undefined *)(param_1 + 0x4a);
  puVar5 = (undefined *)(param_2 + 0x50);
  *(undefined *)(param_2 + 0x4b) = *(undefined *)(param_1 + 0x4b);
  puVar4 = (undefined *)(param_1 + 0x50);
  *(undefined *)(param_2 + 0x4c) = *(undefined *)(param_1 + 0x4c);
  iVar3 = 0;
  *(undefined *)(param_2 + 0x4d) = *(undefined *)(param_1 + 0x4d);
  puVar2 = (undefined *)(param_2 + 0x53);
  *(undefined *)(param_2 + 0x4e) = *(undefined *)(param_1 + 0x4e);
  puVar1 = (undefined *)(param_1 + 0x53);
  *(undefined *)(param_2 + 0x4f) = *(undefined *)(param_1 + 0x4f);
  do {
    iVar3 = iVar3 + 1;
    *puVar5 = *puVar4;
    puVar2[-2] = puVar1[-2];
    puVar4 = puVar4 + 4;
    puVar2[-1] = puVar1[-1];
    puVar5 = puVar5 + 4;
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (iVar3 < 2);
  _bcopy(param_1 + 0x58,param_2 + 0x58,0x18);
  _bcopy(param_1 + 0x70,param_2 + 0x70,0x20);
  iVar9 = 0;
  iVar8 = 0;
  *(undefined *)(param_2 + 0x90) = *(undefined *)(param_1 + 0x90);
  iVar7 = 0;
  *(undefined *)(param_2 + 0x91) = *(undefined *)(param_1 + 0x91);
  iVar3 = param_1;
  do {
    iVar6 = iVar8 + param_2;
    *(undefined *)(iVar6 + 0x92) = *(undefined *)(iVar3 + 0x94);
    *(undefined *)(iVar6 + 0x93) = *(undefined *)(iVar3 + 0x95);
    *(undefined *)(iVar6 + 0x94) = *(undefined *)(iVar3 + 0x96);
    *(undefined *)(iVar6 + 0x95) = *(undefined *)(iVar3 + 0x97);
    *(undefined *)(iVar6 + 0x96) = *(undefined *)(iVar3 + 0x98);
    *(undefined *)(iVar6 + 0x97) = *(undefined *)(iVar3 + 0x99);
    *(undefined *)(iVar6 + 0x98) = *(undefined *)(iVar3 + 0x9a);
    *(undefined *)(iVar6 + 0x99) = *(undefined *)(iVar3 + 0x9b);
    *(undefined *)(iVar6 + 0x9a) = *(undefined *)(iVar3 + 0x9c);
    *(undefined *)(iVar6 + 0x9b) = *(undefined *)(iVar3 + 0x9d);
    *(undefined *)(iVar6 + 0x9c) = *(undefined *)(iVar3 + 0x9e);
    *(undefined *)(iVar6 + 0x9d) = *(undefined *)(iVar3 + 0x9f);
    *(undefined *)(iVar6 + 0x9e) = *(undefined *)(iVar3 + 0xa0);
    iVar8 = iVar8 + 0x2e;
    *(undefined *)(iVar6 + 0xa0) = *(undefined *)(iVar3 + 0xa2);
    iVar7 = iVar7 + 0x30;
    *(undefined *)(iVar6 + 0xa1) = *(undefined *)(iVar3 + 0xa3);
    iVar9 = iVar9 + 1;
    *(undefined *)(iVar6 + 0xa2) = *(undefined *)(iVar3 + 0xa4);
    *(undefined *)(iVar6 + 0xa3) = *(undefined *)(iVar3 + 0xa5);
    *(undefined *)(iVar6 + 0xa4) = *(undefined *)(iVar3 + 0xa6);
    *(undefined *)(iVar6 + 0xa5) = *(undefined *)(iVar3 + 0xa7);
    _bcopy(iVar3 + 0xa8,iVar6 + 0xa6,0x10);
    *(undefined *)(iVar6 + 0xb6) = *(undefined *)(iVar3 + 0xb8);
    _bcopy(iVar3 + 0xb9,iVar6 + 0xb7,8);
    iVar3 = iVar7 + param_1;
  } while (iVar9 < 8);
  return CONCAT44(param_2,param_1);
}
