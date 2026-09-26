/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e538 */

void FUN_0017e538(void)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &_indirectDevList;
  puVar1 = _indirectDevList;
  while (puVar1 != (undefined *)0x0) {
    iVar2 = _objc_getClass(*ppuVar3);
    if (iVar2 == 0) {
      _IOLog(s_registerIndirectClasses__Class___001e0f6e,*ppuVar3);
    }
    else {
      _objc_msgSend(iVar2,PTR_s_name_001f9228);
    }
    ppuVar3 = ppuVar3 + 1;
    puVar1 = *ppuVar3;
  }
  return;
}

