/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001540dc */

undefined4 _msg_return_translate(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffffc3ff;
  if ((int)uVar1 < 0x1000000f) {
    if (0x1000000c < (int)uVar1) {
      _printf(s_msg_return_translate___x__>_inte_001dea9c,param_1);
      return 0xffffff94;
    }
    if (uVar1 == 0x10000006) {
      return 0xffffff96;
    }
    if ((int)uVar1 < 0x10000007) {
      if (uVar1 == 0x10000002) {
        return 0xffffff9b;
      }
      if (0x10000002 < (int)uVar1) {
        if (uVar1 == 0x10000004) {
          return 0xffffff99;
        }
        if ((int)uVar1 < 0x10000005) {
          return 0xffffff9a;
        }
        return 0xffffff97;
      }
      if (uVar1 == 0) {
        return 0;
      }
    }
    else if ((int)uVar1 < 0x1000000b) {
      if (0x10000008 < (int)uVar1) {
        return 0xffffff9a;
      }
      if (uVar1 == 0x10000007) {
        return 0xffffff94;
      }
      if (uVar1 == 0x10000008) {
        return 0xffffff92;
      }
    }
    else if ((uVar1 != 0x1000000b) && (uVar1 == 0x1000000c)) {
      return 0xffffff9b;
    }
  }
  else {
    if (uVar1 == 0x10004005) {
      return 0xffffff31;
    }
    if ((int)uVar1 < 0x10004006) {
      if (uVar1 != 0x10004001) {
        if (0x10004001 < (int)uVar1) {
          if (uVar1 == 0x10004003) {
            return 0xffffff35;
          }
          if ((int)uVar1 < 0x10004004) {
            return 0xffffff36;
          }
          return 0xffffff34;
        }
        if (uVar1 == 0x1000000f) {
          return 0xffffff9a;
        }
      }
    }
    else if ((int)uVar1 < 0x1000400b) {
      if (0x10004008 < (int)uVar1) {
        return 0xffffff36;
      }
      if (uVar1 != 0x10004007) {
        if ((int)uVar1 < 0x10004008) {
          return 0xffffff30;
        }
        return 0xffffff37;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_msg_return_translate_001deac5);
}

