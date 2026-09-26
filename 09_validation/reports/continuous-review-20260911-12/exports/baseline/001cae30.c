
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NXAllocErrorData(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  do {
  } while (DAT_001e5540 != 0);
  LOCK();
  DAT_001e5540 = 1;
  UNLOCK();
  uVar2 = param_1 + _DAT_001e553c + 7 & 0xfffffff8;
  if ((int)DAT_001e5454 < (int)uVar2) {
    DAT_001e5538 = _realloc(DAT_001e5538,uVar2);
    DAT_001e5454 = uVar2;
  }
  *param_2 = (int)DAT_001e5538 + _DAT_001e553c;
  uVar1 = DAT_001e5540;
  _DAT_001e553c = uVar2;
  LOCK();
  DAT_001e5540 = 0;
  UNLOCK();
  return uVar1;
}

