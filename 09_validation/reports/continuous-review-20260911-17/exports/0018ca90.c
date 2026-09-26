
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _loutw(undefined2 param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  
  while (param_3 != 0) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    out(param_1,uVar1);
    LOCK();
    _DAT_001e7728 = _DAT_001e7728 + 1;
    UNLOCK();
    param_3 = param_3 + -1;
  }
  return;
}

