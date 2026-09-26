/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107c1c */

int _getgroups(int param_1,gid_t param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  int local_44 [16];
  
  iVar4 = DAT_001e875c;
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  for (uVar5 = _active_u[7] + 0x2a; (_active_u[7] + 10U < uVar5 && (*(short *)(uVar5 - 2) == -1));
      uVar5 = uVar5 - 2) {
  }
  uVar5 = (int)((uVar5 - 10) - _active_u[7]) >> 1;
  if (*puVar1 < uVar5) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  else {
    *puVar1 = uVar5;
    if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
      psVar6 = (short *)(_active_u[7] + 10);
      piVar3 = local_44;
      if (local_44 < local_44 + uVar5) {
        do {
          *piVar3 = (int)*psVar6;
          psVar6 = psVar6 + 1;
          piVar3 = piVar3 + 1;
        } while (piVar3 < local_44 + *puVar1);
      }
      iVar4 = *puVar1 * 4;
      uVar5 = puVar1[1];
      piVar3 = local_44;
    }
    else {
      iVar4 = uVar5 * 2;
      uVar5 = puVar1[1];
      piVar3 = (int *)(_active_u[7] + 10);
    }
    uVar2 = _copyout(piVar3,uVar5,iVar4);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    iVar4 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      *(uint *)(DAT_001e875c + 0x60) = *puVar1;
    }
  }
  return iVar4;
}

