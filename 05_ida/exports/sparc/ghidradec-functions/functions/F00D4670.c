
/* WARNING: Removing unreachable block (ram,0xf00d4744) */
/* WARNING: Removing unreachable block (ram,0xf00d46f0) */
/* WARNING: Removing unreachable block (ram,0xf00d4754) */
/* WARNING: Removing unreachable block (ram,0xf00d4698) */

undefined8
-[EventDriver relativePointerEvent:deltaX:deltaY:atTime:]
          (int param_1,undefined4 param_2,uint param_3,int param_4)

{
  sword sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 in_o4_5;
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
  *(int *)((int)register0x00000038 + 0x58) = (int)in_o4_5;
  uVar4 = (uint)((qword)*(undefined8 *)((int)register0x00000038 + 0x58) >> 0x20);
  uVar3 = uVar4 << 8 | (uint)*(undefined8 *)((int)register0x00000038 + 0x58) >> 0x18;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,uVar4 >> 0x18,uVar3);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    if ((param_3 & 4) != (*(uint *)(*(int *)(param_1 + 0x168) + 8) & 4)) {
      if ((param_3 & 4) == 0) {
        *(undefined *)(param_1 + 0x1c0) = 0;
      }
      else {
        *(undefined *)(param_1 + 0x1c0) = 0xff;
      }
    }
    _objc_msgSend(param_1,paSetbuttonstate,param_3,uVar3);
    if (param_4 == 0) {
      if ((int)((qword)in_o4_5 >> 0x20) == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x110);
        goto loc_F00D4750;
      }
      sVar1 = *(sword *)(param_1 + 0x1a8);
    }
    else {
      sVar1 = *(sword *)(param_1 + 0x1a8);
    }
    *(sword *)(param_1 + 0x1a8) = sVar1 + (sword)param_4;
    *(sword *)(param_1 + 0x1aa) = *(sword *)(param_1 + 0x1aa) + (sword)((qword)in_o4_5 >> 0x20);
    if (*(char *)(param_1 + 0x211) == '\0') {
      _objc_msgSend(param_1,paSetcursorposit_0,param_1 + 0x1a8,uVar3);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
loc_F00D4750:
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
