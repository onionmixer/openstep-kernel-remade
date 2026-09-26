
/* WARNING: Removing unreachable block (ram,0xf00d28c8) */
/* WARNING: Removing unreachable block (ram,0xf00d2838) */
/* WARNING: Removing unreachable block (ram,0xf00d28b4) */
/* WARNING: Removing unreachable block (ram,0xf00d28d8) */
/* WARNING: Removing unreachable block (ram,0xf00d27f8) */

undefined8 -[EventDriver unregisterScreen:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  param_3 = param_3 + -0x100;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    if (param_3 < 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D28D4;
    }
    if (*(int *)(param_1 + 0x188) <= param_3) {
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D28D4;
    }
    _objc_msgSend(param_1,paHidecursor_0);
    *(undefined4 *)(*(int *)(param_1 + 0x180) + param_3 * 0x14) = 0;
    if (*(int *)(param_1 + 0x18c) == param_3) {
      iVar2 = *(int *)(param_1 + 0x188) + -1;
      if (iVar2 != -1) {
        iVar3 = iVar2 * 0x14;
        do {
          if (*(int *)(iVar3 + *(int *)(param_1 + 0x180)) != 0) {
            *(int *)(param_1 + 0x18c) = iVar2;
            break;
          }
          iVar2 = iVar2 + -1;
          iVar3 = iVar3 + -0x14;
        } while (iVar2 != -1);
      }
      _objc_msgSend(param_1,paSetcursorposit,*(int *)(param_1 + 0x168) + 0x18);
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D28D4;
    }
    _objc_msgSend(param_1,paShowcursor);
  }
  uVar1 = *(undefined4 *)(param_1 + 0x110);
loc_F00D28D4:
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}
