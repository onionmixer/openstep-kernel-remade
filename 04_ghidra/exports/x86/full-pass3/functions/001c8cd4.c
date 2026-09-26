/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8cd4 */

void FUN_001c8cd4(int param_1)

{
  code *pcVar1;
  code *pcVar2;
  
  pcVar1 = FUN_001c8a78;
  if (**(char **)(param_1 + 0xc) == '@') {
    pcVar1 = FUN_001c8a60;
  }
  pcVar2 = FUN_001c8a78;
  if (**(char **)(param_1 + 8) == '@') {
    pcVar2 = FUN_001c8a60;
  }
  _objc_msgSend(param_1,PTR_s_freeKeys_values__001f9318,pcVar2,pcVar1);
  return;
}

