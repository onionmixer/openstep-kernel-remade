/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9960 */

int FUN_001b9960(int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined1 local_c [4];
  int local_8;
  
  uVar1 = *param_3;
  iVar7 = param_3[3] - uVar1;
  uVar6 = ~_page_mask;
  iVar2 = uVar1 - (uVar6 & uVar1);
  uVar3 = _kern_serv_kernel_task_port();
  iVar4 = _vm_read_EXTERNAL(uVar3,uVar6 & uVar1,iVar2 + iVar7 + _page_mask & ~_page_mask,&local_8,
                            local_c);
  if (iVar4 != 0) {
    _IOLog("Audio: vm_read returned %d\n",iVar4);
  }
  iVar2 = iVar2 + local_8;
  if (iVar7 != 0) {
    uVar3 = _IOConvertPort(param_3[7],0,1);
    uVar5 = _IOConvertPort(*(undefined4 *)(param_1 + 0x10),0,1);
    if (*(int *)(param_1 + 0x1c) == 0) {
      __NXAudioReplyRecordedData
                (uVar3,uVar5,uVar3,*(undefined4 *)(param_1 + 0x18),param_3[5],iVar2,iVar7);
    }
    else {
      if (*(int *)(param_1 + 0x34) == 0) {
        iVar4 = _IOMalloc(0x2000);
        *(int *)(param_1 + 0x34) = iVar4;
        *(undefined1 *)(iVar4 + 3) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 4) = 0x18;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 8) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0xc) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x10) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x34) + 0x14) = 0;
      }
      _audio_snd_reply_recorded_data(*(undefined4 *)(param_1 + 0x34),uVar3,param_3[5],iVar2,iVar7);
      _msg_send(*(undefined4 *)(param_1 + 0x34),0x21,1000);
    }
  }
  return param_1;
}

