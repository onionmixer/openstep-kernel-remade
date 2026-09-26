
void _open(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  *(byte *)(iVar2 + 0x16) =
       *(byte *)(iVar2 + 0x16) & 0xbf |
       (byte)(((*(uint *)((int)puVar1 + 7) & 0x1fffffff) >> 0x1c) << 6);
  uVar3 = _copen(*puVar1,puVar1[1] + 1,puVar1[2]);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  *(byte *)(iVar2 + 0x16) = *(byte *)(iVar2 + 0x16) & 0xbf;
  return;
}
