
int _vm_page_lookup(int param_1,uint param_2)

{
  int iVar1;
  
  for (iVar1 = *(int *)(_vm_page_buckets +
                       (_vm_page_hash_mask & param_1 + (param_2 >> (_page_shift & 0x3f))) * 4);
      (iVar1 != 0 && ((param_1 != *(int *)(iVar1 + 0x14) || (param_2 != *(uint *)(iVar1 + 0x18)))));
      iVar1 = *(int *)(iVar1 + 0x10)) {
  }
  return iVar1;
}

