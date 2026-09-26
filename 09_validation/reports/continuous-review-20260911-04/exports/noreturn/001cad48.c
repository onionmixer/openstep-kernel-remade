
void _NXDefaultExceptionRaiser(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = _current_thread_EXTERNAL();
  piVar2 = &DAT_001e551c;
  do {
    if (piVar2[4] == iVar1) goto LAB_001cad84;
    piVar2 = (int *)piVar2[5];
  } while (piVar2 != (int *)0x0);
  piVar2 = (int *)FUN_001ca960(iVar1);
LAB_001cad84:
  while( true ) {
    piVar3 = (int *)*piVar2;
    if (piVar3 == (int *)0x0) {
      if (__NXUncaughtExceptionHandler != (code *)0x0) {
        (*__NXUncaughtExceptionHandler)(param_1,param_2,param_3);
      }
                    /* WARNING: Subroutine does not return */
      _panic("Uncaught exception");
    }
    if (((uint)piVar3 & 1) == 0) break;
    piVar3 = (int *)((((int)piVar3 + -1) / 2) * 0xc + piVar2[1]);
    *piVar2 = *piVar3;
    piVar2[3] = ((int)piVar3 - piVar2[1]) * -0x55555555 >> 2;
    (*(code *)piVar3[1])(piVar3[2],param_1,param_2,param_3);
  }
  piVar3[0x13] = param_1;
  piVar3[0x14] = param_2;
  piVar3[0x15] = param_3;
  *piVar2 = piVar3[0x12];
                    /* WARNING: Subroutine does not return */
  _jump_label(piVar3,1);
}

