
void _ipc_object_copyin_from_kernel(int *param_1,undefined4 param_2)

{
  switch(param_2) {
  case :
  case :
    param_1[5] = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    break;
  case :
  case :
    if (param_1[1] < 0) {
      param_1[6] = param_1[6] + 1;
    }
    *param_1 = *param_1 + 1;
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcObjectCopyi_0);
  case :
  case :
    break;
  case :
    *param_1 = *param_1 + 1;
    param_1[5] = param_1[5] + 1;
    param_1[6] = param_1[6] + 1;
    break;
  case :
    *param_1 = *param_1 + 1;
    param_1[7] = param_1[7] + 1;
  }
  return;
}
