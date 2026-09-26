/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6cec */

void FUN_001b6cec(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5
                 )

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  *param_4 = 0;
  uVar2 = _objc_msgSend(param_1,PTR_s__inputChannel_001f9908);
  cVar1 = _objc_msgSend(param_5,PTR_s_isEqual__001f9838,uVar2);
  if (cVar1 == '\0') {
    uVar2 = _objc_msgSend(param_1,PTR_s__outputChannel_001f9900);
    cVar1 = _objc_msgSend(param_5,PTR_s_isEqual__001f9838,uVar2);
    if (cVar1 == '\0') {
      uVar2 = _objc_msgSend(PTR_s_InputStream_001f9dc4,PTR_s_class_001f9234);
      cVar1 = _objc_msgSend(param_5,PTR_s_isKindOf__001f9260,uVar2);
      if (cVar1 == '\0') {
        uVar2 = _objc_msgSend(PTR_s_OutputStream_001f9dc0,PTR_s_class_001f9234);
        cVar1 = _objc_msgSend(param_5,PTR_s_isKindOf__001f9260,uVar2);
        if (cVar1 == '\0') {
          _IOLog("Audio: unknown parameter object\n");
        }
        else {
          puVar4 = &DAT_001d5e2c;
          *param_4 = 10;
        }
      }
      else {
        puVar4 = &DAT_001d5e54;
        *param_4 = 6;
      }
    }
    else {
      puVar4 = &DAT_001d5dd8;
      *param_4 = 0xe;
    }
  }
  else {
    puVar4 = (undefined4 *)&DAT_001d5e10;
    *param_4 = 7;
  }
  uVar3 = 0;
  if (*param_4 != 0) {
    do {
      *(undefined4 *)(param_3 + uVar3 * 4) = puVar4[uVar3];
      uVar3 = uVar3 + 1;
    } while (uVar3 < *param_4);
  }
  return;
}

