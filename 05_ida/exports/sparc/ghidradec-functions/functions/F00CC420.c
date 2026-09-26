
/* WARNING: Removing unreachable block (ram,0xf00cc4ac) */
/* WARNING: Removing unreachable block (ram,0xf00cc494) */
/* WARNING: Removing unreachable block (ram,0xf00cc450) */
/* WARNING: Removing unreachable block (ram,0xf00cc484) */
/* WARNING: Removing unreachable block (ram,0xf00cc4c0) */
/* WARNING: Removing unreachable block (ram,0xf00cc4d4) */
/* WARNING: Removing unreachable block (ram,0xf00cc430) */

undefined8 -[DriverCmdtr send:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
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
  puVar2 = (undefined *)((int)register0x00000038 + -0x28);
  _memset(puVar2,0,0x18);
  uVar1 = paLockwhen;
  *(uint *)((int)register0x00000038 + -0x28) = (uint)*(byte *)((int)register0x00000038 + -0x25);
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paLockwhen,3);
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0x18;
  *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0x232324;
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paUnlockwith,2);
  _msg_send_from_kernel(puVar2,0,0);
  if (puVar2 == (undefined *)0x0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),uVar1,1);
    puVar2 = *(undefined **)(param_1 + 0x10);
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),paLock);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 8),paUnlockwith,3);
  return CONCAT44(param_2,puVar2);
}
