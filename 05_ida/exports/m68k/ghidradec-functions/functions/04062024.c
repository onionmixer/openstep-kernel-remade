
int _task_by_pid(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  uVar1 = *(undefined4 *)(_active_threads + 0xc);
  iStack_c = 0;
  iVar2 = _task_by_unix_pid(uVar1,param_1,&uStack_8);
  if (iVar2 == 0) {
    iStack_c = _convert_task_to_port(uStack_8);
    if (iStack_c != 0) {
      _object_copyout(uVar1,iStack_c,6,&iStack_c);
    }
  }
  return iStack_c;
}
