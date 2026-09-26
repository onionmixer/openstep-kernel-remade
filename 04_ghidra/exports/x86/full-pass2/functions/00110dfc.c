/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00110dfc */

void _ttyrub(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_8;
  
  piVar1 = (int *)*param_2;
  uVar2 = piVar1[0xf];
  if ((uVar2 & 8) == 0) {
    return;
  }
  if ((*(byte *)((int)piVar1 + 0x42) & 0x40) != 0) {
    return;
  }
  piVar1[0xf] = uVar2 & 0xff7fffff;
  if ((uVar2 & 0x10000) == 0) {
    if ((uVar2 & 0x20000) == 0) {
      param_1 = (uint)*(byte *)((int)piVar1 + 0x4d);
    }
    else if ((*(byte *)((int)piVar1 + 0x42) & 4) == 0) {
      _ttyoutput(0x5c,piVar1);
      piVar1[0x10] = piVar1[0x10] | 0x40000;
    }
    _ttyecho(param_1,param_2);
    goto LAB_00110f96;
  }
  if (*(char *)((int)piVar1 + 0x4b) == '\0') {
LAB_00110ea8:
    _ttyretype(param_2);
    return;
  }
  if (param_1 - 0x109 < 2) {
LAB_00110e92:
    uVar5 = 2;
  }
  else {
    switch((&_partab)[param_1 & 0xff] & 0x3f) {
    case 0:
      uVar5 = 1;
      break;
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
      if ((*(byte *)((int)piVar1 + 0x3f) & 0x10) == 0) goto LAB_00110f96;
      goto LAB_00110e92;
    case 4:
      if ((int)*(char *)((int)piVar1 + 0x4b) < *piVar1) goto LAB_00110ea8;
      uVar5 = _spltty();
      iVar4 = piVar1[0x12];
      piVar1[0x10] = piVar1[0x10] | 0x200000;
      piVar1[0xf] = piVar1[0xf] | 0x800000;
      *(char *)(piVar1 + 0x12) = (char)piVar1[0x13];
      iVar3 = piVar1[1] + -1;
      while (iVar3 = _nextc3(piVar1,iVar3,&local_8), iVar3 != 0) {
        _ttyecho(local_8,param_2);
      }
      piVar1[0xf] = piVar1[0xf] & 0xff7fffff;
      piVar1[0x10] = piVar1[0x10] & 0xffdfffff;
      _splx(uVar5);
      iVar4 = (int)(char)iVar4 - (int)(char)piVar1[0x12];
      *(char *)(piVar1 + 0x12) = (char)iVar4 + (char)piVar1[0x12];
      if (8 < iVar4) {
        iVar4 = 8;
      }
      while (iVar4 = iVar4 + -1, -1 < iVar4) {
        _ttyoutput(8,piVar1);
      }
      goto LAB_00110f96;
    default:
                    /* WARNING: Subroutine does not return */
      _panic(s_ttyrub_001dafce);
    }
  }
  _ttyrubo(piVar1,uVar5);
LAB_00110f96:
  *(char *)((int)piVar1 + 0x4b) = *(char *)((int)piVar1 + 0x4b) + -1;
  return;
}

