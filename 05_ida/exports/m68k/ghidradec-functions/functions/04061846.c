
undefined4 _vm_page_zero_fill(int param_1)

{
  _pmap_zero_page(*(undefined4 *)(param_1 + 0x22));
  return 1;
}
