
void _raw_detach(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (param_1[0xe] != 0) {
    _rtfree(param_1[0xe]);
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  _sofree(iVar1);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  if (param_1[0xd] != 0) {
    _m_freem(param_1[0xd] & 0xffffff80);
  }
  if (iVar1 == _ip_mrouter) {
    _ip_mrouter_done();
  }
  if (*(sword *)(param_1 + 0xb) == 2) {
    _ip_freemoptions(*(undefined4 *)((int)param_1 + 0x4e));
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return;
}
