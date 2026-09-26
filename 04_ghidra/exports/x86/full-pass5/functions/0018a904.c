/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a904 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _locate_gdt(undefined4 param_1)

{
  __gdt_base = (undefined2)param_1;
  uRam001e17b4 = (undefined2)((uint)param_1 >> 0x10);
  __gdt_limit = 0xff;
  GlobalDescriptorTableRegister(CONCAT22(__gdt_base,0xff));
  return;
}

