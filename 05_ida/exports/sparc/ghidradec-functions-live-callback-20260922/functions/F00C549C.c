
undefined8 -[IODevice errnoFromReturn:](undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  uVar1 = 0x2d;
  if (param_3 != -0x2c7) {
    if (param_3 < -0x2c6) {
      uVar1 = 5;
      if (param_3 != -0x2d1) {
        if (param_3 < -0x2d0) {
          if (param_3 != -0x2d4) {
            if (param_3 < -0x2d3) {
              uVar1 = 0x10;
              if (param_3 != -0x2d5) {
                uVar1 = 5;
              }
            }
            else {
              uVar1 = 0x10;
              if (param_3 != -0x2d2) {
                uVar1 = 5;
              }
            }
          }
        }
        else {
          uVar1 = 5;
          if (((param_3 < -0x2cb) && (uVar1 = 0xd, param_3 < -0x2ce)) &&
             (uVar1 = 0x1e, param_3 != -0x2cf)) {
            uVar1 = 5;
          }
        }
      }
    }
    else if (param_3 == -0x2c1) {
      uVar1 = 0xd;
    }
    else if (param_3 < -0x2c0) {
      if (param_3 < -0x2c5) {
        uVar1 = 5;
      }
      else {
        uVar1 = 0xd;
        if (-0x2c3 < param_3) {
          uVar1 = 0x16;
        }
      }
    }
    else if (param_3 < -700) {
      uVar1 = 0xc;
      if ((param_3 < -0x2be) && (uVar1 = 6, param_3 != -0x2c0)) {
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 5;
      if (param_3 == 0) {
        uVar1 = 0;
      }
    }
  }
  return CONCAT44(param_2,uVar1);
}

