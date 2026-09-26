/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00127b90 */

undefined4 _ip_pcbopts(int *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  
  if (*param_1 != 0) {
    _m_free(*param_1);
  }
  *param_1 = 0;
  if (param_2 != 0) {
    sVar2 = *(short *)(param_2 + 8);
    if (sVar2 == 0) {
      _m_free(param_2);
    }
    else {
      uVar4 = (uint)sVar2;
      if (((uVar4 & 3) != 0) || (0x7c < *(int *)(param_2 + 4) + uVar4 + 4)) {
LAB_00127cb0:
        _m_free(param_2);
        return 0x16;
      }
      *(short *)(param_2 + 8) = sVar2 + 4;
      iVar3 = param_2 + *(int *)(param_2 + 4);
      pcVar6 = (char *)(iVar3 + 4);
      _ovbcopy(iVar3,pcVar6,uVar4);
      _bzero((void *)(param_2 + *(int *)(param_2 + 4)),4);
      for (; (0 < (int)uVar4 && (cVar1 = *pcVar6, cVar1 != '\0')); pcVar6 = pcVar6 + uVar5) {
        if (cVar1 == '\x01') {
          uVar5 = 1;
        }
        else {
          uVar5 = (uint)(byte)pcVar6[1];
          if ((uVar5 < 2) || ((int)uVar4 < (int)uVar5)) goto LAB_00127cb0;
        }
        if ((cVar1 == -0x7d) || (uVar7 = uVar4, cVar1 == -0x77)) {
          if (uVar5 < 7) goto LAB_00127cb0;
          *(short *)(param_2 + 8) = *(short *)(param_2 + 8) + -4;
          uVar7 = uVar4 - 4;
          uVar5 = uVar5 - 4;
          pcVar6[1] = (char)uVar5;
          _bcopy(pcVar6 + 3,(void *)(param_2 + *(int *)(param_2 + 4)),4);
          _ovbcopy(pcVar6 + 7,pcVar6 + 3,uVar4);
        }
        uVar4 = uVar7 - uVar5;
      }
      *param_1 = param_2;
    }
  }
  return 0;
}

