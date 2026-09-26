
undefined4 _task_get_assignment(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 5;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x24);
    _pset_reference(*param_2);
    uVar1 = 0;
  }
  return uVar1;
}
