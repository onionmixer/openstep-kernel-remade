/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00131c0c */

int FUN_00131c0c(undefined4 param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  short *psVar3;
  uint uVar4;
  undefined1 local_44 [4];
  ushort local_40;
  short local_3e;
  short local_3c;
  
  uVar1 = _nfsgetattr(param_1,local_44,param_3,0);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if (*(short *)(param_3 + 2) != 0) {
      uVar4 = param_2;
      if ((local_3e != *(short *)(param_3 + 2)) &&
         (uVar4 = (int)param_2 >> 3, *(short *)(param_3 + 4) != local_3c)) {
        for (psVar3 = (short *)(param_3 + 10);
            (psVar3 < (short *)(param_3 + 0x2aU) && (*psVar3 != -1)); psVar3 = psVar3 + 1) {
          if (local_3c == *psVar3) goto LAB_00131c88;
        }
        uVar4 = (int)param_2 >> 6;
      }
LAB_00131c88:
      if ((local_40 & uVar4) != uVar4) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0xd;
        return 0xd;
      }
    }
    iVar2 = 0;
  }
  else {
    iVar2 = (int)*(char *)(DAT_001e875c + 0x68);
  }
  return iVar2;
}

