
int _do_writeback(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  word wVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = 0;
  if ((*(byte *)(param_1 + 0x53) & 0x98) != 0x80) goto loc_409A682;
  uVar5 = *(uint *)(param_1 + 0x6c);
  uVar2 = (*(byte *)(param_1 + 0x53) & 0x7f) >> 5;
  wVar4 = (word)(uVar5 >> 0x10);
  if (uVar2 == 1) {
    uVar2 = *(uint *)(param_1 + 0x68) & 3;
    if (uVar2 == 1) {
      uVar5 = (uint)wVar4;
    }
    else if (uVar2 < 2) {
      if (uVar2 == 0) {
        uVar5 = uVar5 >> 0x18;
      }
    }
    else if (uVar2 == 2) {
      uVar5 = uVar5 >> 8;
    }
    uVar7 = 1;
loc_409A668:
    bVar1 = *(byte *)(param_1 + 0x53);
  }
  else {
    if (uVar2 < 2) {
      if (uVar2 != 0) goto loc_409A682;
      uVar2 = *(uint *)(param_1 + 0x68) & 3;
      if (uVar2 == 1) {
        uVar5 = uVar5 << 8 | uVar5 >> 0x18;
      }
      else if (1 < uVar2) {
        if (uVar2 == 2) {
          uVar5 = uVar5 << 0x10 | uVar5 >> 0x10;
        }
        else if (uVar2 == 3) {
          uVar5 = uVar5 << 0x18 | uVar5 >> 8;
        }
      }
      uVar7 = 0;
      goto loc_409A668;
    }
    if (uVar2 != 2) goto loc_409A682;
    uVar2 = *(uint *)(param_1 + 0x68) & 3;
    if (uVar2 == 1) {
      uVar5 = uVar5 >> 8;
    }
    else if (uVar2 < 2) {
      if (uVar2 == 0) {
        uVar5 = (uint)wVar4;
      }
    }
    else if ((uVar2 != 2) && (uVar2 == 3)) {
      uVar5 = uVar5 << 8 | uVar5 >> 0x18;
    }
    uVar7 = 2;
    bVar1 = *(byte *)(param_1 + 0x53);
  }
  iVar6 = _move_space(*(undefined4 *)(param_1 + 0x68),bVar1 & 7,uVar7,uVar5,param_1);
loc_409A682:
  bVar1 = *(byte *)(param_1 + 0x51);
  if (((bVar1 & 0x98) == 0x80) &&
     (iVar3 = _move_space(*(undefined4 *)(param_1 + 0x60),bVar1 & 7,(bVar1 & 0x7f) >> 5,
                          *(undefined4 *)(param_1 + 100),param_1), iVar6 == 0)) {
    iVar6 = iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x4f);
  if (((bVar1 & 0x98) == 0x80) &&
     (iVar3 = _move_space(*(undefined4 *)(param_1 + 0x58),bVar1 & 7,(bVar1 & 0x7f) >> 5,
                          *(undefined4 *)(param_1 + 0x5c),param_1), iVar6 == 0)) {
    iVar6 = iVar3;
  }
  return iVar6;
}
