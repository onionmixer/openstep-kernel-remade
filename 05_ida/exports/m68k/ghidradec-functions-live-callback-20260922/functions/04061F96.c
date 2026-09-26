
undefined4 _task_by_unix_pid(int param_1,undefined4 param_2,undefined4 *param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _pfind(param_2);
  if ((((iVar2 != 0) && (*(int *)(param_1 + 0x34) != 0)) &&
      ((*(sword *)(*(int *)(param_1 + 0x34) + 0x2c) == *(sword *)(iVar2 + 0x2c) ||
       (iVar3 = _suser(), iVar3 != 0)))) && (*(char *)(iVar2 + 0x13) != '\x05')) {
    if (*(int *)(iVar2 + 0x66) != 0) {
      _task_reference(*(int *)(iVar2 + 0x66));
    }
    *param_3 = *(undefined4 *)(iVar2 + 0x66);
    iVar2 = _suser();
    if ((iVar2 != 0) && (iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0x34), iVar2 != 0)) {
      pbVar1 = (byte *)(iVar2 + 0x16);
      *pbVar1 = *pbVar1 | 0x80;
    }
    return 0;
  }
  *param_3 = 0;
  return 5;
}

