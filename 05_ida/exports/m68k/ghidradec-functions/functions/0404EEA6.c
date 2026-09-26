
void _pset_sys_bootstrap(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  _pset_init(_default_pset);
  dword_40B6768 = 0;
  iVar2 = 0;
  puVar1 = _processor_array;
  puVar3 = &_processor_ptr;
  do {
    *puVar3 = puVar1;
    _processor_init(puVar1,iVar2);
    puVar1 = puVar1 + 0x140;
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 1);
  _master_processor = (&_processor_ptr)[_master_cpu];
  _all_psets = _default_pset;
  dword_40B678C = &_all_psets;
  dword_40B6788 = &_all_psets;
  unk_40B6644 = _default_pset;
  _all_psets_count = 1;
  dword_40B6790 = 1;
  dword_40B6768 = 0;
  return;
}
