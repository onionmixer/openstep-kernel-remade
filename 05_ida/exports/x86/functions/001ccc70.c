/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ccc70. */
Method __cdecl class_getInstanceMethod(Class cls, SEL name)
{
  Class v2; // ebx
  objc_method_list **methodLists; // ecx
  Method result; // eax
  int v5; // edx

  if ( !cls || !name ) /*0x1ccc81*/
    return nullptr; /*0x1cccb3*/
  v2 = cls; /*0x1ccc83*/
  while ( 1 ) /*0x1ccc88*/
  {
    methodLists = v2->methodLists; /*0x1ccc88*/
    if ( methodLists ) /*0x1ccc8d*/
      break; /*0x1ccc8d*/
LABEL_9:
    v2 = v2->super_class; /*0x1cccac*/
    if ( !v2 ) /*0x1cccb1*/
      return nullptr; /*0x1cccb1*/
  }
  while ( 1 ) /*0x1ccc90*/
  {
    result = (Method)(methodLists + 2); /*0x1ccc90*/
    v5 = (int)&methodLists[1][-1].method_list[0].method_imp + 3; /*0x1ccc96*/
    if ( v5 >= 0 ) /*0x1ccc97*/
      break; /*0x1ccc97*/
LABEL_8:
    methodLists = (objc_method_list **)*methodLists; /*0x1ccca6*/
    if ( !methodLists ) /*0x1cccaa*/
      goto LABEL_9; /*0x1cccaa*/
  }
  while ( result->method_name != name ) /*0x1ccc9e*/
  {
    ++result; /*0x1ccca0*/
    if ( --v5 < 0 ) /*0x1ccca4*/
      goto LABEL_8; /*0x1ccca4*/
  }
  return result; /*0x1cccb8*/
}
