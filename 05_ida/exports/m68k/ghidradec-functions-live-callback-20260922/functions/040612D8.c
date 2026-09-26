
void _vm_page_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _vm_page_remove(param_1);
  _vm_page_insert(param_1,param_2,param_3);
  return;
}

