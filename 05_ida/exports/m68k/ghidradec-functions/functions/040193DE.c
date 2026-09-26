
int _lookupname(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined auStack_10 [12];
  
  iVar1 = _pn_get(param_1,param_2,auStack_10);
  if (iVar1 == 0) {
    iVar1 = _lookuppn(auStack_10,param_3,param_4,param_5);
    _pn_free(auStack_10);
  }
  return iVar1;
}
