
undefined4 _mach_reply_port(void)

{
  int iVar1;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  iVar1 = _ipc_port_alloc(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c),&uStack_8,
                          auStack_c);
  if (iVar1 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}
