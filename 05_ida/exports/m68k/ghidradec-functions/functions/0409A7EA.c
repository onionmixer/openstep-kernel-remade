
void _bmap_parity_error(int param_1)

{
  int iVar1;
  undefined6 *puVar2;
  int iVar3;
  
  *(byte *)(_bmap_chip + 8) = *(byte *)(_bmap_chip + 8) | 0x80;
  if (_dma_chip == 0x139) {
    iVar1 = 0x4000000;
    if (_machine_type == '\x03') {
      iVar1 = 0x2000000;
    }
  }
  else {
    iVar1 = 0x8000000;
  }
  iVar3 = 4;
  if ((_machine_type == '\x03') &&
     ((param_1 - (_slot_id + 0x4000000)) / (iVar1 / _num_regions) != 0)) {
    iVar3 = 2;
  }
  if (_machine_type == '\x03') {
    iVar1 = iVar3 + 1;
  }
  else {
    iVar1 = iVar3 + 3;
  }
  puVar2 = (undefined6 *)&DAT_40ace31;
  if (_machine_type == '\x03') {
    puVar2 = &aAnd;
  }
  _printf(aParityErrorAtA_0,param_1,iVar3,puVar2,iVar1);
                    /* WARNING: Subroutine does not return */
  _panic(aParityError);
}
