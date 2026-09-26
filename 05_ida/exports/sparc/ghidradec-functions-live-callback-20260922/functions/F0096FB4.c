
void _stphys(int param_1,undefined4 param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  if (_cache == 3) {
    puVar2 = (uint *)segment(4);
    uVar3 = *puVar2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar3 | 0x8000;
    iVar1 = segment(0x20);
    *(undefined4 *)(param_1 + iVar1) = param_2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar3;
  }
  else {
    iVar1 = segment(0x20);
    *(undefined4 *)(param_1 + iVar1) = param_2;
  }
  return;
}

