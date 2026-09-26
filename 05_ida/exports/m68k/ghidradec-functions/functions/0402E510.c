
void _clntkudp_destroy(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  _soclose(*(undefined4 *)(iVar1 + 0x14));
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  _kfree(iVar1,0x78);
  return;
}
