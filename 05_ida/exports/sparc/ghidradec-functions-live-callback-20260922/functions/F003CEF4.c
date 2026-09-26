
qword sub_F003CEF4(int param_1)

{
  byte bVar1;
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
  *(undefined4 *)(param_1 + 8) =
       *(undefined4 *)
        (_rtable +
        ((byte)(*(byte *)(param_1 + 0x5b) ^
               *(byte *)(param_1 + 0x5a) ^
               *(byte *)(param_1 + 0x59) ^
               *(byte *)(param_1 + 0x58) ^
               *(byte *)(param_1 + 0x57) ^
               *(byte *)(param_1 + 0x56) ^
               *(byte *)(param_1 + 0x55) ^
               *(byte *)(param_1 + 0x54) ^
               *(byte *)(param_1 + 0x51) ^
               *(byte *)(param_1 + 0x50) ^
               *(byte *)(param_1 + 0x4f) ^
               *(byte *)(param_1 + 0x4e) ^
               *(byte *)(param_1 + 0x4d) ^
               *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b)) &
        0x3f) * 4);
  bVar1 = *(byte *)(param_1 + 0x59) ^
          *(byte *)(param_1 + 0x58) ^
          *(byte *)(param_1 + 0x57) ^
          *(byte *)(param_1 + 0x56) ^
          *(byte *)(param_1 + 0x55) ^
          *(byte *)(param_1 + 0x54) ^
          *(byte *)(param_1 + 0x51) ^
          *(byte *)(param_1 + 0x50) ^
          *(byte *)(param_1 + 0x4f) ^
          *(byte *)(param_1 + 0x4e) ^
          *(byte *)(param_1 + 0x4d) ^
          *(byte *)(param_1 + 0x4c) ^ *(byte *)(param_1 + 0x4a) ^ *(byte *)(param_1 + 0x4b);
  *(int *)(_rtable +
          ((byte)(*(byte *)(param_1 + 0x5b) ^ *(byte *)(param_1 + 0x5a) ^ bVar1) & 0x3f) * 4) =
       param_1;
  _rnhash = _rnhash + 1;
  return (qword)CONCAT14(bVar1,param_1);
}

