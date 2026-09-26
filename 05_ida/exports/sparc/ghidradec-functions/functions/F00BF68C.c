
/* WARNING: Removing unreachable block (ram,0xf00bf750) */
/* WARNING: Removing unreachable block (ram,0xf00bf760) */
/* WARNING: Removing unreachable block (ram,0xf00bf734) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00bf750 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventSrcPCKeyboard dispatchKeyboardEvent:](undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 in_o0_1;
  undefined8 uVar3;
  undefined4 uVar4;
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
  uVar3 = *param_1;
  *(undefined8 *)(iVar1 + 0x158) = uVar3;
  uVar2 = *(uint *)(param_1 + 1);
  if (uVar2 != 0x7f) {
    if (uVar2 == 99) {
      uVar4 = 2;
    }
    else if (uVar2 < 100) {
      if (uVar2 == 0x13) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 1;
        if (uVar2 != 0x4c) {
          uVar4 = 0;
        }
      }
    }
    else {
      uVar4 = 8;
      if (uVar2 != 0x78) {
        if (uVar2 < 0x79) {
          uVar4 = 4;
          if (uVar2 != 0x6e) {
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0x10;
          if (uVar2 != 0x7a) {
            uVar4 = 0;
          }
        }
      }
    }
    *(int *)(iVar1 + 0x148) = (int)((qword)uVar3 >> 0x20);
    _objc_msgSend();
    _objc_msgSend(*(undefined4 *)(iVar1 + 0x128),uVar4,*(undefined4 *)(param_1 + 1),
                  (int)*(char *)((int)param_1 + 0xc),iVar1 + 0x134);
    _objc_msgSend();
  }
  return iVar1;
}
