/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018991c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _dbf_init(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = _pmap_kernel();
  puVar1 = _gdt;
  _DAT_001f79ac = *(undefined4 *)(iVar2 + 4);
  _DAT_001f7994 = &_dbf_state;
  _DAT_001f7998 = 0x10;
  _DAT_001f79cc = &_dbf_state;
  _DAT_001f79c8 = &_dbf_state;
  _DAT_001f79e0 = 0x10;
  _DAT_001f79b0 = _dbf_handler_;
  _DAT_001f79dc = 8;
  _DAT_001f79e4 = 0x10;
  _DAT_001f79d8 = 0x10;
  _DAT_001f79f6 = 0x68;
  *(undefined2 *)(_gdt + 0x72) = 0x7990;
  puVar1[0x74] = 0x1f;
  puVar1[0x77] = 0xc0;
  puVar1[0x75] = 0x89;
  puVar1[0x76] = puVar1[0x76] & 0x7f;
  *(undefined2 *)(puVar1 + 0x70) = 0x67;
  puVar1[0x76] = puVar1[0x76] & 0xf0;
  puVar1 = _idt;
  *(undefined2 *)(_idt + 0x42) = 0x70;
  puVar1[0x45] = 0x85;
  return;
}

