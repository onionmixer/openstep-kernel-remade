
int _geterror(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (((*(byte *)(param_1 + 3) & 4) != 0) && (iVar1 = (int)*(sword *)(param_1 + 0x1c), iVar1 == 0))
  {
    iVar1 = 5;
  }
  return iVar1;
}
