
void _pmap_tt(int param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined uVar4;
  int iVar3;
  byte bVar5;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (_cache == 0) {
    param_5 = 0;
  }
  puVar2 = (undefined *)(iVar1 + 0x58);
  _bzero(puVar2,4);
  uVar4 = (undefined)((uint)param_3 >> 0x18);
  if (_cpu_type == '\0') {
    *puVar2 = uVar4;
    *(char *)(iVar1 + 0x59) = (char)((uint)(param_4 + -1) >> 0x18);
    *(byte *)(iVar1 + 0x5a) =
         *(byte *)(iVar1 + 0x5a) & 0x7b | (byte)((param_2 & 1) << 7) | (param_5 == 0) << 2 | 1;
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x44) == 0) {
      bVar5 = *(byte *)(iVar1 + 0x5b) & 0x8f | 7;
    }
    else {
      bVar5 = *(byte *)(iVar1 + 0x5b) & 0xcb | 0x43;
    }
    *(byte *)(iVar1 + 0x5b) = bVar5;
  }
  else {
    *puVar2 = uVar4;
    *(char *)(iVar1 + 0x59) = (char)((uint)(param_4 + -1) >> 0x18);
    *(uint *)(iVar1 + 0x5a) = *(uint *)(iVar1 + 0x5a) & 0x7fffffff | param_2 << 0x1f;
    iVar3 = 2;
    if (param_5 != 0) {
      iVar3 = 1;
    }
    *(uint *)(iVar1 + 0x5b) = *(uint *)(iVar1 + 0x5b) & 0x9fffffff | iVar3 << 0x1d;
    if (*(int *)(*(int *)(param_1 + 0xc) + 0x44) == 0) {
      *(byte *)(iVar1 + 0x5a) = *(byte *)(iVar1 + 0x5a) & 0xdf | 0x40;
    }
    else {
      *(byte *)(iVar1 + 0x5a) = *(byte *)(iVar1 + 0x5a) & 0xbf | 0x20;
    }
  }
  _pmove_tt1(iVar1 + 0x58);
  if (param_2 == 0) {
    *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) & 0x7f;
  }
  else {
    *(byte *)(iVar1 + 0x54) = *(byte *)(iVar1 + 0x54) | 0x80;
  }
  return;
}

