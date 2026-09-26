
int sub_407E802(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _kalloc(0xd6);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSdNewSvCouldnT);
  }
  _bzero(iVar2,0xd6);
  *(undefined4 *)(iVar2 + 4) = param_1;
  *(undefined4 *)(iVar2 + 8) = 0x80;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x5c) = 0;
  *(undefined *)(iVar2 + 0xc) = 0;
  *(undefined *)(iVar2 + 0xd) = 0;
  iVar3 = _kalloc(0x1c58);
  *(int *)(iVar2 + 0xce) = iVar3;
  uVar1 = iVar3 + 0xfU & 0xfffffff0;
  *(uint *)(iVar2 + 0xd2) = uVar1;
  if (uVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSdNewSvCouldnT_0);
  }
  *(uint *)(iVar2 + 0xc6) = iVar2 + 0x95U & 0xfffffff0;
  *(uint *)(iVar2 + 0xca) = iVar2 + 0xbeU & 0xfffffff0;
  _disksort_init(iVar2 + 0x60);
  return iVar2;
}
