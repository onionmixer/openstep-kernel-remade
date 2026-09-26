
/* WARNING: Removing unreachable block (ram,0xf0052880) */
/* WARNING: Removing unreachable block (ram,0xf005285c) */
/* WARNING: Removing unreachable block (ram,0xf00528fc) */
/* WARNING: Removing unreachable block (ram,0xf005282c) */

undefined8 sub_F00527B4(int param_1,int param_2,undefined4 param_3)

{
  word wVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
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
  iVar3 = param_1;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))
            (param_1,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar3 == 0) {
    param_1 = *(int *)((int)register0x00000038 + -0xc);
  }
  iVar3 = *(int *)(param_1 + 0x30);
  if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) ||
     ((*(word *)(iVar3 + 100) & 0xf000) != 0x4000)) {
    uVar2 = *(word *)(iVar3 + 100) & 0xf000;
    if ((uVar2 == 0x4000) && (_suser(0x4000,param_3), uVar2 == 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x30);
      _direnter(uVar4,param_3,1,0,iVar3,0,0);
      if ((*(word *)(iVar3 + 0x44) & 0x46) != 0) {
        *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 8;
        _microtime(&_iuniqtime);
        if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
          *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
        }
        if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
          *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(iVar3 + 0x44) & 0x40) == 0) {
          wVar1 = *(word *)(iVar3 + 0x44);
        }
        else {
          *(undefined4 *)(iVar3 + 0x4c) = 0;
          *(undefined4 *)(iVar3 + 0x84) = _iuniqtime;
          wVar1 = *(word *)(iVar3 + 0x44);
        }
        *(word *)(iVar3 + 0x44) = wVar1 & 0xffb9;
      }
      wVar1 = *(word *)(*(int *)(param_2 + 0x30) + 0x44);
      if ((wVar1 & 0x46) != 0) {
        *(word *)(*(int *)(param_2 + 0x30) + 0x44) = wVar1 | 8;
        _microtime(&_iuniqtime);
        iVar3 = *(int *)(param_2 + 0x30);
        if ((*(word *)(iVar3 + 0x44) & 4) != 0) {
          *(undefined4 *)(iVar3 + 0x74) = _iuniqtime;
          iVar3 = *(int *)(param_2 + 0x30);
        }
        if ((*(word *)(iVar3 + 0x44) & 2) != 0) {
          *(undefined4 *)(iVar3 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(*(int *)(param_2 + 0x30) + 0x44) & 0x40) == 0) {
          iVar3 = *(int *)(param_2 + 0x30);
        }
        else {
          *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x4c) = 0;
          *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x84) = _iuniqtime;
          iVar3 = *(int *)(param_2 + 0x30);
        }
        *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) & 0xffb9;
      }
    }
  }
  else {
    uVar4 = 1;
  }
  return CONCAT44(param_2,uVar4);
}
