/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba5b4 */

undefined4
FUN_001ba5b4(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,undefined4 param_6
            ,int param_7)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int local_8;
  
  iVar2 = _IOConvertPort(param_6,2,0);
  if (*(int *)(param_1 + 0x68) == 0) {
    if (*(int *)(param_1 + 0x6c) == 1) {
      param_4 = param_4 & 0xfffffffe;
    }
    else {
      param_4 = param_4 & 0xfffffffc;
    }
  }
  uVar7 = ~_page_mask & param_3;
  uVar8 = ~_page_mask & (param_3 - uVar7) + param_4 + _page_mask;
  uVar3 = _kern_serv_kernel_task_port();
  uVar4 = _task_self(uVar7,uVar8,0,1);
  iVar5 = _vm_protect_EXTERNAL(uVar4);
  if (iVar5 != 0) {
    _IOLog("Audio: vm_protect returned %d\n",iVar5);
  }
  iVar5 = _vm_allocate_EXTERNAL(uVar3,&local_8,uVar8,1);
  if (iVar5 == 0) {
    iVar5 = _vm_write_EXTERNAL(uVar3,local_8,uVar7,uVar8);
    if (iVar5 != 0) {
      _IOLog("Audio: vm_write returned %d\n",iVar5);
    }
    uVar3 = _task_self(uVar7,uVar8);
    iVar5 = _vm_deallocate_EXTERNAL(uVar3);
    if (iVar5 != 0) {
      _IOLog("Audio: vm_deallocate returned %d\n",iVar5);
    }
    local_8 = local_8 + (param_3 - uVar7);
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    piVar6 = (int *)_objc_msgSend(param_1,PTR_s_newRegion_001f970c);
    piVar6[2] = local_8;
    *piVar6 = local_8;
    piVar6[1] = local_8 + param_4;
    piVar6[4] = param_4;
    piVar6[5] = param_5;
    piVar6[7] = iVar2;
    piVar6[6] = param_7;
    *(int *)(param_1 + 0x60) = param_7;
    *(int *)(param_1 + 0x5c) = iVar2;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
    iVar2 = param_1 + 0x2c;
    if (*(int *)(param_1 + 0x2c) == iVar2) {
      *(int **)(param_1 + 0x2c) = piVar6;
      *(int **)(param_1 + 0x30) = piVar6;
      piVar6[0xf] = iVar2;
      piVar6[0x10] = iVar2;
    }
    else {
      iVar5 = *(int *)(param_1 + 0x30);
      piVar6[0x10] = iVar5;
      piVar6[0xf] = iVar2;
      *(int **)(param_1 + 0x30) = piVar6;
      *(int **)(iVar5 + 0x3c) = piVar6;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    uVar3 = _objc_msgSend(param_1,PTR_s_channel_001f97b0);
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s__dataPendingForChannel__001f9724,uVar3);
    uVar3 = 1;
  }
  else {
    _IOLog("Audio: playback request (%d bytes) too large\n",param_4);
    uVar3 = 0;
  }
  return uVar3;
}

