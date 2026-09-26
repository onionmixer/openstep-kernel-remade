/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9c18 */

undefined4 FUN_001c9c18(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)__alloc)(param_1,0);
  if (1 < *(int *)(*param_1 + 0xc)) {
    uVar1 = _objc_msgSend(uVar1,PTR_s_init_001f924c);
  }
  return uVar1;
}

