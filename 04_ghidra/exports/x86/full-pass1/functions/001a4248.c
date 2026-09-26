/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4248 */

void FUN_001a4248(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  iVar3 = FUN_001a3e08(param_1);
  if (iVar3 != 0) {
    _IOLog("Unregistering Device: %s\n",param_1 + 8);
    puVar1 = *(undefined4 **)(iVar3 + 8);
    puVar2 = *(undefined4 **)(iVar3 + 0xc);
    puVar4 = &DAT_001e866c;
    if (puVar1 != &DAT_001e866c) {
      puVar4 = puVar1 + 2;
    }
    puVar4[1] = puVar2;
    puVar4 = &DAT_001e866c;
    if (puVar2 != &DAT_001e866c) {
      puVar4 = puVar2 + 2;
    }
    *puVar4 = puVar1;
    _IOFree(iVar3,0x10);
  }
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  return;
}

