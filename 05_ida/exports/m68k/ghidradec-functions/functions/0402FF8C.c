
bool _xdr_char(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uStack_8;
  
  uStack_8 = (int)*param_2;
  iVar1 = _xdr_int(param_1,&uStack_8);
  if (iVar1 != 0) {
    *param_2 = (char)uStack_8;
  }
  return iVar1 != 0;
}
