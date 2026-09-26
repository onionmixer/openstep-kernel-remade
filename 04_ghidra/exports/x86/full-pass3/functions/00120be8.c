/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120be8 */

undefined4 _if_ioctl(int param_1,uint param_2,int param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  uint local_c;
  int local_8;
  
  pcVar1 = *(code **)(param_1 + 0x38);
  if (pcVar1 == (code *)0x0) {
    uVar2 = 6;
  }
  else if (param_2 == 0x80206931) {
    uVar2 = (*pcVar1)(param_1,"add-multicast",param_3);
  }
  else {
    if (param_2 < 0x80206932) {
      if (param_2 == 0x8020690c) {
        uVar2 = (*pcVar1)(param_1,"setaddr",param_3);
        return uVar2;
      }
      if (param_2 == 0x80206910) {
        uVar2 = (*pcVar1)(param_1,"setflags",param_3 + 0x10);
        return uVar2;
      }
    }
    else {
      if (param_2 == 0xc020690d) {
        uVar2 = (*pcVar1)(param_1,"getaddr",param_3 + 0x10);
        return uVar2;
      }
      if (param_2 < 0xc020690e) {
        if (param_2 == 0x80206932) {
          uVar2 = (*pcVar1)(param_1,"rmv-multicast",param_3);
          return uVar2;
        }
      }
      else if (param_2 == 0xc0206921) {
        uVar2 = (*pcVar1)(param_1,"autoaddr",param_3 + 0x10);
        return uVar2;
      }
    }
    local_c = param_2;
    local_8 = param_3;
    uVar2 = (**(code **)(param_1 + 0x38))(param_1,"unix-ioctl",&local_c);
  }
  return uVar2;
}

