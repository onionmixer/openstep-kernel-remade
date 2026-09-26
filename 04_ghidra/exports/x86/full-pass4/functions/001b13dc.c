/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b13dc */

undefined4 FUN_001b13dc(int param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  uVar1 = param_3[1];
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    uVar3 = 0xfffffd3f;
  }
  else {
    if (*(int *)(param_1 + 0x180) == 0) {
      iVar2 = *param_3;
      *(int *)(param_1 + 0x17c) = iVar2 * 0x14;
      pvVar4 = (void *)_IOMalloc(iVar2 * 0x14);
      *(void **)(param_1 + 0x180) = pvVar4;
      _bzero(pvVar4,*(size_t *)(param_1 + 0x17c));
      *(undefined4 *)(param_1 + 0x160) = 0xe18;
      *(undefined4 *)(param_1 + 0x184) = 0;
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined2 *)(param_1 + 0x19e) = 0;
      *(undefined2 *)(param_1 + 0x19a) = 0;
      *(undefined2 *)(param_1 + 0x19c) = 0;
      *(undefined2 *)(param_1 + 0x198) = 0;
    }
    if (((int)uVar1 < 0) || (*(uint *)(param_1 + 0x17c) / 0x14 <= uVar1)) {
      uVar3 = 0xfffffd3e;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x180) + uVar1 * 0x14;
      *(short *)(iVar2 + 0xc) = (short)param_3[3];
      *(short *)(iVar2 + 0xe) = (short)param_3[4];
      *(short *)(iVar2 + 0x10) = (short)param_3[5];
      *(short *)(iVar2 + 0x12) = (short)param_3[6];
      *(int *)(iVar2 + 8) = param_3[2];
      *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + param_3[2];
      if (*(short *)(iVar2 + 0xc) < *(short *)(param_1 + 0x198)) {
        *(undefined2 *)(param_1 + 0x198) = *(undefined2 *)(iVar2 + 0xc);
      }
      if (*(short *)(iVar2 + 0x10) < *(short *)(param_1 + 0x19c)) {
        *(undefined2 *)(param_1 + 0x19c) = *(undefined2 *)(iVar2 + 0x10);
      }
      if (*(short *)(iVar2 + 0xe) < *(short *)(param_1 + 0x19a)) {
        *(undefined2 *)(param_1 + 0x19a) = *(undefined2 *)(iVar2 + 0xe);
      }
      if (*(short *)(iVar2 + 0x12) < *(short *)(param_1 + 0x19e)) {
        *(undefined2 *)(param_1 + 0x19e) = *(undefined2 *)(iVar2 + 0x12);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}

