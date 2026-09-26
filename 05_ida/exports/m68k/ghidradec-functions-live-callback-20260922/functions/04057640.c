
void _pnotify_start(void)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  _task_create(_kernel_task,0,&uStack_8);
  _task_deallocate(uStack_8);
  _thread_create(uStack_8,&uStack_c);
  _thread_deallocate(uStack_c);
  _thread_start(uStack_c,_notify_server_loop);
  _thread_resume(uStack_c);
  return;
}

