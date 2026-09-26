/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181458 */

int FUN_00181458(int param_1,undefined4 param_2,int param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 0xb;
  bVar4 = true;
  pcVar2 = param_4;
  pcVar3 = s_IRQ_Levels_001e0fe8;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_empty_001f931c);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x14),PTR_s_appendList__001f9320,param_3);
  }
  iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_insertKey_value__001f9288,param_4,
                        param_3);
  if ((iVar1 != 0) && (param_3 != iVar1)) {
    _objc_msgSend(iVar1,PTR_s_freeObjects_001f92ec);
    _objc_msgSend(iVar1,PTR_s_free_001f921c);
  }
  return param_1;
}

