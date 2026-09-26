/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c42c */

int * _getsegbynamefromheader(int param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = (int *)(param_1 + 0x1c);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    do {
      if ((*piVar2 == 1) && (iVar1 = _strncmp((char *)(piVar2 + 2),param_2,0x10), iVar1 == 0)) {
        return piVar2;
      }
      piVar2 = (int *)((int)piVar2 + piVar2[1]);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}

