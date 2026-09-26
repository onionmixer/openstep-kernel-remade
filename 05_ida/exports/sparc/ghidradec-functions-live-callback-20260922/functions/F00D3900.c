
/* WARNING: Removing unreachable block (ram,0xf00d3984) */
/* WARNING: Removing unreachable block (ram,0xf00d3950) */
/* WARNING: Removing unreachable block (ram,0xf00d3964) */
/* WARNING: Removing unreachable block (ram,0xf00d39a0) */
/* WARNING: Removing unreachable block (ram,0xf00d3948) */

undefined8 -[EventDriver _ioOpHandler:](undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
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
  if ((undefined4 *)param_3[2] != (undefined4 *)0x0) {
    *(undefined4 *)param_3[2] = 0;
  }
  uVar1 = *param_3;
  if (uVar1 == 1) {
    uVar1 = param_3[1];
    goto loc_F00D3990;
  }
  if (uVar1 < 2) {
    _objc_msgSend(param_3[1],paUnlockwith,2);
    _IOExitThread();
loc_F00D395C:
    uVar2 = param_1;
    _objc_msgSend(param_1,paDoperforminiot,param_3 + 3);
    if ((undefined4 *)param_3[2] == (undefined4 *)0x0) {
      uVar1 = param_3[1];
      goto loc_F00D3990;
    }
    *(undefined4 *)param_3[2] = uVar2;
  }
  else {
    if (uVar1 == 2) goto loc_F00D395C;
    _IOPanic(aEventdriverBog);
  }
  uVar1 = param_3[1];
loc_F00D3990:
  if (uVar1 != 0) {
    _objc_msgSend(uVar1,paUnlockwith,2);
  }
  return CONCAT44(param_2,param_1);
}

