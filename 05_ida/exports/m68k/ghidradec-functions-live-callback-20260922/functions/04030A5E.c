
bool _xdr_bp_address(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,unk_40AF0AE,0);
  return iVar1 != 0;
}

