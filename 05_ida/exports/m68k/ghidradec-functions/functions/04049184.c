
undefined4 _mig_get_reply_port(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _active_threads;
  if (*(int *)(_active_threads + 0xb4) == 0) {
    uVar2 = _mach_reply_port();
    *(undefined4 *)(iVar1 + 0xb4) = uVar2;
  }
  return *(undefined4 *)(iVar1 + 0xb4);
}
