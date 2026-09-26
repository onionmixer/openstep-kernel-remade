
bool sub_406B38A(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (_fd_polling_mode == 0) {
    _fc_flags_bclr(param_1,8);
    _fc_start_timer(param_1,param_2);
    _fd_thread_block((uint *)(param_1 + 0x18),0x48,param_1 + 8);
    if ((*(uint *)(param_1 + 0x18) & 0x10) != 0) {
      _fc_stop_timer(param_1);
    }
  }
  else {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffff7;
    iVar1 = 0;
    if (0 < param_3) {
      do {
        if ((*(uint *)(param_1 + 0x18) & 0x40) != 0) break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_3);
    }
    if (param_3 == iVar1) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
    }
  }
  _fc_flags_bclr(param_1,0x80);
  return (*(uint *)(param_1 + 0x18) & 8) != 0;
}

