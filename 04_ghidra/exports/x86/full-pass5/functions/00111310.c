/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111310 */

void _tty_ld_remove(int param_1)

{
  undefined4 uVar1;
  
  if ((-1 < param_1) && (param_1 < _nldisp)) {
    uVar1 = _spltty();
    (&_linesw)[param_1 * 0xc] = _nodev;
    (&PTR__ttylclose_001dafec)[param_1 * 0xc] = _nodev;
    (&PTR__ttread_001daff0)[param_1 * 0xc] = _nodev;
    (&PTR__ttwrite_001daff4)[param_1 * 0xc] = _nodev;
    (&PTR__nullioctl_001daff8)[param_1 * 0xc] = _nodev;
    (&PTR__ttyinput_001daffc)[param_1 * 0xc] = _nodev;
    (&PTR__ttyblkin_001db000)[param_1 * 0xc] = _nodev;
    (&PTR__ttstart_001db008)[param_1 * 0xc] = _nodev;
    (&PTR__ttymodem_001db00c)[param_1 * 0xc] = _nodev;
    (&PTR__ttselect_001db010)[param_1 * 0xc] = _nodev;
    _splx(uVar1);
  }
  return;
}

