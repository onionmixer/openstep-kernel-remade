
int _inet_netmatch(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _in_netof(*(undefined4 *)(param_1 + 4));
  iVar2 = _in_netof(*(undefined4 *)(param_2 + 4));
  return -(int)-(iVar2 == iVar1);
}

