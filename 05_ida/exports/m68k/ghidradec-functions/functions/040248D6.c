
void _tcp_drop(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x18);
  if (*(sword *)(param_1 + 8) < 3) {
    dword_40BBD3C = dword_40BBD3C + 1;
  }
  else {
    *(undefined2 *)(param_1 + 8) = 0;
    _tcp_output(param_1);
    dword_40BBD38 = dword_40BBD38 + 1;
  }
  if ((param_2 == 0x3c) && (*(sword *)(param_1 + 0x6a) != 0)) {
    param_2 = (int)*(sword *)(param_1 + 0x6a);
  }
  *(sword *)(iVar1 + 0x50) = (sword)param_2;
  _tcp_close(param_1);
  return;
}
