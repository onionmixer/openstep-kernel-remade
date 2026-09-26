
undefined4 _evopen(void)

{
  undefined4 uVar1;
  
  *(byte *)(_mon_global + 4) = *(byte *)(_mon_global + 4) & 0xf7;
  if ((unk_40B6904 & 1) == 0) {
    _kminit();
  }
  if (dword_40B4F5A == 0) {
    dword_40B4F5A = 1;
    _kernel_thread(_kernel_task,sub_40683B6);
  }
  if (_evOpenCalled == 0) {
    unk_40B6904 = unk_40B6904 & 0xfff7;
    word_40B6906 = 0;
    word_40B6938 = 0;
    dword_40B4F5E = 0;
    _eventPort = 0;
    _evOpenCalled = 1;
    _evRetryMask = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}

