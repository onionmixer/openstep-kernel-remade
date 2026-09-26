/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cce94. */
void __cdecl class_removeMethods(Class a1, objc_method_list *a2)
{
  objc_method_list **methodLists; // edx
  objc_method_list *v3; // eax

  if ( (objc_method_list *)a1->methodLists == a2 ) /*0x1ccea1*/
  {
    a1->methodLists = &a2->obsolete->obsolete; /*0x1ccea5*/
  }
  else
  {
    methodLists = a1->methodLists; /*0x1cceac*/
    v3 = *methodLists; /*0x1cceaf*/
    if ( *methodLists ) /*0x1cceaf*/
    {
      while ( v3 != a2 ) /*0x1cceba*/
      {
        methodLists = &v3->obsolete; /*0x1ccec4*/
        v3 = v3->obsolete; /*0x1ccec6*/
        if ( !v3 ) /*0x1cceca*/
          goto LABEL_7; /*0x1cceca*/
      }
      *methodLists = v3->obsolete; /*0x1ccebe*/
    }
  }
LABEL_7:
  sub_1CCDA0(a1, 0); /*0x1ccecc*/
}
