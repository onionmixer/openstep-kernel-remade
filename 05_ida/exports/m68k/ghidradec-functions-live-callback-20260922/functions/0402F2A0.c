
int _ku_sendto_mbuf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  _Sendtries = _Sendtries + 1;
  iVar3 = _m_get(1,8);
  if (iVar3 == 0) {
    _m_freem(param_2);
    iVar4 = 0x37;
  }
  else {
    *(undefined2 *)(iVar3 + 8) = 0x10;
    puVar5 = (undefined4 *)(*(int *)(iVar3 + 4) + iVar3);
    *puVar5 = *param_3;
    puVar5[1] = param_3[1];
    puVar5[2] = param_3[2];
    puVar5[3] = param_3[3];
    uVar2 = *(undefined4 *)(iVar1 + 0x12);
    iVar4 = _in_pcbconnect(iVar1,iVar3);
    if (iVar4 == 0) {
      iVar4 = _udp_output(iVar1,param_2);
      _in_pcbdisconnect(iVar1);
      *(undefined4 *)(iVar1 + 0x12) = uVar2;
      _m_free(iVar3);
      _Sendok = _Sendok + 1;
    }
    else {
      _printf(aPcbsetaddrFail,iVar4);
      _m_freem(param_2);
      _m_free(iVar3);
    }
  }
  return iVar4;
}

