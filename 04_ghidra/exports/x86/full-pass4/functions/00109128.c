/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109128 */

int _sigvec(int param_1,sigvec *param_2,sigvec *param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int *piVar4;
  uint uVar5;
  byte bVar6;
  int local_10;
  int local_c;
  uint local_8;
  
  piVar4 = DAT_001e875c;
  piVar1 = (int *)DAT_001e875c[9];
  iVar2 = *piVar1;
  if (((iVar2 - 1U < 0x1f) && (iVar2 != 9)) && (iVar2 != 0x11)) {
    if (piVar1[2] != 0) {
      local_10 = _active_u[iVar2 + 0xc];
      local_c = _active_u[iVar2 + 0x2d];
      uVar5 = 1 << ((byte)(iVar2 - 1U) & 0x1f);
      bVar6 = (_active_u[0x4f] & uVar5) != 0;
      if ((_active_u[0x50] & uVar5) != 0) {
        bVar6 = bVar6 | 2;
      }
      local_8 = (uint)bVar6;
      uVar3 = _copyout(&local_10,piVar1[2],0xc);
      *(undefined1 *)(DAT_001e875c + 0x1a) = uVar3;
      if ((char)DAT_001e875c[0x1a] != '\0') {
        return (int)DAT_001e875c;
      }
    }
    piVar4 = (int *)0x0;
    if (piVar1[1] != 0) {
      uVar3 = _copyin(piVar1[1],&local_10,0xc);
      piVar4 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x1a) = uVar3;
      if ((char)DAT_001e875c[0x1a] == '\0') {
        if (((iVar2 == 0x13) && (local_10 == 1)) &&
           (piVar4 = (int *)*_active_u, (*(byte *)((int)piVar4 + 0x16) & 2) == 0)) {
          *(undefined1 *)(DAT_001e875c + 0x1a) = 0x16;
        }
        else {
          _setsigvec(iVar2,&local_10);
          piVar4 = _active_u;
          _active_u[0x4e] = *(int *)(*DAT_001e875c + 0x24);
        }
      }
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x1a) = 0x16;
  }
  return (int)piVar4;
}

