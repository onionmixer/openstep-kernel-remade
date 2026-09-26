/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00129a8c */

void _tcp_dooptions(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  ushort local_6;
  
  iVar4 = (int)*(short *)(param_2 + 8);
  for (pcVar3 = (char *)(param_2 + *(int *)(param_2 + 4));
      (0 < iVar4 && (cVar1 = *pcVar3, cVar1 != '\0')); pcVar3 = pcVar3 + uVar2) {
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
    else {
      uVar2 = (uint)(byte)pcVar3[1];
      if (uVar2 == 0) break;
    }
    if (((cVar1 == '\x02') && (uVar2 == 4)) && ((*(byte *)(param_3 + 0x21) & 2) != 0)) {
      _bcopy(pcVar3 + 2,&local_6,2);
      local_6 = local_6 >> 8 | local_6 << 8;
      _tcp_mss(param_1,local_6);
    }
    iVar4 = iVar4 - uVar2;
  }
  _m_free(param_2);
  return;
}

