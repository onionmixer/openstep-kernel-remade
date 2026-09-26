
/* WARNING: Removing unreachable block (ram,0xf00c055c) */
/* WARNING: Removing unreachable block (ram,0xf00c04f0) */
/* WARNING: Removing unreachable block (ram,0xf00c04c0) */
/* WARNING: Removing unreachable block (ram,0xf00c054c) */
/* WARNING: Removing unreachable block (ram,0xf00c0580) */
/* WARNING: Removing unreachable block (ram,0xf00c042c) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00c04f0 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[EventSrcPCPointer dispatchPointerEvent:](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 in_o2_3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
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
  
  puVar3 = (undefined8 *)((qword)in_o2_3 >> 0x20);
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  uVar2 = *(uint *)(puVar3 + 1);
  uVar7 = uVar2 >> 0x16 & 4;
  if ((uVar2 & 0x2000000) != 0) {
    uVar7 = uVar7 | 1;
  }
  *(int *)((int)register0x00000038 + -0x14) = (int)(uVar2 << 8) >> 0x18;
  uVar4 = *puVar3;
  *(int *)((int)register0x00000038 + -0x18) = (*(int *)(puVar3 + 1) << 0x10) >> 0x18;
  uVar5 = (uint)uVar4;
  uVar2 = (int)((qword)uVar4 >> 0x20) << 8 | uVar5 >> 0x18;
  if (*(int *)(param_1 + 300) == 0) {
    uVar6 = 2;
  }
  else {
    uVar6 = uVar2 - *(int *)(param_1 + 300);
  }
  if ((uVar6 < 2) && (dword_F0120CC8 != 0)) {
    dword_F0120CC8 = 0;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paUnlock);
    goto locret_F00C0588;
  }
  dword_F0120CC8 = dword_F0120CC8 + 1;
  _objc_msgSend(param_1,paScalepointerin,(undefined *)((int)register0x00000038 + -0x14),uVar5,uVar6,
                *(undefined4 *)(param_1 + 0x130));
  *(uint *)(param_1 + 300) = uVar2;
  if (*(int *)(param_1 + 0x134) == 0) {
    if (uVar7 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x124);
    }
    else {
loc_F00C0544:
      uVar1 = *(undefined4 *)(param_1 + 0x124);
    }
  }
  else {
    if (*(int *)(param_1 + 0x134) == 1) goto loc_F00C0544;
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  _objc_msgSend(uVar1,paUnlock);
  _objc_msgSend(param_1,paOwner_0);
  _objc_msgSend();
locret_F00C0588:
  return CONCAT44(param_2,param_1);
}
