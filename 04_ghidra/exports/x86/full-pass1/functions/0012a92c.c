/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012a92c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _tcp_slowtimo(void)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar4 = _splnet();
  __tcp_maxidle = __tcp_keepintvl << 3;
  puVar2 = _tcb;
  if (_tcb != (undefined4 *)0x0) {
LAB_0012a9b9:
    puVar6 = puVar2;
    if ((undefined4 **)puVar6 != &_tcb) {
      puVar2 = (undefined4 *)*puVar6;
      iVar3 = puVar6[8];
      if (iVar3 != 0) {
        iVar5 = 0;
        do {
          sVar1 = *(short *)(iVar3 + 10 + iVar5 * 2);
          if (((sVar1 != 0) && (*(short *)(iVar3 + 10 + iVar5 * 2) = sVar1 + -1, sVar1 == 1)) &&
             (_tcp_usrreq(*(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x1c),0x13,0,iVar5,0),
             (undefined4 *)puVar2[1] != puVar6)) goto LAB_0012a9b9;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 4);
        *(short *)(iVar3 + 0x58) = *(short *)(iVar3 + 0x58) + 1;
        if (*(short *)(iVar3 + 0x5a) != 0) {
          *(short *)(iVar3 + 0x5a) = *(short *)(iVar3 + 0x5a) + 1;
        }
      }
      goto LAB_0012a9b9;
    }
    _tcp_iss = _tcp_iss + 64000;
  }
  _splx(uVar4);
  return;
}

