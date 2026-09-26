/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ef78 */

void _if_down_all(void)

{
  sockaddr *psVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = _splnet();
  for (iVar2 = _ifnet; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x5c)) {
    *(byte *)(iVar2 + 0xc) = *(byte *)(iVar2 + 0xc) & 0xbe;
    for (psVar1 = *(sockaddr **)(iVar2 + 0x18); psVar1 != (sockaddr *)0x0;
        psVar1 = *(sockaddr **)(psVar1[2].sa_data + 2)) {
      _pfctlinput(0,psVar1);
    }
    _if_qflush(iVar2 + 0x1c);
  }
  _splx(uVar3);
  return;
}

