
undefined8 _rp_rmhash(int param_1)

{
  int iVar1;
  byte bVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  uint uVar4;
  undefined4 unaff_i2;
  uint uVar5;
  uint uVar6;
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
  bVar2 = *(byte *)(param_1 + 0x59) ^
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
  uVar4 = (uint)bVar2;
  uVar5 = *(uint *)(_rtable +
                   ((byte)(*(byte *)(param_1 + 0x5b) ^ *(byte *)(param_1 + 0x5a) ^ bVar2) & 0x3f) *
                   4);
  uVar3 = 0;
  if (uVar5 != 0) {
    iVar1 = uVar5 - param_1;
    do {
      if (iVar1 == 0) {
        if (uVar3 == 0) {
          bVar2 = *(byte *)(uVar5 + 0x58) ^
                  *(byte *)(uVar5 + 0x57) ^
                  *(byte *)(uVar5 + 0x56) ^
                  *(byte *)(uVar5 + 0x55) ^
                  *(byte *)(uVar5 + 0x54) ^
                  *(byte *)(uVar5 + 0x51) ^
                  *(byte *)(uVar5 + 0x50) ^
                  *(byte *)(uVar5 + 0x4f) ^
                  *(byte *)(uVar5 + 0x4e) ^
                  *(byte *)(uVar5 + 0x4d) ^
                  *(byte *)(uVar5 + 0x4c) ^ *(byte *)(uVar5 + 0x4a) ^ *(byte *)(uVar5 + 0x4b);
          uVar3 = (uint)bVar2;
          bVar2 = *(byte *)(uVar5 + 0x59) ^ bVar2;
          uVar4 = (uint)bVar2;
          *(undefined4 *)
           (_rtable + ((byte)(*(byte *)(uVar5 + 0x5b) ^ *(byte *)(uVar5 + 0x5a) ^ bVar2) & 0x3f) * 4
           ) = *(undefined4 *)(uVar5 + 8);
        }
        else {
          *(undefined4 *)(uVar3 + 8) = *(undefined4 *)(uVar5 + 8);
        }
        _rnhash = _rnhash + -1;
        break;
      }
      uVar6 = *(uint *)(uVar5 + 8);
      iVar1 = uVar6 - param_1;
      uVar3 = uVar5;
      uVar5 = uVar6;
    } while (uVar6 != 0);
  }
  return CONCAT44(uVar4,uVar3);
}
