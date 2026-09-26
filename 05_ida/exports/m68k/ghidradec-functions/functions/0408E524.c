
undefined4 _enoutput(int param_1,int param_2,byte *param_3)

{
  uint uVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  sVar2 = *(sword *)(param_1 + 8);
  iVar3 = sVar2 * 0x52c;
  iVar4 = *(int *)((int)&DAT_40c9132 + iVar3);
  uVar1 = *(uint *)((int)&DAT_40c9132 + iVar3 + 4);
  if (((uVar1 & 1) == 0) || ((uVar1 & 8) != 0)) {
    _nb_free(param_2);
    uVar5 = 0x32;
  }
  else {
    iVar6 = *(int *)(param_2 + 4) + param_2;
    _bcopy(param_3,iVar6,6);
    _bcopy((int)&unk_40C8F38 + iVar3,iVar6 + 6,6);
    if (((*param_3 & 1) != 0) &&
       (((_bmap_chip != 0 && (*(int *)(_bmap_chip + 0x34) < 0)) ||
        ((_dma_chip != 0x139 && ((*(byte *)(iVar4 + 4) & 4) != 0)))))) {
      iVar4 = _en_accept_multicast(&_en_softc + sVar2 * 0x14b,param_3);
      if (iVar4 == 1) {
        iVar4 = _m_copy(param_2,0,1000000000);
        if (iVar4 != 0) {
          _if_handle_input((&_en_softc)[sVar2 * 0x14b],iVar4,0);
        }
      }
    }
    if (*(int *)(param_1 + 0x22) < *(int *)(param_1 + 0x26)) {
      *(undefined4 *)(param_2 + 0x7c) = 0;
      if (*(int *)(param_1 + 0x1e) == 0) {
        *(int *)(param_1 + 0x1a) = param_2;
      }
      else {
        *(int *)(*(int *)(param_1 + 0x1e) + 0x7c) = param_2;
      }
      *(int *)(param_1 + 0x1e) = param_2;
      *(int *)(param_1 + 0x22) = *(int *)(param_1 + 0x22) + 1;
      if (((&byte_40C9139)[iVar3] & 2) == 0) {
        _enstart((int)*(sword *)(param_1 + 8));
      }
      uVar5 = 0;
    }
    else {
      *(int *)(param_1 + 0x2a) = *(int *)(param_1 + 0x2a) + 1;
      _m_freem(param_2);
      uVar5 = 0x37;
    }
  }
  return uVar5;
}
