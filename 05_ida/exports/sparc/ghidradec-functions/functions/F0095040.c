
/* WARNING: Removing unreachable block (ram,0xf00950bc) */

undefined4 _hwbzero(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = _page_size;
  cVar2 = _bcopy_res._0_1_;
  _bcopy_res = CONCAT13(0xff,_bcopy_res._1_3_);
  if (cVar2 == '\0') {
    iVar1 = segment(2);
    *(undefined4 *)(iVar1 + 0x1c00100) = param_3;
    do {
      iVar1 = segment(2);
      *(undefined4 *)(iVar1 + 0x1c00200) = param_1;
      iVar3 = iVar3 + -0x20;
      param_2 = param_2 + 0x20;
    } while (iVar3 != 0);
    iVar3 = segment(2);
    if (((*(uint *)(iVar3 + 0x1c00e00) & 0x4000000) == 0) ||
       ((*(uint *)(iVar3 + 0x1c00e00) & 0x2000000) == 0)) {
      _bcopy_res = 0;
      return 0;
    }
    _panic(aHwBzeroStreamO,param_2);
  }
  return 1;
}
