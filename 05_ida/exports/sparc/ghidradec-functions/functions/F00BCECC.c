
undefined8 sub_F00BCECC(int param_1)

{
  bool bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  uint uVar3;
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
  bVar1 = false;
  switch(*(undefined4 *)(param_1 + 8)) {
  case :
    *(undefined4 *)(param_1 + 8) = 0;
    dword_F013204C = (int)*(char *)(param_1 + 0xc);
    break;
  :
    bVar1 = true;
    break;
  case :
    *(undefined4 *)(param_1 + 8) = 0;
    dword_F0132050 = (int)*(char *)(param_1 + 0xc);
    break;
  case :
    *(undefined4 *)(param_1 + 8) = 0;
    dword_F0132054 = (int)*(char *)(param_1 + 0xc);
    break;
  case :
    *(undefined4 *)(param_1 + 8) = 0;
    dword_F0132058 = (int)*(char *)(param_1 + 0xc);
    break;
  case :
    *(undefined4 *)(param_1 + 8) = 0;
    dword_F013205C = (int)*(char *)(param_1 + 0xc);
  }
  if (bVar1) {
    uVar2 = 0;
    if ((dword_F0132054 != 0) || (dword_F0132050 != 0)) {
      uVar2 = 1;
    }
    uVar2 = (uint)*(word *)(_ascii + ((*(int *)(param_1 + 8) << 1 | uVar2) +
                                     (-(uint)(dword_F013204C != 0) & 0x100)) * 2);
    if ((dword_F013205C != 0) || (uVar3 = 0, dword_F0132058 != 0)) {
      uVar3 = 0x80;
    }
    switch(uVar2) {
    case :
    case :
    case :
    case :
    case :
    case :
      break;
    :
      uVar2 = uVar2 | uVar3;
    }
    uVar3 = 0x100;
    if (*(char *)(param_1 + 0xc) != '\0') {
      uVar3 = uVar2;
    }
  }
  else {
    uVar3 = 0x100;
  }
  return CONCAT44(param_1,uVar3);
}
