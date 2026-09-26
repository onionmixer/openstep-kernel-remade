
int sub_4032C82(int param_1,undefined2 *param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  
  dword_40B35BE = dword_40B35BE + 1;
  *param_2 = (sword)(param_4 >> 0xd);
  if (*(uint *)(param_1 + 0x3e) == param_4) {
    dword_40B35C2 = dword_40B35C2 + 1;
    _compress_backoff_cnt = _compress_backoff_cnt + 1;
    _bcopy(param_2,*(int *)(param_1 + 0x32) + param_5,param_3);
    if (param_4 == *(uint *)(param_1 + 0x2c)) {
      _swpgotcha = _swpgotcha + 1;
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(undefined *)(param_1 + 0x30) = 0;
    }
  }
  else if (param_4 == *(uint *)(param_1 + 0x2c)) {
    dword_40B35C6 = dword_40B35C6 + 1;
    _compress_backoff_cnt = _compress_backoff_cnt + 1;
    _bcopy(param_2,*(int *)(param_1 + 0x24) + param_5,param_3);
    *(undefined *)(param_1 + 0x30) = 1;
  }
  else {
    if (*(uint *)(param_1 + 0x3e) != 0xffffffff) {
      dword_40B35CA = dword_40B35CA + 1;
      iVar1 = sub_4032B84(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x36),_page_size,
                          *(undefined4 *)(param_1 + 0x3e));
      if (iVar1 != 0) {
        _printf(aCannotFlushOut);
        return iVar1;
      }
    }
    *(uint *)(param_1 + 0x3e) = param_4;
    _bcopy(param_2,*(int *)(param_1 + 0x32) + param_5,param_3);
  }
  return 0;
}
