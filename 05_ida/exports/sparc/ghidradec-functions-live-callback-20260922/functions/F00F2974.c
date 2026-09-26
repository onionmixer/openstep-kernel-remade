
int sub_F00F2974(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_2 + 0xc) != 0)) {
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar1 = *(int *)(param_2 + 0x14);
    }
    else {
      if (*(int *)(param_1 + 0xc) == 0) {
        return 1;
      }
      iVar1 = *(int *)(param_2 + 0x14);
    }
    iVar1 = iVar1 - *(int *)(param_1 + 0x14);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

