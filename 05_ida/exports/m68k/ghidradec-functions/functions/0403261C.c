
undefined4 _spec_realvp(int param_1,int *param_2)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 != 0) {
    if ((*(undefined **)(param_1 + 0x1c) == _spec_vnodeops) ||
       (*(undefined **)(param_1 + 0x1c) == _fifo_vnodeops)) {
      param_1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
    }
    if (param_1 != 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))(param_1,&iStack_8);
      if (iVar1 == 0) {
        param_1 = iStack_8;
      }
    }
  }
  *param_2 = param_1;
  return 0;
}
