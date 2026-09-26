/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c034 */

undefined4 _task_by_unix_pid(int param_1,undefined4 param_2,undefined4 *param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _pfind(param_2);
  if ((((iVar2 != 0) && (*(int *)(param_1 + 0x3c) != 0)) &&
      ((*(short *)(iVar2 + 0x2c) == *(short *)(*(int *)(param_1 + 0x3c) + 0x2c) ||
       (iVar3 = _suser(), iVar3 != 0)))) && (*(char *)(iVar2 + 0x13) != '\x05')) {
    if (*(int *)(iVar2 + 0x68) != 0) {
      _task_reference(*(int *)(iVar2 + 0x68));
    }
    *param_3 = *(undefined4 *)(iVar2 + 0x68);
    iVar2 = _suser();
    if ((iVar2 != 0) && (iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0x3c), iVar2 != 0)) {
      pbVar1 = (byte *)(iVar2 + 0x16);
      *pbVar1 = *pbVar1 | 1;
    }
    return 0;
  }
  *param_3 = 0;
  return 5;
}

