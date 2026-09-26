/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012c06f */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0012c06f(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  
  *(undefined2 *)((int)unaff_ESI + 10) = 2;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9180 = _DAT_001e9180 + 1;
  _mfree = (undefined4 *)*unaff_ESI;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0xc;
  _splx();
  if (unaff_ESI != (undefined4 *)0x0) {
    _splimp();
    puVar3 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_m_more(0);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001dbf4d);
      }
      *(undefined2 *)((int)_mfree + 10) = 0xe;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e9198 = _DAT_001e9198 + 1;
      puVar4 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar4;
      puVar3[1] = 0xc;
    }
    _splx();
    if (puVar3 == (undefined4 *)0x0) {
      _m_free();
    }
    else {
      unaff_ESI[1] = 0x74;
      *(undefined2 *)(unaff_ESI + 2) = 8;
      puVar5 = (undefined1 *)((int)unaff_ESI + unaff_ESI[1]);
      *puVar5 = 0x12;
      puVar5[1] = 0;
      *(undefined4 *)(puVar5 + 4) = **(undefined4 **)(unaff_EBP + 8);
      *(undefined2 *)(puVar5 + 2) = 0;
      uVar2 = _in_cksum();
      *(undefined2 *)(puVar5 + 2) = uVar2;
      unaff_ESI[1] = unaff_ESI[1] + -0x14;
      *(short *)(unaff_ESI + 2) = *(short *)(unaff_ESI + 2) + 0x14;
      iVar1 = unaff_ESI[1];
      *(undefined1 *)((int)unaff_ESI + iVar1 + 1) = 0;
      *(undefined2 *)((int)unaff_ESI + iVar1 + 2) = 0x1c;
      *(undefined2 *)((int)unaff_ESI + iVar1 + 6) = 0;
      *(undefined1 *)((int)unaff_ESI + iVar1 + 9) = 2;
      *(undefined4 *)((int)unaff_ESI + iVar1 + 0xc) = 0;
      *(undefined4 *)((int)unaff_ESI + iVar1 + 0x10) = *(undefined4 *)(puVar5 + 4);
      puVar4 = (undefined4 *)((int)puVar3 + puVar3[1]);
      *puVar4 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4);
      *(undefined1 *)(puVar4 + 1) = 1;
      *(bool *)((int)puVar4 + 5) = _ip_mrouter != 0;
      _ip_output();
      _m_free(puVar3);
      _DAT_001eee90 = _DAT_001eee90 + 1;
    }
  }
  return;
}

