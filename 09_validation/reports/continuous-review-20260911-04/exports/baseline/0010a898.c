
void _sleep_with_continuation_and_deadline(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int unaff_EBX;
  
  iVar4 = *_active_u;
  uVar1 = _splhigh();
  if (iVar4 != 0) {
    *(byte *)(iVar4 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,0x19 < (int)param_2);
  if ((int)param_2 < 0x1a) {
    if (param_4 != 0) {
      uVar3 = _hzto(param_4);
      _thread_set_timeout(uVar3);
    }
    _spl0();
    _active_u[0x6c] = _active_u[0x6c] + 1;
    if (_master_cpu != 0) {
      _printf(s_unix_sleep__on_slave__001daa8e);
    }
    _thread_block_with_continuation(param_3);
LAB_0010aa15:
    _spln(uVar1);
  }
  else {
    if ((iVar4 == 0) ||
       (((*(byte *)(_active_threads + 0x17c) & 3) == 0 &&
        ((uVar5 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x7c),
         uVar5 == 0 ||
         ((((*(byte *)(iVar4 + 0x28) & 0x10) == 0 &&
           ((~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c)) & uVar5) == 0)) ||
          (iVar2 = _issig(1), iVar2 == 0)))))))) {
      if (param_4 != 0) {
        uVar3 = _hzto(param_4);
        _thread_set_timeout(uVar3);
      }
      _spl0();
      _active_u[0x6c] = _active_u[0x6c] + 1;
      if (_master_cpu != 0) {
        _printf(s_unix_sleep__on_slave__001daa77);
      }
      _thread_block_with_continuation(param_3);
      if ((iVar4 == 0) ||
         (((*(byte *)(_active_threads + 0x17c) & 3) == 0 &&
          (((uVar5 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x7c),
            uVar5 == 0 ||
            (((*(byte *)(iVar4 + 0x28) & 0x10) == 0 &&
             ((~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c)) & uVar5) == 0)))) ||
           (iVar4 = _issig(1), iVar4 == 0)))))) goto LAB_0010aa15;
    }
    else {
      _clear_wait(_active_threads,2,1);
      _spl0();
    }
    if (param_3 != 0) {
      _call_continuation(param_3);
    }
    if ((param_2 & 0x100) == 0) {
      _jump_label((int *)(DAT_001e875c + 0x28),unaff_EBX);
    }
  }
  return;
}

