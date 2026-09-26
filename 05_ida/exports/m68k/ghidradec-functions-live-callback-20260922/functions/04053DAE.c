
void _thread_swapin(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x12] & 0x300;
  if (uVar1 == 0x100) {
    param_1[0x12] = param_1[0x12] & 0xfffffcff | 0x200;
    *param_1 = &_swapin_queue;
    param_1[1] = dword_40C2B6C;
    *(undefined4 **)param_1[1] = param_1;
    dword_40C2B6C = param_1;
    _thread_wakeup_prim(&_swapin_queue,0,0);
  }
  else if (uVar1 != 0x200) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadSwapin);
  }
  return;
}

