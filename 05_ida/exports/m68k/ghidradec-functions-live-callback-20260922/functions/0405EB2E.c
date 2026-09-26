
undefined4 _vm_map_check_protection(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  iVar1 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar1 == 0) {
loc_405EB58:
    uVar2 = 0;
  }
  else {
    if (param_2 < param_3) {
      do {
        if (((param_1 + 8 == iStack_8) || (param_2 < *(uint *)(iStack_8 + 8))) ||
           (param_4 != (param_4 & *(uint *)(iStack_8 + 0x1a)))) goto loc_405EB58;
        param_2 = *(uint *)(iStack_8 + 0xc);
        iStack_8 = *(int *)(iStack_8 + 4);
      } while (param_2 < param_3);
    }
    uVar2 = 1;
  }
  return uVar2;
}

