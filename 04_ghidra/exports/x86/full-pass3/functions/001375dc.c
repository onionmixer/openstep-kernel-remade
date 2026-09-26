/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001375dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _svckudp_recv(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  boolean_t bVar4;
  
  iVar1 = param_1[0xc];
  __rsstat = __rsstat + 1;
  uVar2 = _splnet();
  iVar3 = _ku_recvfrom(*param_1,param_1 + 4);
  _splx(uVar2);
  if (iVar3 == 0) {
    _DAT_001ef288 = _DAT_001ef288 + 1;
  }
  else {
    if (*(ushort *)(iVar3 + 8) < 0x10) {
      _DAT_001ef28c = _DAT_001ef28c + 1;
    }
    else {
      _xdrmbuf_init(iVar1 + 0xc,iVar3,1);
      bVar4 = _xdr_callmsg();
      if (bVar4 != 0) {
        *(undefined4 *)(iVar1 + 4) = *param_2;
        *(int *)(iVar1 + 8) = iVar3;
        return 1;
      }
      _DAT_001ef290 = _DAT_001ef290 + 1;
    }
    _m_freem(iVar3);
    *(undefined4 *)(iVar1 + 8) = 0;
    _DAT_001ef284 = _DAT_001ef284 + 1;
  }
  return 0;
}

