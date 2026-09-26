
/* WARNING: Removing unreachable block (ram,0xf001a74c) */
/* WARNING: Removing unreachable block (ram,0xf001a71c) */

undefined8
_tty_ld_install(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar1;
  undefined4 unaff_l3;
  undefined4 uVar2;
  undefined4 unaff_l4;
  undefined4 uVar3;
  undefined4 unaff_l5;
  undefined4 uVar4;
  undefined4 unaff_l6;
  undefined4 uVar5;
  undefined4 unaff_l7;
  undefined4 uVar6;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x60);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 100);
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x6c);
  uVar6 = *(undefined4 *)((int)register0x00000038 + 0x70);
  if (-1 < param_1) {
    if (_nldisp <= param_1) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    param_1 = param_1 * 0x30;
    uVar7 = 0xffffffff;
    if (*(code **)(_linesw + param_1) != _nodev) goto locret_F001A758;
    if (*(code **)(_linesw + param_1 + 4) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 8) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0xc) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x10) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x14) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x18) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x20) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x24) != _nodev) {
      uVar7 = 0xffffffff;
      goto locret_F001A758;
    }
    if (*(code **)(_linesw + param_1 + 0x28) == _nodev) {
      _spltty();
      *(undefined4 *)(_linesw + param_1 + 0x2c) = param_2;
      *(undefined4 *)(_linesw + param_1) = param_3;
      *(undefined4 *)(_linesw + param_1 + 4) = param_4;
      *(undefined4 *)(_linesw + param_1 + 8) = param_5;
      *(undefined4 *)(_linesw + param_1 + 0xc) = param_6;
      *(undefined4 *)(_linesw + param_1 + 0x10) = uVar1;
      *(undefined4 *)(_linesw + param_1 + 0x14) = uVar2;
      *(undefined4 *)(_linesw + param_1 + 0x18) = uVar3;
      *(undefined4 *)(_linesw + param_1 + 0x20) = uVar4;
      *(undefined4 *)(_linesw + param_1 + 0x24) = uVar5;
      *(undefined4 *)(_linesw + param_1 + 0x28) = uVar6;
      _splx();
      uVar7 = 0;
      goto locret_F001A758;
    }
  }
  uVar7 = 0xffffffff;
locret_F001A758:
  return CONCAT44(param_2,uVar7);
}
