/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf010. */
void __cdecl _objc_add_category(const char **a1, int a2)
{
  Class Class; // ecx
  objc_class *v3; // eax

  Class = objc_getClass(a1[1]); /*0x1cf021*/
  if ( Class ) /*0x1cf028*/
  {
    if ( a1[2] ) /*0x1cf02a*/
    {
      *(_DWORD *)a1[2] = Class->methodLists; /*0x1cf036*/
      Class->methodLists = (objc_method_list **)a1[2]; /*0x1cf03b*/
    }
    if ( a1[3] ) /*0x1cf03e*/
    {
      *(_DWORD *)a1[3] = Class->isa->methodLists; /*0x1cf04c*/
      Class->isa->methodLists = (objc_method_list **)a1[3]; /*0x1cf053*/
    }
    if ( a2 > 4 && a1[4] ) /*0x1cf05c*/
    {
      if ( Class->isa->version <= 4 ) /*0x1cf068*/
      {
        _objc_inform("unable to add protocols from category %s...\n", *a1); /*0x1cf08c*/
        _objc_inform("class `%s' must be recompiled\n", a1[1]); /*0x1cf09a*/
      }
      else
      {
        *(_DWORD *)a1[4] = Class->protocols; /*0x1cf070*/
        Class->protocols = (objc_protocol_list *)a1[4]; /*0x1cf075*/
        Class->isa->protocols = (objc_protocol_list *)a1[4]; /*0x1cf07d*/
      }
    }
  }
  else
  {
    _objc_inform("unable to add category %s...\n", *a1); /*0x1cf0a4*/
    _objc_inform("class `%s' not linked into application\n", a1[1]); /*0x1cf0b2*/
  }
  v3 = objc_getClass(a1[1]); /*0x1cf0be*/
  _objc_flush_caches(v3); /*0x1cf0c4*/
}
