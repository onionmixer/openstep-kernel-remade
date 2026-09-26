/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ba53 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0012ba53(void)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  *(undefined2 *)((int)unaff_ESI + 10) = 2;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9180 = _DAT_001e9180 + 1;
  _mfree = *unaff_ESI;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0xc;
  _splx();
  if (unaff_ESI == (undefined4 *)0x0) {
    _m_freem();
    uVar3 = 0x37;
  }
  else {
    unaff_ESI[1] = 0x60;
    *(undefined2 *)(unaff_ESI + 2) = 0x1c;
    *unaff_ESI = *(undefined4 *)(unaff_EBP + 0x10);
    puVar4 = (undefined4 *)((int)unaff_ESI + unaff_ESI[1]);
    puVar4[1] = 0;
    *puVar4 = 0;
    *(undefined1 *)(puVar4 + 2) = 0;
    *(undefined1 *)((int)puVar4 + 9) = 0x11;
    uVar1 = *(short *)(unaff_EBP + -0xc) + 8;
    *(ushort *)((int)puVar4 + 10) = uVar1 >> 8 | uVar1 * 0x100;
    puVar4[3] = *(undefined4 *)(unaff_EDI + 0x14);
    puVar4[4] = *(undefined4 *)(unaff_EDI + 0xc);
    *(undefined2 *)(puVar4 + 5) = *(undefined2 *)(unaff_EDI + 0x18);
    *(undefined2 *)((int)puVar4 + 0x16) = *(undefined2 *)(unaff_EDI + 0x10);
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)((int)puVar4 + 10);
    *(undefined2 *)((int)puVar4 + 0x1a) = 0;
    if (_udpcksum != 0) {
      sVar2 = _in_cksum();
      *(short *)((int)puVar4 + 0x1a) = sVar2;
      if (sVar2 == 0) {
        *(undefined2 *)((int)puVar4 + 0x1a) = 0xffff;
      }
    }
    *(short *)((int)puVar4 + 2) = *(short *)(unaff_EBP + -0xc) + 0x1c;
    *(undefined1 *)(puVar4 + 2) = _udp_ttl;
    uVar3 = _ip_output();
  }
  *(undefined4 *)(unaff_EBP + 0x10) = 0;
  if (*(int *)(unaff_EBP + 0x14) != 0) {
    _in_pcbdisconnect();
    *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EBP + -8);
  }
  _splx();
  if (*(int *)(unaff_EBP + 0x10) != 0) {
    _m_freem();
  }
  return uVar3;
}

