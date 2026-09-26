/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161134 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pset_sys_bootstrap(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  _pset_init(&_default_pset);
  _DAT_001e9738 = 0;
  iVar2 = 0;
  puVar1 = &_processor_array;
  iVar3 = 0;
  do {
    *(undefined **)((int)&_processor_ptr + iVar3) = puVar1;
    _processor_init(puVar1,iVar2);
    puVar1 = puVar1 + 0x148;
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  _master_processor = (&_processor_ptr)[_master_cpu];
  _all_psets_lock = 0;
  _all_psets = &_default_pset;
  _DAT_001e9760 = &_all_psets;
  DAT_001e975c = &_all_psets;
  _DAT_001e9604 = &_default_pset;
  __all_psets_count = 1;
  _DAT_001e9764 = 1;
  _DAT_001e9738 = 0;
  return;
}

