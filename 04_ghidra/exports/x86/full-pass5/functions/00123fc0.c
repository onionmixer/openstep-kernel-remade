/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123fc0 */

int * _in_addmulti(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 local_24 [16];
  undefined2 local_14;
  int local_10;
  
  uVar1 = _splnet();
  iVar2 = _in_ifaddr;
  if (_in_ifaddr == 0) {
LAB_00124014:
    iVar2 = _in_ifaddr;
    if (_in_ifaddr != 0) {
      do {
        if (*(int *)(iVar2 + 0x20) == param_2) break;
        iVar2 = *(int *)(iVar2 + 0x40);
      } while (iVar2 != 0);
      if ((iVar2 != 0) && (iVar3 = _m_getclr(0,0xf), iVar3 != 0)) {
        piVar4 = (int *)(iVar3 + *(int *)(iVar3 + 4));
        *piVar4 = param_1;
        piVar4[1] = param_2;
        piVar4[3] = 1;
        piVar4[2] = iVar2;
        piVar4[5] = *(int *)(iVar2 + 0x44);
        *(int **)(iVar2 + 0x44) = piVar4;
        local_14 = 2;
        local_10 = param_1;
        if ((*(int *)(param_2 + 0x38) == 0) ||
           (iVar5 = _if_ioctl(param_2,0x80206931,local_24), iVar5 != 0)) {
          *(int *)(iVar2 + 0x44) = piVar4[5];
          _m_free(iVar3);
          piVar4 = (int *)0x0;
        }
        else {
          _igmp_joingroup(piVar4);
        }
        goto LAB_001240bd;
      }
    }
    _splx(uVar1);
    piVar4 = (int *)0x0;
  }
  else {
    do {
      if (*(int *)(iVar2 + 0x20) == param_2) break;
      iVar2 = *(int *)(iVar2 + 0x40);
    } while (iVar2 != 0);
    if ((iVar2 == 0) || (piVar4 = *(int **)(iVar2 + 0x44), piVar4 == (int *)0x0)) goto LAB_00124014;
    do {
      if (*piVar4 == param_1) break;
      piVar4 = (int *)piVar4[5];
    } while (piVar4 != (int *)0x0);
    if (piVar4 == (int *)0x0) goto LAB_00124014;
    piVar4[3] = piVar4[3] + 1;
LAB_001240bd:
    _splx(uVar1);
  }
  return piVar4;
}

