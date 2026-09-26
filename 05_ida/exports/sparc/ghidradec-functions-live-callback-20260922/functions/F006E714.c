
/* WARNING: Removing unreachable block (ram,0xf006e7d4) */
/* WARNING: Removing unreachable block (ram,0xf006e80c) */
/* WARNING: Removing unreachable block (ram,0xf006e804) */
/* WARNING: Removing unreachable block (ram,0xf006e7c0) */
/* WARNING: Removing unreachable block (ram,0xf006e794) */
/* WARNING: Removing unreachable block (ram,0xf006e71c) */

undefined8 sub_F006E714(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0xc);
  _PMGetPowerEvent();
  if (puVar1 == (undefined *)0x0) {
    switch(*(undefined4 *)((int)register0x00000038 + -0xc)) {
    case :
    case :
      dword_F012F928 = 1;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
      _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10));
      break;
    case :
    case :
    case :
      dword_F012F928 = 2;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
      _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10),2);
      dword_F012F928 = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
      _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10),0);
      break;
    case :
    case :
    case :
      if (dword_F012F928 != 0) {
        dword_F012F928 = 0;
        *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
        _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10),0);
      }
    case :
      _PMUpdateClock();
    :
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  return CONCAT44(param_2,puVar1);
}

