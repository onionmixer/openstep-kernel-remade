/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014758c */

undefined4 _ipc_kmsg_get(undefined4 param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _ipc_kmsg_cache;
  if (((param_2 < 0x18) || ((param_2 & 3) != 0)) || (0 < param_3)) {
    return 0x10000008;
  }
  if (param_2 < 0xed) {
    if (_ipc_kmsg_cache != 0) {
      _ipc_kmsg_cache = 0;
      goto LAB_00147616;
    }
    iVar1 = _kalloc(0x100);
    if (iVar1 == 0) {
      return 0x1000000d;
    }
    *(undefined4 *)(iVar1 + 8) = 0x100;
  }
  else {
    iVar1 = _kalloc(param_2 + 0x14);
    if (iVar1 == 0) {
      return 0x1000000d;
    }
    *(uint *)(iVar1 + 8) = param_2 + 0x14;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
LAB_00147616:
  *(undefined4 *)(iVar1 + 0x10) = 0;
  iVar2 = _copyinmsg(param_1,iVar1 + 0x14,param_3 + param_2);
  if (iVar2 == 0) {
    *(int *)(iVar1 + 0x10) = param_3;
    *(uint *)(iVar1 + 0x18) = param_2;
    *param_4 = iVar1;
    return 0;
  }
  iVar2 = *(int *)(iVar1 + 8);
  if (iVar2 < 1) {
    if (iVar2 == -2) {
      _KernDeviceInterruptMsgRelease(iVar1);
      return 0x10000002;
    }
    if (iVar2 == -1) {
      return 0x10000002;
    }
    if (iVar2 == -3) {
      _netipc_msg_release(iVar1);
      return 0x10000002;
    }
  }
  _kfree(iVar1,iVar2);
  return 0x10000002;
}

