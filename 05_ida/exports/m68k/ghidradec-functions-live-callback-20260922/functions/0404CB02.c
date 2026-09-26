
int _find_listener(int param_1,sword param_2,int param_3,sword param_4,byte param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = (int *)(_listeners + (param_5 & 0xf) * 4);
  piVar4 = (int *)*piVar1;
  piVar3 = (int *)*piVar1;
  while( true ) {
    piVar2 = piVar4;
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (((((*(sword *)((int)piVar2 + 0xe) == 0) || (param_4 == *(sword *)((int)piVar2 + 0xe))) &&
         ((*(sword *)(piVar2 + 3) == 0 || (param_2 == *(sword *)(piVar2 + 3))))) &&
        ((piVar2[1] == 0 || (param_1 == piVar2[1])))) &&
       ((piVar2[2] == 0 || (param_3 == piVar2[2])))) break;
    piVar4 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  if (piVar2 != (int *)*piVar1) {
    *piVar3 = *piVar2;
    *piVar2 = *piVar1;
    *piVar1 = (int)piVar2;
  }
  return piVar2[4];
}

