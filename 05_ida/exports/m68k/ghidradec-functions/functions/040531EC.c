
undefined4 _thread_dowait(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadDowait);
  }
  iVar2 = 0;
  do {
    switch(*(uint *)(param_1 + 0x48) & 0xf) {
    :
      goto loc_40532C2;
    case :
      iVar1 = _rem_runq(param_1);
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
        iVar2 = *(int *)(param_1 + 0x44);
        *(undefined4 *)(param_1 + 0x44) = 0;
        goto loc_40532C2;
      }
      break;
    case :
    case :
    case :
    case :
      break;
    }
    *(undefined4 *)(param_1 + 0x44) = 1;
    _thread_sleep(param_1 + 0x44,0,1);
  } while ((*(int *)(_active_threads + 0x40) == 0) || (param_2 != 0));
  uVar3 = 5;
loc_40532C2:
  if (iVar2 != 0) {
    _thread_wakeup_prim(param_1 + 0x44,0,0);
  }
  return uVar3;
}
