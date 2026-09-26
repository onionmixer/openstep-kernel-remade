
undefined4 _xdr_opaque_auth(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _xdr_enum(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = _xdr_bytes(param_1,param_2 + 4,param_2 + 8,400);
  }
  return uVar2;
}
