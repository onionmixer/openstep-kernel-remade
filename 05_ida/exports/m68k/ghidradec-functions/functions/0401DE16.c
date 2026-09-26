
void _arpwhohas(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_14;
  undefined auStack_12 [14];
  
  iVar1 = _m_get(0,1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    uStack_14 = 0x806;
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    _bcopy(&uStack_14,auStack_12 + (uint)word_40AE906._0_1_ * 2,2);
    _bcopy(DAT_40ae90a + (uint)word_40AE906._0_1_ + (uint)(byte)word_40AE906,auStack_12,
           (uint)word_40AE906._0_1_);
    iVar2 = 0x7c - *(sword *)(iVar1 + 8);
    *(int *)(iVar1 + 4) = iVar2;
    iVar2 = iVar1 + iVar2;
    _bcopy(&_arpethertempl,iVar2,(int)*(sword *)(iVar1 + 8));
    _bcopy(param_2,iVar2 + 8,word_40AE906._0_1_);
    _bcopy(&param_3,iVar2 + 8 + (uint)word_40AE906._0_1_,(byte)word_40AE906);
    _bcopy(param_4,iVar2 + (byte)word_40AE906 + 8 + (uint)word_40AE906._0_1_ * 2,
           (uint)(byte)word_40AE906);
    uStack_14 = 0;
    _if_output_mbuf(param_1,iVar1,&uStack_14);
  }
  return;
}
