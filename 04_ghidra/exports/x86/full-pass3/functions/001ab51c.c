/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab51c */

undefined4 FUN_001ab51c(int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  
  _objc_msgSend(param_1,PTR_s_registerDevice_001f948c);
  *(undefined4 *)(param_1 + 0x13c) = param_3;
  *(undefined2 *)(param_1 + 0x140) = param_4;
  uVar1 = _objc_msgSend(param_1,PTR_s_unit_001f9c28,"4/16Mb Token-Ring",
                        *(undefined4 *)(param_1 + 0x138),0);
  uVar1 = _objc_msgSend(PTR_s_IONetwork_001f9dd0,PTR_s_alloc_001f9210,
                        PTR_s_initForNetworkDevice_name_unit_t_001f9b30,param_1,&DAT_001e5158,uVar1)
  ;
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x150) = uVar1;
  if ((*(byte *)(param_1 + 0x128) & 8) != 0) {
    uVar1 = _objc_msgSend(param_1,PTR_s_unit_001f9c28,(*(byte *)(param_1 + 0x128) & 0x20) != 0,
                          *(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_1 + 0x130));
    _vtrip_config(uVar1);
  }
  uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined1 *)(param_1 + 0x13c),
                        *(undefined1 *)(param_1 + 0x13d),*(undefined1 *)(param_1 + 0x13e),
                        *(undefined1 *)(param_1 + 0x13f),*(undefined1 *)(param_1 + 0x140),
                        *(undefined1 *)(param_1 + 0x141));
  _IOLog("%s: Token Ring Node address %02x:%02x:%02x:%02x:%02x:%02x\n",uVar1);
  return *(undefined4 *)(param_1 + 0x150);
}

