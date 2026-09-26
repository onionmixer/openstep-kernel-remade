
undefined4 _ptcopen(word param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 & 0xff) < 0x20) {
    iVar3 = _pty_alloc((int)(sword)param_1);
    iVar3 = *(int *)(iVar3 + 6);
    if (*(int *)(iVar3 + 0x24) == 0) {
      *(code **)(iVar3 + 0x24) = _ptsstart;
      (**(code **)(DAT_40ae4d0 + *(char *)(iVar3 + 0x45) * 0x30))(iVar3,1);
      *(uint *)(iVar3 + 0x3e) = *(uint *)(iVar3 + 0x3e) & 0xffbfffff | 0x10;
      puVar1 = *(undefined4 **)((int)&dword_40B318E + (sword)(param_1 & 0xff) * 0xe);
      *puVar1 = 0;
      *(undefined *)(puVar1 + 3) = 0;
      *(undefined *)((int)puVar1 + 0xd) = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 6;
  }
  return uVar2;
}
