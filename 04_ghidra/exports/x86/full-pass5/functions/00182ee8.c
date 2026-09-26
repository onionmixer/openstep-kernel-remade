/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182ee8 */

void FUN_00182ee8(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (((((param_1[1] == 0x48) && (*param_1 < 0)) && ((param_1[6] & 0x3fffffffU) == 0x10012011)) &&
      ((param_1[8] == DAT_001e1174 && (param_1[10] == DAT_001e1178)))) &&
     ((param_1[0xc] == DAT_001e117c &&
      ((param_1[0xe] == DAT_001e1180 && (param_1[0x10] == DAT_001e1184)))))) {
    uVar2 = _convert_port_to_task(param_1[7]);
    uVar3 = _convert_port_to_dev
                      (param_1[2],uVar2,param_1[9],param_1[0xb],param_1 + 0xd,
                       (int)(char)param_1[0xf],param_1[0x11]);
    uVar3 = _kern_IOMapEISADeviceMemory(uVar3);
    *(undefined4 *)(param_2 + 0x1c) = uVar3;
    _task_deallocate(uVar2);
    if (*(int *)(param_2 + 0x1c) == 0) {
      iVar1 = param_1[7];
      if ((iVar1 != 0) && (iVar1 != -1)) {
        _ipc_port_release_send(iVar1);
      }
      *(undefined4 *)(param_2 + 4) = 0x28;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e1188;
      *(int *)(param_2 + 0x24) = param_1[0xd];
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

