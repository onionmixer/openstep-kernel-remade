
void _selcont(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iStack_c;
  int iStack_8;
  
  iVar4 = dword_40B57D4;
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = dword_40B57D4 + 0x7e;
  if (*(int *)(dword_40B57D4 + 0x14a) < 0) {
    iVar6 = _thread_wait_result();
    if (iVar6 - 2U < 2) {
      *(undefined4 *)(iVar4 + 0x14a) = 4;
    }
    else {
      *(undefined4 *)(iVar4 + 0x14a) = 0;
    }
  }
  if (*(int *)(iVar4 + 0x14a) < 1) {
    while( true ) {
      iVar5 = _nselcoll;
      iVar6 = *_active_u;
      *(byte *)(iVar6 + 0x29) = *(byte *)(iVar6 + 0x29) | 0x40;
      uVar7 = _selscan(iVar3,iVar4 + 0xde,*piVar1);
      *(undefined4 *)(dword_40B57D4 + 0x5c) = uVar7;
      cVar2 = *(char *)(dword_40B57D4 + 100);
      *(int *)(iVar4 + 0x14a) = (int)cVar2;
      if (((cVar2 != 0) || (*(int *)(dword_40B57D4 + 0x5c) != 0)) || (*(int *)(iVar4 + 0x146) != 0))
      goto loc_400C68C;
      if (piVar1[4] != 0) {
        _getthetime(&iStack_c);
        if ((*(int *)(iVar4 + 0x13e) < iStack_c) ||
           ((*(int *)(iVar4 + 0x13e) == iStack_c && (*(int *)(iVar4 + 0x142) <= iStack_8))))
        goto loc_400C68C;
      }
      uVar8 = *(uint *)(iVar6 + 0x28);
      if (((uVar8 & 0x400000) != 0) && (iVar5 == _nselcoll)) break;
      *(uint *)(iVar6 + 0x28) = uVar8 & 0xffbfffff;
    }
    *(uint *)(iVar6 + 0x28) = uVar8 & 0xffbfffff;
    *(undefined4 *)(iVar4 + 0x14a) = 0xffffffff;
    if (piVar1[4] == 0) {
      _sleep_with_continuation(&_selwait,0x1a,_selcont);
    }
    else {
      _sleep_with_continuation_and_deadline(&_selwait,0x1a,_selcont,iVar4 + 0x13e);
    }
  }
loc_400C68C:
  uVar8 = *piVar1 + 0x1fU >> 5;
  if (*(int *)(iVar4 + 0x14a) == 0) {
    if (piVar1[1] != 0) {
      uVar7 = _copyoutmsg(iVar4 + 0xde,piVar1[1],uVar8 << 2);
      *(undefined4 *)(iVar4 + 0x14a) = uVar7;
    }
    if (piVar1[2] != 0) {
      uVar7 = _copyoutmsg(iVar4 + 0xfe,piVar1[2],uVar8 << 2);
      *(undefined4 *)(iVar4 + 0x14a) = uVar7;
    }
    if (piVar1[3] != 0) {
      uVar7 = _copyoutmsg(iVar4 + 0x11e,piVar1[3],uVar8 << 2);
      *(undefined4 *)(iVar4 + 0x14a) = uVar7;
    }
    if (*(int *)(iVar4 + 0x14a) == 0) goto loc_400C70C;
  }
  *(undefined *)(dword_40B57D4 + 100) = *(undefined *)(iVar4 + 0x14d);
loc_400C70C:
  _unix_syscall_return(*(undefined4 *)(iVar4 + 0x14a));
  return;
}
