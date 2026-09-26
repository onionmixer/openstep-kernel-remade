
undefined4 _ldphys(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (_cache == 3) {
    puVar2 = (uint *)segment(4);
    uVar4 = *puVar2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4 | 0x8000;
    iVar1 = segment(0x20);
    uVar3 = *(undefined4 *)(param_1 + iVar1);
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4;
  }
  else {
    iVar1 = segment(0x20);
    uVar3 = *(undefined4 *)(param_1 + iVar1);
  }
  return uVar3;
}
