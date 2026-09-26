/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cce5c. */
void __cdecl class_addMethods(Class a1, objc_method_list *a2)
{
  a2->obsolete = (objc_method_list *)a1->methodLists; /*0x1cce68*/
  a1->methodLists = &a2->obsolete; /*0x1cce6a*/
  sub_1CCDA0(a1, 0); /*0x1cce70*/
}
