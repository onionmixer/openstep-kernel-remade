
undefined4 _snd_unix_ioctl(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined auStack_1c [3];
  undefined uStack_19;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (param_2 == 0x20004108) {
    if (dword_40C6EC4 == 0) {
      _task_create(_kernel_task,0,&uStack_20);
      _thread_create(uStack_20,&uStack_24);
      _thread_start(uStack_24,_snd_server_loop);
      _thread_resume(uStack_24);
      if (dword_40C6EC4 == 0) {
        _assert_wait(&dword_40C6EC4,0);
        _thread_block();
      }
    }
    _object_copyin(*(undefined4 *)(_active_threads + 0xc),*param_3,6,0,param_3);
    _object_copyin(dword_40C6EB8,dword_40C6EB4,6,0,&uStack_28);
    uStack_19 = 1;
    uStack_18 = 0x18;
    uStack_14 = 0;
    uStack_10 = uStack_28;
    uStack_c = *param_3;
    uStack_8 = 0x12f;
    _msg_send_from_kernel(auStack_1c,0,0);
    _port_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c),*param_3);
    _port_deallocate(dword_40C6EC0,uStack_28);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
