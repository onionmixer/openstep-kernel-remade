/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001beb58 */

long _strtol(char *param_1,char **param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int local_10;
  uint local_8;
  
  bVar2 = false;
  pcVar7 = param_1;
  do {
    pcVar6 = pcVar7;
    cVar3 = *pcVar6;
    iVar4 = (int)cVar3;
    pcVar7 = pcVar6 + 1;
    bVar1 = false;
    if (((cVar3 == ' ') || ((byte)(cVar3 - 9U) < 2)) || (cVar3 == '\n')) {
      bVar1 = true;
    }
  } while (bVar1);
  if (iVar4 == 0x2d) {
    bVar2 = true;
LAB_001beba5:
    iVar4 = (int)*pcVar7;
    pcVar7 = pcVar6 + 2;
  }
  else if (iVar4 == 0x2b) goto LAB_001beba5;
  if (((param_3 == 0) || (param_3 == 0x10)) && (iVar4 == 0x30)) {
    if ((*pcVar7 == 'x') || (*pcVar7 == 'X')) {
      iVar4 = (int)pcVar7[1];
      pcVar7 = pcVar7 + 2;
      param_3 = 0x10;
      goto LAB_001bec1c;
    }
  }
  if (((param_3 == 0) || (param_3 == 2)) && (iVar4 == 0x30)) {
    if ((*pcVar7 == 'b') || (*pcVar7 == 'B')) {
      iVar4 = (int)pcVar7[1];
      pcVar7 = pcVar7 + 2;
      param_3 = 2;
    }
  }
  if ((param_3 == 0) && (param_3 = 10, iVar4 == 0x30)) {
    param_3 = 8;
  }
LAB_001bec1c:
  local_8 = 0x7fffffff;
  if (bVar2) {
    local_8 = 0x80000000;
  }
  uVar5 = 0;
  local_10 = 0;
  do {
    cVar3 = (char)iVar4;
    if ((byte)(cVar3 - 0x30U) < 10) {
      iVar4 = iVar4 + -0x30;
    }
    else {
      bVar1 = false;
      if (((byte)(cVar3 + 0xbfU) < 0x1a) || ((byte)(cVar3 + 0x9fU) < 0x1a)) {
        bVar1 = true;
      }
      if (!bVar1) {
LAB_001becbc:
        if (local_10 < 0) {
          uVar5 = 0x7fffffff;
          if (bVar2) {
            uVar5 = 0x80000000;
          }
        }
        else if (bVar2) {
          uVar5 = -uVar5;
        }
        if (param_2 != (char **)0x0) {
          if (local_10 != 0) {
            param_1 = pcVar7 + -1;
          }
          *param_2 = param_1;
        }
        return uVar5;
      }
      if ((byte)(cVar3 + 0xbfU) < 0x1a) {
        iVar4 = iVar4 + -0x37;
      }
      else {
        iVar4 = iVar4 + -0x57;
      }
    }
    if (param_3 <= iVar4) goto LAB_001becbc;
    if (((local_10 < 0) || (local_8 / (uint)param_3 < uVar5)) ||
       ((local_8 / (uint)param_3 == uVar5 && ((int)(local_8 % (uint)param_3) < iVar4)))) {
      local_10 = -1;
    }
    else {
      local_10 = 1;
      uVar5 = uVar5 * param_3 + iVar4;
    }
    iVar4 = (int)*pcVar7;
    pcVar7 = pcVar7 + 1;
  } while( true );
}

