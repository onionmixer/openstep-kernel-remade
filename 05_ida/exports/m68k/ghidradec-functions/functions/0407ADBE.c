
/* WARNING: Removing unreachable block (ram,0x0407ae4c) */

void sub_407ADBE(int param_1,byte param_2)

{
  undefined uVar1;
  
  *(undefined *)(param_1 + 0x20) = 2;
  _delay(10);
  *(undefined *)(param_1 + 0x20) = 0;
  _delay(10);
  *(byte *)(param_1 + 8) = param_2 & 7 | 0x50;
  uVar1 = 5;
  if (_dma_chip == 0x139) {
    uVar1 = 4;
  }
  *(undefined *)(param_1 + 9) = uVar1;
  *(undefined *)(param_1 + 5) = 0x99;
  *(undefined *)(param_1 + 7) = 0;
  *(undefined *)(param_1 + 6) = 5;
  _delay(10);
  *(undefined *)(param_1 + 0x20) = 0x20;
  return;
}
