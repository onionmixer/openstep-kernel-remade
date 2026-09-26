/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114bd4 */

int _socreate(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  short *psVar1;
  int iVar2;
  undefined2 *puVar3;
  
  if (param_4 == 0) {
    psVar1 = (short *)_pffindtype(param_1,param_3);
  }
  else {
    psVar1 = (short *)_pffindproto(param_1,param_4,param_3);
  }
  if (psVar1 == (short *)0x0) {
    iVar2 = 0x2b;
  }
  else if (*psVar1 == param_3) {
    iVar2 = _m_getclr(1,3);
    puVar3 = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
    puVar3[1] = 0x20;
    puVar3[3] = 0;
    *puVar3 = (short)param_3;
    if (*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
      puVar3[3] = 0x80;
    }
    *(short **)(puVar3 + 6) = psVar1;
    iVar2 = (**(code **)(psVar1 + 0xe))(puVar3,0,0,param_4,0);
    if (iVar2 == 0) {
      *param_2 = (int)puVar3;
      iVar2 = 0;
    }
    else {
      *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 1;
      _sofree(puVar3);
    }
  }
  else {
    iVar2 = 0x29;
  }
  return iVar2;
}

