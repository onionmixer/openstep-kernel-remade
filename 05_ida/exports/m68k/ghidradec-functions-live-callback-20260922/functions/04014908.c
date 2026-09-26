
void _socket(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _falloc();
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 8) = 3;
    *(undefined2 *)(iVar2 + 0xc) = 2;
    *(undefined **)(iVar2 + 0x12) = _socketops;
    uVar3 = _socreate(*puVar1,&uStack_8,puVar1[1],puVar1[2]);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(undefined4 *)(iVar2 + 0x16) = uStack_8;
      *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar2;
    }
    else {
      *(undefined4 *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = 0;
      *(undefined2 *)(iVar2 + 0xe) = 0;
    }
  }
  return;
}

