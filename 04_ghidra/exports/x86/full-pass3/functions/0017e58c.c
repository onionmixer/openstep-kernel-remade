/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e58c */

void FUN_0017e58c(void)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &_pseudoDevList;
  puVar1 = _pseudoDevList;
  while (puVar1 != (undefined *)0x0) {
    iVar2 = _objc_getClass(*ppuVar3);
    if (iVar2 == 0) {
      _IOLog(s_probePseudoDevices__class__s_not_001e0fa0,*ppuVar3);
    }
    else {
      _objc_msgSend(PTR_s_IODevice_001f9d68,PTR_s_addLoadedClass_description__001f922c,iVar2,0);
    }
    ppuVar3 = ppuVar3 + 1;
    puVar1 = *ppuVar3;
  }
  return;
}

