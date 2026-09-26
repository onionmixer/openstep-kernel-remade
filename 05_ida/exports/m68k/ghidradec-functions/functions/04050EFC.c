
void _thread_dispatch(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    *(word *)(param_1 + 0x4a) = *(word *)(param_1 + 0x4a) | 0x100;
    _stack_free(param_1);
  }
  uVar1 = *(uint *)(param_1 + 0x48) & 0xfffffcff;
  if (uVar1 == 0xc) {
loc_4050F86:
    _thread_setrun(param_1,0);
  }
  else {
    if ((int)uVar1 < 0xd) {
      if (uVar1 != 5) {
        if (5 < (int)uVar1) {
          if ((int)uVar1 < 8) {
loc_4050F66:
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
            if (*(int *)(param_1 + 0x44) == 0) {
              return;
            }
            *(undefined4 *)(param_1 + 0x44) = 0;
            _thread_wakeup_prim(param_1 + 0x44,0,0);
            return;
          }
          goto loc_4050F9A;
        }
        uVar2 = 4;
loc_4050F50:
        if (uVar2 != uVar1) {
loc_4050F9A:
                    /* WARNING: Subroutine does not return */
          _panic(aThreadDispatch);
        }
        goto loc_4050F86;
      }
    }
    else if (uVar1 != 0xf) {
      if (0xf < (int)uVar1) {
        if (uVar1 == 0x16) goto loc_4050F66;
        if (uVar1 == 0x84) {
          return;
        }
        goto loc_4050F9A;
      }
      if (uVar1 != 0xd) {
        uVar2 = 0xe;
        goto loc_4050F50;
      }
    }
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
  }
  return;
}
