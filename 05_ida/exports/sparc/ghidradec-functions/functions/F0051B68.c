
/* WARNING: Removing unreachable block (ram,0xf0051c9c) */
/* WARNING: Removing unreachable block (ram,0xf0051b88) */

sqword sub_F0051B68(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  word wVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  iVar5 = param_1[0xc];
  if ((*(word *)(iVar5 + 0x44) & 0x46) != 0) {
    *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
      wVar3 = *(word *)(iVar5 + 0x44);
    }
    else {
      *(undefined4 *)(iVar5 + 0x4c) = 0;
      *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
      wVar3 = *(word *)(iVar5 + 0x44);
    }
    *(word *)(iVar5 + 0x44) = wVar3 & 0xffb9;
  }
  *param_2 = *(undefined4 *)(_iftovt_tab + (uint)(*(word *)(iVar5 + 100) >> 0xd) * 4);
  *(undefined2 *)(param_2 + 1) = *(undefined2 *)(iVar5 + 100);
  *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)(iVar5 + 0x68);
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(iVar5 + 0x6a);
  param_2[3] = (int)*(sword *)(iVar5 + 0x46);
  param_2[4] = *(undefined4 *)(iVar5 + 0x48);
  *(undefined2 *)(param_2 + 5) = *(undefined2 *)(iVar5 + 0x66);
  if (param_1[10] == 1) {
    uVar1 = *(undefined4 *)(*param_1 + 0x14);
  }
  else {
    uVar1 = *(undefined4 *)(iVar5 + 0x70);
  }
  param_2[6] = uVar1;
  param_2[8] = *(undefined4 *)(iVar5 + 0x74);
  param_2[9] = 0;
  param_2[10] = *(undefined4 *)(iVar5 + 0x7c);
  param_2[0xb] = 0;
  param_2[0xc] = *(undefined4 *)(iVar5 + 0x84);
  param_2[0xd] = 0;
  *(sword *)(param_2 + 0xe) = (sword)*(undefined4 *)(iVar5 + 0x8c);
  piVar2 = param_1;
  (**(code **)(param_1[7] + 0x80))(param_1);
  uVar4 = *(uint *)(iVar5 + 0xcc);
  .umul(uVar4,piVar2);
  param_2[0xf] = uVar4 >> 9;
  wVar3 = *(word *)(iVar5 + 100) & 0xf000;
  if (wVar3 == 0x2000) {
    param_2[7] = 0x2000;
  }
  else if (wVar3 == 0x6000) {
    (**(code **)(param_1[7] + 0x80))();
    param_2[7] = param_1;
  }
  else {
    param_2[7] = *(undefined4 *)(param_1[9] + 0x10);
  }
  return ZEXT48(param_2) << 0x20;
}
