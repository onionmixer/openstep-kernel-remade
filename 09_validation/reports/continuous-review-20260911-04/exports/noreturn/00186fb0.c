
void _jump_label(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[4];
  *piVar1 = param_1[5];
  piVar1[-1] = param_1[6];
  piVar1[-2] = 0x186fd2;
  _splx();
  return;
}

