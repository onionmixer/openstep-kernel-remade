/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c93c8. */
int __cdecl sub_1C93C8(int a1, char *a2, id a3)
{
  char v3; // al
  id v5; // [esp-8h] [ebp-Ch]

  v3 = *a2; /*0x1c93d5*/
  if ( *a2 == 64 ) /*0x1c93d9*/
  {
    v5 = objc_msgSend(a3, sel_name); /*0x1c9401*/
    return NXPrintf(a1, (int)"%s[0x%x]", v5, a3); /*0x1c9407*/
  }
  if ( *a2 <= 64 ) /*0x1c93db*/
  {
    if ( v3 == 37 || v3 == 42 ) /*0x1c93e3*/
      return NXPrintf(a1, (int)"\"%s\"", a3); /*0x1c9422*/
    return NXPrintf(a1, (int)"0x%x", a3); /*0x1c93e3*/
  }
  if ( v3 != 105 ) /*0x1c93ea*/
    return NXPrintf(a1, (int)"0x%x", a3); /*0x1c942b*/
  return NXPrintf(a1, (int)"%d[0x%x]", a3, a3); /*0x1c9430*/
}
