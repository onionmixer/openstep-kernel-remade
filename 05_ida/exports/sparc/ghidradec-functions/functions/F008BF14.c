
undefined8 sub_F008BF14(uint *param_1,uint param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar3;
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
  uVar3 = *param_1;
  puVar2 = (undefined *)0x0;
  if (uVar3 >> 0x18 != 0) {
    iVar1 = 0;
    if (0 < dword_F0111EA8) {
      param_2 = uVar3 & 0xffffff;
      puVar2 = unk_F0130FB0;
      do {
        iVar1 = iVar1 + 1;
        if ((uint)(byte)*puVar2 == uVar3 >> 0x18) {
          uVar3 = *(uint *)puVar2 & 0xffffff;
          if (uVar3 < param_2) {
            uVar3 = param_2;
          }
          *(uint *)puVar2 = *(uint *)puVar2 & 0xff000000 | uVar3;
          goto locret_F008BFC0;
        }
        puVar2 = (undefined *)((int)puVar2 + 4);
      } while (iVar1 < dword_F0111EA8);
    }
    puVar2 = (undefined *)0xf0111c00;
    iVar1 = dword_F0111EA8 * 4;
    dword_F0111EA8 = dword_F0111EA8 + 1;
    *(uint *)(unk_F0130FB0 + iVar1) = uVar3;
  }
locret_F008BFC0:
  return CONCAT44(param_2,puVar2);
}
