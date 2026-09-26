
/* WARNING: Removing unreachable block (ram,0xf0061448) */
/* WARNING: Removing unreachable block (ram,0xf0061438) */

undefined8 _msg_return_translate(uint param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = param_1 & 0xffffc3ff;
  if ((int)uVar1 < 0x1000000f) {
    if (0x1000000c < (int)uVar1) {
      _printf(aMsgReturnTrans);
loc_F0061440:
      param_1 = 0xffffff94;
      goto locret_F0061450;
    }
    if (uVar1 == 0x10000006) {
      param_1 = 0xffffff96;
      goto locret_F0061450;
    }
    if ((int)uVar1 < 0x10000007) {
      if (uVar1 == 0x10000002) {
        param_1 = 0xffffff9b;
        goto locret_F0061450;
      }
      if (0x10000002 < (int)uVar1) {
        param_1 = 0xffffff99;
        if ((uVar1 != 0x10000004) && (param_1 = 0xffffff97, (int)uVar1 < 0x10000005)) {
          param_1 = 0xffffff9a;
        }
        goto locret_F0061450;
      }
      param_1 = 0;
      if (uVar1 == 0) goto locret_F0061450;
    }
    else if ((int)uVar1 < 0x1000000b) {
      param_1 = 0xffffff9a;
      if (0x10000008 < (int)uVar1) goto locret_F0061450;
      if (uVar1 == 0x10000007) goto loc_F0061440;
      param_1 = 0xffffff92;
      if (uVar1 == 0x10000008) goto locret_F0061450;
    }
    else if ((uVar1 != 0x1000000b) && (param_1 = 0xffffff9b, uVar1 == 0x1000000c))
    goto locret_F0061450;
  }
  else {
    param_1 = 0xffffff31;
    if (uVar1 == 0x10004005) goto locret_F0061450;
    if ((int)uVar1 < 0x10004006) {
      if (uVar1 != 0x10004001) {
        if (0x10004001 < (int)uVar1) {
          param_1 = 0xffffff35;
          if ((uVar1 != 0x10004003) && (param_1 = 0xffffff34, (int)uVar1 < 0x10004004)) {
            param_1 = 0xffffff36;
          }
          goto locret_F0061450;
        }
        param_1 = 0xffffff9a;
        if (uVar1 == 0x1000000f) goto locret_F0061450;
      }
    }
    else if ((int)uVar1 < 0x1000400b) {
      param_1 = 0xffffff36;
      if (0x10004008 < (int)uVar1) goto locret_F0061450;
      if (uVar1 != 0x10004007) {
        param_1 = 0xffffff37;
        if ((int)uVar1 < 0x10004008) {
          param_1 = 0xffffff30;
        }
        goto locret_F0061450;
      }
    }
  }
  _panic(aMsgReturnTrans_0);
locret_F0061450:
  return CONCAT44(param_2,param_1);
}
