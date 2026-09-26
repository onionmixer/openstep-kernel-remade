
void _svckudp_destroy(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  iVar2 = *(int *)(iVar1 + 8);
  if (iVar2 != 0) {
    _m_freem(iVar2);
  }
  _kfree(iVar1,0x1cc);
  _kfree(*(undefined4 *)(param_1 + 0x2a),0x2260);
  _kfree(param_1,0x32);
  return;
}

