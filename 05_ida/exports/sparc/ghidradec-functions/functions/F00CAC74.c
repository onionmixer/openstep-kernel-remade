
/* WARNING: Removing unreachable block (ram,0xf00cad10) */
/* WARNING: Removing unreachable block (ram,0xf00cacac) */

undefined8
_IOAddToBdevsw(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar3 = _bdevsw;
  iVar4 = 0;
  iVar1 = 0;
  if (0 < _nblkdev) {
    do {
      puVar2 = puVar3;
      _memcmp(puVar3,&off_F012EC9C,0x18);
      if (puVar2 == (undefined *)0x0) break;
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x18;
    } while (iVar4 < _nblkdev);
    iVar1 = iVar4 << 1;
  }
  iVar1 = (iVar1 + iVar4) * 8;
  puVar3 = _bdevsw + iVar1;
  if (-1 < iVar4) {
    if (_nblkdev <= iVar4) {
      iVar4 = -1;
      goto locret_F00CAD54;
    }
    _memcmp(puVar3,&off_F012EC9C,0x18);
    if (puVar3 == (undefined *)0x0) {
      *(undefined4 *)(_bdevsw + iVar1) = param_1;
      *(undefined4 *)(_bdevsw + iVar1 + 4) = param_2;
      *(undefined4 *)(_bdevsw + iVar1 + 8) = param_3;
      *(undefined4 *)(_bdevsw + iVar1 + 0xc) = param_4;
      *(undefined4 *)(_bdevsw + iVar1 + 0x10) = param_5;
      *(undefined4 *)(_bdevsw + iVar1 + 0x14) = 0;
      if ((param_6 & 0xff) != 0) {
        *(undefined4 *)(_bdevsw + iVar1 + 0x14) = 0x400;
      }
      goto locret_F00CAD54;
    }
  }
  iVar4 = -1;
locret_F00CAD54:
  return CONCAT44(param_2,iVar4);
}
