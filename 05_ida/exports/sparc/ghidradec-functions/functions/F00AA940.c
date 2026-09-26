
/* WARNING: Removing unreachable block (ram,0xf00aaa74) */
/* WARNING: Removing unreachable block (ram,0xf00aa9f4) */
/* WARNING: Removing unreachable block (ram,0xf00aa9e8) */
/* WARNING: Removing unreachable block (ram,0xf00aaa60) */
/* WARNING: Removing unreachable block (ram,0xf00aaa80) */
/* WARNING: Removing unreachable block (ram,0xf00aa980) */

undefined8 _startup_early(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar3 = _nclist * 0x40;
  iVar1 = _ncsize * 0x48;
  if (_bufpages == 0) {
    uVar4 = _mem_size;
    .udiv(_mem_size,0x32);
    _bufpages = uVar4 >> ((byte)_page_shift & 0x1f);
  }
  if ((_nbuf == 0) && (_nbuf = _bufpages, (int)_bufpages < 0x10)) {
    _nbuf = 0x10;
  }
  if (0xff < (int)_nbuf) {
    _nbuf = 0xff;
  }
  uVar2 = 0x2000;
  .udiv(0x2000,_page_size);
  uVar4 = _nbuf;
  .umul(_nbuf,uVar2);
  if (uVar4 < _bufpages) {
    _bufpages = uVar4;
  }
  if (_nmfsbuf == 0) {
    _nmfsbuf = (int)_nbuf / 2;
  }
  uVar4 = iVar3 + iVar1 + _nbuf * 0x44 + _page_mask & ~_page_mask;
  iVar1 = _kernel_map;
  _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4);
  if (iVar1 != 0) {
    _panic(aStartupEarlyNo);
  }
  _bzero(*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
  _cfree = *(int *)((int)register0x00000038 + -0xc);
  _ncache = *(int *)((int)register0x00000038 + -0xc) + _nclist * 0x40;
  *(int *)((int)register0x00000038 + -0xc) = _ncache;
  _buf = _ncache + _ncsize * 0x48;
  *(int *)((int)register0x00000038 + -0xc) = _buf;
  *(uint *)((int)register0x00000038 + -0xc) = _buf + _nbuf * 0x44;
  return CONCAT44(param_2,param_1);
}
