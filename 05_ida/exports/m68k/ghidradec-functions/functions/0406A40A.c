
void _evsetup_screens(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[2];
  if (_evScreen == 0) {
    _evScreenSize = param_1[1] * 0x28;
    _evScreen = _kalloc(_evScreenSize);
    _bzero(_evScreen,_evScreenSize);
    _totalShmemSize = 0xcd2;
  }
  iVar1 = _evScreen;
  iVar2 = iVar2 * 0x28;
  iVar3 = param_1[5];
  *(int *)(_evScreen + 0xc + iVar2) = param_1[4];
  *(int *)(iVar1 + 0x10 + iVar2) = iVar3;
  iVar1 = iVar1 + iVar2;
  *(int *)(iVar1 + 8) = param_1[3];
  _totalShmemSize = _totalShmemSize + *(int *)(iVar1 + 8);
  *param_1 = _totalShmemSize;
  return;
}
