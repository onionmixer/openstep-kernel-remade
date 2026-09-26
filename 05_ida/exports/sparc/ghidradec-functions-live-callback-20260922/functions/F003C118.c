
/* WARNING: Removing unreachable block (ram,0xf003c1a8) */
/* WARNING: Removing unreachable block (ram,0xf003c148) */
/* WARNING: Removing unreachable block (ram,0xf003c154) */

undefined8 sub_F003C118(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  if (_nfs_portmon == 0) {
    iVar3 = *(int *)(param_2 + 0xc);
  }
  else {
    iVar3 = *(int *)(param_2 + 0x1c) + 0x14;
    if (0x3ff < *(word *)(*(int *)(param_2 + 0x1c) + 0x12)) {
      _inet_ntoa(iVar3);
      _printf(aNfsRequestFrom,iVar3);
      uVar6 = 0;
      goto locret_F003C250;
    }
    iVar3 = *(int *)(param_2 + 0xc);
  }
  if (iVar3 != *(int *)(param_1 + 8)) {
    iVar3 = 0;
  }
  if (iVar3 == 0) {
loc_F003C1BC:
    *(sword *)(param_3 + 2) = (sword)*(undefined4 *)(param_1 + 4);
    puVar4 = (undefined2 *)(param_3 + 10);
    *(sword *)(param_3 + 4) = (sword)*(undefined4 *)(param_1 + 4);
  }
  else {
    if (iVar3 != 1) {
      uVar6 = 0;
      goto locret_F003C250;
    }
    iVar3 = *(int *)(param_2 + 0x18);
    if (*(int *)(iVar3 + 8) == 0) {
      iVar2 = *(int *)(param_2 + 0x1c) + 0x10;
      sub_F003C0BC(iVar2,param_1 + 0xc);
      if (iVar2 == 0) goto loc_F003C1BC;
      *(sword *)(param_3 + 2) = (sword)*(undefined4 *)(iVar3 + 8);
    }
    else {
      *(sword *)(param_3 + 2) = (sword)*(int *)(iVar3 + 8);
    }
    *(sword *)(param_3 + 4) = (sword)*(undefined4 *)(iVar3 + 0xc);
    iVar2 = *(int *)(iVar3 + 0x10);
    iVar5 = *(int *)(iVar3 + 0x14);
    for (puVar4 = (undefined2 *)(param_3 + 10); puVar4 < (undefined2 *)(param_3 + iVar2 * 2 + 10);
        puVar4 = puVar4 + 1) {
      *puVar4 = *(undefined2 *)(iVar5 + 2);
      iVar5 = iVar5 + 4;
      iVar2 = *(int *)(iVar3 + 0x10);
    }
  }
  if (puVar4 < (undefined2 *)(param_3 + 0x2a)) {
    *puVar4 = 0xffff;
    while (puVar4 = puVar4 + 1, puVar4 < (undefined2 *)(param_3 + 0x2a)) {
      *puVar4 = 0xffff;
    }
    sVar1 = *(sword *)(param_3 + 2);
  }
  else {
    sVar1 = *(sword *)(param_3 + 2);
  }
  uVar6 = (uint)(sVar1 != -1);
locret_F003C250:
  return CONCAT44(param_2,uVar6);
}

