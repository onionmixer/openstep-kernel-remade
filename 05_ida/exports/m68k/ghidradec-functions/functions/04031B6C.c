
void _smark(int param_1,word param_2)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  _microtime(&uStack_c);
  *(word *)(param_1 + 0x3e) = param_2 | *(word *)(param_1 + 0x3e);
  if ((param_2 & 4) != 0) {
    *(undefined4 *)(param_1 + 0x4a) = uStack_c;
    *(undefined4 *)(param_1 + 0x4e) = uStack_8;
  }
  if ((param_2 & 2) != 0) {
    *(undefined4 *)(param_1 + 0x52) = uStack_c;
    *(undefined4 *)(param_1 + 0x56) = uStack_8;
  }
  if ((param_2 & 0x40) != 0) {
    *(undefined4 *)(param_1 + 0x5a) = uStack_c;
    *(undefined4 *)(param_1 + 0x5e) = uStack_8;
  }
  return;
}
