
/* WARNING: Removing unreachable block (ram,0xf00d2c8c) */
/* WARNING: Removing unreachable block (ram,0xf00d2c58) */
/* WARNING: Removing unreachable block (ram,0xf00d2c38) */
/* WARNING: Removing unreachable block (ram,0xf00d2c68) */
/* WARNING: Removing unreachable block (ram,0xf00d2c18) */
/* WARNING: Removing unreachable block (ram,0xf00d2bd8) */

undefined8 -[EventDriver unmapEventShmem:](int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  if (param_3 == *(int *)(param_1 + 0x114)) {
    if (*(char *)(param_1 + 0x1d0) == '\0') {
      uVar1 = *(undefined4 *)(param_1 + 0x110);
    }
    else {
      if (*(char *)(param_1 + 0x1d2) != '\0') {
        iVar3 = *(int *)(param_1 + 0x150);
        *(undefined *)(param_1 + 0x1d2) = 0;
        _destroyEventShmem(iVar3,*(undefined4 *)(param_1 + 0x154),*(undefined4 *)(param_1 + 0x160),
                           *(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x15c));
        if (iVar3 != 0) {
          iVar2 = param_1;
          _objc_msgSend(param_1,paName);
          _IOLog(aSDestroyevents,iVar2,iVar3);
        }
        *(undefined4 *)(param_1 + 0x158) = 0;
        *(undefined4 *)(param_1 + 0x15c) = 0;
        *(undefined4 *)(param_1 + 0x160) = 0;
        *(undefined4 *)(param_1 + 0x154) = 0;
        uVar1 = paUnlock;
        *(undefined4 *)(param_1 + 0x150) = 0;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar1);
        goto locret_F00D2C98;
      }
      uVar1 = *(undefined4 *)(param_1 + 0x110);
    }
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x110);
  }
  _objc_msgSend(uVar1,paUnlock);
  iVar3 = -0x2c1;
locret_F00D2C98:
  return CONCAT44(param_2,iVar3);
}
