
/* WARNING: Removing unreachable block (ram,0xf00bb0e8) */
/* WARNING: Removing unreachable block (ram,0xf00bb090) */

undefined8 _zslevel6intr(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = 0;
  uVar1 = *(uint *)(_zscurr + 0x10);
  uVar4 = _zscurr;
  while ((uVar2 = uVar1 | 4, uVar1 == 0 || (_zszread(uVar2,3), uVar2 == 0))) {
    uVar4 = uVar4 + 0x80;
    if (_zslast < uVar4) {
      uVar4 = _zscom + 0x40;
    }
    iVar5 = iVar5 + 1;
    uVar1 = _zsNcurr._0_4_;
    if (1 < iVar5 * 0x10000 >> 0x10) goto locret_F00BB180;
    uVar1 = *(uint *)(uVar4 + 0x10);
  }
  uVar2 = *(uint *)(uVar4 + 0x10);
  _zscurr = uVar4;
  _zszread(uVar2,2);
  uVar1 = _zscurr;
  if ((uVar2 & 8) != 0) {
    uVar1 = _zscurr - 0x40;
  }
  uVar2 = uVar2 & 6;
  if (uVar2 == 2) {
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 8);
  }
  else if (uVar2 < 3) {
    if (uVar2 != 0) goto locret_F00BB180;
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 4);
  }
  else if (uVar2 == 4) {
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 0xc);
  }
  else {
    if (uVar2 != 6) goto locret_F00BB180;
    pcVar3 = *(code **)(*(int *)(uVar1 + 0x1c) + 0x10);
  }
  (*pcVar3)(uVar1);
locret_F00BB180:
  _zsNcurr._0_4_ = uVar1;
  return CONCAT44(param_2,param_1);
}
