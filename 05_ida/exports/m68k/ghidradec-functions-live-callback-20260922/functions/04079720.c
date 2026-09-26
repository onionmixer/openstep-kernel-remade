
void _od_update_thread(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(_active_threads + 0x4c);
  uVar2 = *(undefined4 *)(_active_threads + 0x54);
  *(undefined4 *)(_active_threads + 0x4c) = 0x1f;
  *(undefined4 *)(_active_threads + 0x54) = 0x1f;
  _od_update();
  *(undefined4 *)(_active_threads + 0x4c) = uVar1;
  *(undefined4 *)(_active_threads + 0x54) = uVar2;
  _od_update_time = 0;
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}

