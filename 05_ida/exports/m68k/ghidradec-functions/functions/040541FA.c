
void _calloutDispatchUnique(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar2 = dword_40B4DB8;
  if (dword_40AFF2C != 0) {
    puVar3 = dword_40B4DC0;
    if ((undefined4 **)dword_40B4DC0 != &dword_40B4DC0) {
      do {
        if ((param_1 == puVar3[2]) && (param_2 == puVar3[3])) break;
        puVar3 = (undefined4 *)*puVar3;
      } while ((undefined4 **)puVar3 != &dword_40B4DC0);
      if ((undefined4 **)puVar3 != &dword_40B4DC0) {
        return;
      }
    }
    if ((int **)dword_40B4DB8 == &dword_40B4DB8) {
                    /* WARNING: Subroutine does not return */
      _panic(aInternalentrya);
    }
    *(int ***)(*dword_40B4DB8 + 4) = &dword_40B4DB8;
    piVar1 = dword_40B4DB8 + 2;
    dword_40B4DB8 = (int *)*dword_40B4DB8;
    *piVar1 = param_1;
    piVar2[3] = param_2;
    piVar2[4] = 0;
    piVar2[5] = 0;
    piVar2[6] = 0;
    *piVar2 = (int)&dword_40B4DC0;
    piVar2[1] = (int)dword_40B4DC4;
    *(int **)piVar2[1] = piVar2;
    dword_40B4DC4 = piVar2;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    piVar2[7] = 1;
    sub_4054786();
  }
  return;
}
