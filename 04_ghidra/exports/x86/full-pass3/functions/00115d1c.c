/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115d1c */

undefined4 _sosetopt(int param_1,int param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = param_4;
  uVar4 = 0;
  if (param_2 != 0xffff) {
    if ((*(int *)(param_1 + 0xc) != 0) &&
       (pcVar1 = *(code **)(*(int *)(param_1 + 0xc) + 0x18), pcVar1 != (code *)0x0)) {
      uVar4 = (*pcVar1)(1,param_1,param_2,param_3,&param_4);
      return uVar4;
    }
    goto LAB_00115eb8;
  }
  if (param_3 == 0x20) {
LAB_00115dd7:
    if ((param_4 != 0) && (3 < *(ushort *)(param_4 + 8))) {
      if (*(int *)(*(int *)(param_4 + 4) + param_4) == 0) {
        *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & ~(ushort)param_3;
      }
      else {
        *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | (ushort)param_3;
      }
      goto switchD_00115e2b_default;
    }
  }
  else {
    if (param_3 < 0x21) {
      if (param_3 != 4) {
        if (param_3 < 5) {
          if (param_3 == 1) goto LAB_00115dd7;
        }
        else if ((param_3 == 8) || (param_3 == 0x10)) goto LAB_00115dd7;
LAB_00115eb8:
        uVar4 = 0x2a;
        goto switchD_00115e2b_default;
      }
      goto LAB_00115dd7;
    }
    if (param_3 == 0x100) goto LAB_00115dd7;
    if (param_3 < 0x101) {
      if (param_3 != 0x40) {
        if (param_3 != 0x80) goto LAB_00115eb8;
        if ((param_4 == 0) || (*(short *)(param_4 + 8) != 8)) goto LAB_00115e0f;
        *(undefined2 *)(param_1 + 4) = *(undefined2 *)(*(int *)(param_4 + 4) + 4 + param_4);
      }
      goto LAB_00115dd7;
    }
    if ((0x1006 < param_3) || (param_3 < 0x1001)) goto LAB_00115eb8;
    if ((param_4 != 0) && (3 < *(ushort *)(param_4 + 8))) {
      switch(param_3) {
      case 0x1001:
      case 0x1002:
        if (param_3 == 0x1001) {
          param_1 = param_1 + 0x3c;
        }
        else {
          param_1 = param_1 + 0x24;
        }
        iVar3 = _sbreserve(param_1,*(undefined4 *)(*(int *)(param_4 + 4) + param_4));
        if (iVar3 == 0) {
          uVar4 = 0x37;
        }
        break;
      case 0x1003:
        *(undefined2 *)(param_1 + 0x44) = *(undefined2 *)(*(int *)(param_4 + 4) + param_4);
        break;
      case 0x1004:
        *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(*(int *)(param_4 + 4) + param_4);
        break;
      case 0x1005:
        *(undefined2 *)(param_1 + 0x46) = *(undefined2 *)(*(int *)(param_4 + 4) + param_4);
        break;
      case 0x1006:
        *(undefined2 *)(param_1 + 0x2e) = *(undefined2 *)(*(int *)(param_4 + 4) + param_4);
      }
      goto switchD_00115e2b_default;
    }
  }
LAB_00115e0f:
  uVar4 = 0x16;
switchD_00115e2b_default:
  if (iVar2 != 0) {
    _m_free(iVar2);
  }
  return uVar4;
}

