/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141e70 */

int _iflush(short param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (_inode_list != (int *)0x0) {
    piVar2 = _inode_list;
    do {
      if (*(short *)((int)piVar2 + 0x46) == param_1) {
        if ((*(byte *)((int)piVar2 + 0x45) & 1) == 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
          *(int *)piVar2[1] = *piVar2;
          *piVar2 = (int)piVar2;
          piVar2[1] = (int)piVar2;
        }
        else {
          iVar1 = -1;
        }
      }
      else if (((((*(byte *)((int)piVar2 + 0x45) & 1) != 0) &&
                ((*(ushort *)(piVar2 + 0x19) & 0xf000) == 0x6000)) && (piVar2[0x23] == (int)param_1)
               ) && (-1 < iVar1)) {
        iVar1 = iVar1 + 1;
      }
      piVar2 = (int *)piVar2[2];
    } while (piVar2 != (int *)0x0);
  }
  return iVar1;
}

