
void _dnlc_init(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  dword_40B6D68 = &_nc_lru;
  dword_40B6D6C = &_nc_lru;
  iVar3 = 0;
  if (0 < _ncsize) {
    iVar6 = 0;
    do {
      puVar1 = dword_40B6D68;
      puVar4 = (undefined8 *)(iVar6 + _ncache);
      puVar2 = puVar4;
      *(undefined8 **)(puVar4 + 1) = dword_40B6D68;
      dword_40B6D68 = puVar2;
      *(undefined8 **)((int)puVar1 + 0xc) = puVar4;
      *(undefined8 **)((int)puVar4 + 0xc) = &_nc_lru;
      *(undefined8 **)((int)puVar4 + 4) = puVar4;
      *(undefined8 **)puVar4 = puVar4;
      *(undefined4 *)(puVar4 + 2) = 0;
      *(undefined4 *)((int)puVar4 + 0x14) = 0;
      *(undefined *)((int)puVar4 + 0x42) = 0;
      iVar6 = iVar6 + 0x46;
      iVar3 = iVar3 + 1;
    } while (iVar3 < _ncsize);
  }
  iVar3 = 0;
  puVar5 = &_nc_hash;
  do {
    puVar5[1] = puVar5;
    *puVar5 = puVar5;
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x40);
  return;
}

