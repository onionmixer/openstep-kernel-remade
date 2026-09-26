
/* WARNING: Removing unreachable block (ram,0xf00bf3dc) */
/* WARNING: Removing unreachable block (ram,0xf00bf330) */
/* WARNING: Removing unreachable block (ram,0xf00bf3b4) */
/* WARNING: Removing unreachable block (ram,0xf00bf3ec) */
/* WARNING: Removing unreachable block (ram,0xf00bf320) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00bf3b4 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventSrcPCKeyboard autoRepeat](void)

{
  int iVar1;
  undefined8 in_o0_1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
  _objc_msgSend();
  if (*(char *)(iVar1 + 0x154) != '\0') {
    *(undefined *)(iVar1 + 0x154) = 0;
    uVar2 = *(uint *)(iVar1 + 0x160);
    *(undefined *)(iVar1 + 0x14e) = 1;
    if ((((uVar2 != 0) || (*(int *)(iVar1 + 0x164) != 0)) &&
        (uVar2 <= *(uint *)((int)register0x00000038 + -0x18))) &&
       ((uVar2 != *(uint *)((int)register0x00000038 + -0x18) ||
        (*(uint *)(iVar1 + 0x164) <= *(uint *)((int)register0x00000038 + -0x14))))) {
      uVar3 = *(undefined8 *)((int)register0x00000038 + -0x18);
      *(undefined8 *)(iVar1 + 0x158) = uVar3;
      _objc_msgSend(iVar1,(int)in_o0_1,*(undefined4 *)(iVar1 + 0x150),(int)uVar3,iVar1 + 0x134);
      uVar2 = (uint)*(undefined8 *)(iVar1 + 0x160);
      uVar4 = (uint)*(undefined8 *)(iVar1 + 0x168);
      *(qword *)(iVar1 + 0x160) =
           CONCAT44((int)((qword)*(undefined8 *)(iVar1 + 0x160) >> 0x20) +
                    (int)((qword)*(undefined8 *)(iVar1 + 0x168) >> 0x20) + (uint)CARRY4(uVar2,uVar4)
                    ,uVar2 + uVar4);
    }
    *(undefined *)(iVar1 + 0x14e) = 0;
    _objc_msgSend(iVar1);
  }
  _objc_msgSend();
  return iVar1;
}
