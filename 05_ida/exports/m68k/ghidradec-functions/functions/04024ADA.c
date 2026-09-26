
void _tcp_quench(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0x54) = *(undefined2 *)(iVar1 + 0x18);
  }
  return;
}
