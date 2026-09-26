/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121654 */

void _rawintr(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int local_10;
  
  while( true ) {
    uVar3 = _splimp();
    puVar2 = _rawintrq;
    if (_rawintrq != (undefined4 *)0x0) {
      if ((undefined4 *)_rawintrq[0x1f] == (undefined4 *)0x0) {
        DAT_001e8a74 = 0;
      }
      puVar1 = _rawintrq + 0x1f;
      _rawintrq = (undefined4 *)_rawintrq[0x1f];
      *puVar1 = 0;
      DAT_001e8a78 = DAT_001e8a78 + -1;
    }
    _splx(uVar3);
    if (puVar2 == (undefined4 *)0x0) break;
    psVar6 = (short *)((int)puVar2 + puVar2[1]);
    local_10 = 0;
    for (puVar1 = _rawcb; (undefined4 **)puVar1 != &_rawcb; puVar1 = (undefined4 *)*puVar1) {
      if ((((*(short *)(puVar1 + 0xb) == *psVar6) &&
           ((*(short *)((int)puVar1 + 0x2e) == 0 || (psVar6[1] == *(short *)((int)puVar1 + 0x2e)))))
          && (((*(byte *)(puVar1 + 0x13) & 1) == 0 ||
              (iVar4 = _bcmp(puVar1 + 7,psVar6 + 2,0x10), iVar4 == 0)))) &&
         (((*(byte *)(puVar1 + 0x13) & 2) == 0 ||
          (iVar4 = _bcmp(puVar1 + 3,psVar6 + 10,0x10), iVar4 == 0)))) {
        if ((local_10 != 0) && (iVar4 = _m_copy(*puVar2,0,1000000000), iVar4 != 0)) {
          iVar5 = _sbappendaddr(local_10 + 0x24,psVar6 + 10,iVar4,0);
          if (iVar5 == 0) {
            _m_freem(iVar4);
          }
          else {
            _sowakeup(local_10,local_10 + 0x24);
          }
        }
        local_10 = puVar1[2];
      }
    }
    if (local_10 == 0) {
      _m_freem(puVar2);
    }
    else {
      iVar4 = _sbappendaddr(local_10 + 0x24,psVar6 + 10,*puVar2,0);
      if (iVar4 == 0) {
        _m_freem(*puVar2);
      }
      else {
        _sowakeup(local_10,local_10 + 0x24);
      }
      _m_free(puVar2);
    }
  }
  return;
}

