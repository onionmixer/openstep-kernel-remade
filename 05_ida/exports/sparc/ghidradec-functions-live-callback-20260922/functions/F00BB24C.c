
/* WARNING: Removing unreachable block (ram,0xf00bb3d0) */
/* WARNING: Removing unreachable block (ram,0xf00bb37c) */
/* WARNING: Removing unreachable block (ram,0xf00bb34c) */
/* WARNING: Removing unreachable block (ram,0xf00bb31c) */
/* WARNING: Removing unreachable block (ram,0xf00bb2ec) */
/* WARNING: Removing unreachable block (ram,0xf00bb288) */
/* WARNING: Removing unreachable block (ram,0xf00bb2c4) */
/* WARNING: Removing unreachable block (ram,0xf00bb304) */
/* WARNING: Removing unreachable block (ram,0xf00bb334) */
/* WARNING: Removing unreachable block (ram,0xf00bb364) */
/* WARNING: Removing unreachable block (ram,0xf00bb3b8) */
/* WARNING: Removing unreachable block (ram,0xf00bb400) */
/* WARNING: Removing unreachable block (ram,0xf00bb258) */

undefined8 _zsnull_attach(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  sword sVar4;
  undefined4 uVar3;
  undefined4 uVar5;
  undefined4 unaff_l0;
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
  _zsopinit(param_1,_zsops_null);
  sVar4 = *(sword *)(param_1 + 0x14);
  bVar1 = false;
  if (sVar4 == 0) {
    iVar2 = *(int *)(*_zsinfo + 0x28);
    _getprop(iVar2,aPortARtsDtrOff,0);
    if (iVar2 == 0) {
      sVar4 = *(sword *)(param_1 + 0x14);
      goto loc_F00BB2A0;
    }
  }
  else {
loc_F00BB2A0:
    if (sVar4 != 1) goto loc_F00BB2E0;
    iVar2 = *(int *)(_zsinfo[1] + 0x28);
    _getprop(iVar2,aPortBRtsDtrOff,0);
    if (iVar2 == 0) goto loc_F00BB2E0;
  }
  bVar1 = true;
loc_F00BB2E0:
  *(undefined *)(param_1 + 0x24) = 0x46;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),4,0x46);
  *(undefined *)(param_1 + 0x23) = 0xc0;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),3,0xc0);
  *(undefined *)(param_1 + 0x2b) = 0x50;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xb,0x50);
  *(char *)(param_1 + 0x2c) = (char)param_2;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xc,param_2 & 0xff);
  *(char *)(param_1 + 0x2d) = (char)(param_2 >> 8);
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xd,param_2 >> 8 & 0xff);
  *(undefined *)(param_1 + 0x2e) = 2;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xe,2);
  *(undefined *)(param_1 + 0x23) = 0xc1;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),3,0xc1);
  if (bVar1) {
    *(undefined *)(param_1 + 0x25) = 0x68;
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    uVar5 = 0x68;
  }
  else {
    *(undefined *)(param_1 + 0x25) = 0xea;
    uVar3 = *(undefined4 *)(param_1 + 0x10);
    uVar5 = 0xea;
  }
  _zszwrite(uVar3,5,uVar5);
  *(undefined *)(param_1 + 0x2e) = 3;
  _zszwrite(*(undefined4 *)(param_1 + 0x10),0xe,3);
  if ((word)(*(sword *)(param_1 + 0x14) - 2U) < 2) {
    *(undefined *)(param_1 + 0x2f) = 0xe8;
    _zszwrite(*(undefined4 *)(param_1 + 0x10),0xf,0xe8);
  }
  **(undefined **)(param_1 + 0x10) = 0x40;
  return CONCAT44(param_2,param_1);
}

