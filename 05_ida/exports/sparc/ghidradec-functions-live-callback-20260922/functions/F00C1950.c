
/* WARNING: Removing unreachable block (ram,0xf00c1a78) */
/* WARNING: Removing unreachable block (ram,0xf00c1adc) */
/* WARNING: Removing unreachable block (ram,0xf00c1aa0) */
/* WARNING: Removing unreachable block (ram,0xf00c1a60) */
/* WARNING: Removing unreachable block (ram,0xf00c1a50) */
/* WARNING: Removing unreachable block (ram,0xf00c1a3c) */
/* WARNING: Removing unreachable block (ram,0xf00c19e8) */
/* WARNING: Removing unreachable block (ram,0xf00c19d0) */
/* WARNING: Removing unreachable block (ram,0xf00c1990) */
/* WARNING: Removing unreachable block (ram,0xf00c199c) */
/* WARNING: Removing unreachable block (ram,0xf00c19f8) */
/* WARNING: Removing unreachable block (ram,0xf00c1a14) */
/* WARNING: Removing unreachable block (ram,0xf00c1a2c) */
/* WARNING: Removing unreachable block (ram,0xf00c1a58) */
/* WARNING: Removing unreachable block (ram,0xf00c1a88) */
/* WARNING: Removing unreachable block (ram,0xf00c1ab0) */
/* WARNING: Removing unreachable block (ram,0xf00c1acc) */
/* WARNING: Removing unreachable block (ram,0xf00c19b4) */
/* WARNING: Removing unreachable block (ram,0xf00c197c) */

undefined8 -[TYPE5Keyboard kbdInit:](int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined7 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  *(undefined *)(param_1 + 300) = 0;
  *(undefined *)(param_1 + 0x12d) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  puVar2 = paNxlock;
  puVar1 = paNew;
  _type5kbd_owner = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  _objc_msgSend(puVar2,puVar1);
  *(undefined7 **)(param_1 + 0x148) = puVar2;
  iVar3 = param_1;
  _objc_msgSend(param_1,paDevicedescript_1);
  _objc_msgSend();
  if (iVar3 == 0) {
    _IOLog(aType5keyboardK);
    uVar5 = 0;
  }
  else {
    iVar4 = iVar3;
    _objc_msgSend(iVar3,paValueforstring,aInterface);
    if (iVar4 == 0) {
      _IOLog(aType5keyboardK_0);
      iVar4 = 7;
    }
    else {
      _PCPatoi();
    }
    *(int *)(param_1 + 0x130) = iVar4;
    _objc_msgSend(iVar3,paValueforstring,aHandlerId);
    if (iVar3 == 0) {
      _IOLog(aType5keyboardK_1);
      *(undefined4 *)(param_1 + 0x134) = 0;
    }
    else {
      _PCPatoi();
      *(int *)(param_1 + 0x134) = iVar3;
    }
    iVar3 = param_1;
    _objc_msgSend(param_1,paEnableallinter);
    _task_self();
    _port_set_allocate_EXTERNAL();
    if (iVar3 == 0) {
      _task_self();
      uVar5 = *(undefined4 *)(param_1 + 0x128);
      iVar4 = param_1;
      _objc_msgSend(param_1,paInterruptport_0);
      _port_set_add_EXTERNAL(iVar3,uVar5,iVar4);
      if (iVar3 == 0) {
        _IOForkThread(sub_F00C186C,param_1);
        uVar5 = 1;
      }
      else {
        _IOLog(aKbdinitPortSet_0,iVar3);
        uVar5 = 0xffffffff;
      }
    }
    else {
      _IOLog(aKbdinitPortSet);
      uVar5 = 0;
    }
  }
  return CONCAT44(param_2,uVar5);
}

