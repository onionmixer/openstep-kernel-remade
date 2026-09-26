/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012b713 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0012b713(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  short unaff_DI;
  
  *(undefined2 *)((int)unaff_ESI + 10) = 2;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9180 = _DAT_001e9180 + 1;
  _mfree = *unaff_ESI;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0xc;
  _splx();
  if (unaff_ESI == (undefined4 *)0x0) {
    _m_freem();
    uVar2 = 0x37;
  }
  else {
    unaff_ESI[1] = 0x60;
    *(undefined2 *)(unaff_ESI + 2) = 0x1c;
    *unaff_ESI = unaff_EBX;
    puVar3 = (undefined4 *)((int)unaff_ESI + unaff_ESI[1]);
    puVar3[1] = 0;
    *puVar3 = 0;
    *(undefined1 *)(puVar3 + 2) = 0;
    *(undefined1 *)((int)puVar3 + 9) = 0x11;
    *(ushort *)((int)puVar3 + 10) = (ushort)(unaff_DI + 8U) >> 8 | (unaff_DI + 8U) * 0x100;
    puVar3[3] = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x14);
    puVar3[4] = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc);
    *(undefined2 *)(puVar3 + 5) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0x18);
    *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0x10);
    *(undefined2 *)(puVar3 + 6) = *(undefined2 *)((int)puVar3 + 10);
    *(undefined2 *)((int)puVar3 + 0x1a) = 0;
    if (_udpcksum != 0) {
      sVar1 = _in_cksum();
      *(short *)((int)puVar3 + 0x1a) = sVar1;
      if (sVar1 == 0) {
        *(undefined2 *)((int)puVar3 + 0x1a) = 0xffff;
      }
    }
    *(short *)((int)puVar3 + 2) = unaff_DI + 0x1c;
    *(undefined1 *)(puVar3 + 2) = _udp_ttl;
    uVar2 = _ip_output();
  }
  return uVar2;
}

