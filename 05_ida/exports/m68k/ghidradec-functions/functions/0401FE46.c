
void _in_losing(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    if ((*(byte *)(iVar1 + 0x25) & 0x10) != 0) {
      _rtrequest(0x8030720b,iVar1);
    }
    _rtfree(iVar1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}
