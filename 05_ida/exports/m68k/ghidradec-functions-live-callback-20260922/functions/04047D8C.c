
void _exception_raise_continue(void)

{
  undefined4 uVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = _ipc_mqueue_receive(*(int *)(_active_threads + 0xbc) + 0x3c,0,0xffffffff,0,1,
                              _exception_raise_continue,&uStack_8,&uStack_c);
  _exception_raise_continue_slow(uVar1,uStack_8,uStack_c);
  return;
}

