/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018a38c */

void _fp_extension_fault(void)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = DAT_001e75f8;
  FUN_0018a428();
  if (_active_threads == iVar2) {
    _exception(3,0x10,0);
  }
  else {
    puVar1 = (uint *)(iVar2 + 0x17c);
    *puVar1 = *puVar1 | 0x40000000;
  }
  return;
}

