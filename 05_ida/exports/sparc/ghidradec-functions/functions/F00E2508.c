
undefined8 _audio_linear8_peak(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  byte *pbVar5;
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
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar4 = 0;
    if (param_3 >> 1 == 0) {
      uVar1 = *param_4;
    }
    else {
      do {
        bVar3 = *param_2 ^ 0x80;
        bVar2 = bVar3 | *param_2 & 0x7f;
        if ((bVar3 & 0x80) != 0) {
          bVar2 = -bVar2;
        }
        if (*param_4 < (uint)(int)(char)bVar2) {
          *param_4 = (int)(char)bVar2;
        }
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 2;
      } while (uVar4 < param_3 >> 1);
      uVar1 = *param_4;
    }
    *param_5 = uVar1;
  }
  else {
    uVar4 = 0;
    if (param_3 >> 1 == 0) {
      uVar1 = *param_5;
      goto loc_F00E2628;
    }
    bVar2 = *param_2;
    while( true ) {
      pbVar5 = param_2 + 1;
      bVar3 = bVar2 ^ 0x80 | bVar2 & 0x7f;
      if (((bVar2 ^ 0x80) & 0x80) != 0) {
        bVar3 = -bVar3;
      }
      if (*param_4 < (uint)(int)(char)bVar3) {
        *param_4 = (int)(char)bVar3;
      }
      param_2 = param_2 + 2;
      bVar3 = *pbVar5 ^ 0x80;
      bVar2 = bVar3 | *pbVar5 & 0x7f;
      if ((bVar3 & 0x80) != 0) {
        bVar2 = -bVar2;
      }
      if (*param_5 < (uint)(int)(char)bVar2) {
        *param_5 = (int)(char)bVar2;
      }
      uVar4 = uVar4 + 1;
      if (param_3 >> 1 <= uVar4) break;
      bVar2 = *param_2;
    }
  }
  uVar1 = *param_5;
loc_F00E2628:
  *param_5 = uVar1 << 8;
  *param_4 = *param_4 << 8;
  return CONCAT44(param_2,uVar4);
}
