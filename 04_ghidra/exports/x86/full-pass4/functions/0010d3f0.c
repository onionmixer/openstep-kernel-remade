/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d3f0 */

void _selcont(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int local_c;
  int local_8;
  
  iVar4 = DAT_001e875c;
  piVar3 = *(int **)(DAT_001e875c + 0x24);
  iVar1 = DAT_001e875c + 0x88;
  if (*(int *)(DAT_001e875c + 0x154) < 0) {
    iVar6 = _thread_wait_result();
    if (iVar6 - 2U < 2) {
      *(undefined4 *)(iVar4 + 0x154) = 4;
    }
    else {
      *(undefined4 *)(iVar4 + 0x154) = 0;
    }
  }
  if (*(int *)(iVar4 + 0x154) < 1) {
    while( true ) {
      iVar5 = _nselcoll;
      iVar6 = *_active_u;
      *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) | 0x400000;
      uVar7 = _selscan(iVar1,iVar4 + 0xe8,*piVar3);
      *(undefined4 *)(DAT_001e875c + 0x60) = uVar7;
      cVar2 = *(char *)(DAT_001e875c + 0x68);
      *(int *)(iVar4 + 0x154) = (int)cVar2;
      if (((cVar2 != 0) || (*(int *)(DAT_001e875c + 0x60) != 0)) || (*(int *)(iVar4 + 0x150) != 0))
      goto LAB_0010d568;
      uVar7 = _splhigh();
      if (piVar3[4] != 0) {
        _getthetime(&local_c);
        if ((*(int *)(iVar4 + 0x148) < local_c) ||
           ((local_c == *(int *)(iVar4 + 0x148) && (*(int *)(iVar4 + 0x14c) <= local_8)))) {
          _splx(uVar7);
          goto LAB_0010d568;
        }
      }
      uVar8 = *(uint *)(iVar6 + 0x28);
      if (((uVar8 & 0x400000) != 0) && (_nselcoll == iVar5)) break;
      *(uint *)(iVar6 + 0x28) = uVar8 & 0xffbfffff;
      _splx(uVar7);
    }
    *(uint *)(iVar6 + 0x28) = uVar8 & 0xffbfffff;
    *(undefined4 *)(iVar4 + 0x154) = 0xffffffff;
    if (piVar3[4] == 0) {
      _sleep_with_continuation(&_selwait,0x1a,_selcont);
    }
    else {
      _sleep_with_continuation_and_deadline(&_selwait,0x1a,_selcont,iVar4 + 0x148);
    }
  }
LAB_0010d568:
  uVar8 = *piVar3 + 0x1fU >> 5;
  if (*(int *)(iVar4 + 0x154) == 0) {
    if (piVar3[1] != 0) {
      uVar7 = _copyout(iVar4 + 0xe8,piVar3[1],uVar8 * 4);
      *(undefined4 *)(iVar4 + 0x154) = uVar7;
    }
    if (piVar3[2] != 0) {
      uVar7 = _copyout(iVar4 + 0x108,piVar3[2],uVar8 * 4);
      *(undefined4 *)(iVar4 + 0x154) = uVar7;
    }
    if (piVar3[3] != 0) {
      uVar7 = _copyout(iVar4 + 0x128,piVar3[3],uVar8 * 4);
      *(undefined4 *)(iVar4 + 0x154) = uVar7;
    }
    if (*(int *)(iVar4 + 0x154) == 0) goto LAB_0010d5fe;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = *(undefined1 *)(iVar4 + 0x154);
LAB_0010d5fe:
  _unix_syscall_return(*(undefined4 *)(iVar4 + 0x154));
  return;
}

