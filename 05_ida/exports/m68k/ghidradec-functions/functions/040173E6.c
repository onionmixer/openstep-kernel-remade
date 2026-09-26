
int * _getvfs(int *param_1)

{
  int *piVar1;
  
  if (_rootvfs != (int *)0x0) {
    piVar1 = _rootvfs;
    do {
      if ((*param_1 == piVar1[5]) && (piVar1[6] == param_1[1])) {
        return piVar1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return (int *)0x0;
}

