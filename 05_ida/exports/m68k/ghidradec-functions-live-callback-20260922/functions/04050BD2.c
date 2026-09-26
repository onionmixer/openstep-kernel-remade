
undefined4 _thread_invoke(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_3 == param_1) {
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffff7;
    if (param_2 == 0) {
      return 1;
    }
    _call_continuation(param_2);
    return 1;
  }
  if ((*(int *)(param_1 + 0x2c) == _active_stacks) || (param_2 == 0)) {
    if (((*(uint *)(param_3 + 0x48) & 0x100) != 0) &&
       (((*(uint *)(param_3 + 0x48) & 0x200) != 0 ||
        (iVar3 = _stack_alloc_try(param_3,_thread_continue), iVar3 == 0)))) {
loc_4050D8A:
      _thread_swapin(param_3);
      _c_thread_invoke_misses = _c_thread_invoke_misses + 1;
      return 0;
    }
loc_4050DAE:
    *(word *)(param_3 + 0x4a) = *(word *)(param_3 + 0x4a) & 0xfef7;
    _need_ast = *(uint *)(param_3 + 0x174) | _need_ast & 0xfffffffc;
    if (_need_ast == 0) {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 & 0xef;
    }
    else {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 | 0x10;
    }
    _switch_unix_context(param_3);
    _c_thread_invoke_csw = _c_thread_invoke_csw + 1;
    uVar4 = _switch_context(param_1,param_2,param_3);
    _thread_dispatch(uVar4);
    return 1;
  }
  uVar2 = *(uint *)(param_3 + 0x48) & 0x300;
  if (uVar2 != 0x100) {
    if ((0x100 < uVar2) && (uVar2 == 0x200)) goto loc_4050D8A;
    goto loc_4050DAE;
  }
  *(uint *)(param_3 + 0x48) = *(uint *)(param_3 + 0x48) & 0xfffffef7;
  _need_ast = *(uint *)(param_3 + 0x174) | _need_ast & 0xfffffffc;
  if (_need_ast == 0) {
    pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar1 = *pbVar1 & 0xef;
  }
  else {
    pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar1 = *pbVar1 | 0x10;
  }
  _switch_unix_context(param_3);
  _stack_handoff(param_1,param_3);
  *(int *)(param_1 + 0x30) = param_2;
  iVar3 = *(int *)(param_1 + 0x48);
  if (iVar3 == 0xc) {
loc_4050D10:
    *(word *)(param_1 + 0x4a) = *(word *)(param_1 + 0x4a) | 0x100;
    _thread_setrun(param_1,0);
  }
  else {
    if (iVar3 < 0xd) {
      if (iVar3 != 5) {
        if (5 < iVar3) {
          if (7 < iVar3) goto loc_4050D3E;
loc_4050CE4:
          *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb | 0x100;
          if (*(int *)(param_1 + 0x44) != 0) {
            *(undefined4 *)(param_1 + 0x44) = 0;
            _thread_wakeup_prim(param_1 + 0x44,0,0);
          }
          goto loc_4050D4C;
        }
        iVar5 = 4;
loc_4050CCE:
        if (iVar5 != iVar3) {
loc_4050D3E:
                    /* WARNING: Subroutine does not return */
          _panic(aThreadInvoke);
        }
        goto loc_4050D10;
      }
    }
    else if (iVar3 != 0xf) {
      if (0xf < iVar3) {
        if (iVar3 != 0x16) {
          if (iVar3 != 0x84) goto loc_4050D3E;
          *(undefined4 *)(param_1 + 0x48) = 0x184;
          goto loc_4050D4C;
        }
        goto loc_4050CE4;
      }
      if (iVar3 != 0xd) {
        iVar5 = 0xe;
        goto loc_4050CCE;
      }
    }
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb | 0x100;
  }
loc_4050D4C:
  _c_thread_invoke_hits = _c_thread_invoke_hits + 1;
  _call_continuation(*(undefined4 *)(param_3 + 0x30));
  return 1;
}

