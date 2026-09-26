
/* WARNING: Removing unreachable block (ram,0xf00d0278) */
/* WARNING: Removing unreachable block (ram,0xf00d028c) */
/* WARNING: Removing unreachable block (ram,0xf00d0214) */

undefined8 -[SCSIDisk unlockIoQLock](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paLastreadystate_0);
  if (param_1 + 0x1b0 == *(int *)(param_1 + 0x1b0)) {
    if (param_1 + 0x1a8 == *(int *)(param_1 + 0x1a8)) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      if (1 < iVar1 - 2U) {
        if (*(char *)(param_1 + 0x1c8) != '\0') {
          uVar2 = *(undefined4 *)(param_1 + 0x1b8);
          goto loc_F00D0270;
        }
        goto loc_F00D0260;
      }
    }
  }
  else {
loc_F00D0260:
    iVar3 = 1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x1b8);
loc_F00D0270:
  _objc_msgSend(uVar2,paUnlockwith,iVar3);
  if (iVar3 == 1) {
    _thread_block();
  }
  return CONCAT44(param_2,param_1);
}

