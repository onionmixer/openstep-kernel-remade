/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b981c */

undefined4
FUN_001b981c(int param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_8;
  
  uVar1 = _kern_serv_kernel_task_port();
  iVar2 = _IOConvertPort(param_5,2,0);
  if (*(int *)(param_1 + 0x68) == 0) {
    if (*(int *)(param_1 + 0x6c) == 1) {
      param_3 = param_3 & 0xfffffffe;
    }
    else {
      param_3 = param_3 & 0xfffffffc;
    }
  }
  iVar3 = _vm_allocate_EXTERNAL(uVar1,&local_8,param_3,1);
  if (iVar3 == 0) {
    piVar4 = (int *)_objc_msgSend(param_1,PTR_s_newRegion_001f970c);
    *piVar4 = local_8;
    piVar4[3] = local_8;
    piVar4[2] = local_8;
    piVar4[1] = *piVar4 + param_3;
    piVar4[4] = param_3;
    piVar4[5] = param_4;
    piVar4[7] = iVar2;
    piVar4[6] = param_6;
    *(int *)(param_1 + 0x60) = param_6;
    *(int *)(param_1 + 0x5c) = iVar2;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
    iVar2 = param_1 + 0x2c;
    if (*(int *)(param_1 + 0x2c) == iVar2) {
      *(int **)(param_1 + 0x2c) = piVar4;
      *(int **)(param_1 + 0x30) = piVar4;
      piVar4[0xf] = iVar2;
      piVar4[0x10] = iVar2;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x30);
      piVar4[0x10] = iVar3;
      piVar4[0xf] = iVar2;
      *(int **)(param_1 + 0x30) = piVar4;
      *(int **)(iVar3 + 0x3c) = piVar4;
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    uVar1 = _objc_msgSend(param_1,PTR_s_channel_001f97b0);
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s__dataPendingForChannel__001f9724,uVar1);
    uVar1 = 1;
  }
  else {
    _IOLog("Audio: record request (%d bytes) too large\n",param_3);
    uVar1 = 0;
  }
  return uVar1;
}

