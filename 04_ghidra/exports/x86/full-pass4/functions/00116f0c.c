/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116f0c */

int _accept(int param_1,sockaddr *param_2,socklen_t *param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_8;
  
  iVar6 = *(int *)(DAT_001e875c + 0x24);
  if (*(int *)(iVar6 + 4) != 0) {
    uVar2 = _copyin(*(undefined4 *)(iVar6 + 8),&local_8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      return DAT_001e875c;
    }
    iVar3 = _useracc(*(undefined4 *)(iVar6 + 4),local_8);
    iVar4 = DAT_001e875c;
    if (iVar3 == 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0xe;
      return iVar4;
    }
  }
  iVar4 = _getsock();
  puVar7 = &stack0xffffffe8;
  if (iVar4 == 0) {
    return 0;
  }
  uVar5 = _splnet();
  iVar4 = *(int *)(iVar4 + 0x18);
  if ((*(byte *)(iVar4 + 2) & 2) == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    puVar7 = &stack0xffffffe8;
    goto LAB_001170e7;
  }
  if ((*(byte *)(iVar4 + 7) & 1) == 0) {
    if (*(short *)(iVar4 + 0x20) != 0) goto LAB_00116fff;
    if (*(short *)(iVar4 + 0x56) == 0) {
      while ((*(byte *)(iVar4 + 6) & 0x20) == 0) {
        _sleep(iVar4 + 0x54);
        if ((*(short *)(iVar4 + 0x20) != 0) || (*(short *)(iVar4 + 0x56) != 0)) goto LAB_00116fff;
      }
      *(undefined2 *)(iVar4 + 0x56) = 0x35;
      goto LAB_00116fff;
    }
  }
  else {
    if (*(short *)(iVar4 + 0x20) == 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x23;
      puVar7 = &stack0xffffffe8;
      goto LAB_001170e7;
    }
LAB_00116fff:
    if (*(short *)(iVar4 + 0x56) == 0) {
      iVar3 = _falloc();
      if (iVar3 == 0) {
        *(undefined4 *)(*(int *)(_active_u + 0x150) + *(int *)(DAT_001e875c + 0x60) * 4) = 0;
      }
      else {
        uVar1 = *(undefined4 *)(iVar4 + 0x1c);
        iVar4 = _soqremque(uVar1);
        if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_accept_001db39d);
        }
        *(undefined2 *)(iVar3 + 0xc) = 2;
        *(undefined4 *)(iVar3 + 8) = 3;
        *(undefined ***)(iVar3 + 0x14) = &_socketops;
        *(undefined4 *)(iVar3 + 0x18) = uVar1;
        *(int *)(*(int *)(_active_u + 0x150) + *(int *)(DAT_001e875c + 0x60) * 4) = iVar3;
        iVar4 = _m_get(1);
        _soaccept(uVar1,iVar4);
        if (*(int *)(iVar6 + 4) != 0) {
          if (*(short *)(iVar4 + 8) < local_8) {
            local_8 = (int)*(short *)(iVar4 + 8);
          }
          _copyout(iVar4 + *(int *)(iVar4 + 4),*(undefined4 *)(iVar6 + 4));
          _copyout(&local_8,*(undefined4 *)(iVar6 + 8),4);
        }
        puVar7 = &stack0xffffffe4;
        _m_freem();
      }
      goto LAB_001170e7;
    }
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = *(undefined1 *)(iVar4 + 0x56);
  *(undefined2 *)(iVar4 + 0x56) = 0;
  puVar7 = &stack0xffffffe8;
LAB_001170e7:
  *(undefined4 *)(puVar7 + -4) = uVar5;
  *(undefined4 *)(puVar7 + -8) = 0x1170f0;
  iVar6 = _splx();
  return iVar6;
}

