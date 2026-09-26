
int _kern_serv_kernel_task_port(void)

{
  int iStack_8;
  
  _task_reference(_kernel_task);
  iStack_8 = _convert_task_to_port(_kernel_task);
  if (iStack_8 == 0) {
    iStack_8 = 0;
  }
  else {
    _object_copyout(*(undefined4 *)(_active_threads + 0xc),iStack_8,6,&iStack_8);
  }
  return iStack_8;
}
