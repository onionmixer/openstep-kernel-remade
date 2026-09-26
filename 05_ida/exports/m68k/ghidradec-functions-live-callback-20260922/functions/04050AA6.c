
void _thread_sleep(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _assert_wait(param_1,param_3);
  _thread_block_with_continuation(0);
  return;
}

