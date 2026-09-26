/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f7a8 */

void FUN_0016f7a8(int *param_1,uint *param_2)

{
  ipc_space_t task;
  uint uVar1;
  int iVar2;
  mach_msg_type_name_t local_8;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e0318)) &&
     (param_1[8] == DAT_001e031c)) {
    task = _convert_port_to_space(param_1[2]);
    uVar1 = _mach_port_extract_right(task,param_1[7],param_1[9],param_2 + 9,&local_8);
    param_2[7] = uVar1;
    _space_deallocate(task);
    if (param_2[7] == 0) {
      param_2[1] = 0x28;
      param_2[8] = DAT_001e0320;
      if ((((local_8 == 0x10) && (iVar2 = param_1[3], iVar2 != 0)) &&
          ((iVar2 != -1 && ((uVar1 = param_2[9], uVar1 != 0 && (uVar1 != 0xffffffff)))))) &&
         (iVar2 = _ipc_port_check_circularity(uVar1,iVar2), iVar2 != 0)) {
        *param_2 = *param_2 | 0x40000000;
      }
      *(char *)(param_2 + 8) = (char)local_8;
      if (local_8 - 0x10 < 6) {
        *param_2 = *param_2 | 0x80000000;
      }
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

