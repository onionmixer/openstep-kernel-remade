
void _task_name(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = _strlen(param_1);
  iVar2 = 0x11;
  if (uVar1 < 0x11) {
    iVar2 = uVar1 + 1;
  }
  _bcopy(param_1,_active_u + 8,iVar2);
  return;
}

