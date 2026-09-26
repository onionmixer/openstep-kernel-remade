
void _sleep_with_continuation(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  
  iVar3 = *_active_u;
  uVar1 = _splhigh();
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,0x19 < (int)param_2);
  if ((int)param_2 < 0x1a) {
    _spl0();
    _active_u[0x6c] = _active_u[0x6c] + 1;
    if (_master_cpu != 0) {
      _printf(s_unix_sleep__on_slave__001daa8e);
    }
    _thread_block_with_continuation(param_3);
LAB_0010a853:
    _spln(uVar1);
  }
  else {
    if ((iVar3 == 0) ||
       (((*(byte *)(_active_threads + 0x17c) & 3) == 0 &&
        ((uVar4 = *(uint *)(iVar3 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x7c),
         uVar4 == 0 ||
         ((((*(byte *)(iVar3 + 0x28) & 0x10) == 0 &&
           ((~(*(uint *)(iVar3 + 0x20) | *(uint *)(iVar3 + 0x1c)) & uVar4) == 0)) ||
          (iVar2 = _issig(1), iVar2 == 0)))))))) {
      _spl0();
      _active_u[0x6c] = _active_u[0x6c] + 1;
      if (_master_cpu != 0) {
        _printf(s_unix_sleep__on_slave__001daa77);
      }
      _thread_block_with_continuation(param_3);
      if ((iVar3 == 0) ||
         (((*(byte *)(_active_threads + 0x17c) & 3) == 0 &&
          (((uVar4 = *(uint *)(iVar3 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x7c),
            uVar4 == 0 ||
            (((*(byte *)(iVar3 + 0x28) & 0x10) == 0 &&
             ((~(*(uint *)(iVar3 + 0x20) | *(uint *)(iVar3 + 0x1c)) & uVar4) == 0)))) ||
           (iVar3 = _issig(1), iVar3 == 0)))))) goto LAB_0010a853;
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

