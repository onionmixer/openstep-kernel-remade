
int * _getsectbynamefromheader(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x1c);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      if ((*piVar5 == 1) &&
         ((iVar1 = _strncmp(piVar5 + 2,param_2,0x10), iVar1 == 0 || (*(int *)(param_1 + 0xc) == 1)))
         ) {
        piVar4 = piVar5 + 0xe;
        uVar2 = 0;
        if (piVar5[0xc] != 0) {
          do {
            iVar1 = _strncmp(piVar4,param_3,0x10);
            if ((iVar1 == 0) && (iVar1 = _strncmp(piVar4 + 4,param_2,0x10), iVar1 == 0)) {
              return piVar4;
            }
            piVar4 = piVar4 + 0x11;
            uVar2 = uVar2 + 1;
          } while (uVar2 < (uint)piVar5[0xc]);
        }
      }
      piVar5 = (int *)(piVar5[1] + (int)piVar5);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}

