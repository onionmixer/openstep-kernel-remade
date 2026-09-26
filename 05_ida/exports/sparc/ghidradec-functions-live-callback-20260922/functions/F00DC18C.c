
/* WARNING: Removing unreachable block (ram,0xf00dc2b8) */
/* WARNING: Removing unreachable block (ram,0xf00dc258) */
/* WARNING: Removing unreachable block (ram,0xf00dc1fc) */
/* WARNING: Removing unreachable block (ram,0xf00dc1c8) */
/* WARNING: Removing unreachable block (ram,0xf00dc1dc) */
/* WARNING: Removing unreachable block (ram,0xf00dc210) */
/* WARNING: Removing unreachable block (ram,0xf00dc2a8) */
/* WARNING: Removing unreachable block (ram,0xf00dc23c) */
/* WARNING: Removing unreachable block (ram,0xf00dc1a8) */

undefined8 -[InputStream sendRecordedDataForRegion:](int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  uVar1 = *param_3;
  iVar4 = param_3[3] - uVar1;
  iVar5 = uVar1 - (uVar1 & ~_page_mask);
  _kern_serv_kernel_task_port();
  _vm_read_EXTERNAL();
  if (uVar1 != 0) {
    _IOLog(aAudioVmReadRet,uVar1);
  }
  iVar5 = *(int *)((int)register0x00000038 + -0x14) + iVar5;
  if (iVar4 != 0) {
    uVar1 = param_3[7];
    _IOConvertPort(uVar1,0,1);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    _IOConvertPort(uVar2,0,1);
    if (*(int *)(param_1 + 0x1c) == 0) {
      __NXAudioReplyRecordedData
                (uVar1,uVar2,uVar1,*(undefined4 *)(param_1 + 0x18),param_3[5],iVar5,iVar4);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x34);
      if (iVar3 == 0) {
        iVar3 = 0x2000;
        _IOMalloc(0x2000,uVar1);
        *(int *)(param_1 + 0x34) = iVar3;
        *(undefined *)(iVar3 + 3) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 0x18;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 8) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x14) = 0;
        iVar3 = *(int *)(param_1 + 0x34);
      }
      _audio_snd_reply_recorded_data(iVar3,uVar1,param_3[5],iVar5,iVar4);
      _msg_send(*(undefined4 *)(param_1 + 0x34),0x21,1000);
    }
  }
  return CONCAT44(param_2,param_1);
}

