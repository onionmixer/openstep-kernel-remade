
undefined8 _bzero(undefined8 *param_1,uint param_2)

{
  undefined4 unaff_g1;
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
  uint uVar1;
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
  if ((int)param_2 < 0xf) {
loc_F0094F60:
    while (0 < (int)param_2) {
      *(undefined *)param_1 = 0;
      param_1 = (undefined8 *)((int)param_1 + 1);
      param_2 = param_2 - 1;
    }
    return CONCAT44(param_2 - 1,unaff_g1);
  }
  uVar1 = 0x100;
  for (; ((uint)param_1 & 3) != 0; param_1 = (undefined8 *)((int)param_1 + 1)) {
    *(undefined *)param_1 = 0;
    param_2 = param_2 - 1;
  }
  unaff_g1 = 0;
  if (((uint)param_1 & 7) != 0) {
    *(undefined4 *)param_1 = 0;
    param_2 = param_2 - 4;
    param_1 = (undefined8 *)((int)param_1 + 4);
  }
  do {
    if (0xff < (int)param_2) {
      param_1[0x1f] = 0;
loc_F0094EA8:
      param_1[0x1e] = 0;
      goto loc_f0094eac;
    }
    uVar1 = param_2 & 0xfffffff8;
    switch(param_2) {
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
loc_f0094eac:
      param_1[0x1d] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x1c] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x1b] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x1a] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x19] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x18] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x17] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x16] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x15] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x14] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x13] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x12] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x11] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0x10] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xf] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xe] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xd] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xc] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[0xb] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[10] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[9] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[8] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[7] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[6] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[5] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[4] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[3] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[2] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      param_1[1] = 0;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      *param_1 = 0;
      param_1 = (undefined8 *)((int)param_1 + uVar1);
      param_2 = param_2 - uVar1;
      break;
    case :
    case :
    case :
    case :
    case :
    case :
    case :
    case :
      goto loc_F0094EA8;
    :
      goto loc_F0094F60;
    }
  } while( true );
}

