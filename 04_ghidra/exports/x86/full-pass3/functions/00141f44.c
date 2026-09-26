/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141f44 */

undefined4 _iaccess(int param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  short *psVar3;
  uint uVar4;
  
  if ((char)param_2 < '\0') {
    if ((((*(char *)(*(int *)(param_1 + 0x50) + 0xd2) != '\0') &&
         (uVar2 = *(ushort *)(param_1 + 100) & 0xf000, uVar2 != 0x2000)) && (uVar2 != 0x6000)) &&
       (uVar2 != 0x1000)) {
      return 0x1e;
    }
    if (((*(byte *)(param_1 + 0x10) & 2) != 0) &&
       (_vnode_uncache(param_1 + 0xc), (*(byte *)(param_1 + 0x10) & 2) != 0)) {
      return 0x1a;
    }
  }
  iVar1 = *(int *)(_active_u + 0x1c);
  if (*(short *)(iVar1 + 2) != 0) {
    uVar4 = param_2;
    if ((*(short *)(param_1 + 0x68) != *(short *)(iVar1 + 2)) &&
       (uVar4 = (int)param_2 >> 3, *(short *)(iVar1 + 4) != *(short *)(param_1 + 0x6a))) {
      for (psVar3 = (short *)(iVar1 + 10); (psVar3 < (short *)(iVar1 + 0x2aU) && (*psVar3 != -1));
          psVar3 = psVar3 + 1) {
        if (*(short *)(param_1 + 0x6a) == *psVar3) goto LAB_00141fe9;
      }
      uVar4 = (int)param_2 >> 6;
    }
LAB_00141fe9:
    if ((*(ushort *)(param_1 + 100) & uVar4) != uVar4) {
      return 0xd;
    }
  }
  return 0;
}

