/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c0c0 */

int _task_by_pid(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_c;
  undefined4 local_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  local_c = 0;
  iVar3 = _pfind(param_1);
  if ((((iVar3 != 0) && (iVar4 = *(int *)(iVar2 + 0x3c), iVar4 != 0)) &&
      ((*(short *)(iVar3 + 0x2c) == *(short *)(iVar4 + 0x2c) || (iVar4 = _suser(), iVar4 != 0)))) &&
     (*(char *)(iVar3 + 0x13) != '\x05')) {
    if (*(int *)(iVar3 + 0x68) != 0) {
      _task_reference(*(int *)(iVar3 + 0x68));
    }
    local_8 = *(undefined4 *)(iVar3 + 0x68);
    iVar3 = _suser();
    if ((iVar3 != 0) && (iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 0x3c), iVar3 != 0)) {
      pbVar1 = (byte *)(iVar3 + 0x16);
      *pbVar1 = *pbVar1 | 1;
    }
    local_c = _convert_task_to_port(local_8);
    if (local_c != 0) {
      _object_copyout(iVar2,local_c,6,&local_c);
    }
  }
  return local_c;
}

