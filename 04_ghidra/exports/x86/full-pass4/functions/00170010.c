/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170010 */

void FUN_00170010(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0418)) {
    uVar1 = _convert_port_to_task(param_1[2]);
    uVar2 = _task_by_unix_pid(uVar1,param_1[7],&local_8);
    param_2[7] = uVar2;
    _task_deallocate(uVar1);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e041c;
      uVar2 = _convert_task_to_port(local_8);
      param_2[9] = uVar2;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

