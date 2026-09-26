/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6e04 */

int FUN_001b6e04(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                int param_5,undefined4 param_6)

{
  char cVar1;
  undefined4 uVar2;
  char local_8;
  
  local_8 = '\x01';
  *param_4 = 0;
  uVar2 = _objc_msgSend(param_1,PTR_s__inputChannel_001f9908);
  cVar1 = _objc_msgSend(param_6,PTR_s_isEqual__001f9838,uVar2);
  if (cVar1 != '\0') {
    if (param_5 == 0xe) {
      *param_4 = 2;
      *param_3 = 200;
      param_3[1] = 0xc9;
    }
    else {
      local_8 = -0x2e;
    }
    goto LAB_001b6f66;
  }
  uVar2 = _objc_msgSend(param_1,PTR_s__outputChannel_001f9900);
  cVar1 = _objc_msgSend(param_6,PTR_s_isEqual__001f9838,uVar2);
  if (cVar1 == '\0') {
    uVar2 = _objc_msgSend(PTR_s_InputStream_001f9dc4,PTR_s_class_001f9234);
    cVar1 = _objc_msgSend(param_6,PTR_s_isKindOf__001f9260,uVar2);
    if (cVar1 == '\0') {
      uVar2 = _objc_msgSend(PTR_s_OutputStream_001f9dc0,PTR_s_class_001f9234);
      cVar1 = _objc_msgSend(param_6,PTR_s_isKindOf__001f9260,uVar2);
      if (cVar1 == '\0') {
        _IOLog("Audio: unknown parameter object\n");
      }
      else {
        if (param_5 == 400) goto LAB_001b6f24;
        if (param_5 == 0x196) {
          *param_4 = 1;
          *param_3 = 0x25f;
          goto LAB_001b6f66;
        }
      }
    }
    else {
      if (param_5 == 400) {
LAB_001b6f24:
        *param_4 = 4;
        *param_3 = 600;
        param_3[1] = 0x259;
        param_3[2] = 0x25a;
        param_3[3] = 0x25b;
        goto LAB_001b6f66;
      }
      if (param_5 == 0x195) {
        *param_4 = 1;
        *param_3 = 0x25d;
        goto LAB_001b6f66;
      }
    }
  }
  local_8 = '\0';
LAB_001b6f66:
  return (int)local_8;
}

