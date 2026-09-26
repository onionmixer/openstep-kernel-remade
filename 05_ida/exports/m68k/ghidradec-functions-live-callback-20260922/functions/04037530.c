
void _ihinit(void)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined *puVar4;
  
  puVar4 = _ihead;
  iVar2 = 0x1ff;
  do {
    do {
      *(undefined **)puVar4 = puVar4;
      *(undefined **)(puVar4 + 4) = puVar4;
      puVar4 = puVar4 + 8;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  _ifreeh = 0;
  _ifreet = 0;
  _inode_list = 0;
  _inode_zone = _zinit(0xe6,2300000,0,0,aInodeStructure);
  return;
}

