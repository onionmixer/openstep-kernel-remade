
/* WARNING: Removing unreachable block (ram,0xf00cfa44) */
/* WARNING: Removing unreachable block (ram,0xf00cfa00) */
/* WARNING: Removing unreachable block (ram,0xf00cf9b8) */
/* WARNING: Removing unreachable block (ram,0xf00cf980) */
/* WARNING: Removing unreachable block (ram,0xf00cf950) */
/* WARNING: Removing unreachable block (ram,0xf00cf994) */
/* WARNING: Removing unreachable block (ram,0xf00cf9d4) */
/* WARNING: Removing unreachable block (ram,0xf00cfa38) */
/* WARNING: Removing unreachable block (ram,0xf00cfa5c) */
/* WARNING: Removing unreachable block (ram,0xf00cf930) */

void _sdIoThread(uint param_1)

{
  undefined (*pauVar1) [15];
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
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
  
  pauVar1 = paLastreadystate_0;
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
  uVar2 = *(undefined4 *)(param_1 + 0x1b8);
  do {
    _objc_msgSend(uVar2,paLockwhen,1);
    if (param_1 + 0x1b0 == *(int *)(param_1 + 0x1b0)) {
      iVar3 = *(int *)(param_1 + 0x1a8);
    }
    else {
      do {
        sub_F00CFA74(param_1,0);
      } while (param_1 + 0x1b0 != *(int *)(param_1 + 0x1b0));
      iVar3 = *(int *)(param_1 + 0x1a8);
    }
    if (param_1 + 0x1a8 != iVar3) {
      do {
        uVar4 = param_1;
        _objc_msgSend(param_1,pauVar1);
        if (((uVar4 == 2) || (uVar4 = param_1, _objc_msgSend(param_1,pauVar1), uVar4 == 3)) ||
           (*(char *)(param_1 + 0x1c8) != '\0')) break;
        sub_F00CFA74(param_1,1);
      } while (param_1 + 0x1a8 != *(int *)(param_1 + 0x1a8));
    }
    uVar4 = param_1;
    _objc_msgSend(param_1,paLastreadystate_0);
    if ((param_1 + 0x1a8 == *(int *)(param_1 + 0x1a8)) ||
       (((uVar4 != 1 || (uVar5 = param_1, _objc_msgSend(param_1,paIsremovable), (uVar5 & 0xff) == 0)
         ) && ((uVar4 != 2 && (*(char *)(param_1 + 0x1c8) == '\0')))))) {
      _objc_msgSend(param_1,paUnlockioqlock);
      uVar2 = *(undefined4 *)(param_1 + 0x1b8);
    }
    else {
      _objc_msgSend(param_1,paUnlockioqlock);
      _volCheckRequest(param_1,2);
      uVar2 = *(undefined4 *)(param_1 + 0x1b8);
    }
  } while( true );
}
