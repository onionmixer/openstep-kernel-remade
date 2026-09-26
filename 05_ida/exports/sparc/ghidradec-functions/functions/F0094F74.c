
/* WARNING: Removing unreachable block (ram,0xf0094ff4) */

undefined4 _hwbcopy(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = _bcopy_res._0_1_;
  _bcopy_res = CONCAT13(0xff,_bcopy_res._1_3_);
  iVar3 = _page_size;
  if (cVar2 == '\0') {
    do {
      iVar1 = segment(2);
      *(undefined4 *)(iVar1 + 0x1c00100) = param_1;
      iVar1 = segment(2);
      *(undefined4 *)(iVar1 + 0x1c00200) = param_3;
      param_2 = param_2 + 0x20;
      iVar3 = iVar3 + -0x20;
      param_4 = param_4 + 0x20;
    } while (iVar3 != 0);
    iVar3 = segment(2);
    if (((*(uint *)(iVar3 + 0x1c00e00) & 0x4000000) == 0) ||
       ((*(uint *)(iVar3 + 0x1c00e00) & 0x2000000) == 0)) {
      _bcopy_res = 0;
      return 0;
    }
    _panic(aHwBcopyStreamO,param_2,0x2000000,param_4);
  }
  return 1;
}
