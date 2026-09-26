/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa80c */

undefined4 FUN_001aa80c(int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x150) = param_3;
  *(undefined2 *)(param_1 + 0x154) = param_4;
  uVar1 = _objc_msgSend(param_1,PTR_s_unit_001f9c28,"10MB Ethernet",0x5dc,0);
  uVar1 = _objc_msgSend(PTR_s_IONetwork_001f9dd0,PTR_s_alloc_001f9210,
                        PTR_s_initForNetworkDevice_name_unit_t_001f9b30,param_1,&DAT_001e5144,uVar1)
  ;
  uVar1 = _objc_msgSend(uVar1);
  *(undefined4 *)(param_1 + 0x14c) = uVar1;
  _objc_msgSend(param_1,PTR_s_registerAsDebuggerDevice_001f9b2c);
  uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined1 *)(param_1 + 0x150),
                        *(undefined1 *)(param_1 + 0x151),*(undefined1 *)(param_1 + 0x152),
                        *(undefined1 *)(param_1 + 0x153),*(undefined1 *)(param_1 + 0x154),
                        *(undefined1 *)(param_1 + 0x155));
  _IOLog("%s: Ethernet address %02x:%02x:%02x:%02x:%02x:%02x\n",uVar1);
  return *(undefined4 *)(param_1 + 0x14c);
}

