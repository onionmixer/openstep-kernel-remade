
undefined4 sub_4030CEC(int param_1,uint param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if (param_3 < 2) {
    if (((param_2 & 1) != 0) &&
       (sVar2 = *(sword *)(iVar1 + 0x80), *(sword *)(iVar1 + 0x80) = sVar2 + -1, sVar2 == 1)) {
      if ((*(word *)(iVar1 + 0x86) & 2) != 0) {
        *(word *)(iVar1 + 0x86) = *(word *)(iVar1 + 0x86) & 0xfffd;
        _wakeup(iVar1 + 0x7e);
      }
      if (*(int *)(iVar1 + 0x76) != 0) {
        _selwakeup(*(int *)(iVar1 + 0x76),*(byte *)(iVar1 + 0x87) & 0x10);
        _thread_deallocate(*(undefined4 *)(iVar1 + 0x76));
        *(word *)(iVar1 + 0x86) = *(word *)(iVar1 + 0x86) & 0xffef;
        *(undefined4 *)(iVar1 + 0x76) = 0;
      }
    }
    if (*(int *)(iVar1 + 0x72) != 0) {
      _thread_deallocate(*(int *)(iVar1 + 0x72));
      *(undefined4 *)(iVar1 + 0x72) = 0;
    }
    if (*(int *)(iVar1 + 0x6e) != 0) {
      _thread_deallocate(*(int *)(iVar1 + 0x6e));
      *(undefined4 *)(iVar1 + 0x6e) = 0;
    }
    if ((((param_2 & 2) != 0) &&
        (sVar2 = *(sword *)(iVar1 + 0x7e), *(sword *)(iVar1 + 0x7e) = sVar2 + -1, sVar2 == 1)) &&
       ((*(word *)(iVar1 + 0x86) & 1) != 0)) {
      *(word *)(iVar1 + 0x86) = *(word *)(iVar1 + 0x86) & 0xfffe;
      _wakeup(iVar1 + 0x80);
    }
    if ((*(sword *)(iVar1 + 0x80) == 0) && (*(sword *)(iVar1 + 0x7e) == 0)) {
      for (iVar3 = *(int *)(iVar1 + 0x66); iVar3 != 0; iVar3 = sub_40315CE(iVar3,iVar1)) {
      }
      if (*(int *)(iVar1 + 0x7a) != 0) {
        _smark(iVar1,0x42);
      }
      *(undefined4 *)(iVar1 + 0x66) = 0;
      *(undefined2 *)(iVar1 + 0x84) = 0;
      *(undefined2 *)(iVar1 + 0x82) = 0;
      *(undefined4 *)(iVar1 + 0x7a) = 0;
    }
  }
  return 0;
}

