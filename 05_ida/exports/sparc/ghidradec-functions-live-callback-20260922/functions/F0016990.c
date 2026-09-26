
/* WARNING: Removing unreachable block (ram,0xf0016a20) */
/* WARNING: Removing unreachable block (ram,0xf00169b8) */
/* WARNING: Removing unreachable block (ram,0xf00169f0) */
/* WARNING: Removing unreachable block (ram,0xf0016994) */

undefined8 _ttywait(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
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
  iVar1 = param_1;
  _spltty();
  iVar3 = *(int *)(param_1 + 0x18);
  do {
    if (iVar3 == 0) {
      if ((*(uint *)(param_1 + 0x40) & 0x2000020) == 0) {
loc_F0016A20:
        _splx(iVar1);
        return CONCAT44(param_2,param_1);
      }
      uVar2 = *(uint *)(param_1 + 0x40);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x40);
    }
    if ((uVar2 & 0x10) == 0) {
      iVar3 = param_1;
      _ttynty();
      if ((*(uint *)(iVar3 + 0x10) & 0x8000) == 0) goto loc_F0016A20;
      pcVar4 = *(code **)(param_1 + 0x24);
    }
    else {
      pcVar4 = *(code **)(param_1 + 0x24);
    }
    (*pcVar4)(param_1);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
    _sleep(param_1 + 0x18,0x1d);
    iVar3 = *(int *)(param_1 + 0x18);
  } while( true );
}

