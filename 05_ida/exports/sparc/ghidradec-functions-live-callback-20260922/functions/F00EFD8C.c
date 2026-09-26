
int _class_lookupMethodInMethodList(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  piVar2 = (int *)(param_1 + 8);
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return 0;
    }
    if (param_2 == *piVar2) break;
    piVar2 = piVar2 + 3;
  }
  return piVar2[2];
}

