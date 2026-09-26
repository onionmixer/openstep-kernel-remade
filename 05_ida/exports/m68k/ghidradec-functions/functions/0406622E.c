
int _dev_find(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,
             undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)*param_4)(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _printf(aSDAt0xX,param_5,param_2,iVar1);
    if (param_3 != 0) {
      iVar2 = _install_polled_intr(param_3,param_4[5]);
      if (-1 < iVar2) {
        _printf(&aIplD,param_3);
      }
    }
    _printf(&asc_40A6049);
  }
  return iVar1;
}
