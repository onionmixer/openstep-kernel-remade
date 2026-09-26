
/* WARNING: Removing unreachable block (ram,0xf002d9b4) */
/* WARNING: Removing unreachable block (ram,0xf002d9c0) */
/* WARNING: Removing unreachable block (ram,0xf002d944) */

undefined8 _arpinput(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
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
  undefined4 uVar1;
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
  uVar1 = *param_3;
  if (((*(word *)(param_1 + 0xc) & 0x80) == 0) && (7 < *(word *)(param_4 + 8))) {
    _bcopy(param_4 + *(int *)(param_4 + 4),(undefined *)((int)register0x00000038 + -0x10),8);
    if (((*(sword *)((int)register0x00000038 + -0x10) == 1) &&
        (((uint)DAT_f010c358[0] + (uint)DAT_f010c358[1]) * 2 + 8 <=
         (uint)(int)*(sword *)(param_4 + 8))) &&
       ((*(sword *)((int)register0x00000038 + -0xe) == 0x800 ||
        (*(sword *)((int)register0x00000038 + -0xe) == 0x1000)))) {
      *(undefined4 *)((int)register0x00000038 + -0x14) = uVar1;
      _in_arpinput(param_1,param_2,(undefined *)((int)register0x00000038 + -0x14),param_4);
      goto locret_F002D9C8;
    }
  }
  _m_freem(param_4);
locret_F002D9C8:
  return CONCAT44(param_2,param_1);
}

