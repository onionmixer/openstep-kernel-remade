/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a889c */

undefined4 FUN_001a889c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numInterrupts_001f9bcc);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = _objc_msgSend(param_1,PTR_s_enableInterrupt__001f9bc8,uVar3);
      if (iVar2 != 0) {
        _objc_msgSend(param_1,PTR_s_disableAllInterrupts_001f9bc4);
        return 0xfffffd27;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0;
}

