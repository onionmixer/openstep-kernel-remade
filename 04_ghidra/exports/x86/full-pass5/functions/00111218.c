/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111218 */

undefined4
_tty_ld_install(int param_1,undefined4 param_2,undefined4 param_3,undefined *param_4,
               undefined *param_5,undefined *param_6,undefined *param_7,undefined *param_8,
               undefined *param_9,undefined *param_10,undefined *param_11,undefined *param_12)

{
  undefined4 uVar1;
  
  if (((((param_1 < 0) || (_nldisp <= param_1)) || ((code *)(&_linesw)[param_1 * 0xc] != _nodev)) ||
      (((((code *)(&PTR__ttylclose_001dafec)[param_1 * 0xc] != _nodev ||
         ((code *)(&PTR__ttread_001daff0)[param_1 * 0xc] != _nodev)) ||
        (((code *)(&PTR__ttwrite_001daff4)[param_1 * 0xc] != _nodev ||
         (((code *)(&PTR__nullioctl_001daff8)[param_1 * 0xc] != _nodev ||
          ((code *)(&PTR__ttyinput_001daffc)[param_1 * 0xc] != _nodev)))))) ||
       ((code *)(&PTR__ttyblkin_001db000)[param_1 * 0xc] != _nodev)))) ||
     ((((code *)(&PTR__ttstart_001db008)[param_1 * 0xc] != _nodev ||
       ((code *)(&PTR__ttymodem_001db00c)[param_1 * 0xc] != _nodev)) ||
      ((code *)(&PTR__ttselect_001db010)[param_1 * 0xc] != _nodev)))) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = _spltty();
    *(undefined4 *)(&DAT_001db014 + param_1 * 0x30) = param_2;
    (&_linesw)[param_1 * 0xc] = param_3;
    (&PTR__ttylclose_001dafec)[param_1 * 0xc] = param_4;
    (&PTR__ttread_001daff0)[param_1 * 0xc] = param_5;
    (&PTR__ttwrite_001daff4)[param_1 * 0xc] = param_6;
    (&PTR__nullioctl_001daff8)[param_1 * 0xc] = param_7;
    (&PTR__ttyinput_001daffc)[param_1 * 0xc] = param_8;
    (&PTR__ttyblkin_001db000)[param_1 * 0xc] = param_9;
    (&PTR__ttstart_001db008)[param_1 * 0xc] = param_10;
    (&PTR__ttymodem_001db00c)[param_1 * 0xc] = param_11;
    (&PTR__ttselect_001db010)[param_1 * 0xc] = param_12;
    _splx(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

