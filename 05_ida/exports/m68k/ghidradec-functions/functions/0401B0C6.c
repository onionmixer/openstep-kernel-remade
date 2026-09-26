
void _vn_rele(int param_1)

{
  sword sVar1;
  
  if (*(sword *)(param_1 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aVnRele);
  }
  sVar1 = *(sword *)(param_1 + 6);
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x4c))(param_1,*(undefined4 *)(_active_u + 0x1a));
  }
  return;
}
