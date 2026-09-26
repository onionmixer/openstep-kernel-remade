
void _setdiropargs(int param_1,undefined4 param_2,int param_3)

{
  _bcopy(*(int *)(param_3 + 0x2e) + 0x3e,param_1,0x20);
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}
