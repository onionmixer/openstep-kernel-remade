
int * _getsegbynamefromheader(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x1c);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      if ((*piVar3 == 1) && (iVar1 = _strncmp(piVar3 + 2,param_2,0x10), iVar1 == 0)) {
        return piVar3;
      }
      piVar3 = (int *)(piVar3[1] + (int)piVar3);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}
