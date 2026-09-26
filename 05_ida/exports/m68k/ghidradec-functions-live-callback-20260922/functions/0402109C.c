
void _ip_freef(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[3];
  while (param_1 != piVar2) {
    piVar1 = (int *)piVar2[3];
    _ip_deq(piVar2);
    _m_freem((uint)piVar2 & 0xffffff80);
    piVar2 = piVar1;
  }
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _m_free((uint)param_1 & 0xffffff80);
  return;
}

