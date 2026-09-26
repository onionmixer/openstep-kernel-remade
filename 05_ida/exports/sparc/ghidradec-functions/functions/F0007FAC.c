
int _ffs(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0) {
    do {
      iVar2 = iVar2 + 1;
      uVar1 = param_1 & 1;
      param_1 = param_1 >> 1;
    } while (uVar1 == 0);
  }
  return iVar2;
}
