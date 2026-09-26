
/* WARNING: Removing unreachable block (ram,0xf002e570) */
/* WARNING: Removing unreachable block (ram,0xf002e564) */

undefined8 _localetheraddr(undefined *param_1,undefined *param_2)

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
  undefined4 uVar2;
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
  if (dword_F010C474 == 0) {
    dword_F010C474 = 1;
    if (param_1 == (undefined *)0x0) {
      uVar2 = 0;
      goto locret_F002E5BC;
    }
    byte_F012F418 = *param_1;
    DAT_f012f419._0_1_ = param_1[1];
    puVar1 = &byte_F012F418;
    DAT_f012f419._1_1_ = param_1[2];
    DAT_f012f419._2_1_ = param_1[3];
    DAT_f012f419._3_1_ = param_1[4];
    DAT_f012f419._4_1_ = param_1[5];
    _ether_sprintf();
    _printf(aEthernetAddres,puVar1);
  }
  if (param_2 != (undefined *)0x0) {
    *param_2 = byte_F012F418;
    param_2[1] = DAT_f012f419._0_1_;
    param_2[2] = DAT_f012f419._1_1_;
    param_2[3] = DAT_f012f419._2_1_;
    param_2[4] = DAT_f012f419._3_1_;
    param_2[5] = (undefined)DAT_f012f419;
  }
  uVar2 = 1;
locret_F002E5BC:
  return CONCAT44(param_2,uVar2);
}

