
int * _choose_pset_thread(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 0x104) < 1) {
    if (*(int *)(param_1 + 0x110) == 1) {
      *(undefined4 *)(param_1 + 0x110) = 2;
      if (param_1 == _master_processor) {
        piVar3 = *(int **)(param_2 + 0x10c);
        if (piVar3 == (int *)(param_2 + 0x108)) {
          *piVar3 = param_1;
        }
        else {
          piVar3[0x42] = param_1;
        }
        *(int **)(param_1 + 0x10c) = piVar3;
        *(int *)(param_1 + 0x108) = param_2 + 0x108;
        *(int *)(param_2 + 0x10c) = param_1;
      }
      else {
        iVar2 = *(int *)(param_2 + 0x108);
        if (iVar2 == param_2 + 0x108) {
          *(int *)(param_2 + 0x10c) = param_1;
        }
        else {
          *(int *)(iVar2 + 0x10c) = param_1;
        }
        *(int *)(param_1 + 0x108) = iVar2;
        *(int **)(param_1 + 0x10c) = (int *)(param_2 + 0x108);
        *(int *)(param_2 + 0x108) = param_1;
      }
      *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + 1;
    }
    piVar3 = *(int **)(param_1 + 0x118);
  }
  else {
    iVar2 = *(int *)(param_2 + 0x100);
    piVar4 = (int *)(param_2 + iVar2 * 8);
    while( true ) {
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aChoosePsetThre);
      }
      piVar3 = (int *)*piVar4;
      if (piVar3 != piVar4) break;
      iVar2 = iVar2 + -1;
      piVar4 = piVar4 + -2;
    }
    if (piVar4 == piVar3) {
      piVar3 = (int *)0x0;
    }
    else {
      *(int **)(*piVar3 + 4) = piVar4;
      *piVar4 = *piVar3;
    }
    *(undefined4 *)((int)piVar3 + 8) = 0;
    iVar1 = *(int *)(param_2 + 0x104);
    *(int *)(param_2 + 0x104) = iVar1 + -1;
    if (((iVar1 != 1 && -1 < iVar1 + -1) && ((*(byte *)(param_2 + 0x15b) & 2) != 0)) &&
       (piVar4 == (int *)*piVar4)) {
      do {
        piVar4 = piVar4 + -2;
        iVar2 = iVar2 + -1;
      } while (piVar4 == (int *)*piVar4);
    }
    *(int *)(param_2 + 0x100) = iVar2;
  }
  return piVar3;
}

