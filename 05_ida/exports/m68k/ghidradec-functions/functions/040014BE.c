
undefined4 __move_space(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = _active_threads;
  uVar1 = *(undefined4 *)(_active_threads + 0x70);
  *(code **)(_active_threads + 0x70) = _move_space_fault;
  if (param_3 == 0) {
    *param_1 = param_4;
  }
  else if (param_3 == 2) {
    *(sword *)param_1 = (sword)param_4;
  }
  else {
    *(char *)param_1 = (char)param_4;
  }
  *(undefined4 *)(iVar2 + 0x70) = uVar1;
  return 0;
}
