
void sub_4087F1E(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  for (; param_2 != 0; param_2 = param_2 - _page_size) {
    uVar1 = _pmap_resident_extract(*(undefined4 *)(dword_40C6EBC + 0x20),param_1);
    iVar2 = _vm_phys_to_vm_page(uVar1);
    if (iVar2 != 0) {
      if (param_3 != 2) {
        *(byte *)(iVar2 + 0x1e) = *(byte *)(iVar2 + 0x1e) & 0xfb | (param_3 == 0) << 2;
      }
      _vm_fault(dword_40C6EBC,param_1,0,1,0);
      if (param_4 != 0) {
        uVar1 = _pmap_extract(*(undefined4 *)(dword_40C6EBC + 0x20),param_1);
        iVar2 = _vm_phys_to_vm_page(uVar1);
        if (iVar2 != 0) {
          _vm_page_deactivate(iVar2);
        }
      }
    }
    param_1 = _page_size + param_1;
  }
  return;
}
