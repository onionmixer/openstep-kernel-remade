
int _catq(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 0) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = param_1[2];
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    iVar1 = 4;
  }
  else {
    while (iVar1 = _getc(param_1), -1 < iVar1) {
      _putc(iVar1,param_2);
    }
  }
  return iVar1;
}
