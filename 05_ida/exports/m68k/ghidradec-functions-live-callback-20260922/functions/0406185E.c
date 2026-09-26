
void _vm_page_copy(int param_1,int param_2)

{
  _pmap_copy_page(*(undefined4 *)(param_1 + 0x22),*(undefined4 *)(param_2 + 0x22));
  return;
}

