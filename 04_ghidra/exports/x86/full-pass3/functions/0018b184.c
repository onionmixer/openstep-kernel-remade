/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018b184 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _locate_idt(undefined4 param_1)

{
  __idt_base = (undefined2)param_1;
  uRam001e17bc = (undefined2)((uint)param_1 >> 0x10);
  __idt_limit = 0x7ff;
  InterruptDescriptorTableRegister(CONCAT22(__idt_base,0x7ff));
  return;
}

