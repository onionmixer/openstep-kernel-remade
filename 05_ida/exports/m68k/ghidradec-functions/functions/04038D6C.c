
void sub_4038D6C(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 4) == *(int *)(param_1 + 4)) {
    *(int *)(param_1 + 4) = *(int *)(param_2 + 8) + 1;
    *(int *)(param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)(param_1 + 8) == *(int *)(param_2 + 8)) {
      *(int *)(param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
    }
    else {
      iVar2 = _kalloc(0x1c);
      _bcopy(param_1,iVar2,0x1c);
      piVar1 = (int *)(*(int *)(iVar2 + 0x10) + 8);
      *piVar1 = *piVar1 + 1;
      *(int *)(iVar2 + 4) = *(int *)(param_2 + 8) + 1;
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_2 + 4) + -1;
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x14);
      *(int *)(param_2 + 0x14) = iVar2;
    }
    *(int *)(param_1 + 0x14) = param_2;
  }
  return;
}
