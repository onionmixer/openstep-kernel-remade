
void _np_nap(undefined4 param_1)

{
  undefined4 uStack_8;
  
  uStack_8 = 0;
  _timeout(_thread_wakeup,&uStack_8,param_1);
  _assert_wait(&uStack_8,0);
  _thread_block();
  return;
}
