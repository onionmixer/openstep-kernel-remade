
undefined4 _arptfree(undefined4 *param_1)

{
  undefined2 extraout_D0u;
  undefined2 uVar1;
  char cVar2;
  
  cVar2 = '\0';
  uVar1 = 0;
  if (param_1[3] != 0) {
    _m_freem(param_1[3]);
    uVar1 = extraout_D0u;
  }
  param_1[3] = 0;
  *(undefined *)((int)param_1 + 0xb) = 0;
  *(undefined *)((int)param_1 + 10) = 0;
  *param_1 = 0;
  return CONCAT22(uVar1,(word)(byte)(cVar2 << 4 | 4));
}

