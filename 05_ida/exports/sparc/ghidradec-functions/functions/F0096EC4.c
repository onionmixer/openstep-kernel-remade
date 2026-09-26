
void _getidprom(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x20;
  do {
    iVar1 = iVar2 + -1;
    *(undefined *)(param_1 + iVar1) = *(undefined *)(iVar2 + -0x1000029);
    iVar2 = iVar1;
  } while (iVar1 != 0);
  return;
}
