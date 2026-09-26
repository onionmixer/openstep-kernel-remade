/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf9f4. */
void __cdecl sub_1CF9F4(_DWORD *a1)
{
  char *v1; // eax
  uint32_t size; // [esp+8h] [ebp-4h] BYREF

  if ( a1[3] ) /*0x1cf9ff*/
  {
    v1 = getsectdatafromheaderinfo((int)a1, "__OBJC", "__meth_var_names", &size); /*0x1cfa14*/
    if ( !v1 ) /*0x1cfa1e*/
      v1 = getsectdatafromheaderinfo((int)a1, "__OBJC", "__selector_strs", &size); /*0x1cfa2c*/
    _sel_init(*a1, v1, size, a1[3]); /*0x1cfa40*/
  }
}
