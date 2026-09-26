
/* WARNING: Removing unreachable block (ram,0xf0098cc4) */
/* WARNING: Removing unreachable block (ram,0xf0098cd4) */
/* WARNING: Removing unreachable block (ram,0xf0098ca0) */

undefined8 _fp_traps(int param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
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
  
  iVar1 = _fptraprp;
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
  if (_fptraprp != 0) {
    _fptraprp = 0;
    param_3 = iVar1;
  }
  if (param_2 == 3) {
    uVar2 = 2;
loc_F0098CBC:
    uVar3 = *(undefined4 *)(param_1 + 0x20);
    uVar4 = 0;
loc_F0098CC4:
    _trap(uVar2,param_3,uVar3,uVar4,0);
  }
  else {
    if (param_2 < 4) {
      if (param_2 == 1) {
        uVar3 = *(undefined4 *)(param_1 + 0x20);
        uVar2 = 8;
        uVar4 = *(undefined4 *)(param_1 + 0x1c);
        goto loc_F0098CC4;
      }
    }
    else {
      if (param_2 == 5) {
        uVar2 = 7;
        goto loc_F0098CBC;
      }
      if (param_2 == 6) {
        _trap(9,param_3,*(undefined4 *)(param_1 + 0x20),_beval,*(undefined4 *)(param_1 + 0x28));
        goto loc_F0098CE0;
      }
    }
    _panic(aFpTrapsBadFtt);
  }
loc_F0098CE0:
  _fptraprp = iVar1;
  return CONCAT44(param_2,param_1);
}

