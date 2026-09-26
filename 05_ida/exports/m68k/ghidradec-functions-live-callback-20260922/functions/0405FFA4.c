
void _vm_object_shadow(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = _vm_object_allocate(param_3);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmObjectShadow);
  }
  *(int *)(iVar2 + 0x1c) = iVar1;
  *(undefined4 *)(iVar2 + 0x20) = *param_2;
  *param_2 = 0;
  *param_1 = iVar2;
  return;
}

