
undefined4 _fd_thread_block(uint *param_1,uint param_2)

{
  uint uVar1;
  
  while( true ) {
    uVar1 = param_2 & *param_1;
    if (uVar1 != 0) break;
    _assert_wait(param_1,0);
    _thread_block();
  }
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar1 < 0) << 3));
}

