
void _fd_free_fv(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(_fd_volume_p + *(int *)(param_1 + 0x10) * 4) = 0;
  iVar1 = (*(code *)&loc_406F0A2)();
  iVar2 = (*(code *)&loc_406F0A2)();
  _kfree(*(undefined4 *)(param_1 + 0x14),-iVar2 & iVar1 + 0x1c47U);
  _disksort_free(param_1 + 0xba);
  _kfree(param_1,0x19a);
  return;
}

