
/* WARNING: Removing unreachable block (ram,0xf002f2a8) */
/* WARNING: Removing unreachable block (ram,0xf002f264) */
/* WARNING: Removing unreachable block (ram,0xf002f184) */
/* WARNING: Removing unreachable block (ram,0xf002f0fc) */
/* WARNING: Removing unreachable block (ram,0xf002f094) */
/* WARNING: Removing unreachable block (ram,0xf002f0a8) */
/* WARNING: Removing unreachable block (ram,0xf002f164) */
/* WARNING: Removing unreachable block (ram,0xf002f204) */
/* WARNING: Removing unreachable block (ram,0xf002f284) */
/* WARNING: Removing unreachable block (ram,0xf002f2b0) */
/* WARNING: Removing unreachable block (ram,0xf002efec) */

undefined8 _in_ifinit(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined2 *puVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar4 = *(uint *)(param_3 + 2);
  iVar1 = param_1;
  _spltty();
  *(undefined2 *)((int)register0x00000038 + -0x18) = *param_2;
  *(undefined2 *)((int)register0x00000038 + -0x16) = param_2[1];
  *(undefined2 *)((int)register0x00000038 + -0x14) = param_2[2];
  *(undefined2 *)((int)register0x00000038 + -0x12) = param_2[3];
  *(undefined2 *)((int)register0x00000038 + -0x10) = param_2[4];
  *(undefined2 *)((int)register0x00000038 + -0xe) = param_2[5];
  *(undefined2 *)((int)register0x00000038 + -0xc) = param_2[6];
  *(undefined2 *)((int)register0x00000038 + -10) = param_2[7];
  *param_2 = *param_3;
  param_2[1] = param_3[1];
  param_2[2] = param_3[2];
  param_2[3] = param_3[3];
  param_2[4] = param_3[4];
  param_2[5] = param_3[5];
  param_2[6] = param_3[6];
  param_2[7] = param_3[7];
  if ((*(int *)(param_1 + 0x38) == 0) ||
     (iVar5 = param_1, _if_ioctl(param_1,0x8020690c,param_2), iVar5 == 0)) {
    puVar6 = (undefined2 *)((int)register0x00000038 + -0x28);
    _bzero(puVar6,0x10);
    *(undefined2 *)((int)register0x00000038 + -0x28) = 2;
    if ((*(uint *)(param_2 + 0x1e) & 1) != 0) {
      if ((*(word *)(param_1 + 0xc) & 8) == 0) {
        if ((*(word *)(param_1 + 0xc) & 0x10) == 0) {
          uVar2 = *(undefined4 *)(param_2 + 0x18);
          _in_makeaddr(uVar2,0);
          *(undefined4 *)((int)register0x00000038 + -0x24) = uVar2;
          uVar2 = 0;
        }
        else {
          uVar2 = 4;
          puVar6 = param_2 + 8;
        }
      }
      else {
        uVar2 = 4;
        puVar6 = (undefined2 *)((int)register0x00000038 + -0x18);
      }
      _rtinit(puVar6,(undefined *)((int)register0x00000038 + -0x18),0x8030720b,uVar2);
      *(uint *)(param_2 + 0x1e) = *(uint *)(param_2 + 0x1e) & 0xfffffffe;
    }
    if ((uVar4 & 0x80000000) == 0) {
      uVar2 = 0xff000000;
    }
    else {
      uVar2 = 0xffffff00;
      if ((uVar4 & 0xc0000000) == 0x80000000) {
        uVar2 = 0xffff0000;
      }
    }
    *(undefined4 *)(param_2 + 0x16) = uVar2;
    uVar3 = *(uint *)(param_2 + 0x1a);
    *(uint *)(param_2 + 0x14) = uVar4 & *(uint *)(param_2 + 0x16);
    *(uint *)(param_2 + 0x1a) = uVar3 | *(uint *)(param_2 + 0x16);
    *(uint *)(param_2 + 0x18) = uVar4 & (uVar3 | *(uint *)(param_2 + 0x16));
    if ((*(word *)(param_1 + 0xc) & 2) != 0) {
      param_2[8] = 2;
      uVar2 = *(undefined4 *)(param_2 + 0x18);
      _in_makeaddr(uVar2,0xffffffff);
      *(undefined4 *)(param_2 + 10) = uVar2;
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x14) | ~*(uint *)(param_2 + 0x16);
    }
    if ((*(word *)(param_1 + 0xc) & 8) == 0) {
      if ((*(word *)(param_1 + 0xc) & 0x10) == 0) {
        uVar2 = *(undefined4 *)(param_2 + 0x18);
        _in_makeaddr(uVar2,0);
        *(undefined4 *)((int)register0x00000038 + -0x24) = uVar2;
        puVar6 = (undefined2 *)((int)register0x00000038 + -0x28);
        uVar2 = 1;
      }
      else {
        puVar6 = param_2 + 8;
        uVar2 = 5;
      }
    }
    else {
      uVar2 = 5;
      puVar6 = param_2;
    }
    iVar5 = 0;
    _rtinit(puVar6,param_2,0x8030720a,uVar2);
    *(uint *)(param_2 + 0x1e) = *(uint *)(param_2 + 0x1e) | 1;
    *(undefined4 *)((int)register0x00000038 + -0x2c) = 0xe0000001;
    _in_addmulti((undefined *)((int)register0x00000038 + -0x2c),param_1);
    _splx(iVar1);
  }
  else {
    _splx(iVar1);
    *param_2 = *(undefined2 *)((int)register0x00000038 + -0x18);
    param_2[1] = *(undefined2 *)((int)register0x00000038 + -0x16);
    param_2[2] = *(undefined2 *)((int)register0x00000038 + -0x14);
    param_2[3] = *(undefined2 *)((int)register0x00000038 + -0x12);
    param_2[4] = *(undefined2 *)((int)register0x00000038 + -0x10);
    param_2[5] = *(undefined2 *)((int)register0x00000038 + -0xe);
    param_2[6] = *(undefined2 *)((int)register0x00000038 + -0xc);
    param_2[7] = *(undefined2 *)((int)register0x00000038 + -10);
  }
  return CONCAT44(param_2,iVar5);
}

