
int _ip_srcroute(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if ((_ip_nhops == 0) || (iVar4 = _m_get(0,10), iVar3 = _ip_nhops, iVar4 == 0)) {
    iVar4 = 0;
  }
  else {
    iVar1 = _ip_nhops * 4;
    *(sword *)(iVar4 + 8) = (sword)iVar1 + 4;
    *(undefined4 *)(iVar4 + *(int *)(iVar4 + 4)) = *(undefined4 *)(&unk_40B3484 + iVar1);
    puVar5 = &DAT_40b3480 + iVar3;
    unk_40B3484 = 1;
    _bcopy(&unk_40B3484,*(int *)(iVar4 + 4) + iVar4 + 4,4);
    puVar2 = (undefined4 *)(*(int *)(iVar4 + 4) + iVar4 + 8);
    for (; &DAT_40b3487 < puVar5; puVar5 = puVar5 + -1) {
      *puVar2 = *puVar5;
      puVar2 = puVar2 + 1;
    }
  }
  return iVar4;
}

