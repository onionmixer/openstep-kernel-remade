/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b13c */

int _tcp_attach(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (((*(short *)(param_1 + 0x3e) == 0) || (*(short *)(param_1 + 0x26) == 0)) &&
     (iVar3 = _soreserve(param_1,_tcp_sendspace,_tcp_recvspace), iVar3 != 0)) {
    return iVar3;
  }
  iVar3 = _in_pcballoc(param_1,&_tcb);
  if (iVar3 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 8);
    iVar3 = _tcp_newtcpcb(uVar2);
    if (iVar3 == 0) {
      uVar1 = *(ushort *)(param_1 + 6);
      *(ushort *)(param_1 + 6) = uVar1 & 0xfffe;
      _in_pcbdetach(uVar2);
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | uVar1 & 1;
      iVar3 = 0x37;
    }
    else {
      *(undefined2 *)(iVar3 + 8) = 0;
      iVar3 = 0;
    }
  }
  return iVar3;
}

