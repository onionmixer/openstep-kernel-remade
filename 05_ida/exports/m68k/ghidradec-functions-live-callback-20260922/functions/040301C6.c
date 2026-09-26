
void _xdr_netobj(undefined4 param_1,int param_2)

{
  _xdr_bytes(param_1,param_2 + 4,param_2,0x400);
  return;
}

