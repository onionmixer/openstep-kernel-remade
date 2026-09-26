
/* WARNING: Removing unreachable block (ram,0xf00e9a14) */
/* WARNING: Removing unreachable block (ram,0xf00e9a44) */
/* WARNING: Removing unreachable block (ram,0xf00e99f8) */
/* WARNING: Removing unreachable block (ram,0xf00e9a28) */
/* WARNING: Removing unreachable block (ram,0xf00e99d4) */

undefined8
-[IOFrameBufferDisplay initFromDeviceDescription:]
          (undefined *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar3;
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
  undefined auStackX_0 [92];
  
  uVar1 = uRamf0142370;
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
  *(undefined **)((int)register0x00000038 + -0x10) = param_1;
  puVar3 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142370;
  puVar2 = puVar3;
  _objc_msgSendSuper(puVar3,paInitfromdevice,param_3);
  if (puVar2 == (undefined *)0x0) {
    *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar1;
    _objc_msgSendSuper(puVar3,paFree);
  }
  else {
    _sprintf((undefined *)((int)register0x00000038 + -0x28),aDisplayD,dword_F012EF7C);
    dword_F012EF7C = dword_F012EF7C + 1;
    _objc_msgSend(param_1,paSetunit);
    _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -0x28));
    puVar3 = param_1;
  }
  return CONCAT44(param_2,puVar3);
}
