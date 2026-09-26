/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018d5c4 */

void _pcb_common_init(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x1c);
  _lock_init(puVar1 + 4,1);
  *puVar1 = _ldt + -0x40000000;
  puVar1[1] = 0x18;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined4 **)(param_1 + 0x40) = puVar1;
  return;
}

