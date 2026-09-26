
undefined4 _swphys(undefined4 param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_i0;
  int unaff_i1;
  
  if (_cache == 3) {
    puVar2 = (uint *)segment(4);
    uVar4 = *puVar2;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4 | 0x8000;
    iVar1 = segment(0x20);
    uVar3 = *(undefined4 *)(param_2 + iVar1);
    *(undefined4 *)(param_2 + iVar1) = param_1;
    puVar2 = (uint *)segment(4);
    *puVar2 = uVar4;
  }
  else {
    iVar1 = segment(0x20);
    *(undefined4 *)(unaff_i1 + iVar1) = unaff_i0;
    uVar3 = param_1;
  }
  return uVar3;
}

