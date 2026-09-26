/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cef90. */
void __cdecl _objc_remove_category(int a1, int a2)
{
  objc_class *Class; // eax
  Class *p_isa; // esi

  Class = objc_getClass(*(const char **)(a1 + 4)); /*0x1cef9c*/
  p_isa = &Class->isa; /*0x1cefa1*/
  if ( Class ) /*0x1cefa8*/
  {
    if ( *(_DWORD *)(a1 + 8) ) /*0x1cefaa*/
      class_removeMethods(Class, *(objc_method_list **)(a1 + 8)); /*0x1cefb5*/
    if ( *(_DWORD *)(a1 + 12) ) /*0x1cefbd*/
      class_removeMethods(*p_isa, *(objc_method_list **)(a1 + 12)); /*0x1cefca*/
    if ( a2 > 4 ) /*0x1cefd6*/
    {
      if ( *(_DWORD *)(a1 + 16) ) /*0x1cefd8*/
        _class_removeProtocols(p_isa, *(_DWORD **)(a1 + 16)); /*0x1cefe3*/
    }
  }
  else
  {
    _objc_inform("unable to remove category %s...\n", *(const char **)a1); /*0x1ceff4*/
    _objc_inform("class `%s' not linked into application\n", *(const char **)(a1 + 4)); /*0x1cf002*/
  }
}
