
/* WARNING: Removing unreachable block (ram,0xf001e370) */
/* WARNING: Removing unreachable block (ram,0xf001e3bc) */
/* WARNING: Removing unreachable block (ram,0xf001e3c8) */
/* WARNING: Removing unreachable block (ram,0xf001e344) */

undefined8
_mclgetx(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
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
  uVar2 = param_1;
  _spltty();
  puVar1 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    _m_more(param_5,1);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_4);
    }
    *(undefined2 *)((int)puVar1 + 10) = 1;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
    _mfree = (undefined4 *)*puVar1;
    puVar1[1] = 0xc;
    *puVar1 = 0;
    param_5 = puVar1;
  }
  _splx(uVar2);
  if (param_5 == (undefined4 *)0x0) {
    param_5 = (undefined4 *)0x0;
  }
  else {
    param_5[1] = param_3 - (int)param_5;
    *(undefined2 *)(param_5 + 2) = param_4;
    *(undefined2 *)(param_5 + 3) = 2;
    param_5[4] = param_1;
    param_5[5] = param_2;
    param_5[6] = 0;
  }
  return CONCAT44(param_2,param_5);
}
