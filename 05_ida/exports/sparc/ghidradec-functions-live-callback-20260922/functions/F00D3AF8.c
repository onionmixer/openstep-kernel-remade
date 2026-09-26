
/* WARNING: Removing unreachable block (ram,0xf00d3cfc) */
/* WARNING: Removing unreachable block (ram,0xf00d3ce4) */
/* WARNING: Removing unreachable block (ram,0xf00d3ca8) */
/* WARNING: Removing unreachable block (ram,0xf00d3b80) */
/* WARNING: Removing unreachable block (ram,0xf00d3b64) */
/* WARNING: Removing unreachable block (ram,0xf00d3b20) */
/* WARNING: Removing unreachable block (ram,0xf00d3b6c) */
/* WARNING: Removing unreachable block (ram,0xf00d3c5c) */
/* WARNING: Removing unreachable block (ram,0xf00d3cb0) */
/* WARNING: Removing unreachable block (ram,0xf00d3cec) */
/* WARNING: Removing unreachable block (ram,0xf00d3d0c) */
/* WARNING: Removing unreachable block (ram,0xf00d3b04) */

undefined8 -[EventDriver periodicEvents](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined (*pauVar4) [15];
  undefined4 unaff_l0;
  int iVar5;
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
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x110);
    goto loc_F00D3D08;
  }
  iVar5 = *(int *)(param_1 + 0x168);
  _IOGetTimestamp(param_1 + 0x200);
  uVar3 = (int)((qword)*(undefined8 *)(param_1 + 0x200) >> 0x20) << 8 |
          (uint)*(undefined8 *)(param_1 + 0x200) >> 0x18;
  if (uVar3 == 0) {
    uVar3 = 1;
  }
  *(uint *)(iVar5 + 0x10) = uVar3;
  if (*(char *)(param_1 + 0x211) == '\x01') {
    _objc_msgSend(param_1,paSetcursorposit_0);
  }
  iVar2 = iVar5 + 0x40;
  _ev_try_lock();
  if (iVar2 != 0) {
    iVar2 = iVar5 + 0x14;
    _ev_try_lock();
    if (iVar2 != 0) {
      if ((*(int *)(iVar5 + 0x38) != *(int *)(iVar5 + 0x3c)) &&
         ((int)*(sword *)(iVar5 + 0x4c) < *(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0x38))) {
        *(undefined *)(iVar5 + 0x48) = 1;
      }
      if (((*(char *)(iVar5 + 0x49) == '\0') || (*(char *)(iVar5 + 0x4a) == '\0')) ||
         (*(char *)(iVar5 + 0x48) == '\0')) {
        if (((*(int *)(iVar5 + 0x44) != 0) &&
            (*(uint *)(param_1 + 0x1e0) <= *(uint *)(param_1 + 0x200))) &&
           ((pauVar4 = paHidewaitcursor, *(uint *)(param_1 + 0x1e0) != *(uint *)(param_1 + 0x200) ||
            (*(uint *)(param_1 + 0x1e4) <= *(uint *)(param_1 + 0x204))))) goto loc_F00D3C5C;
      }
      else {
        pauVar4 = paShowwaitcursor;
        if (*(int *)(iVar5 + 0x44) == 0) {
loc_F00D3C5C:
          _objc_msgSend(param_1,pauVar4);
        }
      }
      if (((*(int *)(iVar5 + 0x44) != 0) &&
          (*(uint *)(param_1 + 0x1f0) <= *(uint *)(param_1 + 0x200))) &&
         ((*(uint *)(param_1 + 0x1f0) != *(uint *)(param_1 + 0x200) ||
          (*(uint *)(param_1 + 500) <= *(uint *)(param_1 + 0x204))))) {
        _objc_msgSend(param_1,paAnimatewaitcur);
      }
      _ev_unlock(iVar5 + 0x14);
      if ((*(uint *)(param_1 + 0x1a4) < *(uint *)(iVar5 + 0x10)) &&
         (*(char *)(param_1 + 0x1d3) == '\0')) {
        _objc_msgSend(param_1,paDoautodim);
      }
    }
    _ev_unlock(iVar5 + 0x40);
  }
  _objc_msgSend(param_1,paSchedulenextpe);
  uVar1 = *(undefined4 *)(param_1 + 0x110);
loc_F00D3D08:
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}

