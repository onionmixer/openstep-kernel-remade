
void _unp_drop(int *param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined2 *)(iVar1 + 0x50) = param_2;
  _unp_disconnect(param_1);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *(undefined4 *)(iVar1 + 8) = 0;
    _m_freem(param_1[6]);
    _kfree(param_1,0x24);
    _sofree(iVar1);
  }
  return;
}

