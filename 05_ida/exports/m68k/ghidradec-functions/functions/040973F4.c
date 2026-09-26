
int _pmap_size(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = _max_virtual_size;
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = param_1;
  }
  iVar1 = ((int)puVar2 + _m68k_pt2_maps + -1) / _m68k_pt2_maps;
  return _m68k_pt1_size + _m68k_pt2_size * iVar1 + _m68k_pte_size * _m68k_pt2_entries * iVar1;
}
