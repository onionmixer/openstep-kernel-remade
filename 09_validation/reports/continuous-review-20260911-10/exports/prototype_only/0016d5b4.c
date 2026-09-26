
void _pnotify_start(void)

{
  thread_act_t local_c;
  void *local_8;
  
  _task_create(_kernel_task,0,&local_8);
  _task_deallocate(local_8);
  _thread_create((task_t)local_8,&local_c);
  _thread_deallocate(local_c);
  _thread_start(local_c,_notify_server_loop);
  _thread_resume(local_c);
  return;
}

