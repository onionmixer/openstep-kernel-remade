
/* WARNING: Removing unreachable block (ram,0xf00b109c) */

undefined8 _decode_address(uint param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
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
  uVar1 = param_2;
  if (param_1 == 0xffffffff) {
    puVar2 = (undefined *)&aVirtual;
  }
  else {
    puVar2 = (undefined *)&_ukbuf;
    _ukbuf._6_1_ = a0123456789abcd_1[param_1 & 0xf];
    if (_cpu == 0x72) {
      if (param_1 != 0xe) {
        if (0xe < param_1) {
          puVar2 = (undefined *)&_ukbuf;
          if (param_1 == 0xf) {
            if (param_2 < 0xf1000000) {
              puVar2 = (undefined *)&aSys;
            }
            else {
              puVar2 = (undefined *)&aObio_0;
              uVar1 = param_2 + 0xf000000;
            }
          }
          goto loc_F00B1098;
        }
        if (param_1 != 0) goto loc_F00B1098;
      }
      puVar2 = aSbusSlot;
      aSbusSlot[10] = a0123456789abcd_2[param_2 >> 0x1c];
      uVar1 = param_2 & 0xfffffff;
    }
  }
loc_F00B1098:
  _printf(aS0xX_1,puVar2,uVar1);
  return CONCAT44(param_2,param_1);
}

