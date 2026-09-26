
undefined4 * _vswap_allocate(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar2 = (undefined4 *)0x0;
  iVar3 = 0;
  if (dword_40B4DFC < 2) {
    if (dword_40B4DFC == 1) {
      puVar2 = dword_40B4DF4;
    }
  }
  else {
    uVar1 = 0;
    do {
      if ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4) {
        puVar4 = dword_40B4DF4;
        do {
          if ((((1 < (int)uVar1) || (puVar4[0xb] != 0)) &&
              (((uVar1 & 1) != 0 || (*(undefined **)(puVar4[2] + 0x1c) == _ufs_vnodeops)))) &&
             (iVar3 < (int)puVar4[6])) {
            puVar2 = puVar4;
            iVar3 = puVar4[6];
          }
          puVar4 = (undefined4 *)*puVar4;
        } while ((undefined4 **)puVar4 != &dword_40B4DF4);
      }
    } while ((puVar2 == (undefined4 *)0x0) && (uVar1 = uVar1 + 1, (int)uVar1 < 4));
  }
  return puVar2;
}

