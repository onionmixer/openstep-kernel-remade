
undefined4
_sleep_with_continuation_and_deadline(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *_active_u;
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,-(int)-(0x19 < (int)param_2));
  if ((int)param_2 < 0x1a) {
    if (param_4 != 0) {
      uVar4 = _hzto(param_4);
      _thread_set_timeout(uVar4);
    }
    *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
    if (_master_cpu != 0) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(param_3);
loc_400A0E0:
    uVar4 = 0;
  }
  else {
    if ((iVar3 == 0) ||
       (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
        ((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
         uVar1 == 0 ||
         ((((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
           ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)) ||
          (iVar2 = _issig(1), iVar2 == 0)))))))) {
      if (param_4 != 0) {
        uVar4 = _hzto(param_4);
        _thread_set_timeout(uVar4);
      }
      *(int *)((int)_active_u + 0x1a6) = *(int *)((int)_active_u + 0x1a6) + 1;
      if (_master_cpu != 0) {
        _printf(aUnixSleepOnSla);
      }
      _thread_block_with_continuation(param_3);
      if ((iVar3 == 0) ||
         (((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 == 0 &&
          (((uVar1 = *(uint *)(*(int *)(_active_threads + 0x80) + 0x72) | *(uint *)(iVar3 + 0x18),
            uVar1 == 0 ||
            (((*(byte *)(iVar3 + 0x2b) & 0x10) == 0 &&
             ((uVar1 & ~(*(uint *)(iVar3 + 0x1c) | *(uint *)(iVar3 + 0x20))) == 0)))) ||
           (iVar3 = _issig(1), iVar3 == 0)))))) goto loc_400A0E0;
    }
    else {
      _clear_wait(_active_threads,2,1);
    }
    if (param_3 != 0) {
      _call_continuation(param_3);
    }
    if ((param_2 & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
      _longjmp(dword_40B57D4 + 0x28);
    }
    uVar4 = 1;
  }
  return uVar4;
}
