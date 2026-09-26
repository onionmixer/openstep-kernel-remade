
int _stat1(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_44;
  undefined auStack_40 [60];
  
  iVar1 = _lookupname(*param_1,0,param_2,0,&uStack_44);
  if (iVar1 == 0) {
    iVar1 = _vno_stat(uStack_44,auStack_40);
    _vn_rele(uStack_44);
    if (iVar1 == 0) {
      iVar1 = _copyoutmsg(auStack_40,param_1[1],0x3c);
    }
  }
  return iVar1;
}
