
void _evretry(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _evRetryMask;
  for (uVar2 = 0; (uVar1 != 0 && (uVar2 < _screens)); uVar2 = uVar2 + 1) {
    if ((uVar1 & 1) != 0) {
      _evdispatch(0,uVar2,0);
    }
    uVar1 = uVar1 >> 1;
  }
  return;
}

