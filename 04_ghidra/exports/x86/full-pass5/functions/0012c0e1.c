/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c0e1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0012c0e1(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(undefined2 *)((int)unaff_EDI + 10) = 0xe;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9198 = _DAT_001e9198 + 1;
  _mfree = *unaff_EDI;
  *unaff_EDI = 0;
  unaff_EDI[1] = 0xc;
  _splx();
  if (unaff_EDI == (undefined4 *)0x0) {
    _m_free();
  }
  else {
    *(undefined4 *)(unaff_ESI + 4) = 0x74;
    *(undefined2 *)(unaff_ESI + 8) = 8;
    puVar4 = (undefined1 *)(unaff_ESI + *(int *)(unaff_ESI + 4));
    *puVar4 = 0x12;
    puVar4[1] = 0;
    *(undefined4 *)(puVar4 + 4) = **(undefined4 **)(unaff_EBP + 8);
    *(undefined2 *)(puVar4 + 2) = 0;
    uVar1 = _in_cksum();
    *(undefined2 *)(puVar4 + 2) = uVar1;
    *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + -0x14;
    *(short *)(unaff_ESI + 8) = *(short *)(unaff_ESI + 8) + 0x14;
    iVar2 = unaff_ESI + *(int *)(unaff_ESI + 4);
    *(undefined1 *)(iVar2 + 1) = 0;
    *(undefined2 *)(iVar2 + 2) = 0x1c;
    *(undefined2 *)(iVar2 + 6) = 0;
    *(undefined1 *)(iVar2 + 9) = 2;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(puVar4 + 4);
    puVar3 = (undefined4 *)((int)unaff_EDI + unaff_EDI[1]);
    *puVar3 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4);
    *(undefined1 *)(puVar3 + 1) = 1;
    *(bool *)((int)puVar3 + 5) = _ip_mrouter != 0;
    _ip_output();
    _m_free();
    _DAT_001eee90 = _DAT_001eee90 + 1;
  }
  return;
}

