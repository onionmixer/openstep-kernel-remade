
void _reboot_mach(uint param_1)

{
  if (_kernel_task == 0) {
    _boot(1,param_1 | 4,&unk_40A62E7);
  }
  else {
    _reboot_how = param_1;
    _kernel_thread_noblock(_kernel_task,_halt_thread);
  }
  return;
}

