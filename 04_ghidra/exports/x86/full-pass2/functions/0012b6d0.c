/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b6d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _udp_output(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = 0;
  for (puVar4 = param_2; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    iVar6 = iVar6 + *(short *)(puVar4 + 2);
  }
  uVar3 = _splimp();
  puVar4 = _mfree;
  if (_mfree == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)_m_more(0,2);
  }
  else {
    if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&DAT_001dbf04);
    }
    *(undefined2 *)((int)_mfree + 10) = 2;
    _DAT_001e917c = _DAT_001e917c + -1;
    _DAT_001e9180 = _DAT_001e9180 + 1;
    puVar5 = (undefined4 *)*_mfree;
    *_mfree = 0;
    _mfree = puVar5;
    puVar4[1] = 0xc;
  }
  _splx(uVar3);
  if (puVar4 == (undefined4 *)0x0) {
    _m_freem(param_2);
    uVar3 = 0x37;
  }
  else {
    puVar4[1] = 0x60;
    *(undefined2 *)(puVar4 + 2) = 0x1c;
    *puVar4 = param_2;
    puVar5 = (undefined4 *)((int)puVar4 + puVar4[1]);
    puVar5[1] = 0;
    *puVar5 = 0;
    *(undefined1 *)(puVar5 + 2) = 0;
    *(undefined1 *)((int)puVar5 + 9) = 0x11;
    uVar1 = (short)iVar6 + 8;
    *(ushort *)((int)puVar5 + 10) = uVar1 >> 8 | uVar1 * 0x100;
    puVar5[3] = *(undefined4 *)(param_1 + 0x14);
    puVar5[4] = *(undefined4 *)(param_1 + 0xc);
    *(undefined2 *)(puVar5 + 5) = *(undefined2 *)(param_1 + 0x18);
    *(undefined2 *)((int)puVar5 + 0x16) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(puVar5 + 6) = *(undefined2 *)((int)puVar5 + 10);
    *(undefined2 *)((int)puVar5 + 0x1a) = 0;
    if (_udpcksum != 0) {
      sVar2 = _in_cksum(puVar4,iVar6 + 0x1c);
      *(short *)((int)puVar5 + 0x1a) = sVar2;
      if (sVar2 == 0) {
        *(undefined2 *)((int)puVar5 + 0x1a) = 0xffff;
      }
    }
    *(short *)((int)puVar5 + 2) = (short)iVar6 + 0x1c;
    *(undefined1 *)(puVar5 + 2) = _udp_ttl;
    uVar3 = _ip_output(puVar4,*(undefined4 *)(param_1 + 0x38),param_1 + 0x24,
                       (byte)*(undefined2 *)(*(int *)(param_1 + 0x1c) + 2) & 0x32 | 2,
                       *(undefined4 *)(param_1 + 0x3c));
  }
  return uVar3;
}

