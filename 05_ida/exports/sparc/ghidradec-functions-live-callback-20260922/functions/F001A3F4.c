
/* WARNING: Removing unreachable block (ram,0xf001a51c) */
/* WARNING: Removing unreachable block (ram,0xf001a490) */

undefined8 _ttyecho(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *param_2;
  if ((*(uint *)(iVar3 + 0x40) & 0x200000) == 0) {
    *(uint *)(iVar3 + 0x3c) = *(uint *)(iVar3 + 0x3c) & 0xff7fffff;
    uVar2 = *(uint *)(iVar3 + 0x3c);
  }
  else {
    uVar2 = *(uint *)(iVar3 + 0x3c);
  }
  if ((uVar2 & 8) == 0) {
    if (((param_2[4] & 2U) == 0) || (param_1 != 10)) goto locret_F001A524;
    uVar1 = *(uint *)(iVar3 + 0x40);
  }
  else {
    uVar1 = *(uint *)(iVar3 + 0x40);
  }
  if ((uVar1 & 0x400000) == 0) {
    if (((uVar2 & 0x10000000) != 0) &&
       ((((param_1 & 0xff) < 0x20 && (1 < param_1 - 9)) || ((param_1 & 0xff) == 0x7f)))) {
      _ttyoutput(0x5e,iVar3);
      param_1 = param_1 & 0xff;
      if (param_1 == 0x7f) {
        param_1 = 0x3f;
      }
      else if ((*(uint *)(iVar3 + 0x3c) & 4) == 0) {
        param_1 = param_1 + 0x40;
      }
      else {
        param_1 = param_1 + 0x60;
      }
    }
    param_1 = param_1 & 0xff;
    if (((0x1f < param_1) &&
        ((((*(uint *)(iVar3 + 0x3c) & 0x8000000) != 0 || ((param_2[4] & 0x400000U) != 0)) ||
         (param_1 < 0x7f)))) || ((param_1 - 7 < 4 || (param_1 == 0xd)))) {
      _ttyoutput(param_1,iVar3);
    }
  }
locret_F001A524:
  return CONCAT44(param_2,param_1);
}

