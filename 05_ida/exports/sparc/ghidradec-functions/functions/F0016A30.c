
/* WARNING: Removing unreachable block (ram,0xf0016ad8) */
/* WARNING: Removing unreachable block (ram,0xf0016a70) */
/* WARNING: Removing unreachable block (ram,0xf0016a48) */
/* WARNING: Removing unreachable block (ram,0xf0016a5c) */
/* WARNING: Removing unreachable block (ram,0xf0016abc) */
/* WARNING: Removing unreachable block (ram,0xf0016b00) */
/* WARNING: Removing unreachable block (ram,0xf0016a34) */

undefined8 _ttyflush(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
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
  if ((param_2 & 1) != 0) {
    do {
      iVar2 = param_1 + 0xc;
      _getc();
    } while (-1 < iVar2);
    _wakeup(param_1);
  }
  if ((param_2 & 2) != 0) {
    _wakeup(param_1 + 0x18);
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffeff;
    (**(code **)(DAT_f011ca04 + (uint)(*(word *)(param_1 + 0x38) >> 8) * 0x2c))(param_1,param_2);
    do {
      iVar2 = param_1 + 0x18;
      _getc();
    } while (-1 < iVar2);
  }
  if ((param_2 & 1) != 0) {
    do {
      iVar2 = param_1;
      _getc();
    } while (-1 < iVar2);
    *(undefined *)(param_1 + 0x4b) = 0;
    *(undefined *)(param_1 + 0x4c) = 0;
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xff40ffff;
  }
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
