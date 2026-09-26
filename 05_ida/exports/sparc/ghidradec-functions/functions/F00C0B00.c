
/* WARNING: Removing unreachable block (ram,0xf00c0b8c) */
/* WARNING: Removing unreachable block (ram,0xf00c0b5c) */
/* WARNING: Removing unreachable block (ram,0xf00c0bb8) */
/* WARNING: Removing unreachable block (ram,0xf00c0b1c) */
/* WARNING: Removing unreachable block (ram,0xf00c0b34) */
/* WARNING: Removing unreachable block (ram,0xf00c0bc8) */
/* WARNING: Removing unreachable block (ram,0xf00c0b78) */
/* WARNING: Removing unreachable block (ram,0xf00c0b9c) */
/* WARNING: Removing unreachable block (ram,0xf00c0b0c) */

undefined8 +[PCPointer probe:](uint param_1,undefined4 param_2)

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
  bool bVar2;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  _objc_msgSend(param_1,paAlloc);
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0x128) = 0;
  uVar1 = param_1;
  _objc_msgSend();
  bVar2 = (uVar1 & 0xff) == 0;
  if (bVar2) {
    _IOLog(aPcpointerProbe);
    _objc_msgSend(param_1,paFree);
  }
  else {
    _sprintf((undefined *)((int)register0x00000038 + -0x28),aPcpointerD,dword_F0132F7C);
    dword_F0132F7C = dword_F0132F7C + 1;
    _objc_msgSend(param_1,paSetunit);
    _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x28));
    _objc_msgSend(param_1,paRegisterdevice);
    dword_F0132F80 = param_1;
  }
  return CONCAT44(param_2,(uint)!bVar2);
}
