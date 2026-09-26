/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00180478 */

int FUN_00180478(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  if ((*(int *)(param_1 + 4) == 0) &&
     (iVar1 = _ipc_object_copyin(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),param_3,
                                 0x14,&local_8), iVar1 == 0)) {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_interrupts_001f92d4);
    if ((iVar1 == 0) || (iVar1 = _objc_msgSend(iVar1,PTR_s_count_001f92d8), iVar1 == 0)) {
      _ipc_port_release_send(local_8);
    }
    else {
      *(undefined4 *)(param_1 + 4) = local_8;
      uVar2 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_initCount__001f92dc,iVar1
                           );
      uVar2 = _objc_msgSend(uVar2);
      *(undefined4 *)(param_1 + 8) = uVar2;
      iVar4 = 0;
      if (0 < iVar1) {
        do {
          uVar2 = _objc_msgSend(PTR_s_KernDeviceInterrupt_001f9d88,PTR_s_alloc_001f9210,
                                PTR_s_initWithInterruptPort__001f92e0,*(undefined4 *)(param_1 + 4));
          uVar2 = _objc_msgSend(uVar2);
          iVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_addObject__001f92c4,uVar2);
          if (iVar3 == 0) {
            _objc_msgSend(param_1,PTR_s__detachInterruptSources_001f92e4);
            _ipc_port_release_send(*(undefined4 *)(param_1 + 4));
            *(undefined4 *)(param_1 + 4) = 0;
            return 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
      }
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

