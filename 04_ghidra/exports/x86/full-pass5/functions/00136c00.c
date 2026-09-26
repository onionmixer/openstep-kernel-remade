/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136c00 */

int * _ku_recvfrom(int param_1,undefined4 *param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  psVar1 = (short *)(param_1 + 0x24);
  iVar7 = 0;
  piVar5 = *(int **)(param_1 + 0x30);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    iVar3 = piVar5[0x1f];
    iVar4 = piVar5[1];
    *param_2 = *(undefined4 *)(iVar4 + (int)piVar5);
    param_2[1] = *(undefined4 *)(iVar4 + 4 + (int)piVar5);
    param_2[2] = *(undefined4 *)(iVar4 + 8 + (int)piVar5);
    param_2[3] = *(undefined4 *)(iVar4 + 0xc + (int)piVar5);
    do {
      if (*(short *)((int)piVar5 + 10) == 1) break;
      *psVar1 = *psVar1 - (short)piVar5[2];
      sVar2 = *(short *)(param_1 + 0x28);
      *(short *)(param_1 + 0x28) = sVar2 + -0x80;
      if (0x7c < (uint)piVar5[1]) {
        *(short *)(param_1 + 0x28) = sVar2 + -0x480;
      }
      piVar5 = (int *)_m_free(piVar5);
    } while (piVar5 != (int *)0x0);
    piVar6 = piVar5;
    if (piVar5 == (int *)0x0) {
      _printf(s_ku_recvfrom__no_body__001dd158);
      *(int *)(param_1 + 0x30) = iVar3;
      piVar5 = (int *)0x0;
    }
    else {
      do {
        *psVar1 = *psVar1 - (short)piVar6[2];
        sVar2 = *(short *)(param_1 + 0x28);
        *(short *)(param_1 + 0x28) = sVar2 + -0x80;
        if (0x7c < (uint)piVar6[1]) {
          *(short *)(param_1 + 0x28) = sVar2 + -0x480;
        }
        iVar7 = iVar7 + (short)piVar6[2];
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
      *(int *)(param_1 + 0x30) = iVar3;
      if (0x2260 < iVar7) {
        _printf(s_ku_recvfrom__len____d_001dd16f,iVar7);
      }
    }
  }
  return piVar5;
}

