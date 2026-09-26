
/* WARNING: Removing unreachable block (ram,0xf00d4804) */
/* WARNING: Removing unreachable block (ram,0xf00d4778) */
/* WARNING: Removing unreachable block (ram,0xf00d47d0) */
/* WARNING: Removing unreachable block (ram,0xf00d4798) */
/* WARNING: Removing unreachable block (ram,0xf00d4768) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00d4804 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8
-[EventDriver absolutePointerEvent:at:inProximity:](int param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  qword in_o2_3;
  undefined4 unaff_l0;
  char cVar2;
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
  uVar1 = (uint)(in_o2_3 >> 0x20);
  _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  cVar2 = *(char *)(param_1 + 0x1c0);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  }
  else {
    if ((uVar1 & 4) != (*(uint *)(*(int *)(param_1 + 0x168) + 8) & 4)) {
      cVar2 = -((in_o2_3 & 0x400000000) != 0);
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
    _objc_msgSend(param_1,paAbsolutepointe,uVar1,(int)in_o2_3,(int)param_3,cVar2);
  }
  return CONCAT44(param_2,param_1);
}
