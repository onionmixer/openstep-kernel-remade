
/* WARNING: Removing unreachable block (ram,0xf005cce4) */

undefined8 _ipc_right_info(int param_1,undefined4 param_2,uint *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  uVar4 = *param_3;
  if ((uVar4 & 0x50000) != 0) {
    puVar5 = (undefined4 *)param_3[1];
    iVar1 = param_1;
    _ipc_right_check(param_1,puVar5,param_2,param_3);
    if (iVar1 == 0) {
      *puVar5 = 0;
    }
    else {
      if ((uVar4 & 0x400000) != 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        uVar6 = 0xf;
        goto locret_F005CD70;
      }
      uVar4 = *param_3;
    }
  }
  uVar3 = uVar4 & 0x1f0000;
  if ((uVar4 & 0x400000) == 0) {
    uVar2 = 0x80000000;
    if (param_3[2] != 0) goto loc_F005CD40;
  }
  else {
    uVar2 = 0x20000000;
loc_F005CD40:
    uVar3 = uVar3 | uVar2;
  }
  if ((uVar4 & 0x200000) != 0) {
    uVar3 = uVar3 | 0x40000000;
  }
  *param_4 = uVar3;
  *param_5 = uVar4 & 0xffff;
  uVar6 = 0;
locret_F005CD70:
  return CONCAT44(param_2,uVar6);
}
