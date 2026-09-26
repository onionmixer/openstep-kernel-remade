/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8904 */

void FUN_001a8904(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_numInterrupts_001f9bcc);
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      _objc_msgSend(param_1,PTR_s_disableInterrupt__001f9bc0,uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

