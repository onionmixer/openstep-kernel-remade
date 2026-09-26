
undefined4 _if_output_mbuf(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  for (puVar1 = param_2; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    iVar5 = *(sword *)(puVar1 + 2) + iVar5;
  }
  if (*(sword *)(param_1 + 10) < iVar5) {
    _m_freem(param_2);
    uVar2 = 0x28;
  }
  else {
    iVar3 = (**(code **)(param_1 + 0x3e))(param_1);
    if (iVar3 == 0) {
      _m_freem(param_2);
      uVar2 = 0x37;
    }
    else {
      uVar2 = _nb_map(iVar3);
      _mbuf_read(param_2,uVar2,0,iVar5);
      iVar4 = _nb_size(iVar3);
      _nb_shrink_bot(iVar3,iVar4 - iVar5);
      _m_freem(param_2);
      uVar2 = (**(code **)(param_1 + 0x32))(param_1,iVar3,param_3);
    }
  }
  return uVar2;
}

