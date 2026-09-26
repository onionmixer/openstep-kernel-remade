/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131898 */

void FUN_00131898(void *param_1)

{
  uint uVar1;
  undefined4 local_24 [8];
  
  _bcopy(param_1,local_24,0x20);
  uVar1 = 0;
  do {
    _printf((char *)&PTR_DAT_001dcb15,local_24[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 8);
  return;
}

