/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016c96c */

undefined4 _kern_serv_load_objc(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x4d0) = param_2;
  _objc_registerModule(param_2,0);
  return 0;
}

