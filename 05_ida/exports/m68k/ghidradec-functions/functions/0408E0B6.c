
undefined4 _en_accept_multicast(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (((*(byte *)(*param_1 + 0xc) & 1) == 0) &&
     ((*param_2 != -1 || (*(sword *)(param_2 + 1) != -1)))) {
    iVar2 = 0;
    uVar1 = 0;
    if (0 < *(int *)((int)param_1 + 0x526)) {
      piVar3 = *(int **)((int)param_1 + 0x522);
      do {
        if ((*param_2 == *piVar3) && (*(sword *)(piVar3 + 1) == *(sword *)(param_2 + 1))) {
          return 1;
        }
        piVar3 = (int *)((int)piVar3 + 6);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)((int)param_1 + 0x526));
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
