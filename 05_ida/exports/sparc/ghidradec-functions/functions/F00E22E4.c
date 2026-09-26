
undefined8 _audio_mulaw8_peak(int param_1,byte *param_2,uint param_3,uint *param_4,uint *param_5)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  *param_5 = 0;
  *param_4 = 0;
  if (param_1 == 1) {
    uVar2 = 0;
    if (param_3 >> 2 != 0) {
      do {
        sVar1 = *(sword *)(_audio_muLaw + (uint)*param_2 * 2);
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        uVar2 = uVar2 + 1;
        param_2 = param_2 + 4;
      } while (uVar2 < param_3 >> 2);
    }
    *param_5 = *param_4;
  }
  else {
    uVar2 = 0;
    if (param_3 >> 2 != 0) {
      do {
        sVar1 = *(sword *)(_audio_muLaw + (uint)*param_2 * 2);
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_4 < (uint)(int)sVar1) {
          *param_4 = (int)sVar1;
        }
        sVar1 = *(sword *)(_audio_muLaw + (uint)param_2[2] * 2);
        if (sVar1 < 0) {
          sVar1 = -sVar1;
        }
        if (*param_5 < (uint)(int)sVar1) {
          *param_5 = (int)sVar1;
        }
        uVar2 = uVar2 + 1;
        param_2 = param_2 + 4;
      } while (uVar2 < param_3 >> 2);
    }
  }
  return CONCAT44(param_2,uVar2);
}
