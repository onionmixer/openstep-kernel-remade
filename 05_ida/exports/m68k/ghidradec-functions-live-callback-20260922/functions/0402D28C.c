
bool _xdr_rdlnres(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _xdr_union(param_1,param_2,param_2 + 4,_rdlnres_discrim,_xdr_void);
  return iVar1 != 0;
}

