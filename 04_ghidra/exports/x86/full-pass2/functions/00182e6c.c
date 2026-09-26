/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182e6c */

void FUN_00182e6c(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (((param_1[1] == 0x20) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) {
    uVar2 = _convert_port_to_thread(param_1[7]);
    uVar3 = _convert_port_to_dev(param_1[2],uVar2);
    uVar3 = _kern_IOUnMapEISADevicePorts(uVar3);
    *(undefined4 *)(param_2 + 0x1c) = uVar3;
    _thread_deallocate(uVar2);
    if (((*(int *)(param_2 + 0x1c) == 0) && (iVar1 = param_1[7], iVar1 != 0)) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

