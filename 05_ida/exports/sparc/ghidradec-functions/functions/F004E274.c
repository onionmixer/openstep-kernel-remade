
/* WARNING: Removing unreachable block (ram,0xf004e2a8) */
/* WARNING: Removing unreachable block (ram,0xf004e308) */
/* WARNING: Removing unreachable block (ram,0xf004e288) */

undefined8 _irele(int param_1,undefined4 param_2)

{
  word wVar1;
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
  if ((*(word *)(param_1 + 0x44) & 1) != 0) {
    _panic(&aIrele);
  }
  if ((*(word *)(param_1 + 0x44) & 0x46) != 0) {
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(param_1 + 0x44) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(param_1 + 0x44) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(param_1 + 0x44) & 0x40) == 0) {
      wVar1 = *(word *)(param_1 + 0x44);
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = wVar1 & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return CONCAT44(param_2,param_1);
}
