
void _in_pcbdetach(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[6];
  *(undefined4 *)(iVar1 + 8) = 0;
  _sofree(iVar1);
  if (param_1[0xd] != 0) {
    _m_free(param_1[0xd]);
  }
  if (param_1[8] != 0) {
    _rtfree(param_1[8]);
  }
  _ip_freemoptions(param_1[0xe]);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _kfree(param_1,0x3c);
  return;
}

