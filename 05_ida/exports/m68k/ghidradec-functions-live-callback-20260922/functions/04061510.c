
void _vm_page_free(int param_1)

{
  _vm_page_remove(param_1);
  if ((*(byte *)(param_1 + 0x1e) & 0x10) == 0) {
    _vm_page_addfree(param_1);
  }
  return;
}

