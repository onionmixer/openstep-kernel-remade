/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001020ac */

void _rpause(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(DAT_001e875c + 0x24);
  if ((*piVar2 != 0x1c) || (piVar2[1] != 0x7fffffff)) goto LAB_0010211c;
  bVar1 = *(byte *)(_active_u + 0x260);
  iVar3 = piVar2[2];
  if (iVar3 == 1) {
    *(byte *)(_active_u + 0x260) = bVar1 & 0xf7;
LAB_00102128:
    if ((bVar1 & 8) == 0) {
      *(undefined4 *)(DAT_001e875c + 0x60) = 0;
    }
    else {
      *(undefined4 *)(DAT_001e875c + 0x60) = 0x7fffffff;
    }
  }
  else {
    if (iVar3 < 2) {
      if (iVar3 == 0) goto LAB_00102128;
    }
    else if (iVar3 == 2) {
      *(byte *)(_active_u + 0x260) = bVar1 | 8;
      goto LAB_00102128;
    }
LAB_0010211c:
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  return;
}

