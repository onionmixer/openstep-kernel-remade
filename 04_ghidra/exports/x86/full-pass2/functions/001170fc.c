/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001170fc */

int _connect(int param_1,sockaddr *param_2,socklen_t param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _getsock(*puVar1);
  iVar5 = DAT_001e875c;
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar3 + 0x18);
  if ((*(ushort *)(iVar3 + 6) & 0x104) == 0x104) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x25;
    return iVar5;
  }
  uVar2 = _sockargs(&local_8,puVar1[1],puVar1[2],8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) != '\0') {
    return DAT_001e875c;
  }
  uVar2 = _soconnect(iVar3,local_8);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if ((*(ushort *)(iVar3 + 6) & 0x104) == 0x104) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x24;
      goto LAB_00117245;
    }
    uVar4 = _splnet();
    iVar5 = _set_label((int *)(DAT_001e875c + 0x28));
    if (iVar5 == 0) {
      if (((*(byte *)(iVar3 + 6) & 4) != 0) && (*(short *)(iVar3 + 0x56) == 0)) {
        do {
          _sleep(iVar3 + 0x54);
          if ((*(byte *)(iVar3 + 6) & 4) == 0) break;
        } while (*(short *)(iVar3 + 0x56) == 0);
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = *(undefined1 *)(iVar3 + 0x56);
      *(undefined2 *)(iVar3 + 0x56) = 0;
    }
    else if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      *(undefined1 *)(DAT_001e875c + 0x68) = 4;
    }
    _splx(uVar4);
  }
  *(byte *)(iVar3 + 6) = *(byte *)(iVar3 + 6) & 0xfb;
LAB_00117245:
  iVar5 = _m_freem(local_8);
  return iVar5;
}

