/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146c0c */

void _ipc_hash_local_delete(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x14);
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar4 = (param_2 >> 6) % uVar2;
  while (*(int *)(iVar1 + 0xc + uVar4 * 0x10) != param_3) {
    uVar4 = uVar4 + 1;
    if (uVar4 == uVar2) {
      uVar4 = 0;
    }
  }
  do {
    uVar3 = uVar4;
    if (param_3 == 0) {
      return;
    }
    do {
      while( true ) {
        uVar3 = uVar3 + 1;
        if (uVar3 == uVar2) {
          uVar3 = 0;
        }
        param_3 = *(int *)(iVar1 + 0xc + uVar3 * 0x10);
        if (param_3 == 0) goto LAB_00146c92;
        uVar5 = (*(uint *)(iVar1 + 4 + param_3 * 0x10) >> 6) % uVar2;
        if (uVar3 < uVar4) break;
        if ((uVar3 < uVar5) || (uVar5 <= uVar4)) goto LAB_00146c92;
      }
    } while ((uVar5 <= uVar3) || (uVar4 < uVar5));
LAB_00146c92:
    *(int *)(iVar1 + 0xc + uVar4 * 0x10) = param_3;
    uVar4 = uVar3;
  } while( true );
}

