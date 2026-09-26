
undefined8 _PCPatoi(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar3;
  undefined4 unaff_i2;
  int iVar4;
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
  iVar4 = 0;
  bVar2 = false;
  do {
    bVar1 = *param_1;
    if (bVar1 == 0x2b) {
loc_F00C0A8C:
      param_1 = param_1 + 1;
      uVar3 = (uint)*param_1;
loc_F00C0AB4:
      while ((uVar3 - 0x30 & 0xff) < 10) {
        param_1 = param_1 + 1;
        iVar4 = iVar4 * 10 + (int)(char)uVar3 + -0x30;
        uVar3 = (uint)*param_1;
      }
      if (bVar2) {
        iVar4 = -iVar4;
      }
      return CONCAT44(uVar3,iVar4);
    }
    if ('+' < (char)bVar1) {
      if (bVar1 != 0x2d) {
        uVar3 = (uint)*param_1;
        goto loc_F00C0AB4;
      }
      bVar2 = true;
      goto loc_F00C0A8C;
    }
    if (bVar1 == 9) {
      param_1 = param_1 + 1;
    }
    else {
      if (bVar1 != 0x20) {
        uVar3 = (uint)*param_1;
        goto loc_F00C0AB4;
      }
      param_1 = param_1 + 1;
    }
  } while( true );
}

