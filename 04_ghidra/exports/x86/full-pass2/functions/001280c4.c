/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001280c4 */

undefined4 _ip_getmoptions(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  
  iVar1 = _m_get(1,0xe);
  *param_3 = iVar1;
  if (param_2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(param_2 + *(int *)(param_2 + 4));
  }
  if (param_1 == 4) {
    iVar1 = *param_3;
    puVar4 = (undefined1 *)(iVar1 + *(int *)(iVar1 + 4));
    *(undefined2 *)(iVar1 + 8) = 1;
    if (piVar5 == (int *)0x0) {
LAB_00128178:
      *puVar4 = 1;
    }
    else {
      *puVar4 = (char)piVar5[1];
    }
LAB_0012817b:
    uVar2 = 0;
  }
  else {
    if (param_1 < 5) {
      if (param_1 == 3) {
        iVar1 = *param_3;
        puVar3 = (undefined4 *)(iVar1 + *(int *)(iVar1 + 4));
        *(undefined2 *)(iVar1 + 8) = 4;
        if (((piVar5 != (int *)0x0) && (*piVar5 != 0)) && (iVar1 = _in_ifaddr, _in_ifaddr != 0)) {
          do {
            if (*(int *)(iVar1 + 0x20) == *piVar5) break;
            iVar1 = *(int *)(iVar1 + 0x40);
          } while (iVar1 != 0);
          if (iVar1 != 0) {
            *puVar3 = *(undefined4 *)(iVar1 + 4);
            goto LAB_0012817b;
          }
        }
        *puVar3 = 0;
        goto LAB_0012817b;
      }
    }
    else if (param_1 == 5) {
      iVar1 = *param_3;
      puVar4 = (undefined1 *)(iVar1 + *(int *)(iVar1 + 4));
      *(undefined2 *)(iVar1 + 8) = 1;
      if (piVar5 == (int *)0x0) goto LAB_00128178;
      *puVar4 = *(undefined1 *)((int)piVar5 + 5);
      goto LAB_0012817b;
    }
    uVar2 = 0x2d;
  }
  return uVar2;
}

