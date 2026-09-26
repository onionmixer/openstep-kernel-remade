
int sub_4025F16(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  while( true ) {
    if (iVar1 != 0) {
      param_1[1] = *(int *)(iVar1 + 0x14);
      return iVar1;
    }
    if (*param_1 == 0) break;
    iVar1 = *(int *)(*param_1 + 0x44);
    *param_1 = *(int *)(*param_1 + 0x40);
  }
  return 0;
}
