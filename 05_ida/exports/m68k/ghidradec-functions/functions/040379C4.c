
void _irele(int param_1)

{
  if ((*(byte *)(param_1 + 0x43) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aIrele);
  }
  if ((*(word *)(param_1 + 0x42) & 0x46) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 8;
    _microtime(&_iuniqtime);
    if ((*(byte *)(param_1 + 0x43) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x72) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7a) = _iuniqtime;
    }
    if ((*(byte *)(param_1 + 0x43) & 0x40) != 0) {
      *(undefined4 *)(param_1 + 0x4a) = 0;
      *(undefined4 *)(param_1 + 0x82) = _iuniqtime;
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return;
}
