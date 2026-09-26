
void _sbflush(sword *param_1)

{
  sword sVar1;
  
  if ((*(byte *)((int)param_1 + 0x15) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aSbflush);
  }
  sVar1 = param_1[2];
  while (sVar1 != 0) {
    _sbdrop(param_1,*param_1);
    sVar1 = param_1[2];
  }
  if (((*param_1 == 0) && (param_1[2] == 0)) && (*(int *)(param_1 + 6) == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aSbflush2);
}

