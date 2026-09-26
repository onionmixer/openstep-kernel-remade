
/* WARNING: Removing unreachable block (ram,0xf00bb778) */
/* WARNING: Removing unreachable block (ram,0xf00bb80c) */
/* WARNING: Removing unreachable block (ram,0xf00bb71c) */

undefined8 _kmopen(uint param_1,undefined4 param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _cons_tp;
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
  uVar3 = _kmId;
  _objc_msgSend(_kmId,paKmopen,param_2);
  if (uVar3 == 0) {
    *(undefined4 *)(iVar1 + 0x34) = 0;
    *(code **)(iVar1 + 0x24) = sub_F00BBDB4;
    *(undefined *)(iVar1 + 0x47) = 2;
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      _ttychars(iVar1);
      *(undefined4 *)(iVar1 + 0x3c) = 0x140700d8;
      *(undefined *)(iVar1 + 0x4d) = 0x7f;
      *(undefined *)(iVar1 + 0x4a) = 0xd;
      *(undefined *)(iVar1 + 0x49) = 0xd;
      *(undefined4 *)(iVar1 + 0x40) = 0x10;
    }
    else if (((*(uint *)(iVar1 + 0x40) & 0x80) != 0) &&
            (uVar3 = 0x10, *(sword *)(*(int *)(_active_u + 0x1c) + 2) != 0)) goto locret_F00BB8AC;
    uVar3 = (uint)(sword)param_1;
    (**(code **)(_linesw + *(char *)(iVar1 + 0x47) * 0x30))(uVar3,iVar1);
    if (uVar3 == 0) {
      if ((param_1 & 0xff) == 2) {
        uVar3 = (uint)_kbddev;
        _kbdopen(uVar3,_zs_tty + (uVar3 & 0xff) * 0x88);
      }
      if (uVar3 == 0) {
        *(undefined2 *)(iVar1 + 0x5c) = 0;
        *(undefined2 *)(iVar1 + 0x5e) = 0;
        *(undefined2 *)(iVar1 + 0x60) = 0;
        *(undefined2 *)(iVar1 + 0x62) = 0;
        if (cRamfeffe016 == '\x13') {
          sVar2 = (sword)(char)bRamfeffe050;
          if (bRamfeffe050 < 10) {
            sVar2 = 0x50;
          }
          else if (0x78 < bRamfeffe050) {
            sVar2 = 0x78;
          }
          *(sword *)(iVar1 + 0x5e) = sVar2;
          sVar2 = (sword)(char)bRamfeffe051;
          if (bRamfeffe051 < 10) {
            sVar2 = 0x22;
          }
          else if (0x30 < bRamfeffe051) {
            sVar2 = 0x30;
          }
          *(sword *)(iVar1 + 0x5c) = sVar2;
        }
      }
    }
  }
locret_F00BB8AC:
  return CONCAT44(param_2,uVar3);
}

