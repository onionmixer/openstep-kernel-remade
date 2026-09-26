
void _vm_map_init(void)

{
  _vm_map_zone = _zinit(0x44,0x19000,0,0,&aMaps);
  _vm_map_entry_zone = _zinit(0x2a,0x100000,0,0,aNonKernelMapEn);
  _vm_map_kentry_zone = _zinit(0x2a,_kentry_data_size,0,0,aKernelMapEntri);
  _zchange(_vm_map_kentry_zone,0,0,0,0);
  _zcram(_vm_map_zone,_map_data,_map_data_size);
  _zcram(_vm_map_kentry_zone,_kentry_data,_kentry_data_size);
  return;
}
