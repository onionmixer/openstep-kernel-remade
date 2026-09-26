
/* WARNING: Removing unreachable block (ram,0xf00d78a8) */
/* WARNING: Removing unreachable block (ram,0xf00d7874) */
/* WARNING: Removing unreachable block (ram,0xf00d78c4) */
/* WARNING: Removing unreachable block (ram,0xf00d7830) */

undefined8 -[IOAudio _dataPendingForChannel:](int param_1,undefined4 param_2,uint param_3)

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
  if (*(int *)(param_1 + 0x13c) == 0) {
    iVar2 = 0x18;
    _IOMalloc();
    *(int *)(param_1 + 0x13c) = iVar2;
    *(undefined *)(iVar2 + 3) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 4) = 0x18;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x10) = *(undefined4 *)(param_1 + 0x134);
  }
  _objc_msgSend(param_3,paIsread);
  uVar1 = 0x385;
  if ((param_3 & 0xff) == 0) {
    iVar2 = *(int *)(param_1 + 0x13c);
    uVar1 = 900;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x13c);
  }
  *(undefined4 *)(iVar2 + 0x14) = uVar1;
  iVar2 = *(int *)(param_1 + 0x13c);
  _msg_send_from_kernel(iVar2,1,1000);
  if ((iVar2 != 0) && (iVar2 != -0x67)) {
    _IOLog(aAudioDataPendi);
  }
  return CONCAT44(param_2,param_1);
}

