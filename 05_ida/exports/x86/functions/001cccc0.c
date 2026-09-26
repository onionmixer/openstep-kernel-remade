/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cccc0. */
Method __cdecl class_getClassMethod(Class cls, SEL name)
{
  Class isa; // eax
  Class v3; // ebx
  objc_method_list **methodLists; // ecx
  Method result; // eax
  int v6; // edx

  if ( !cls || !name ) /*0x1cccd1*/
    return nullptr; /*0x1ccd0b*/
  isa = cls; /*0x1cccd3*/
  if ( (cls->info & 2) == 0 ) /*0x1cccd9*/
    isa = cls->isa; /*0x1cccdb*/
  v3 = isa; /*0x1cccdd*/
  while ( 1 ) /*0x1ccce0*/
  {
    methodLists = v3->methodLists; /*0x1ccce0*/
    if ( methodLists ) /*0x1ccce5*/
      break; /*0x1ccce5*/
LABEL_11:
    v3 = v3->super_class; /*0x1ccd04*/
    if ( !v3 ) /*0x1ccd09*/
      return nullptr; /*0x1ccd09*/
  }
  while ( 1 ) /*0x1ccce8*/
  {
    result = (Method)(methodLists + 2); /*0x1ccce8*/
    v6 = (int)&methodLists[1][-1].method_list[0].method_imp + 3; /*0x1cccee*/
    if ( v6 >= 0 ) /*0x1cccef*/
      break; /*0x1cccef*/
LABEL_10:
    methodLists = (objc_method_list **)*methodLists; /*0x1cccfe*/
    if ( !methodLists ) /*0x1ccd02*/
      goto LABEL_11; /*0x1ccd02*/
  }
  while ( result->method_name != name ) /*0x1cccf6*/
  {
    ++result; /*0x1cccf8*/
    if ( --v6 < 0 ) /*0x1cccfc*/
      goto LABEL_10; /*0x1cccfc*/
  }
  return result; /*0x1ccd10*/
}
