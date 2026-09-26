
void _sbselqueue(int param_1)

{
  int iVar1;
  
  iVar1 = _selthreadcache(param_1 + 0x10);
  if (iVar1 != 0) {
    *(word *)(param_1 + 0x14) = *(word *)(param_1 + 0x14) | 0x10;
  }
  return;
}

