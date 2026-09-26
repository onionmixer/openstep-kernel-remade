
int _new_inode(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = _zalloc(_inode_zone);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    _bzero(iVar2,0xe6);
    *(int *)iVar2 = iVar2;
    *(int *)(iVar2 + 4) = iVar2;
    *(undefined4 *)(iVar2 + 0x5a) = 0;
    *(undefined4 *)(iVar2 + 0x5e) = 0;
    *(int *)(iVar2 + 0x3a) = iVar2;
    *(undefined **)(iVar2 + 0x28) = _ufs_vnodeops;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    _vm_info_init((int *)(iVar2 + 0xc));
    pbVar1 = (byte *)(*(int *)(iVar2 + 0xc) + 0x34);
    *pbVar1 = *pbVar1 & 0xdf;
    *(int *)(iVar2 + 8) = _inode_list;
    _inode_list = iVar2;
  }
  return iVar2;
}
