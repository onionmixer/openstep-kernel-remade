
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _NXAllocErrorData(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  do {
    do {
      iVar1 = DAT_001e5540;
    } while (iVar1 != 0);
    LOCK();
    iVar1 = DAT_001e5540;
    DAT_001e5540 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  uVar3 = param_1 + _DAT_001e553c + 7 & 0xfffffff8;
  if ((int)DAT_001e5454 < (int)uVar3) {
    DAT_001e5538 = _realloc(DAT_001e5538,uVar3);
    DAT_001e5454 = uVar3;
  }
  *param_2 = (int)DAT_001e5538 + _DAT_001e553c;
  _DAT_001e553c = uVar3;
  LOCK();
  uVar2 = DAT_001e5540;
  DAT_001e5540 = 0;
  UNLOCK();
  return uVar2;
}

