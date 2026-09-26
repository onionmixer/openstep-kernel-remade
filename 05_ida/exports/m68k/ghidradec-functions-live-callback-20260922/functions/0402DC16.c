
void _clntkudp_realloc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _bcopy(*(undefined4 *)(iVar1 + 0x68),param_2,0x2260);
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  *(undefined4 *)(iVar1 + 0x68) = param_2;
  return;
}

