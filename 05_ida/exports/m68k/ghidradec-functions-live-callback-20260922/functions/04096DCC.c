
void _pcb_terminate(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(iVar1 + 0x4c);
  if (iVar2 != 0) {
    uVar3 = 0x138;
    if (_cpu_type != '\0') {
      uVar3 = 0x244;
    }
    _kfree(iVar2,uVar3);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  _zfree(_pcb_zone,iVar1);
  return;
}

