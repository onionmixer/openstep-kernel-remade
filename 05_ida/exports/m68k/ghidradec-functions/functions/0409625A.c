
int _wrmem(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _dbg_setjmp(unk_40B55CC);
  if (iVar1 == 0) {
    dword_40B5610 = unk_40B55CC;
    sub_409630E();
    if (param_2 == 2) {
      *(sword *)param_1 = (sword)param_3;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
loc_40962D8:
        dword_40B5610 = (undefined *)0x0;
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aWrmemBadSize);
      }
      *(char *)param_1 = (char)param_3;
    }
    else {
      if (param_2 != 4) goto loc_40962D8;
      *param_1 = param_3;
    }
    _cache_push();
    dword_40B5610 = (undefined *)0x0;
    sub_4096358();
    _cache_push();
    iVar1 = 0;
  }
  else {
    sub_4096358();
  }
  return iVar1;
}
