
void _ux_handler_init(void)

{
  undefined4 uVar1;
  
  _ux_exception_port = 0;
  uVar1 = _kernel_task_create(_kernel_task,0);
  _kernel_thread(uVar1,sub_405C12E,0);
  if (_ux_exception_port == 0) {
    _thread_sleep(&_ux_exception_port,0,0);
  }
  return;
}
