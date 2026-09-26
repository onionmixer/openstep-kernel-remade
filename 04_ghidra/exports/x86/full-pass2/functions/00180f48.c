/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00180f48 */

bool FUN_00180f48(char *param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint local_18;
  int local_10;
  
  bVar2 = false;
  local_18 = 0;
  pcVar8 = param_1;
  do {
    pcVar7 = pcVar8;
    cVar4 = *pcVar7;
    iVar5 = (int)cVar4;
    pcVar8 = pcVar7 + 1;
    bVar1 = false;
    if (((cVar4 == ' ') || ((byte)(cVar4 - 9U) < 2)) || (cVar4 == '\n')) {
      bVar1 = true;
    }
  } while (bVar1);
  if (iVar5 == 0x2d) {
    bVar2 = true;
  }
  else if (iVar5 != 0x2b) goto LAB_00180fa1;
  iVar5 = (int)*pcVar8;
  pcVar8 = pcVar7 + 2;
LAB_00180fa1:
  if ((iVar5 == 0x30) && ((*pcVar8 == 'x' || (*pcVar8 == 'X')))) {
    iVar5 = (int)pcVar8[1];
    pcVar8 = pcVar8 + 2;
    local_18 = 0x10;
  }
  if ((local_18 == 0) && (local_18 = 10, iVar5 == 0x30)) {
    local_18 = 8;
  }
  uVar3 = (uint)(0xffffffff / (ulonglong)local_18);
  uVar6 = 0;
  local_10 = 0;
  do {
    cVar4 = (char)iVar5;
    if ((byte)(cVar4 - 0x30U) < 10) {
      iVar5 = iVar5 + -0x30;
    }
    else {
      bVar1 = false;
      if (((byte)(cVar4 + 0xbfU) < 0x1a) || ((byte)(cVar4 + 0x9fU) < 0x1a)) {
        bVar1 = true;
      }
      if (!bVar1) {
LAB_00181068:
        if (local_10 < 0) {
          uVar6 = 0xffffffff;
        }
        else if (bVar2) {
          uVar6 = -uVar6;
        }
        if (param_2 != (int *)0x0) {
          if (local_10 != 0) {
            param_1 = pcVar8 + -1;
          }
          *param_2 = (int)param_1;
        }
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar6;
        }
        return 0 < local_10;
      }
      if ((byte)(cVar4 + 0xbfU) < 0x1a) {
        iVar5 = iVar5 + -0x37;
      }
      else {
        iVar5 = iVar5 + -0x57;
      }
    }
    if ((int)local_18 <= iVar5) goto LAB_00181068;
    if (((local_10 < 0) || (uVar3 < uVar6)) ||
       ((uVar3 == uVar6 && ((int)(0xffffffff % (ulonglong)local_18) < iVar5)))) {
      local_10 = -1;
    }
    else {
      local_10 = 1;
      uVar6 = uVar6 * local_18 + iVar5;
    }
    iVar5 = (int)*pcVar8;
    pcVar8 = pcVar8 + 1;
  } while( true );
}

