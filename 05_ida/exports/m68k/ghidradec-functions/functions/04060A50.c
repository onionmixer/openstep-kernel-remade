
void _vm_policy_apply(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (((2 < *(sword *)(param_1 + 0x14)) &&
      (piVar1 = *(int **)(param_1 + 0x24), piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
    uVar2 = (uint)piVar1[3] >> 0x1f ^ 1;
  }
  if (((param_3 & 2) != 0) || (uVar2 == 0)) {
    if (param_3 == 0) {
      if (((*(byte *)(param_2 + 0x1e) & 4) == 0) ||
         (iVar3 = _pmap_is_modified(*(undefined4 *)(param_2 + 0x22)), iVar3 != 0)) {
        if ((*(byte *)(param_2 + 0x1e) & 0x40) != 0) {
          _vm_page_deactivate(param_2);
        }
      }
      else {
        sub_4060982(param_2);
      }
      _pmap_remove_all(*(undefined4 *)(param_2 + 0x22));
    }
    else if ((param_3 == 1) && ((*(byte *)(param_2 + 0x1e) & 0x40) != 0)) {
      _vm_page_deactivate(param_2);
    }
  }
  return;
}
