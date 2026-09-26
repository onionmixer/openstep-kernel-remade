/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136cf8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _ku_sendto_mbuf(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  __Sendtries = __Sendtries + 1;
  iVar3 = _m_get(1,8);
  if (iVar3 == 0) {
    _m_freem(param_2);
    iVar4 = 0x37;
  }
  else {
    *(undefined2 *)(iVar3 + 8) = 0x10;
    iVar4 = *(int *)(iVar3 + 4);
    *(undefined4 *)(iVar4 + iVar3) = *param_3;
    *(undefined4 *)(iVar4 + 4 + iVar3) = param_3[1];
    *(undefined4 *)(iVar4 + 8 + iVar3) = param_3[2];
    *(undefined4 *)(iVar4 + 0xc + iVar3) = param_3[3];
    uVar5 = _splnet();
    uVar2 = *(undefined4 *)(iVar1 + 0x14);
    iVar4 = _in_pcbconnect(iVar1,iVar3);
    if (iVar4 == 0) {
      iVar4 = _udp_output(iVar1,param_2);
      _in_pcbdisconnect(iVar1);
      *(undefined4 *)(iVar1 + 0x14) = uVar2;
      _splx(uVar5);
      _m_free(iVar3);
      __Sendok = __Sendok + 1;
    }
    else {
      _printf(s_pcbsetaddr_failed__d_001dd190,iVar4);
      _splx(uVar5);
      _m_freem(param_2);
      _m_free(iVar3);
    }
  }
  return iVar4;
}

